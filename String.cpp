#include "String.h"


void String::setStr(const char * s)
{
	if (s == nullptr) throw runtime_error("Null");
	int len = strlen(s) + 1;
	char* temp = new char[len];
	strcpy_s(temp, len, s);
	delete[] str;
	str = temp;
}

String::String()// :String("")
{
	setStr("");
}

String::String(const char * str)
{
	setStr(str);
}

String::String(const String & cpy) :String(cpy.str)
{
	
}

String & String::operator=(const String & cpy)
{
	if (this != &cpy)
	{
		setStr(cpy.str);
	}
	return *this;
}


String::~String()
{
	delete[] str;
}

const char * String::getStr() const
{
	return str;
}

char String::operator[](int ind) const
{
	return str[ind];
}

char & String::operator[](int index)
{
	return str[index];
}

bool String::operator==(const String & s) const
{
	return !strcmp(str,s.str) ;
}

ostream & operator<<(ostream & c, const String & A)
{
	return c << A.str;

}

istream & operator>>(istream & c, String & A)
{
	char str[1024];
	c.getline(str, 1024);
	A.setStr(str);
	return c;
}
