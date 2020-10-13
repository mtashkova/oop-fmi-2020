#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class Product
{
public:
	enum class Type
	{
		Clothes, Accessories, Shoes
	};
private:
	string category;
	string name;
	Type type;
	double price;

public:
	Product() = default;
	Product(const string& Category,const string& Name,Type Type, double Price);
	Product::Type getType() const;
	string TypeStr() const;
	const string& getName() const;
	const string& getCategory() const;
	double getPrice() const;
	void setPrice(double newPrice);
	virtual ostream&  print(ostream & output) const;
	virtual ~Product();
	virtual Product* clone() const = 0;
	friend ostream& operator<<(ostream& o, const Product& p);
};

