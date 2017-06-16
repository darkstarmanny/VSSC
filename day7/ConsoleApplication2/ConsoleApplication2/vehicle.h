#ifndef VEHICLE_H
#define VEHICLE_H
#include"tstring.h"
#include"part.h"
using namespace std;

class vehicle
{
	TString company, model, number;

public:
	TString get_company();
	TString get_model();
	TString get_no();
	void input();
	void set_company(const TString&company);
	void set_model(const TString&model);
	void set_number(const TString&number);
	vehicle();
	vehicle(const TString& company, const TString& model, const TString& number);
};

#endif