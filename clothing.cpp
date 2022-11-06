#include <sstream>
#include <iomanip>
#include <sstream>
#include "clothing.h"
#include "util.h"

using namespace std;

Clothing::Clothing(const std::string name, double price, int qty, const std::string size, const std::string brand) :
	Product("clothing", name, price, qty){
	size_=size;
	brand_=brand;
}

Clothing::~Clothing(){

}

std::set<std::string> Clothing::keywords() const{//stitches all searchable keywords together such as name and brand
	set<string> keyword;
	set<string> keyword2;
	set<string> keywordfinal;
	string tempkey;
	string valget = getName();
	keyword = parseStringToWords(valget);
	tempkey = {brand_};
	keyword2 = parseStringToWords(tempkey);
	keywordfinal = setUnion(keyword, keyword2);
	return keywordfinal;
}

std::string Clothing::displayString() const{//uses append to output correct format
	string returnstring(name_);
	stringstream s1, s2, s3, s4;
	s1 << price_;
	s2 << size_;
	s3 << brand_;
	s4 << qty_;
	returnstring.append("\n");
	returnstring.append("Size: ");
	returnstring.append(s2.str());
	returnstring.append(" Brand: ");
	returnstring.append(s3.str());
	returnstring.append("\n");
	returnstring.append(s1.str());
	returnstring.append(" ");
	returnstring.append(s4.str());
	returnstring.append(" left.");
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
