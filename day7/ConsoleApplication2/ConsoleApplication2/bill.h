#ifndef BILL_H
#define BILL_H
#include"tstring.h"
#include"service_request.h"
#include <time.h>

using namespace std;

class bill
{
	double amount;
	double paid_amount;
	service_request* req;
public:
	bill(service_request* req);
	double compute_amount();
	double compute_tax();
	double compute_total_bill();
	double get_paid_amount();
	void print();
	void set_paid_amount(double amount);
	void getTodaysDate();
};

#endif