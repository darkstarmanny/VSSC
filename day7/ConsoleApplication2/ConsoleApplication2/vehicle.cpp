#include<iostream>
#include"tstring.h"
#include"part.h"
#include"vehicle.h"
using namespace std;

TString vehicle::get_company()
{
	return this->company;
}
TString vehicle::get_model()
{
	return this->model;
}
TString vehicle::get_no()
{
	return this->number;
}
void vehicle::input()
{
	cout << "\nEnter name of the Vehicle company : ";
	cin >> this->company;
	cout << "\nEnter the Model : ";
	cin >> this->model;
	cout << "\nEnter the Reg no : ";
	cin >> this->number;
}
void vehicle::set_company(const TString&company)
{
	this->company = company;
}
void vehicle::set_model(const TString&model)
{
	this->model = model;
}
void vehicle::set_number(const TString&number)
{
	this->number = number;
}
vehicle::vehicle()
{
	this->company = company;
	this->model = model;
	this->number = number;
}
vehicle::vehicle(const TString& company, const TString& model, const TString& number)
{
	this->company = company;
	this->model = model;
	this->number = number;
}

