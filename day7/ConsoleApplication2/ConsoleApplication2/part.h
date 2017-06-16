#ifndef PART_H
#define PART_H
#include"tstring.h"
#include"service.h"
#include"oil.h"
using namespace std;

class part
{
	double rate;
	TString des;

public:
	part();
	part(const TString &desc, double rate);
	void input();
	TString get_desc();
	double get_rate();
	void set_desc(const TString &desc);
	void set_rate(double rate);
};

#endif