



#include <iostream>
#include <string>
using namespace std;
#include "Airport.h"

// This is the Simulator Class
class Simulator
{
	Airport airport;
	int time_limit;
	int refresh_rate;

	// Utility Functions
	// Initialize 
	void initialize(string config_filename);

public:	// This is where the member goes
	// Constructors
	// Contructor with params
	Simulator(string config_filename);

	// Destructor
	~Simulator();
	
	// Member Functions
	// Begin Simulation
	void BeginSimulation();
};