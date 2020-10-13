#include "User.h"



User::User(const string & Username, const string & Password): username(Username), password(Password)
{
}



void User::logIn(const string & Username, const string & Password)
{
	if (username == Username && password == Password)
	{
		isLogged = true;
		return;
	}
	isLogged = false;

}

void User::logOut()
{
	isLogged = false;
}

bool User::isLoggedIn() const
{
	return isLogged;
}

bool User::changePassword(const string & oldPass, const string & newPass)
{
	if (oldPass == password) 
	{
		password = newPass;
		return true;
	}
	return false;
}

void User::addToCart(const Product & newProduct) 
{
	if (isLoggedIn() == false)  throw std::runtime_error("The user is not logged");
	cart.addToCart(newProduct);
}

void User::removeFromCart(int index)
{
	if(index < 0 || index >= cart.countProducts()) throw std::runtime_error("The index is invalid");
	cart.removeFromCart(index);
}

void User::viewCart() const
{
	cart.print();
}


Cart& User::getCart() 
{
	return cart;
}

