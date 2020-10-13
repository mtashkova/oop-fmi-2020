#include "Shop.h"




Shop::Shop(const Shop& cpy)
{
	for (int i = 0; i < cpy.product.size();i++)
	{
		product.push_back(cpy.product[i]->clone());
	}
}

Shop & Shop::operator=(const Shop & cpy)
{
	if (this != &cpy)
	{
		for (int i = 0; i < product.size();i++)
		{
			delete product[i];
		}
		product.clear();
		for (int i = 0; i < cpy.product.size();i++)
		{
			product.push_back(cpy.product[i]->clone());
		}
	}
	return *this;
	
}

Shop::~Shop()
{
	for (int i = 0; i < product.size();i++)
	{
		delete product[i];
	}
}

void Shop::addToShop(const Product& newProduct)
{
	product.push_back(newProduct.clone());
}


void Shop::removeFromShop(int index)
{
	auto iter = product.begin() + index;
	delete *iter;
	product.erase(iter);
}

void Shop::printShop() const
{
	for (int i = 0; i < product.size(); i++)
	{
		product[i]->print(cout);
	}
}

void Shop::filterByPrice(double lowerCap, double upperCap) const
{
	
	for (int i = 0; i < product.size();i++)
	{
		if (product[i]->getPrice() >= lowerCap && product[i]->getPrice() <= upperCap)
		{
			product[i]->print(cout);
		}
	}
}

void Shop::filterByName(const string& givenName) const
{
	for (int i = 0; i < product.size();i++)
	{
		if (product[i]->getName() == givenName)
		{
			product[i]->print(cout);
		}
	}
}

void Shop::filterByType(Product::Type givenType) const
{
	for (int i = 0; i < product.size();i++)
	{
		if (product[i]->getType() == givenType)
		{
			product[i]->print(cout);
		}
	}
}

const Product& Shop::getProduct(int index) const
{
	if(index < 0 || index >= product.size()) throw std::runtime_error("The index is not valid!");
	return *product[index];
}

