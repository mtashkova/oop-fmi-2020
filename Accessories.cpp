#include "Accessories.h"



Accessories::Accessories(const string & Category, const string & Name, double Price, const string & Color, const string & Shape) :
Product(Category, Name,Product::Type::Accessories,Price), color(Color), shape(Shape){}

Accessories * Accessories::clone() const
{
	return new Accessories(*this);
}

ostream& Accessories::print(ostream& output) const
{
	output << *this << endl;
	return output;
}

ostream & operator<<(ostream & output, const Accessories & accessories)
{
	output << (const Product&) accessories;
	output << "Color: " << accessories.color << endl;
	output << "Shape: " << accessories.shape << endl;
	return output;
}
