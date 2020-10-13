#pragma once
#include <string>
#include "Product.h"
using namespace std;

class Clothes : public Product
{
	string brand;
	int size;
public:
	Clothes(const string& Category, const string& Name, double Price, const string& Brand,int Size);
	void setSize(int Size);
	Clothes* clone() const override;
	ostream& print(ostream& output) const override;
	friend ostream& operator<<(ostream& output, const Clothes& clothes);
};

