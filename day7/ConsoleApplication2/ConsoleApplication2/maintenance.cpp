#include"tstring.h"
#include"part.h"
#include"service.h"
#include"oil.h"
#include"maintenance.h"
using namespace std;

void maintenance::add_part(const part& new_part)
{
	this->part_list.push_back(new_part);
}
void maintenance::display()
{
	
	list<part>::iterator itr = this->part_list.begin();
	while (itr != this->part_list.end())
	{
		cout << "\nPart name\t" << itr->get_desc() << " Price : Rs. " << itr->get_rate() << endl;
		itr++;
	}
	cout << "\nLabor Charges are " << get_labor_charges();
}


double maintenance::get_labor_charges()
{
	return this->labor_charges;
}
list<part>& maintenance::get_part_list()
{
	return this->part_list;
}
void maintenance::input()
{
	cout << "\nWhat type of Maintenance do you want? ";
	service::input();
	TString ans;
	while (true)
	{
		cout << "Do You Want to Add any part? Enter (Y/N) : ";
		cin >> ans;
		if (!(ans == (TString)"Y" || ans == (TString)"y"))
			break;
		part new_part;
		new_part.input();
		this->add_part(new_part);
	}
	cout << "Enter labor Charge ";
	cin >> this->labor_charges;
}
maintenance::maintenance()
{
	this->labor_charges = 0;
}
maintenance::maintenance(const TString& desc, double labor_charges) :service (desc)
{
	this->labor_charges=labor_charges;
	
}
double maintenance::price()
{

	int rate = 0;
	list<part>::iterator itr = this->part_list.begin();
	while (itr != this->part_list.end())
	{
		rate += (*itr).get_rate();
		itr++;
	}
	return rate + labor_charges;
}
void maintenance::set_labor_charges(double labor)
{
	this->labor_charges = labor_charges;
}