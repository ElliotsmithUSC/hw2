#include <sstream>
#include <iomanip>
#include <sstream>
#include "movie.h"
#include "util.h"

using namespace std;

Movie::Movie(const std::string name, double price, int qty, const std::string genre, const std::string rating):
Product("movie", name, price, qty){
genre_=genre;
rating_=rating;
}


Movie::~Movie(){

}

std::set<std::string> Movie::keywords() const{//stitches all searchable keywords into one set
	set<string> keyword;
	string tempkey;
	string valget = getName();
	keyword = parseStringToWords(valget);
	tempkey = {genre_};
	keyword.insert(tempkey);
	return keyword;
}

std::string Movie::displayString() const{//displays product in correct fashion
	string returnstring(name_);
	stringstream s1, s2, s3, s4;
	s1 << price_;
	s2 << genre_;
	s3 << rating_;
	s4 << qty_;
	returnstring.append("\n");
	returnstring.append("Genre: ");
	returnstring.append(s2.str());
	returnstring.append(" Rating: ");
	returnstring.append(s3.str());
	returnstring.append("\n");
	returnstring.append(s1.str());
	returnstring.append(" ");
	returnstring.append(s4.str());
	returnstring.append(" left.");
	return returnstring;
}

void Movie::dump(std::ostream& os) const{
	os << category_ << endl;
	os << name_ << endl;
	os << price_ << endl;
	os << qty_ << endl;
	os << genre_ << endl;
	os << rating_ << endl;
}