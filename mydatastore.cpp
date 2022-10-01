#include <iomanip>
#include <sstream>
#include <map>
#include "mydatastore.h"
#include "util.h"

using namespace std;
MyDataStore::~MyDataStore(){//deallocates datastorage devises instantiated for products and users
	std::set<Product*>::iterator it;
	for(it = productset.begin(); it != productset.end(); ++it){
		delete *it;
	}
 
	std::map<std::string, User*>::iterator st;
	for(st = usermap.begin(); st != usermap.end(); ++st){
		delete st->second;
	}
}

std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type){
	std::set<Product*> resultsearch;
	std::vector<Product*> returnprod;//if no terms returns an empty set
	if(terms.size()==0){
		return returnprod;
	}
	if(type == 0){//AND search function searches for products with every word in terms
		string curword = terms[0];
		if(keywordprod.find(curword)==keywordprod.end()){
			return returnprod;
		}
		else{
			resultsearch = keywordprod[curword];
			for(unsigned int i=1; i<terms.size(); i++){//iterates through words in terms and intersects their products with already searched words.
				resultsearch = setIntersection(resultsearch, keywordprod[terms[i]]);
			}
			std::set<Product*>::iterator it;
			for(it = resultsearch.begin(); it!=resultsearch.end(); ++it){//pushes set into a vector to return
				returnprod.push_back(*it);
			}
			return returnprod;
		}

	}
	
	if(type == 1){//OR search function searches for products with any word in terms
		for(unsigned int i=0;i<terms.size(); i++){//iterates through terms and finds products associated and adds them to set of results
			string curword = terms[i];
			if(keywordprod.find(curword) != keywordprod.end()){
				resultsearch = setUnion(keywordprod[terms[i]], resultsearch );
			}
		}
		std::set<Product*>::iterator it;
		for(it = resultsearch.begin(); it!=resultsearch.end(); ++it){//pushes set into a vector to return
			returnprod.push_back(*it);
		}
		return returnprod;
	}
	return returnprod;
}

void MyDataStore::addProduct(Product* p){//stores products from testfile and inserts them and their keywords into a map
	productset.insert(p);
	set<string> keywords;
	keywords = p->keywords();
	set<string>::iterator it;
	for(it = keywords.begin(); it!=keywords.end(); ++it){//creates a node for each keyword, checks if keyword exists, if so adds product* to node
		if(keywordprod.find(convToLower(*it))==keywordprod.end()){
			set<Product*> noprod;
			noprod.insert(p);
			keywordprod.insert(make_pair(convToLower(*it), noprod));
		}
		else{
			keywordprod[convToLower(*it)].insert(p);
		}
	}
}

void MyDataStore::addUser(User* u){//adds user from txt file into usermap and creates a cart for the user
	string uname = u->getName();
	std::queue<Product*> cart;
	usermap.insert(make_pair(uname, u));
	cartmap.insert(make_pair(uname, cart));
}

void MyDataStore::AddToCart(User* u, std::vector<Product*> hits, int hitnum){
	string uname = u->getName();//adds a search result to the users cart who called the addtocart
	int truehit = hitnum--;//returns a warning however since the deletion incident the hitnum was being wonky and wouldn't go down in value any other way
	Product* pushp = (hits[hitnum]);
	if(cartmap.find(uname)!=cartmap.end()){
		cartmap[uname].push(pushp);
	}	
}

void MyDataStore::viewcart(User* u){//displays the cart of the user
	queue<Product*> qtemp;
	int itemnum = 1;
	string uname = u->getName();
	while(!cartmap[uname].empty()){
		cout << "Item " << itemnum << ": " << (cartmap[uname].front())->displayString() << endl;
		qtemp.push(cartmap[uname].front());
		cartmap[uname].pop();
		++itemnum;
	}
	while(!qtemp.empty()){
		cartmap[uname].push(qtemp.front());
		qtemp.pop();
	}
}

void MyDataStore::buycart(User* u){//checks if item is available and subtracts price from users money if they can afford it. Does nothing if they can't
queue<Product*> qtemp;
string uname = u->getName();
while(!cartmap[uname].empty()){
	Product* F = cartmap[uname].front();
	double fprice = F->getPrice();
	double bal = u->getBalance();
	if(fprice <= bal && F->getQty()>0){
		u->deductAmount(fprice);
		F->subtractQty(1);
		cartmap[uname].pop();
	}
	if(F->getQty()==0 || bal<fprice){
		qtemp.push(cartmap[uname].front());
		cartmap[uname].pop();
	}
}
while(!qtemp.empty()){
	cartmap[uname].push(qtemp.front());
	qtemp.pop();
}
}
void MyDataStore::dump(std::ostream& ofile){//creates an output txt file and adds information
	ofile << "<products>" << endl;
	std::set<Product*>::iterator it;
	for(it = productset.begin(); it!=productset.end(); ++it){
		(*it)->dump(ofile);
	}
	ofile << "<users>" << endl;
	std::map<string, User*>::iterator st;
	for(st = usermap.begin(); st!=usermap.end();++st){
		st->second->dump(ofile);
	}
}
