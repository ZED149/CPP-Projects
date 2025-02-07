

#pragma once


// Contains CandleStick class

#include "Country.h"
#include <vector>
#include <map>

class CSVReader
{
	// initialize
	void initialize(const string filename);

	// read_file
	void read_file(const string filename);

	vector<Country> list_of_countries;				// list to store country objects.

	map<string, string> c_codes = {					// pre-defined country map for populating the list during runtime.
		{"Austria", "AT"},
		{"Belgium", "BE"},
		{"Bulgaria", "BG"},
		{"Switzerland", "CH"},
		{"Czechia", "CZ"},
		{"Germany", "DE"},
		{"Denmark", "DK"},
		{"Estonia", "EE"},
		{"Spain", "ES"},
		{"Finland", "FI"},
		{"France", "FR"},
		{"United Kingdom", "GB"},
		{"Greece", "GR"},
		{"Crotia", "HR"},
		{"Hungary", "HU"},
		{"Ireland", "IE"},
		{"Italy", "IT"},
		{"Lithuania", "LT"},
		{"Luxembourg", "LU"},
		{"Latvia", "LV"},
		{"Netherlands", "NL"},
		{"Norway", "NO"},
		{"Poland", "PL"},
		{"Portugal", "PT"},
		{"Romania", "RO"},
		{"Sweden", "SE"},
		{"Slovenia", "SI"},
		{"Slovakia", "SK"}
	};

public:
	// Constructor
	CSVReader(const string filename);

	// get_list_of_countries
	vector<Country> get_list_of_countries();
};