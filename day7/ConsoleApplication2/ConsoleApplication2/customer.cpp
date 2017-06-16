#include"tstring.h"
#include"service.h"
#include"bill.h"
#include"vehicle.h"
#include"customer.h"


customer::customer()
{
	this->address = "";
	this->mobile = "";
	this->name = "";
}
customer::customer(const TString& name, const TString& address, const TString& mobile)
{
	this->address=address;
	this->mobile=mobile;
	this->name=name;
}
void customer::display_vehicles()
{
	vector<vehicle>::iterator itr = veh_list.begin();
	int i;
	for (i = 1; itr != veh_list.end(); i++)
	{
		cout << i << ". Company Name: " << (*itr).get_company() << " | Model no: " << (*itr).get_model() << " | Reg no: " << (*itr).get_no() << endl;
		itr++;
	}
}
TString customer::get_address()
{
	return this->address;
}
TString customer::get_mobile()
{
	return this->mobile;
}
TString customer::get_name()
{
	return this->name;
}
vector<vehicle>& customer::get_veh_list()
{
	return this->veh_list;
}
void customer::input()
{
	cout << "\n---------------Vehicle Station Console--------------------\n\n***Customer Details***\n";
	cout << "\nEnter Customer name : ";
	cin >> this->name;
	cout << "\nEnter Mobile no : ";
	cin >> this->mobile;
	cout << "\nEnter Address : ";
	cin >> this->address;
}
void customer::load_customer(ifstream& fin)
{
	
	fin.read((char*)&name, sizeof(name));
	fin.read((char*)&mobile, sizeof(mobile));
	fin.read((char*)&address, sizeof(address));

	int veh_count;
	fin.read((char*)&veh_count, sizeof(veh_count));
	for (int i = 0; i < veh_count; i++)
	{
		vehicle veh;
		fin.read((char*)&veh, sizeof(vehicle));
		veh_list.push_back(veh);
	}
}
	vehicle* customer::new_vehicle()
{
		vehicle veh;
		int index = veh_list.size();
		veh.input();
		veh_list.push_back(veh);
		return &veh_list[index];
}
void customer::pay_bill(bill& bill)
{
	double amt, bal;
	cout << "\nEnter amount paid : ";
	cin >> amt;
	bill.set_paid_amount(amt);
	bal = bill.compute_total_bill()-amt;
	cout << "\nBalance Left : " << bal;
}
void customer::set_address(const TString& address)
{
	this->address = address;
}
void customer::set_mobile(const TString& mobile)
{
	this->mobile = mobile;
}
void customer::set_name(const TString& name)
{
	this->name = name;
}
void customer::store_customer(ofstream& fout)
{
	
	fout.write((char*)&this->name, sizeof(name));
	fout.write((char*)&this->mobile, sizeof(mobile));
	fout.write((char*)&this->address, sizeof(address));
	
	int veh_count = veh_list.size();
	fout.write((char*)&veh_count, sizeof(veh_count));
	for (int i = 0; i < veh_count; i++)
	fout.write((char*)&veh_list[i], sizeof(vehicle));
}