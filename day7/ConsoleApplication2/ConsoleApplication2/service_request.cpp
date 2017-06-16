#include"oil.h"
#include"service.h"
#include"vehicle.h"
#include "maintenance.h"
#include"service_request.h"
using namespace std;

void service_request::add_item(service* serv)
{
	this->serv_list.push_back(serv);
}
TString& service_request::get_cust_name()
{
	return this->cust_name;
}
list<service*>& service_request::get_serv_list()
{
	return this->serv_list;
}
TString& service_request::get_veh_number()
{
	return this->veh_number;
}

int service_request::menu()
{
	int ch;
	cout << "\n\n1. Oiling  \n2. Maintenance \n0. Exit" << endl;
	cout << "Enter Your Choice::" << endl;
	cin >> ch;
	return ch;
}

void service_request::process_request()
{
	int ch;

	//list<service*> service_list;

	service *ptr = NULL;
	while ((ch = menu()) != 0)
	{
		switch (ch)
		{
		case 1:
			ptr = new oil();
			break;

		case 2:
			ptr = new maintenance();
			break;
		}
		if (ptr != NULL)
		{
			ptr->input();
			ptr->price();
			ptr->display();
			this->serv_list.push_back(ptr);
		}

	}
	list<service*>::iterator itr = this->serv_list.begin();
	double cost = 0;
	while (itr != this->serv_list.end())
	{
		cout << "\t";
		cost += (*itr)->price();
		(*itr)->display();
		cout << "\n";
		itr++;
	}
	cout << "\nTotal Cost is :" << cost << "\n";
}

service_request::service_request()
{
	this->cust_name = "";
	this->veh_number = "";
}
service_request::service_request(const TString& cust_name, const TString& veh_number)
{
	cout << cust_name;
	cout<<" "<<veh_number;
	this->cust_name = cust_name;
	this->veh_number = veh_number;
}

void service_request::set_cust_name(const TString& cust_name)
{
	this->cust_name = cust_name;
}
void service_request::set_veh_number(const TString& veh_number)
{
	this->veh_number = veh_number;
}