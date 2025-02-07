

// Contains implementations of Country.cpp

#include <iostream>
#include <string>
using namespace std;
#include "Country.h"

// Constructor
Country::Country(string c_name, string c_code):
	c_name(c_name), c_code(c_code)
{
#ifdef _DEBUG
	cout << "Country() called\n";
#endif
}


// overloaded << operator for this class
ostream& operator << (ostream& out, const Country &obj)
{	
	out << "Country Name: " << obj.c_name << " || Country Code: " << obj.c_code << "\n";
	return out;
}


// check_min_t
void Country::check_min_t(const double temp)
{
	// updates the temp if present temp is lower
	for (auto& i : c_data)
		if (temp < i.min_t)
			i.min_t = temp;
}

// check_max_t
void Country::check_max_t(const double temp)
{
	for (auto& i : c_data)
		// updates the temp if present temp is higher
		if (temp > i.max_t)
			i.max_t = temp;
	
}

// get_c_name
const string Country::get_c_name() const
{
	return this->c_name;
}

// add_open
void Country::add_open(const double open, const string year)
{
	// increments the open variable for particular country for that specific year
	for (auto& i : c_data)
		if (i.c_year == year)
			i.c_open += open;
}