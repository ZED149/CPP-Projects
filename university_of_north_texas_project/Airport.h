

#include <iostream>
#include <string>
#include <vector>
#include "Tile.h"
using namespace std;

// This is the Airport Class
#ifndef AIRPORT_H
#define AIRPORT_H
class Airport
{
	vector<vector<Tile>> airport_enviournment_grid;
	string zone_filename;
	int rows;
	int cols;
	vector<Tile> domestic_workers;
	int total_domestic_workers;
	int total_domestic_cells;
	int total_cargo_cells;

	// Utility Functions
	// Initialize
	void initialize(string filename);

	// Calculate Total Domestic Workers From Airportt Enviournment Grid
	void calcualte_total_domestic_workers_from_airport_enviournment_grid();

	// Update Airport Enviournment Grid Tiles Coordinates
	void update_airport_enviournment_grid_tiles_coordinates();

	// Is Adjacent To a Powerline
	bool is_adjacent_to_a_powerline(const char _powerline, int i, int j);

	// Is Adjacent To a Cell of Population
	bool is_adjacent_to_cell_of_population(const int population, int i, int j);

	// Is Adjacent To At Least Two Cells Of Population
	bool is_adjacent_to_at_least_two_cells_of_population(const int population, int i, int j);

	// Is Adjacent To At Least Four Cells Of Population
	bool is_adjacent_to_at_least_number_of_cells_of_population(const int population, int i, int j, int number_of_cells);

	// Spread Pollution Adjacently
	void spread_pollution_adjacently(int i, int j);


public:	// This is where the member goes
	// Constructor
	// Default Constructor
	Airport();

	// Destructor
	~Airport();

	// Getters
	// Zone File Name
	string GetZoneFileName();

	// Domestic Workers
	int GetTotalDomesticWorkers();

	// Total Cargo Cells
	int GetTotalCargoCells();

	// Total Goods
	int GetTotalGoods();

	// Setters
	// Zone Filename
	void SetZoneFilename(string zone_filename);

	// Member Functions
	// Print
	void Print();

	// Initialize
	void Initialize(string zone_filename);

	// Print Grid
	void PrintGrid();

	// Perform Operations
	void PerformOperations();

	// Print Demostic Workers
	void PrintDomesticWorkers();

	// Print Zones Populations
	void PrintZonesPopulation();

	// Specific Zone Information
	void SpecificZoneInformation(int x1, int y1, int x2, int y2);

	// Spread Pollution
	void SpreadPollution();

	// Print Pollution Grid
	void PrintPollutionGrid();
};
#endif