#include"tstring.h"
#include"part.h"
#include"oil.h"
#include"service.h"
#include"bill.h"

bill::bill(service_request* req)
{
	this->req = req;
}
double bill::compute_amount()
{
	typedef list<service*> service_list;
	service_list& serv_list = this->req->get_serv_list();
	list<service*>::iterator itr = serv_list.begin();
	double cost = 0;
	while (itr != serv_list.end())
	{
		cost += (*itr)->price();
		itr++;
	}
	return cost;
}
double bill::compute_tax()
{
	double tax;
	return tax = 0.126*compute_amount();
}
double bill::compute_total_bill()
{
	double total_bill;
	return total_bill = compute_amount() + compute_tax();
}
double bill::get_paid_amount()
{
	return paid_amount;
}
void bill::print()
{
	cout << "\n---------BILL----------------\n\n***Manish Service Station***";
	getTodaysDate();
	cout << "\n\nCustomer Name : " << this->req->get_cust_name() << "\t\t\t\tVehicle No : " << this->req->get_veh_number();
	cout << "\n\nService amount : " << this->compute_amount();
	cout << "\nTAX amount : " << this->compute_tax();
	cout << "\nTotal amount Bill : " << this->compute_total_bill()<<"\n";
}
void bill::set_paid_amount(double amount)
{
	this->paid_amount = amount;
}
void bill::getTodaysDate()
{
	time_t t = time(NULL);
	struct tm now = *localtime(&t);
	int Day = now.tm_mday;
	int Month = now.tm_mon + 1;
	int Year = now.tm_year + 1900;
	cout <<"\n\nDate :"<< Day <<"/"<< Month<<"/" << Year;
}