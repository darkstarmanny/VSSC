#include"tstring.h"
#include"service_station.h"
#include"bill.h"
#include"vehicle.h"
#include"customer.h"
const char* db_file = "customer.dat";

double service_station::compute_cash()
{
	int cash = 0;
	list<bill>::iterator itr = this->bill_list.begin();
	while (itr != this->bill_list.end())
	{
		cash += (*itr).get_paid_amount();
		itr++;
	}
	return cash;
}
void service_station::display_customer_list()
{
	list<customer>::iterator itr = cust_list.begin();
	int i;
	for (i = 1; itr != cust_list.end(); i++)
	{
		cout << i << ". Customer Name: " << (*itr).get_name() << " | Mobile no: " << (*itr).get_mobile() << " | Address: " << (*itr).get_address() << endl;
		itr++;
	}
}
customer* service_station::find_customer(const TString& mobile)
{
	list<customer>::iterator cust_itr = this->cust_list.begin();
	while (cust_itr != this->cust_list.end())
	{
		if (cust_itr->get_mobile() == mobile)
		{
			return &(*cust_itr);
		}
		cust_itr++;
	}
	return NULL;
}
list<bill>& service_station::get_bill_list()
{
	return bill_list;
}
list<customer>& service_station::get_cust_list()
{
	return cust_list;
}
TString service_station::get_name()
{
	 return this->name;
}
void service_station::handle_service_request()
{
	customer *cust,c;
	vehicle *veh;
	TString cust_mobile;
	list<bill>bl;
	int option;
	system("cls");
	display_customer_list();
	cout << "\nEnter Mobile no: ";
	cin >> cust_mobile;
	if (!find_customer(cust_mobile))
	{
		cout << "\nCustomer is not Register \n";
		return;
		
	}
	else
	{
		cout << "\nCustomer Registered \n";
	}

		cust = find_customer(cust_mobile);
		cout << "\n1.Enter Vehicle for Servicing \n0. For New Vehicle\n";
		cust->display_vehicles();
		int ch;
		cout << "\nVehicle to be Serviced :";
		cin >> ch;
		if (ch == 0)
		{
			veh = cust->new_vehicle();
		}
		else
		{
			veh = &cust->get_veh_list()[ch - 1];
		}
			//vector<vehicle>ve = cust->get_veh_list();
			service_request *ser = new service_request(cust->get_name(), veh->get_no());
			ser->process_request();
			bill b(ser);
			b.print();
			c.pay_bill(b);
			bill_list.push_back(b);
		
	
}
void service_station::load_customer_details()
{
	ifstream fin;
	fin.open(db_file, ios::binary | ios::in);
	if (!fin)
	{
		cout << "Database file cannot be opened." << endl;
		return;
	}
	int cust_count;
	fin.read((char*)&cust_count, sizeof(cust_count));
	list<customer>::iterator cust_itr = this->cust_list.begin();
	for (int i = 0; i < cust_count; i++)
	{
		customer cust;
		cust.load_customer(fin);
		cust_list.push_back(cust);
	}
	fin.close();
}
void service_station::new_customer()
{
	customer c;
	c.input();
	cust_list.push_back(c);
}
service_station::service_station()
{
	this->name = "";
}
service_station::service_station(const TString& name)
{
	this->name = name;
}
void service_station::store_customer_details()
{
	ofstream fout;
	fout.open(db_file, ios::binary | ios::out);
	if (!fout)
	{
		cout << "Database file cannot be opened." << endl;
		return;
	}
	int cust_count = cust_list.size();
	fout.write((char*)&cust_count, sizeof(cust_count));
	list<customer>::iterator cust_itr = this->cust_list.begin();
	while (cust_itr != this->cust_list.end())
	{
		cust_itr->store_customer(fout);
		cust_itr++;
	}
	fout.close();
}