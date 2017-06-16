#include <iostream>
#include <cstring>
using namespace std;
#ifndef STRING_H
#define STRING_H
using namespace std;

class TString
{
private:
	char buff[64];
public:
	TString();
	TString(const char *buf);

	char* toString();

	bool operator==(const TString& other) const;

	bool operator!=(const TString& other) const;

	friend istream& operator>>(istream& in, TString& s);

	friend ostream& operator<<(ostream& out, const TString& s);

};

#endif