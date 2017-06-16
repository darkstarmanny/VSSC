#ifndef SERVICEREQUEST_H
#define SERVICEREQUEST_H
#include"tstring.h"
#include"part.h"
#include"oil.h"
#include"service.h"
#include<list>
using namespace std;

class service_request 
{
	TString cust_name;
	list<service*> serv_list;
	TString veh_number;


public:

	void add_item(service* serv);
	TString& get_cust_name();
	list<service*>& get_serv_list();
	TString& get_veh_number();
	void process_request();
	service_request();
	service_request(const TString& cust_name, const TString&veh_number);
	void set_cust_name(const TString& cust_name);
	void set_veh_number(const TString& veh_number);
	int menu();
};

#endif