#ifndef CUSTOMER_H
#define CUSTOMER_H
#include"tstring.h"
#include"service.h"
#include"bill.h"
#include"vehicle.h"
#include <vector>
#include <fstream>
#include<list>
using namespace std;

class customer
{
	TString address;
	TString mobile;
	TString name;
	vector<vehicle> veh_list;
public:

	customer();
	customer(const TString& name, const TString& address, const TString& mobile);
	void display_vehicles();
	TString get_address();
	TString get_mobile();
	TString get_name();
	vector<vehicle>& get_veh_list();
	void input();
	void load_customer(ifstream& fin);
	vehicle* new_vehicle();
	void pay_bill(bill& bill);
	void set_address(const TString& address);
	void set_mobile(const TString& mobile);
	void set_name(const TString& name);
	void store_customer(ofstream& fout);

};

#endif