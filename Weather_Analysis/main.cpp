

#include <iostream>
using namespace std;
#include "Country.h"
#include "CSVReader.h"
#include "CandleStick.h"
#include <vector>


int main()
{
	// reading csv file. This method reads a very heavy csv file so this computation can take some time.
	cout << "Reading CSV File. This may take some time...\n";
#ifdef _DEBUG
	CSVReader obj("sample_data.csv");
#else
	CSVReader obj("weather_data.csv");
#endif

	// creating a candlestick object
	CandleStick j;
	
#ifdef _DEBUG
	// for development purposes
	j.compute_candle_sticks(obj.get_list_of_countries(), "Austria");
	j.print_candle_sticks_temps(obj.get_list_of_countries());
#else
	// prompting the user for which filter he/she wants to plot data for...
	int choice = j.ask();

	if (choice == 1)
	{
		// for country
		// storing country decision in the candlestick object.
		j.country_decision = j.ask_country();
		// computing candlestick for that specific country.
		j.compute_candle_sticks(obj.get_list_of_countries(), j.country_decision);
		// plotting data.
		j.print_candle_sticks();
	}
	else if (choice == 2)
	{
		// for temps
		// computing candle sticks data for graph representation. Any country name can be passed here.
		// will have no effect as this is just a reference in this case.
		j.compute_candle_sticks(obj.get_list_of_countries(), "Austria");
		// plotting data.
		j.print_candle_sticks_temps(obj.get_list_of_countries());
	}
	else
	{
		cout << "Invalid decision. Program exiting.\n";
		exit(0);
	}
#endif
	

	
}