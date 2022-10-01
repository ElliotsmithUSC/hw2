#ifndef UTIL_H
#define UTIL_H
#include <string>
#include <iostream>
#include <set>


/** Complete the setIntersection and setUnion functions below
 *  in this header file (since they are templates).
 *  Both functions should run in time O(n*log(n)) and not O(n^2)
 */
template <typename T>
std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2)
{
std::set<T> intersectionset;
int size1 = s1.size();
int size2 = s2.size();
typename std::set<T>::iterator it;
if(size1>=size2){//checks if an element from 1 is in 2 if it is than it adds to the intersection set runs if s1 is larger than s2
	for(it = s1.begin(); it!=s1.end(); ++it){
		if(s2.find(*it)!=s2.end()){
			intersectionset.insert(*it);
		}
	}
}
else{
	for( it = s2.begin(); it!=s2.end(); ++it){//same as above function but works for if s2 is larger than s1.
		if(s1.find(*it)!=s1.end()){
			intersectionset.insert(*it);
		}
	}
}
return intersectionset;

}



template <typename T>
std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2)
{ 
 std::set<T> unionset = s1;//sets unionset to first input
 for(typename std::set<T>::iterator it = s2.begin(); it!=s2.end(); ++it){
		 unionset.insert(*it);//adds anything from second input to unionset that's not already in there
 } 

return unionset;



}



/***********************************************/
/* Prototypes of functions defined in util.cpp */
/***********************************************/

std::string convToLower(std::string src);

std::set<std::string> parseStringToWords(std::string line);

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// Removes any leading whitespace
std::string &ltrim(std::string &s) ;

// Removes any trailing whitespace
std::string &rtrim(std::string &s) ;

// Removes leading and trailing whitespace
std::string &trim(std::string &s) ;
#endif
