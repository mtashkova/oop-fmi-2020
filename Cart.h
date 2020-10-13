#pragma once
#include <vector>
#include "Product.h"
using namespace std;

class Cart
{
	vector<Product*> products;
	int id;
public:
	Cart();
	Cart(int i);
	Cart(const Cart& cpy);
	Cart& operator=(const Cart& cpy);
	~Cart();
	void addToCart(const Product& newProduct);
	void removeFromCart(int index);
	int countProducts() const;
	bool emptyCart() const;
	double totalSum() const;
	int getID() const;
	void print() const;

};

