#ifndef MAINTENANCE_H
#define MAINTENANCE_H
#include"tstring.h"
#include"part.h"
#include"oil.h"
#include"service.h"
#include<list>
using namespace std;

class maintenance:public service
{
	double labor_charges;
	list<part> part_list;
	

public:
	
	void add_part(const part& new_part);
	void display();
	double get_labor_charges();
	list<part>& get_part_list();
	void input();
	maintenance();
	maintenance(const TString& desc, double labor_charges);
	double price();
	void set_labor_charges(double labor);
	

};

#endif