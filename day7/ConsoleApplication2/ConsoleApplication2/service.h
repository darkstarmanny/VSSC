#ifndef SERVICE_H
#define SERVICE_H
#include"tstring.h"
using namespace std;

class service
{
	TString desc;

public:

	virtual void display();
	TString get_desc();
	virtual void input();
	virtual double price()=0;
	service();
	service(const TString& desc);
	void set_desc(const TString& desc);
};

#endif