#pragma once
#include "Product.h"
#include "String.h"
#include <vector>
#include "User.h"
#include "Cart.h"
#include <stdexcept>
using namespace std;


class Shop
{
	vector<Product*> product;
public:
	Shop() = default;
	Shop(const Shop& cpy);
	Shop& operator=(const Shop& cpy);
	~Shop();
	void addToShop(const Product& newProduct);
	void removeFromShop(int index);
	void printShop() const;
	void filterByPrice(double minPrice, double maxPrice) const;
	void filterByName(const string& givenName) const;
	void filterByType(Product::Type givenType) const;
	const Product& getProduct(int index) const;


};

