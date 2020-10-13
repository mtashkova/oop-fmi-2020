#include "Shoes.h"






Shoes::Shoes(const string & Category, const string & Name, double Price, const string & Brand, double Size): 
Product(Category, Name, Product::Type::Shoes, Price), brand(Brand)
{
	setSize(Size);
}

void Shoes::setSize(double Size)
{
	if (Size<=0) throw std::runtime_error("The size cannot be less than zero");
	size = Size;
}

Shoes * Shoes::clone() const
{
	return new Shoes(*this);
}

ostream & Shoes::print(ostream & output) const
{

	output << *this << endl;
	return output;
}



ostream & operator<<(ostream & output, const Shoes & shoes)
{
	output << (const Product&) shoes;
	output << "Brand: " << shoes.brand << endl;
	output << "Size: " << shoes.size << endl;
	return output;
}
