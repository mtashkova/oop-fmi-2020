#pragma once
#include <string>
#include "Product.h"
using namespace std;

class Accessories: public Product
{
	string color;
	string shape;
public:
	Accessories(const string& Category, const string& Name, double Price,const string& Color, const string& Shape);
	Accessories* clone() const override;
	ostream& print(ostream& output) const override;
	friend ostream& operator<<(ostream& output, const Accessories& accessories);
};

