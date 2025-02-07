
#pragma once


// Contains CandleStick.h

#include <vector>
#include <string>
#include "Country.h"
using namespace std;

class CandleStick
{
	string c_name;					// name of the country to store candle sticks for
	string c_year;					// year of the country for candle sticks
	double max_t;					// max temperature recorded
	double min_t;					// minimum temperature recorded
	long double c_open;				// open variable for the country for that year

	vector<CandleStick> data;		// list to store candlestick data for a single country for computation purposes
public:
	string country_decision = "";	// decision enterted by the user for which country to plot data for	

	// default constructor
	CandleStick() {};
	// parameterized constructor
	CandleStick(string c_name, string c_year, double max_t, double min_t, long double c_open);

	// compute_candle_sticks
	vector<CandleStick> compute_candle_sticks(const vector<Country> &list_of_countries, const string country_name);

	// print_candle_sticks_for_country
	void print_candle_sticks();

	// ask
	int ask();
	
	// ask_country
	string ask_country();

	// print_candle_sticks_temps
	void print_candle_sticks_temps(vector<Country> list_of_countries);
};