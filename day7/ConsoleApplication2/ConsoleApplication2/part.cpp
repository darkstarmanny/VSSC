#include<iostream>
#include"tstring.h"
#include"part.h"
using namespace std;


part::part()
{
	this->des = des;
	this->rate = rate;
}
part::part(const TString &desc, double rate)
{
	this->des = des;
	this->rate = rate;
}

void part::input()
{
	cout << "Enter name of the part \n";
	cin >> this->des;
	cout << "\nEnter the price\n";
	cin >> this->rate;
}

TString part::get_desc()
{
	return this->des = des;
}

double part::get_rate()
{
	return this->rate = rate;
}

void part::set_desc(const TString &desc)
{
	this->des = des;
}
void part::set_rate(double rate)
{
	this->rate = rate;
}

