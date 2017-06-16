#include<iostream>
#include"tstring.h"
#include"part.h"
#include"oil.h"
using namespace std;

void oil::display()
{
	cout << "\nOil changed is :" << this->get_desc();
	cout << "\nCost for oil change :" << cost;

}

double oil::get_cost()
{
	return this->cost;
}

void oil::input()
{
	TString str;
	cout << "\nEnter which Oil :";
	cin >> str;
	this->set_desc(str);
	cout << "\nEnter cost for oil change :";
	cin >> cost;
}
oil::oil()
{
	this->cost = 0;
}

oil::oil(const TString& desc, double cost) :service(desc)
{
	this->cost = cost;

}

double oil::price()
{
	return get_cost();
}

void oil::set_cost(double cost)
{
	this->cost = cost;
}