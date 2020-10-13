#pragma once
#include <string>
#include "User.h"
using namespace std;

class Guest
{
	string name;
	string address;
	string number;
public:
	Guest(const string& Name, const string& Address, const string& Number);
	User singUp(const string& Username, const string& Password) const;

};

