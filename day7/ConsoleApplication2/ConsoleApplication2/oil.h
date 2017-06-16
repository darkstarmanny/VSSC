#ifndef OIL_H
#define OIL_H
#include"tstring.h"
#include"part.h"
#include"service.h"
using namespace std;

class oil :public service
{
	double cost;

public:
	void display();
	double get_cost();
	void input();
	oil();
	oil(const TString& desc, double cost);
	double price();
	void set_cost(double cost);

};

#endif