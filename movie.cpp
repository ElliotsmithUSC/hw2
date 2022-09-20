#include <sstream>
#include <iomanip>
#include <sstream>
#include "movie.h"
#include "util.h"

using namespace std;

Movie::Movie(const std::string name, double price, int qty, const std::string genre, const std::string rating){
Product("movie", name, price, qty),
genre_(genre),
rating_(rating),
}


Movie::~Movie(){

}

std::set<std::string> Movie::keywords() const{
	set<string> keyword;
	set<string> tempkey;
	string valget = getName();
	keyword = parseStringToWords(valget);
	tempkey = {genre_};
	keyword = setUnion<string>(keyword, tempkey);
	return keyword;
}

std::string Movie::displayString() const{
/*std::string returnval = std::string("Title: ") + name_ + (" Written by: ") + author_ + (" Price: ") + price_;
return returnval;*/
std::stringstream s;
s << name_ << " Genre: " << genre_ << " $" << price_ << " " << qty_ << " copies remain";
string returnstring;
s >> returnstring;
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