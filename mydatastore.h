#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include <string>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include "product.h"
#include "user.h"
#include "datastore.h"

class MyDataStore : public DataStore {
	public:
	virtual ~MyDataStore();
  virtual std::vector<Product*> search(std::vector<std::string>& terms, int type);
  virtual void addProduct(Product* p);
	virtual void addUser(User* u);
	virtual void AddToCart(User* u, std::vector<Product*> hits, int hitnum);
	virtual void viewcart(User* u);
	virtual void buycart(User* u);
	virtual void dump(std::ostream& ofile);

	protected:
	std::map<std::string, User*> usermap;
	std::set<Product*> productset;
	std::map<std::string, std::vector<Product*>> productmap;
	std::map<std::string, std::queue<Product*>> cartmap;
	std::map<std::string, std::set<Product*>> keywordprod;
};
#endif 