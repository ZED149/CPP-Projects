

// Contains implementation of CandleStick.cpp


#include "CSVReader.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;


// Constructor
CSVReader::CSVReader(const string filename)
{
#ifdef _DEBUG
	cout << "CandleStick() called\n";
#endif // _DEBUG

	// calling initialize function
	// it will perform following functions
	// 1. prepares list of countries
	// 2. readfile 
	this->initialize(filename);
}


// initialize
void CSVReader::initialize(const string filename)
{
	// preparing list of countries by initializing each country object
	for (auto &[key, value] : c_codes)
	{
		// intitialize and push country into vector
		Country obj(key, value);
		this->list_of_countries.push_back(obj);
	}

	// reading file 
	this->read_file(filename);
}


// readfile
void CSVReader::read_file(const string filename)
{
	// read given file
	fstream fin(filename);
	string buffer;

	// if file is open
	if (fin.is_open())
	{
		// discarding headers
		getline(fin, buffer, '\n');
		int year_counter = 0;			// counter to reset year for countries
		int counter = 0;				// counter to add year to total 28 countries during 1 iteration of getline.
		bool year_flag = true;			// flag to only tokenize year from token for once every year.

		string Year = "";
		while (!fin.eof())
		{
			// reading from file line by line
			getline(fin, buffer, '\n');
			// now we need to parse data for each country
			char* next_token = nullptr;
			char* token = strtok_s(const_cast<char*>(buffer.c_str()), ",", &next_token);
			// this loop will skip radiation direct horizontal and radiation diffuse horizontal
			// and will only read temps from the read line for each country
			for (auto &country : list_of_countries)
			{
				// add country after every 8784 iterations, bcz data is in hourly format and there are 8760 hours in a year.
				if (year_flag)
				{
					// here, I need to extract year from the token
					stringstream year(token);
					string year_buffer;
					while (!year.eof())
					{
						getline(year, year_buffer, '-');
						// putting year in country's list of years
						// initializing a fake c_data object, with accurate year, min and max temps will update as the program proceed.
						Country::data temp(year_buffer, 0, 0);
						Year = year_buffer;
						year_flag = false;
						break;
					}
				}
				// tokenizing token for each country stored in a single line(buffer)
				while (token)
				{
					if (counter < 28)
					{
						Country::data temp(Year, 0, 0);
						// adding the year to respective country
						country.c_data.push_back(temp);
						counter++;
					}
					token = strtok_s(NULL, ",", &next_token);
					if (token)
					{
						// checking min temp for that country
						country.check_min_t(stod(token));
						// checking for max temo for that country
						country.check_max_t(stod(token));
						// adding the open for that country
						country.add_open(stod(token), Year);
						//country.open += stod(token);
					}
					// adding open values to calculate mean after loop ends
					country.open_temp_counter++;
					// discarding next two entries
					token = strtok_s(NULL, ",", &next_token);
					token = strtok_s(NULL, ",", &next_token);
					// counter check to add year only for first 28 iterations of loop for each year.
					break;
				}
			}
			year_counter++;
			// check if a year has passed.
			if (year_counter == 8784)
			{
				// resetting flag and counters for next year.
				year_counter = 0;
				year_flag = true;
				counter = 0;
			}
		}
		// calculating average mean temp for each country
		// to calculate avg open, keep in mind we need to do it for each year not for whole data as once
		for (auto& country : list_of_countries)
			for (auto& i : country.c_data)
				i.c_open /= 8784;
	}
	else
	{
		cerr << "Unable to read file\n";
	}
}


// get_list_of_countries
vector<Country> CSVReader::get_list_of_countries()
{
	return list_of_countries;
}