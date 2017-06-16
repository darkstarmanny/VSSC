#include<iostream>
#include"tstring.h"
#include"part.h"
#include"oil.h"
#include"maintenance.h"
#include"service.h"

using namespace std;

void service::display()
{
	cout << this->desc;
}

TString service::get_desc()
{
	return this->desc;
}

void service::input()
{
	
	cout << "\nDescription of the Service :";
	cin >> this->desc;
}

service::service()
{
	this->desc = "";
}

service::service(const TString& desc)
{
	this->desc = desc;
}

void service::set_desc(const TString& desc)
{
	this->desc = desc;
}

