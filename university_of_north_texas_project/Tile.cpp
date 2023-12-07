


#include <iostream>
#include <string>
#include "Tile.h"
using namespace std;


// Constructor
// Default Constructor
Tile::Tile()
{
	//cout << "Tile() called" << endl;
	this->pollution = this->population = 0;
	this->label_zone_name = this->x_coordinate = this->y_coordinate = '@';
	this->assigned_worker_x_coordinate_for_cargo = this->assigned_workers_y_coordinate_for_cargo = -1;
}

// Constructor with params
Tile::Tile(int population, int pollution, char label_zone_name, char x_coordinate, char y_coordinate, 
	int assigned_worker_x_coordinate_for_cargo, int assigned_worker_y_corrdinate_for_cargo)
{
	//cout << "Tile(params) called" << endl;
	this->population = population;
	this->pollution = pollution;
	this->label_zone_name = label_zone_name;
	this->x_coordinate = x_coordinate;
	this->y_coordinate = y_coordinate;
	this->assigned_worker_x_coordinate_for_cargo = assigned_worker_x_coordinate_for_cargo;
	this->assigned_workers_y_coordinate_for_cargo = assigned_workers_y_coordinate_for_cargo;
}

// Destructor
Tile::~Tile()
{
	//cout << "~Tile() called" << endl;
}

// Member Functions
void Tile::Print()
{
	cout << "Population: " << this->population << endl;
	cout << "Pollution: " << this->pollution << endl;
	cout << "Label Zone Name: " << this->label_zone_name << endl;
	cout << "X Coordinate" << this->x_coordinate << endl;
	cout << "Y  Coordinate" << this->y_coordinate << endl;
}

// Getters
// Label Zone Name
char Tile::GetLabelZoneName()
{
	return this->label_zone_name;
}

// Get Population
int Tile::GetPopulation()
{
	return this->population;
}

// X Coordinate
char Tile::GetXCoordinate()
{
	return this->x_coordinate;
}

// Y Coordinate
char Tile::GetYCoordinate()
{
	return this->y_coordinate;
}

// Get Pollution
int Tile::GetPollution()
{
	return this->pollution;
}

// Setters
// Label Zone Name
void Tile::SetLabelZoneName(char *label_zone_name)
{
	this->label_zone_name = *label_zone_name;
}

// Population
void Tile::SetPopulation(const int population)
{
	this->population = population;
}

// X Coordinate
void Tile::SetXCoordinate(int x_coordinate)
{
	this->x_coordinate = x_coordinate;
}

// Y Coordinate
void Tile::SetYCoordinate(int y_coordinate)
{
	this->y_coordinate = y_coordinate;
}

// Pollution
void Tile::SetPollution(int pollution)
{
	this->pollution = pollution;
}