#include "User.h"




Cart::Cart(const Cart & cpy): id(cpy.id)
{
	for (int i = 0; i < cpy.products.size();i++)
	{
		products.push_back(cpy.products[i]->clone());
	}
}

Cart & Cart::operator=(const Cart & cpy)
{
	if (this != &cpy)
	{
		id = cpy.id;
		for (int i = 0; i < products.size();i++)
		{
			delete products[i];
		}
		products.clear();
		for (int i = 0; i < cpy.products.size();i++)
		{
			products.push_back(cpy.products[i]->clone());
		}
	}
	return *this;

}

Cart::~Cart()
{
	for (int i = 0; i < products.size();i++)
	{
		delete products[i];
	}
}

Cart::Cart(): id(0)
{
}

Cart::Cart(int i):id(i)
{

}

void Cart::addToCart(const Product& newProduct)
{
	products.push_back(newProduct.clone());
}

void Cart::removeFromCart(int index)
{
	if (index < 0 || index >= countProducts()) throw std::runtime_error("The index is invalid!");
	auto iter=products.begin() + index;
	delete *iter;
	products.erase(iter);
	
}

int Cart::countProducts() const
{
	return products.size();
}

bool Cart::emptyCart() const
{
	return products.empty();
}

double Cart::totalSum() const
{
	double sum=0;
	for (int i = 0; i < products.size(); i++)
	{
		sum += products[i]->getPrice();
	}
	return sum;
}

int Cart::getID() const
{
	return id;
}

void Cart::print() const
{
	cout << "Cart ID: " << getID() << endl;
	for (int i = 0; i < products.size(); i++)
	{
		products[i]->print(cout);
	}
}



