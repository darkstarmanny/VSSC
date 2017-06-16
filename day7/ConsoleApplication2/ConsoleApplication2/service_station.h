#ifndef SERVICESTATION_H
#define SERVICESTATION_H
#include"tstring.h"
#include"bill.h"
#include"customer.h"
#include<list>
using namespace std;

class service_station
{
	list<bill> bill_list;
	list<customer> cust_list;
	TString name;

public:
	double compute_cash();
	void display_customer_list();
	customer* find_customer(const TString& mobile);
	list<bill>& get_bill_list();
	list<customer>& get_cust_list();
	TString get_name();
	void handle_service_request();
	void load_customer_details();
	void new_customer();
	service_station();
	service_station(const TString& name);
	void store_customer_details();
	
};

#endif