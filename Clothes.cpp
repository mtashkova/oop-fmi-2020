#include "Clothes.h"






Clothes::Clothes(const string & Category, const string & Name, double Price, const string & Brand, int Size):
Product(Category, Name, Product::Type::Clothes, Price), brand(Brand)
{
	setSize(Size);
}

void Clothes::setSize(int Size)
{
	if (Size <= 0) throw std::runtime_error("The size cannot be less than/or 0");
	size = Size;
}

Clothes * Clothes::clone() const
{
	return new Clothes(*this);
}

ostream& Clothes::print(ostream& output) const
{

	output << *this << endl;
	return output;
}

ostream & operator<<(ostream & output, const Clothes & clothes)
{
	output << (const Product&) clothes;
	output << "Brand: " << clothes.brand << endl;
	output << "Size: " << clothes.size << endl;
	return output;
}
