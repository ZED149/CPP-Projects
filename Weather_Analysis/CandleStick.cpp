

// Contains implementations of CandleStick.h

#include "CandleStick.h"
#include <string>
#include <vector>
#include <iostream>
#include "CSVReader.h"
using namespace std;


// Constructor
CandleStick::CandleStick(string c_name, string c_year, double max_t, double min_t, long double c_open):
	c_name(c_name), c_year(c_year), max_t(max_t), min_t(min_t), c_open(c_open)
{
#ifdef _DEBUG
	cout << "CandleStick() called\n";
#endif
	srand(time(0));
}


// compute_candle_sticks
vector<CandleStick> CandleStick::compute_candle_sticks(const vector<Country> &list_of_countries, const string country_name)
{
#ifdef _DEBUG
	cout << "compute_candle_sticks() called\n";
#endif
	// we have already computed data while reading the file
	// now, we just need to extract data for that particular country and maintain the format
	// iterate on list, for the country provided
	
	for (auto& country : list_of_countries)
	{
		if (country.get_c_name() == country_name)
		{
			for (auto& i : country.c_data)
			{
				// create a new CandleStick object and push it into the vector
				this->data.push_back(CandleStick(country_name, i.c_year, i.max_t, i.min_t, i.c_open));
			}
		}
	}
	srand(time(0));
	return data;
}

// print_candle_sticks
void CandleStick::print_candle_sticks()
{

	// finding max and minimum for the open b/w all years from 1980 - 2019
	double o_max = -99999999, o_min = 100000000;
	for (auto& i : data)
	{
		if (i.c_open > o_max)
			o_max = i.c_open;

		if (i.c_open < o_min)
			o_min = i.c_open;
	}
	
	// converting o_max and o_min to round integers
	int ro_max = int(o_max), ro_min = int(o_min);

	cout << "Printing Data for: " << data[0].c_name << endl;

	// printing x-axis (years)
	int counter = 0;
	cout.clear();
	for (auto& i : data)
	{
		cout << " " << (stoi(i.c_year) % 100);
		counter++;
	}
	cout << "\n ";
	for (int i = 0; i < counter; i++)
	{
		cout << "+~~";
	}
	cout << "\n";
	// priting y axis
	int r_counter = counter;
	counter = 0;
	int index = 0;
	for (int i = ro_min - 2; i<= ro_max + 2; i++)
	{
		cout.clear();
		cout << " |\n" << i << "+";

		// check for each country with each iteration of parent loop
		int inner_counter = 0;
		for (auto& check : data)
		{
			if (int(check.c_open) == i)
			{
				// print as much sep(s) for it
				for (int j = 0; j < inner_counter; j++)
				{
					cout << " ";
				}
				// after printing sep(s), then print symbol "@"
				cout << "@";
			}
			inner_counter++;
		}

		//cout << "-|";
		counter++;
		cout << "\n";
	}
}

// ask
int CandleStick::ask()
{
	// prompt the user for which country or at which temp he wants to see data
	cout << "Either you wish to plot data for temps or country...";
	cout << "For country enter 1, for temps enter 2\n";
	int choice = 0;
	cin >> choice;
	return choice;
}

// ask_country
string CandleStick::ask_country()
{
	// for country
	cout << "For which Euorepan country you wish to see data for? ";
	string country_name;
	cin.ignore();
	getline(cin, country_name, '\n');
	return country_name;	
}

// print_candle_sticks_temps
void CandleStick::print_candle_sticks_temps(vector<Country> list_of_countries)
{
	// finding max and minimum for the open b/w all years from 1980 - 2019
	double o_max = -99999999, o_min = 100000000;
	for (auto& i : data)
	{
		if (i.c_open > o_max)
			o_max = i.c_open;

		if (i.c_open < o_min)
			o_min = i.c_open;
	}

	// converting o_max and o_min to round integers
	int ro_max = int(o_max), ro_min = int(o_min);

	cout << "Printing Data for temps \n";
	// printing year axis
	int counter = 0;
	cout.clear();
	for (auto& i : data)
	{
		cout << " " << (stoi(i.c_year) % 100);
		counter++;
	}
	cout << "\n";
	for (int i = 0; i < counter; i++)
	{
		cout << "+  ";
	}
	cout << "\n";

	// priting y axis
	counter = 0;
	for (int i = ro_min - 3; i <= ro_max + 3; i++)
	{
		// this conidition keeps countries list index in range
		if (counter == 29)
			counter = 0;
		cout.clear();
		cout << " |\n" << i << "+";
		// check for each country with each iteration of parent loop
		int inner_counter = 0;
		for (auto& check : data)
		{
			// check for each country temp with the parent loop iterator (avg), if matches print that country name for that year...
			if (int(check.c_open) == i)
			{
				// print as much sep(s) for it
				for (int j = 0; j < inner_counter; j++)
				{
					cout << " ";
				}
				// after printing sep(s), then print country name
				cout << list_of_countries[counter].get_c_name();
			}
			inner_counter++;
		}
		counter++;
		cout << "\n";
	}
}