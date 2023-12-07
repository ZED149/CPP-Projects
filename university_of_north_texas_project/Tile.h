


#include <iostream>
#include <string>
using namespace std;


// This is the class for the Tiles
#ifndef TILE_H
#define TILE_H
class Tile
{
	int population;
	int pollution;
	char label_zone_name;
	char x_coordinate;
	char y_coordinate;
	int assigned_worker_x_coordinate_for_cargo;
	int assigned_workers_y_coordinate_for_cargo;

public:	// This is where the member goes
	// Constructor
	// Default Constructor
	Tile();
	
	// Constructor with params
	Tile(int population, int poluution, char label_zone_name, char x_coordinate, char y_coordinate,
		int assigned_worker_x_coodinate_for_cargo, int assigned_worker_y_coordinate_for_cargo);

	// Destructor
	~Tile();

	// Getters
	// Label Zone Name
	char GetLabelZoneName();

	// Get Population
	int GetPopulation();

	// X Coordinate
	char GetXCoordinate();

	// Y Coordinate
	char GetYCoordinate();

	// Get Pollution
	int GetPollution();

	// Setters
	// Label Zone Name
	void SetLabelZoneName(char *label_zone_name);

	// Population
	void SetPopulation(int population);

	// X Coordinate
	void SetXCoordinate(int x_coordinate);

	// Y Coordinate
	void SetYCoordinate(int y_coordinate);

	// Pollution
	void SetPollution(int pollution);

	// Member Functions
	// Print
	void Print();
};
#endif