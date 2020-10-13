#include "Product.h"



Product::Product(const string& Category, const string& Name, Type Type, double Price): type(Type),category(Category), name(Name)
{
	setPrice(Price);
}

 Product:: Type Product::getType() const
 {
	 return type;
 }

 string Product::TypeStr() const
 {
	 switch (type)
	 {
	    case Type::Clothes: return "Clothes";
	    case Type::Accessories: return "Accessories";
	    case Type::Shoes: return "Shoes";
	    default: return "Other";
	 }
 }

 const string & Product::getName() const
 {
	 return name;
 }

 const string & Product::getCategory() const
 {
	 return category;
 }

 double Product::getPrice() const
 {
	 return price;
 }


 void Product::setPrice(double newPrice)
 {
	 if (newPrice < 0) throw std::runtime_error("The price cannot be less than zero");
	 price = newPrice;
 }

 ostream& Product::print(ostream& output) const
 {
	 output << *this << endl;
	 return output;
 }

 Product::~Product()
 {
 }


 ostream& operator<<(ostream & o, const Product & p)
 {
	 o << "Category: " << p.getCategory() << endl;
	 o << "Name: " << p.getName() << endl;
	 o << "Type: " << p.TypeStr() << endl;
	 o << "Price: " << p.getPrice() << endl;
	 return o;
 }
