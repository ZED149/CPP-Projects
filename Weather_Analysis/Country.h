

#pragma once


// this file contains the country class
// responsible for storing the country code alongside with its full name

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Country
{
	string c_name;			// name of the country,		e.g (Austria)
	string c_code;			// code for the country,	e.g (AT) ==> for Austria
	

public:
	unsigned int open_temp_counter = 0;
	struct data
	{
		string c_year;		// year of the country		e.g (2012)
		double max_t;		// max temperature recorded for that country
		double min_t;		// min temperature recorded for that country
		long double c_open;	// open variable for the country for each year

		// constructor
		data(string c_year, double max, double min, long double open = 0) :
			c_year(c_year), max_t(max), min_t(min), c_open(open) {}
	};
	vector<data> c_data;	// list to store all years data for a single country

	// Constructor
	Country(string c_name = "none", string c_code = "none");

	// overloaded outpur operator for this class
	friend ostream& operator << (ostream& out, const Country &obj);

	// get_c_name
	const string get_c_name() const;

	// check_min_t
	void check_min_t(const double temp);

	// check_max_t
	void check_max_t(const double temp);

	// add_open
	void add_open(const double open, const string year);
};