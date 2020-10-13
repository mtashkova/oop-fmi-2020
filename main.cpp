#include <iostream>
#include <vector>
#include <string>
#include "Shop.h"
#include "Product.h"
#include "Clothes.h"
#include "Cart.h"
#include "Accessories.h"
#include "Shoes.h"
#include "User.h"
#include "Guest.h"
using namespace std;

void AddProducts(Shop& shop)
{
	Clothes dress("Fashion", "Pink dress", 40.5, "Zara", 36);
	Accessories scarf("Fashion", "Silk scarf", 10, "blue", "round");
	Accessories scarf2 = scarf;
	Shoes boots("Fashion&Style", "Leather boots", 36, "Zara", 36);
	shop.addToShop(dress);
	shop.addToShop(dress);
	shop.addToShop(boots);
	shop.addToShop(scarf);
}

void MenuShop(User& user, Shop& shop)
{
	int n;
	while(cin)
	{
		cout << "1 View All Products " << endl;
		cout << "2 Filter By Name " << endl;
		cout << "3 Filter By Price " << endl;
		cout << "4 Filter By Type " << endl;
		cout << "5 Add To Cart " << endl;
		cout << "6 Remove From Cart " << endl;
		cout << "7 View Cart " << endl;
		cout << "8 View Total Sum " << endl;
		cout << "9 Log Out " << endl;
		cout << "Enter a number:" << endl;
		cin >> n;
		switch (n)
		{
		case 1: shop.printShop(); break;
		case 2:
		{
			string name;
			cout << "Enter name of the product:";
			getline(cin, name);
			cin.ignore();
			shop.filterByName(name);
			break;
		}
		case 3:
		{
			double lowestPrice, highestPrice;
			cout << "Enter lowest limit: ";
			cin >> lowestPrice;
			cout << endl;
			cout << "Enter highest limit: ";
			cin >> highestPrice;
			cout << endl;
			shop.filterByPrice(lowestPrice, highestPrice);
			break;
		}
		case 4:
		{
			cout << "1 Shoes " << endl;
			cout << "2 Clothes " << endl;
			cout << "3 Accessories " << endl;
			cout << "Enter product type: ";
			int x;
			cin >> x;
			cout << endl;
			switch (x)
			{
			case 1: shop.filterByType(Product::Type::Shoes); break;
			case 2: shop.filterByType(Product::Type::Clothes); break;
			case 3: shop.filterByType(Product::Type::Accessories); break;
			default: cout << "Type not found" << endl;
			}
			break;
		}
		case 5:
		{
			cout << "Enter which product to add to cart: ";
			int index;
			cin >> index;
			user.addToCart(shop.getProduct(index));
			break;
		}
		case 6:
		{
			cout << "Enter which product to delete from cart: ";
			int index;
			cin >> index;
			user.removeFromCart(index);
			break;
		}
		case 7:
		{
			if (user.getCart().emptyCart() == true) cout << "The cart is empty!" << endl;
			user.viewCart();
			break;
		}
		case 8:
		{
			cout << "Total sum: " << user.getCart().totalSum() << endl;
			break;
		}
		case 9:
		{
			user.logOut();
			return;
		}
		default: return;
		}
	}
}

void SignUp(vector<User>& user)
{
	string name, address, number, username, password;
	cout << "Enter username: ";
	cin >> username;
	cout << "Enter password: ";
	cin >> password;
	cout << "Enter name: ";
	cin >> name;
	cout << "Enter address: ";
	cin >> address;
	cout << "Enter number: ";
	cin >> number;
	Guest guest(name, password, number);
	user.emplace_back(guest.singUp(username, password));
	cout << "Successful registration!" << endl;
	
}

void LogIn(vector<User>& user, Shop& shop)
{
	string username, password;
	cout << "Enter username: ";
	cin >> username;
	cout << "Enter password: ";
	cin >> password;
	for (auto& x : user)
	{
		x.logIn(username, password);
		if (x.isLoggedIn() == false) cout << "Wrong username or password!" << endl;
		if (x.isLoggedIn() == true)
		{
			cout << "User is logged successfully!"<< endl;
			MenuShop(x,shop);
			x.logOut();
		}
	}
}

void Menu(vector<User>& user, Shop& shop)
{
	cout << "1 Sign Up:" << endl;
	cout << "2 Log in:" << endl;
	cout << "Enter a number:" << endl;
	int n;
	cin >> n;
	switch (n)
	{
	case 1: 
	{
		SignUp(user);
		LogIn(user, shop);
		break;
	}
	case 2: LogIn(user,shop); break;
	default: return;
	}
}

int main()
{
	Shop eBay;
	vector<User> users;
	AddProducts(eBay);
	Menu(users, eBay);
	system("pause");
	return 0;
}