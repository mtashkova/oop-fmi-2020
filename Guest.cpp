#include "Guest.h"



Guest::Guest(const string & Name, const string & Address, const string & Number) : name(Name),address(Address), number(Number)
{

}

User Guest::singUp(const string & Username, const string & Password) const
{
	User user(Username, Password);
	return user;
}

