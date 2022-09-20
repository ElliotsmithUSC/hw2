#include <sstream>
#include <iomanip>
#include <sstream>
#include "clothing.h"
#include "util.h"

using namespace std;

Clothing::Clothing(const std::string name, double price, int qty, const std::string size, const std::string brand) :
	Product("clothing", name, price, qty),
	size_(size),
	brand_(brand)
}

Clothing::~Clothing(){

}

std::set<std::string> Clothing::keywords() const{
	set<string> keyword;
	set<string> tempkey;
	string valget = getName();
	keyword = parseStringToWords(valget);
	tempkey = {brand_};
	keyword = setUnion<string>(keyword, tempkey);
	return keyword;
}

std::string Clothing::displayString() const{
/*std::string returnval = std::string("Title: ") + name_ + (" Written by: ") + author_ + (" Price: ") + price_;
return returnval;*/
std::stringstream s;
s << name_ << " from " << brand_ << " $" << price_ << " " << qty_ << " articles remain";
string returnstring;
s >> returnstring;
return returnstring;
}

void Clothing::dump(std::ostream& os) const{
	os << category_ << endl;
	os << name_ << endl;
	os << price_ << endl;
	os << qty_ << endl;
	os << size_ << endl;
	os << brand_ << endl;
}
