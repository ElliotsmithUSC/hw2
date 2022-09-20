#include <sstream>
#include <iomanip>
#include <sstream>
#include "book.h"
#include "util.h"

using namespace std;

Book::Book(const std::string category, const std::string name, double price, int qty, const std::string isbn, const std::string author) :
	Product("book", name, price, qty),
	isbn_(isbn),
	author_(author)
}

Book::~Book(){

}

std::set<std::string> Book::keywords() const{
	set<string> keyword;
	set<string> tempkey;
	string valget = getName();
	keyword = parseStringToWords(valget);
	tempkey = {isbn_};
	keyword = setUnion<string>(keyword, tempkey);
	valget = author_;
	tempkey = parseStringToWords(valget);
	keyword = setUnion<string>(keyword, tempkey);
	return keyword;
}

std::string Book::displayString() const{
/*std::string returnval = std::string("Title: ") + name_ + (" Written by: ") + author_ + (" Price: ") + price_;
return returnval;*/
std::stringstream s;
s << name_ << " by " << author_ << " $" << price_ << " " << qty_ << " copies remain";
string returnstring;
s >> returnstring;
return returnstring;
}

void Book::dump(std::ostream& os) const{
	os << category_ << endl;
	os << name_ << endl;
	os << price_ << endl;
	os << qty_ << endl;
	os << isbn_ << endl;
	os << author_ << endl;
}

