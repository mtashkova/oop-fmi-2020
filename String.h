#pragma once
#include<stdexcept>
#include<cstring>
#include<iostream>
#include <cstring>
using namespace std;

class String
{
	char* str = nullptr;
	void setStr(const char* str);
public:
	String();
	String(const char* str);
	String(const String& cpy);
	String& operator=(const String& cpy);
	~String();
	const char* getStr() const;
	char operator[](int ind) const;
	char& operator[](int index);
	bool operator==(const String& s) const;

	friend ostream& operator<<(ostream& c, const String & A);
	friend istream& operator>>(istream& c, String& A);

};

