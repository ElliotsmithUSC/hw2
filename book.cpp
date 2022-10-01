#include <sstream>
#include <iomanip>
#include <sstream>
#include "book.h"
#include "util.h"

using namespace std;

Book::Book(const std::string name, double price, int qty, const std::string isbn, const std::string author) :
	Product("book", name, price, qty){
	isbn_=isbn;
	author_=author;
}

Book::~Book(){

}

std::set<std::string> Book::keywords() const{//stitches all searchable keywords together into one set
	set<string> keyword;
	set<string> authorget;
	authorget = parseStringToWords(author_);
	string tempkey;
	string valget = getName();
	keyword = parseStringToWords(valget);
	tempkey = {isbn_};
	keyword.insert(tempkey);
	cout << "yes" << endl;
	keyword = setUnion(keyword, authorget);
	return keyword;
}

std::string Book::displayString() const{//uses .append() to stitch together the correct format. DUE to th
	string returnstring(name_);//
	stringstream s1, s2, s3, s4;
	s1 << price_;
	s2 << isbn_;
	s3 << author_;
	s4 << qty_;
	returnstring.append("\n");
	returnstring.append("Author:");
	returnstring.append(s3.str());
	returnstring.append(" ISBN:");
	returnstring.append(s2.str());
	returnstring.append("\n");
	returnstring.append("$");
	returnstring.append(s1.str());
	returnstring.append(" ");
	returnstring.append(s4.str());
	returnstring.append(" left.");
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