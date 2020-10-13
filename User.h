#pragma once
#include "Cart.h"
#include "Product.h"
#include <string>
using namespace std;

class User
{
	string username;
	string password;
	bool isLogged = false;
	Cart cart;
public:
	User(const string& Username, const string& Password);
	void logIn(const string& Username, const string& Password);
	void logOut();
	bool isLoggedIn() const;
	bool changePassword(const string& oldPass, const string& newPass);
	void addToCart(const Product& newProduct);
	void removeFromCart(int index);
	void viewCart() const;
	Cart& getCart();

};

