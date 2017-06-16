#include<iostream>
using namespace std;
#include"tstring.h"

TString::TString()
{
	strcpy(this->buff, "");
}

TString::TString(const char *buff)
{
	strcpy(this->buff, buff);
}
char* TString::toString()
{
	return buff;
}
bool TString::operator==(const TString& other) const
{
	if (strcmp(this->buff, other.buff) == 0)
		return 1;
	else
		return 0;
}
bool TString::operator!=(const TString& other) const
{
	if (strcmp(this->buff, other.buff) != 0)
		return 1;
	else
		return 0;
}
istream& operator>>(istream& in, TString& s)
{
	in >> s.buff;
	return in;
}

ostream& operator<<(ostream& out, const TString& s)
{
	out << s.buff;
	return out;
}



