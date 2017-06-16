#include<iostream>
#include"tstring.h"
#include"part.h"
#include"oil.h"
#include"service.h"
#include"vehicle.h"
#include "maintenance.h"
#include"service_request.h"
#include"service_station.h"
#include"bill.h";
#include "customer.h"
using namespace std;
service_station s;

enum SEnum
{
	EXIT = 0, NEW_CUSTOMER, SERVICE_REQUEST, TOTAL_CASH
};
int menu_list(void)
{
	int choice;
	cout << "\n0.Exit" << endl;
	cout << "1.New Customer" << endl;
	cout << "2.Service_Request" << endl;
	cout << "3.Total_Cash" << endl;
	cout << "Enter choice	:	";
	cin >> choice;
	return choice;
}
int main(void)
{
	int choice,a;
	s.load_customer_details();
	
	while ((choice = ::menu_list()) != 0)
	{
		
		switch (choice)
		{
		case NEW_CUSTOMER:s.new_customer();
			
			break;
		case SERVICE_REQUEST:s.handle_service_request();
			
			break;
		case TOTAL_CASH:a=s.compute_cash();
			cout << "\nTotal Cash is: "<<a;
			
			break;
		}
		s.store_customer_details();
	}
	return 0;
}


