
#define _CRT_SECURE_NO_WARNINGS

#include "Simulator.h"
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;



// Utility Functions
void Simulator::initialize(string config_filname)
{
	// This function will open configuration file provided by the user from main() function
	// The configuration file contains three lines
	// * 1. First line contains the name of the airport grid file
	// * 2.  Second line contains the time limit for which the simulation runs totally
	// * 3. Third line contains the refresh rate for which data will be displayed/refreshed

	// * a. Moreover, this function reads zone filename and initialize airport enviornment
	// * b. initialize time_limit
	// * c. initialize refresh_rate

	// opening configuration file
	FILE* fin = fopen(config_filname.c_str(), "r");

	// checking for errors
	if (fin == NULL)
	{
		cout << "Error opening configuration file provided by the user" << endl;
		return;
	}

	// reading 3 lines of configuration file
	char buffer[100];

	// reading first line
	fgets(buffer, 100, fin);
	// initializing zone_filenme which will later be passed to the airport enviournment
	string zone_filename;
	{
		string temp(buffer);
		zone_filename = temp.substr(14, temp.size());
		// replacing new line character with null terminated character
		zone_filename[zone_filename.size() - 1] = '\0';
		// setting airport [zone_filename] of [airport]
		this->airport.SetZoneFilename(zone_filename);
		// initializing [airport_enviournment_grid] of [airport]
		this->airport.Initialize(zone_filename);
	}

	// reading second line
	fgets(buffer, 100, fin);
	// initializing time_limit [private attribute]
	{
		string temp(buffer);
		string _time_limit = temp.substr(11, temp.size());
		this->time_limit = stoi(_time_limit);
	}

	// reading third line
	fgets(buffer, 100, fin);
	// initializing refresh_rate [private attribute]
	{
		string temp(buffer);
		string _refresh_rate = temp.substr(13, temp.size());
		this->refresh_rate = stoi(_refresh_rate);
	}

	// Printing [airport_envoiurnment_grid]
	cout << "Beginning Simulation..." << endl;
	cout << "Configuration File provided by the user is: " << this->airport.GetZoneFileName() << endl;
	cout << "Initial Zone State" << endl;
	this->airport.PrintGrid();
}

// Constructor
// Constructor with params
Simulator::Simulator(string config_filename)
{
	//cout << "Simulator(config_filename) called" << endl;
	// This constructor just calls the initialize function
	// initialize is a private method of class simulator
	// which serves as a utility function/method
	this->initialize(config_filename);
}


// Destructor
Simulator::~Simulator()
{
	//cout << "~Simulator() called" << endl;
}

// Member Functions
// Begin Simulation
void Simulator::BeginSimulation()
{
	// At the time this function is called
	// Airport Enviournement Grid will be stored
	// and functions on Domestin | International | Cargo Tiles/Cells can be performed
	// This Function will perform these operations on the above mentioned cells

	for (int i = 1; i <= this->time_limit; i++)
	{
		Sleep(this->refresh_rate);
		this->airport.PerformOperations();
		cout << "Current Time Step: " << i << " Total Workers: " << this->airport.GetTotalDomesticWorkers();
		cout << " Total Goods: " << this->airport.GetTotalGoods() << endl;
		this->airport.PrintGrid();
	}

	// Printing Final Zone State
	cout << "Final Zone State: " << endl;
	this->airport.PrintGrid();

	// Printing Pollution Grid
	this->airport.SpreadPollution();
	this->airport.PrintPollutionGrid();

	// Printing Total Populations For Zones
	cout << endl << endl;
	cout << "The Total Populations for the zones are: " << endl;
	this->airport.PrintZonesPopulation();

	
	// Now Need To Prompt User For In-Depth Detail Of Any Zone If User Wants
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	cout << "Please enter the diagonal corners of the area you wish to have more information about. (MinX = 0, MinY = 0, MaxX = 7, MaxY = 7)" << endl;
	cout << "X1: ";
	cin >> x1;
	cout << "\nY1: ";
	cin >> y1;
	cout << "\nX2: ";
	cin >> x2;
	cout << "\nY2: ";
	cin >> y2;
	this->airport.SpecificZoneInformation(x1, y1, x2, y2);

	// aaaaaaaaah, Finally
	cout << "Simulation Complete" << endl;

}