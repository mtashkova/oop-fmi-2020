#pragma once
#include "String.h"
#include "Product.h"
#include <string>
#include <stdexcept>
class Shoes : public Product
{
	string brand;
	double size;
public:
	Shoes(const string& Category, const string& Name, double Price, const string& Brand, double Size);
	void setSize(double Size);
	Shoes* clone() const override;
	ostream& print(ostream& output) const override;
	friend ostream& operator<<(ostream& output, const Shoes& shoes);
};

