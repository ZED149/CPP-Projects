
#define _CRT_SECURE_NO_WARNINGS

#include "Airport.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;



// Utility Functions
// Initialize
void Airport::initialize(string zone_filename)
{
	//cout << "Zone Filename is: " << zone_filename << endl;

	// This function/method will initialize [airport_enviournment_grid]

	// opening file for reading
	FILE* fin = fopen(zone_filename.c_str(), "r");

	// checking for errors
	if (fin == NULL)
	{
		cout << "Error opening Zone File for reading Data Grid" << endl;
		return;
	}

	// reading file till end
	char buffer[100];
	int index = 0;
	while (!feof(fin))
	{
		fgets(buffer, 100, fin);
		vector<Tile> temp_tile_vector;
		this->airport_enviournment_grid.push_back(temp_tile_vector);	// adds 1 row to the vector
		// parsing string using ','
		char* token = NULL, * next_token = NULL;
		token = strtok_s(buffer, ",", &next_token);
		while (token)
		{
			Tile temp_tile;
			temp_tile.SetLabelZoneName(token);
			this->airport_enviournment_grid[index].push_back(temp_tile);
			token = strtok_s(NULL, ",", &next_token);
		}
		index++;
	}
	fclose(fin);


	this->airport_enviournment_grid.pop_back();
	// Updating [rows] Value
	this->rows = index - 1;
	// Updating [cols] Value
	int _col_size = this->airport_enviournment_grid[0].size();
	this->cols = _col_size;
	this->update_airport_enviournment_grid_tiles_coordinates();
}

// Calculate Total Domestic Workers From Airport Enviournment Grid
void Airport::calcualte_total_domestic_workers_from_airport_enviournment_grid()
{
	this->total_domestic_workers = 0;
	for (int i = 0; i < this->airport_enviournment_grid.size(); i++)
	{
		for (int j = 0; j < this->airport_enviournment_grid[i].size(); j++)
		{
			if (this->airport_enviournment_grid[i][j].GetLabelZoneName() == 'D')
			{
				this->total_domestic_workers += this->airport_enviournment_grid[i][j].GetPopulation();
			}
		}
	}
}

// Update Airport Enviournment Grid Tiles Coordinates
void Airport::update_airport_enviournment_grid_tiles_coordinates()
{
	for (int i = 0; i < this->airport_enviournment_grid.size(); i++)
	{
		for (int j = 0; j < this->airport_enviournment_grid[i].size(); j++)
		{
			this->airport_enviournment_grid[i][j].SetXCoordinate(i);
			this->airport_enviournment_grid[i][j].SetYCoordinate(j);
		}
	}
}

// Is Adjacent To a Powerline
bool Airport::is_adjacent_to_a_powerline(const char _powerline, int i, int j)
{
	// Doing Boundary Checks
	if (i == 0)
	{
		if (j == 0)
		{
			if (this->airport_enviournment_grid[i][j + 1].GetLabelZoneName() == _powerline)
			{
				return true;
			}
			else if (this->airport_enviournment_grid[i + 1][j].GetLabelZoneName() == _powerline)
			{
				return true;
			}
		}
		else if (j == this->cols - 1)
		{
			if (this->airport_enviournment_grid[i + 1][j].GetLabelZoneName() == _powerline)
			{
				return true;
			}
			else if (this->airport_enviournment_grid[i][j - 1].GetLabelZoneName() == _powerline)
			{
				return true;
			}
		}
		else
		{
			if (this->airport_enviournment_grid[i][j + 1].GetLabelZoneName() == _powerline)
			{
				return true;
			}
			else if (this->airport_enviournment_grid[i + 1][j].GetLabelZoneName() == _powerline)
			{
				return true;
			}
			else if (this->airport_enviournment_grid[i][j - 1].GetLabelZoneName() == _powerline)
			{
				return true;
			}
		}
	}
	else if (i == this->rows - 1)
	{
		if (j == 0)
		{
			if (this->airport_enviournment_grid[i - 1][j].GetLabelZoneName() == _powerline)
			{
				return true;
			}
			else if (this->airport_enviournment_grid[i][j + 1].GetLabelZoneName() == _powerline)
			{
				return true;
			}
		}
		else if (j == this->cols - 1)
		{
			if (this->airport_enviournment_grid[i - 1][j].GetLabelZoneName() == _powerline)
			{
				return true;
			}
			else if (this->airport_enviournment_grid[i][j - 1].GetLabelZoneName() == _powerline)
			{
				return true;
			}
		}
		else
		{
			if (this->airport_enviournment_grid[i - 1][j].GetLabelZoneName() == _powerline)
			{
				return true;
			}
			else if (this->airport_enviournment_grid[i][j + 1].GetLabelZoneName() == _powerline)
			{
				return true;
			}
			else if (this->airport_enviournment_grid[i][j - 1].GetLabelZoneName() == _powerline)
			{
				return true;
			}
		}
	}
	else
	{
		if (j == 0)
		{
			if (this->airport_enviournment_grid[i - 1][j].GetLabelZoneName() == _powerline)
			{
				return true;
			}
			else if (this->airport_enviournment_grid[i][j + 1].GetLabelZoneName() == _powerline)
			{
				return true;
			}
			else if (this->airport_enviournment_grid[i + 1][j].GetLabelZoneName() == _powerline)
			{
				return true;
			}
		}
		else if (j == this->cols - 1)
		{
			if (this->airport_enviournment_grid[i - 1][j].GetLabelZoneName() == _powerline)
			{
				return true;
			}
			else if (this->airport_enviournment_grid[i + 1][j].GetLabelZoneName() == _powerline)
			{
				return true;
			}
			else if (this->airport_enviournment_grid[i][j - 1].GetLabelZoneName() == _powerline)
			{
				return true;
			}
		}
		else
		{
			if (this->airport_enviournment_grid[i - 1][j].GetLabelZoneName() == _powerline)
			{
				return true;
			}
			else if (this->airport_enviournment_grid[i][j + 1].GetLabelZoneName() == _powerline)
			{
				return true;
			}
			else if (this->airport_enviournment_grid[i + 1][j].GetLabelZoneName() == _powerline)
			{
				return true;
			}
			else if (this->airport_enviournment_grid[i][j - 1].GetLabelZoneName() == _powerline)
			{
				return true;
			}
		}
	}

	return false;
}

// Is Adjacent To a Cell of Population
bool Airport::is_adjacent_to_cell_of_population(const int population, int i, int j)
{
	// Doing Boundary Checks
	if (i == 0)
	{
		if (j == 0)
		{
			if (this->airport_enviournment_grid[i][j + 1].GetPopulation() == population)
			{
				return true;
			}
			else if (this->airport_enviournment_grid[i + 1][j].GetPopulation() == population)
			{
				return true;
			}
		}
		else if (j == this->cols - 1)
		{
			if (this->airport_enviournment_grid[i + 1][j].GetPopulation() == population)
			{
				return true;
			}
			else if (this->airport_enviournment_grid[i][j - 1].GetPopulation() == population)
			{
				return true;
			}
		}
		else
		{
			if (this->airport_enviournment_grid[i][j + 1].GetPopulation() == population)
			{
				return true;
			}
			else if (this->airport_enviournment_grid[i + 1][j].GetPopulation() == population)
			{
				return true;
			}
			else if (this->airport_enviournment_grid[i][j - 1].GetPopulation() == population)
			{
				return true;
			}
		}
	}
	else if (i == this->rows - 1)
	{
		if (j == 0)
		{
			if (this->airport_enviournment_grid[i - 1][j].GetPopulation() == population)
			{
				return true;
			}
			else if (this->airport_enviournment_grid[i][j + 1].GetPopulation() == population)
			{
				return true;
			}
		}
		else if (j == this->cols - 1)
		{
			if (this->airport_enviournment_grid[i - 1][j].GetPopulation() == population)
			{
				return true;
			}
			else if (this->airport_enviournment_grid[i][j - 1].GetPopulation() == population)
			{
				return true;
			}
		}
		else
		{
			if (this->airport_enviournment_grid[i - 1][j].GetPopulation() == population)
			{
				return true;
			}
			else if (this->airport_enviournment_grid[i][j + 1].GetPopulation() == population)
			{
				return true;
			}
			else if (this->airport_enviournment_grid[i][j - 1].GetPopulation() == population)
			{
				return true;
			}
		}
	}
	else
	{
		if (j == 0)
		{
			if (this->airport_enviournment_grid[i - 1][j].GetPopulation() == population)
			{
				return true;
			}
			else if (this->airport_enviournment_grid[i][j + 1].GetPopulation() == population)
			{
				return true;
			}
			else if (this->airport_enviournment_grid[i + 1][j].GetPopulation() == population)
			{
				return true;
			}
		}
		else if (j == this->cols - 1)
		{
			if (this->airport_enviournment_grid[i - 1][j].GetPopulation() == population)
			{
				return true;
			}
			else if (this->airport_enviournment_grid[i + 1][j].GetPopulation() == population)
			{
				return true;
			}
			else if (this->airport_enviournment_grid[i][j - 1].GetPopulation() == population)
			{
				return true;
			}
		}
		else
		{
			if (this->airport_enviournment_grid[i - 1][j].GetPopulation() == population)
			{
				return true;
			}
			else if (this->airport_enviournment_grid[i][j + 1].GetPopulation() == population)
			{
				return true;
			}
			else if (this->airport_enviournment_grid[i + 1][j].GetPopulation() == population)
			{
				return true;
			}
			else if (this->airport_enviournment_grid[i][j - 1].GetPopulation() == population)
			{
				return true;
			}
		}
	}

	return false;
}

// Is Adjacent To At Least Two Cells Of Population
bool Airport::is_adjacent_to_at_least_two_cells_of_population(const int population, int i, int j)
{
	if (i == 0)
	{
		if ((this->rows - 1) - i >= 2)
		{
			if (this->airport_enviournment_grid[i + 1][j].GetPopulation() >= 1 &&
				this->airport_enviournment_grid[i + 2][j].GetPopulation() >= 1)
			{
				return true;
			}
		}
		if ((this->cols - j) >= 2)
		{
			if (this->airport_enviournment_grid[i][j + 1].GetPopulation() >= 1 &&
				this->airport_enviournment_grid[i][j + 2].GetPopulation() >= 1)
			{
				return true;
			}
		}
		if ((j >= 2))
		{
			if (this->airport_enviournment_grid[i][j - 1].GetPopulation() >= 1 &&
				this->airport_enviournment_grid[i][j - 2].GetPopulation() >= 1)
			{
				return true;
			}
		}
	}
	else if (i == rows - 1)
	{
		if (i >= 2)
		{
			if (this->airport_enviournment_grid[i - 1][j].GetPopulation() >= 1 &&
				this->airport_enviournment_grid[i - 2][j].GetPopulation() >= 1)
			{
				return true;
			}
		}
		if ((this->cols - j) >= 2)
		{
			if (this->airport_enviournment_grid[i][j + 1].GetPopulation() >= 1 &&
				this->airport_enviournment_grid[i][j + 2].GetPopulation() >= 1)
			{
				return true;
			}
		}
		if ((j >= 2))
		{
			if (this->airport_enviournment_grid[i][j - 1].GetPopulation() >= 1 &&
				this->airport_enviournment_grid[i][j - 2].GetPopulation() >= 1)
			{
				return true;
			}
		}
	}
	else
	{
		if (i >= 2)
		{
			if (this->airport_enviournment_grid[i - 1][j].GetPopulation() >= 1 &&
				this->airport_enviournment_grid[i - 2][j].GetPopulation() >= 1)
			{
				return true;
			}
		}
		if ((this->rows - 1) - i >= 2)
		{
			if (this->airport_enviournment_grid[i + 1][j].GetPopulation() >= 1 &&
				this->airport_enviournment_grid[i + 2][j].GetPopulation() >= 1)
			{
				return true;
			}
		}
		if ((this->cols - j) >= 2)
		{
			if (this->airport_enviournment_grid[i][j + 1].GetPopulation() >= 1 &&
				this->airport_enviournment_grid[i][j + 2].GetPopulation() >= 1)
			{
				return true;
			}
		}
		if ((j >= 2))
		{
			if (this->airport_enviournment_grid[i][j - 1].GetPopulation() >= 1 &&
				this->airport_enviournment_grid[i][j - 2].GetPopulation() >= 1)
			{
				return true;
			}
		}

		if (i >= 1 && (this->rows - 1) - i >= 1)
		{
			if (this->airport_enviournment_grid[i - 1][j].GetPopulation() >= 1 &&
				this->airport_enviournment_grid[i + 1][j].GetPopulation() >= 1)
			{
				return true;
			}
		}

		if (j >= 1 && (this->cols - j) >= 1)
		{
			if (this->airport_enviournment_grid[i][j - 1].GetPopulation() >= 1 &&
				this->airport_enviournment_grid[i][j + 1].GetPopulation() >= 1)
			{
				return true;
			}
		}
	}

	return false;
}

// Is Adjacent To At Least Four Cells Of Population
bool Airport::is_adjacent_to_at_least_number_of_cells_of_population(const int population, int i, int j, int number_of_cells)
{
	int counter = 0;
	// Doing Boundary Checks
	if (i == 0)
	{
		if (j == 0)
		{
			if (this->airport_enviournment_grid[i][j + 1].GetPopulation() == population)
			{
				counter++;
			}
			if (this->airport_enviournment_grid[i + 1][j + 1].GetPopulation() == population)
			{
				counter++;
			}
			if (this->airport_enviournment_grid[i + 1][j].GetPopulation() == population)
			{
				counter++;
			}
		}
		else if (j == this->cols - 1)
		{
			if (this->airport_enviournment_grid[i + 1][j].GetPopulation() == population)
			{
				counter++;
			}
			if (this->airport_enviournment_grid[i + 1][j - 1].GetPopulation() == population)
			{
				counter++;
			}
			if (this->airport_enviournment_grid[i][j - 1].GetPopulation() == population)
			{
				counter++;
			}
		}
		else
		{
			if (this->airport_enviournment_grid[i][j + 1].GetPopulation() == population)
			{
				counter++;
			}
			if (this->airport_enviournment_grid[i + 1][j + 1].GetPopulation() == population)
			{
				counter++;
			}
			if (this->airport_enviournment_grid[i + 1][j].GetPopulation() == population)
			{
				counter++;
			}
			if (this->airport_enviournment_grid[i + 1][j - 1].GetPopulation() == population)
			{
				counter++;
			}
			if (this->airport_enviournment_grid[i][j - 1].GetPopulation() == population)
			{
				counter++;
			}
		}
	}
	else if (i == this->rows - 1)
	{
		if (j == 0)
		{
			if (this->airport_enviournment_grid[i - 1][j].GetPopulation() == population)
			{
				counter++;
			}
			if (this->airport_enviournment_grid[i - 1][j + 1].GetPopulation() == population)
			{
				counter++;
			}
			if (this->airport_enviournment_grid[i][j + 1].GetPopulation() == population)
			{
				counter++;
			}
		}
		else if (j == this->cols - 1)
		{
			if (this->airport_enviournment_grid[i - 1][j].GetPopulation() == population)
			{
				counter++;
			}
			if (this->airport_enviournment_grid[i][j - 1].GetPopulation() == population)
			{
				counter++;
			}
			if (this->airport_enviournment_grid[i - 1][j - 1].GetPopulation() == population)
			{
				counter++;
			}
		}
		else
		{
			if (this->airport_enviournment_grid[i - 1][j].GetPopulation() == population)
			{
				counter++;
			}
			if (this->airport_enviournment_grid[i - 1][j + 1].GetPopulation() == population)
			{
				counter++;
			}
			if (this->airport_enviournment_grid[i][j + 1].GetPopulation() == population)
			{
				counter++;
			}
			if (this->airport_enviournment_grid[i][j - 1].GetPopulation() == population)
			{
				counter++;
			}
			if (this->airport_enviournment_grid[i - 1][j - 1].GetPopulation() == population)
			{
				counter++;
			}
		}
	}
	else
	{
		if (j == 0)
		{
			if (this->airport_enviournment_grid[i - 1][j].GetPopulation() == population)
			{
				counter++;
			}
			if (this->airport_enviournment_grid[i - 1][j + 1].GetPopulation() == population)
			{
				counter++;
			}
			if (this->airport_enviournment_grid[i][j + 1].GetPopulation() == population)
			{
				counter++;
			}
			if (this->airport_enviournment_grid[i + 1][j + 1].GetPopulation() == population)
			{
				counter++;
			}
			if (this->airport_enviournment_grid[i + 1][j].GetPopulation() == population)
			{
				counter++;
			}
		}
		else if (j == this->cols - 1)
		{
			if (this->airport_enviournment_grid[i - 1][j].GetPopulation() == population)
			{
				counter++;
			}
			if (this->airport_enviournment_grid[i + 1][j].GetPopulation() == population)
			{
				counter++;
			}
			if (this->airport_enviournment_grid[i + 1][j - 1].GetPopulation() == population)
			{
				counter++;
			}
			if (this->airport_enviournment_grid[i][j - 1].GetPopulation() == population)
			{
				counter++;
			}
			if (this->airport_enviournment_grid[i - 1][j - 1].GetPopulation() == population)
			{
				counter++;
			}
		}
		else
		{
			if (this->airport_enviournment_grid[i - 1][j].GetPopulation() == population)
			{
				counter++;
			}
			if (this->airport_enviournment_grid[i - 1][j + 1].GetPopulation() == population)
			{
				counter++;
			}
			if (this->airport_enviournment_grid[i][j + 1].GetPopulation() == population)
			{
				counter++;
			}
			if (this->airport_enviournment_grid[i + 1][j + 1].GetPopulation() == population)
			{
				counter++;
			}
			if (this->airport_enviournment_grid[i + 1][j].GetPopulation() == population)
			{
				counter++;
			}
			if (this->airport_enviournment_grid[i + 1][j - 1].GetPopulation() == population)
			{
				counter++;
			}
			if (this->airport_enviournment_grid[i][j - 1].GetPopulation() == population)
			{
				counter++;
			}
			if (this->airport_enviournment_grid[i - 1][j - 1].GetPopulation() == population)
			{
				counter++;
			}
		}
	}

	if (counter >= number_of_cells)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Spread Pollution Adjacenlty
void Airport::spread_pollution_adjacently(int i, int j)
{
	int _this_population = this->airport_enviournment_grid[i][j].GetPopulation();

	// Doing Boundary Checks
	if (i == 0)
	{
		if (j == 0)
		{
			this->airport_enviournment_grid[i][j + 1].SetPollution(--_this_population);
			if (_this_population <= 1)
				return;
			this->airport_enviournment_grid[i + 1][j + 1].SetPollution(--_this_population);
			if (_this_population <= 1)
				return;
			this->airport_enviournment_grid[i + 1][j].SetPollution(--_this_population);
			if (_this_population <= 1)
				return;
		}
		else if (j == this->cols - 1)
		{
			this->airport_enviournment_grid[i + 1][j].SetPollution(--_this_population);
			if (_this_population <= 1)
				return;
			this->airport_enviournment_grid[i + 1][j - 1].SetPollution(--_this_population);
			if (_this_population <= 1)
				return;
			this->airport_enviournment_grid[i][j - 1].SetPollution(--_this_population);
			if (_this_population <= 1)
				return;
		}
		else
		{
			this->airport_enviournment_grid[i][j + 1].SetPollution(--_this_population);
			if (_this_population <= 1)
				return;
			this->airport_enviournment_grid[i + 1][j + 1].SetPollution(--_this_population);
			if (_this_population <= 1)
				return;
			this->airport_enviournment_grid[i + 1][j].SetPollution(--_this_population);
			if (_this_population <= 1)
				return;
			this->airport_enviournment_grid[i + 1][j - 1].SetPollution(--_this_population);
			if (_this_population <= 1)
				return;
			this->airport_enviournment_grid[i][j - 1].SetPollution(--_this_population);
			if (_this_population <= 1)
				return;
		}
	}
	else if (i == this->rows - 1)
	{
		if (j == 0)
		{
			this->airport_enviournment_grid[i - 1][j].SetPollution(--_this_population);
			if (_this_population <= 1)
				return;
			this->airport_enviournment_grid[i - 1][j + 1].SetPollution(--_this_population);
			if (_this_population <= 1)
				return;
			this->airport_enviournment_grid[i][j + 1].SetPollution(--_this_population);
			if (_this_population <= 1)
				return;
		}
		else if (j == this->cols - 1)
		{
			this->airport_enviournment_grid[i - 1][j].SetPollution(--_this_population);
			if (_this_population <= 1)
				return;
			this->airport_enviournment_grid[i][j - 1].SetPollution(--_this_population);
			if (_this_population <= 1)
				return;
			this->airport_enviournment_grid[i - 1][j - 1].SetPollution(--_this_population);
			if (_this_population <= 1)
				return;
		}
		else
		{
			this->airport_enviournment_grid[i - 1][j].SetPollution(--_this_population);
			if (_this_population <= 1)
				return;
			this->airport_enviournment_grid[i - 1][j + 1].SetPollution(--_this_population);
			if (_this_population <= 1)
				return;
			this->airport_enviournment_grid[i][j + 1].SetPollution(--_this_population);
			if (_this_population <= 1)
				return;
			this->airport_enviournment_grid[i][j - 1].SetPollution(--_this_population);
			if (_this_population <= 1)
				return;
			this->airport_enviournment_grid[i - 1][j - 1].SetPollution(--_this_population);
			if (_this_population <= 1)
				return;
		}
	}
	else
	{
		if (j == 0)
		{
			this->airport_enviournment_grid[i - 1][j].SetPollution(--_this_population);
			if (_this_population <= 1)
				return;
			this->airport_enviournment_grid[i - 1][j + 1].SetPollution(--_this_population);
			if (_this_population <= 1)
				return;
			this->airport_enviournment_grid[i][j + 1].SetPollution(--_this_population);
			if (_this_population <= 1)
				return;
			this->airport_enviournment_grid[i + 1][j + 1].SetPollution(--_this_population);
			if (_this_population <= 1)
				return;
			this->airport_enviournment_grid[i + 1][j].SetPollution(--_this_population);
			if (_this_population <= 1)
				return;
		}
		else if (j == this->cols - 1)
		{
			this->airport_enviournment_grid[i - 1][j].SetPollution(--_this_population);
			if (_this_population <= 1)
				return;
			this->airport_enviournment_grid[i + 1][j].SetPollution(--_this_population);
			if (_this_population <= 1)
				return;
			this->airport_enviournment_grid[i + 1][j - 1].SetPollution(--_this_population);
			if (_this_population <= 1)
				return;
			this->airport_enviournment_grid[i][j - 1].SetPollution(--_this_population);
			if (_this_population <= 1)
				return;
			this->airport_enviournment_grid[i - 1][j - 1].SetPollution(--_this_population);
			if (_this_population <= 1)
				return;
		}
		else
		{
			this->airport_enviournment_grid[i - 1][j].SetPollution(--_this_population);
			if (_this_population <= 1)
				return;
			this->airport_enviournment_grid[i - 1][j + 1].SetPollution(--_this_population);
			if (_this_population <= 1)
				return;
			this->airport_enviournment_grid[i][j + 1].SetPollution(--_this_population);
			if (_this_population <= 1)
				return;
			this->airport_enviournment_grid[i + 1][j + 1].SetPollution(--_this_population);
			if (_this_population <= 1)
				return;
			this->airport_enviournment_grid[i + 1][j].SetPollution(--_this_population);
			if (_this_population <= 1)
				return;
			this->airport_enviournment_grid[i + 1][j - 1].SetPollution(--_this_population);
			if (_this_population <= 1)
				return;
			this->airport_enviournment_grid[i][j - 1].SetPollution(--_this_population);
			if (_this_population <= 1)
				return;
			this->airport_enviournment_grid[i - 1][j - 1].SetPollution(--_this_population);
			if (_this_population <= 1)
				return;
		}
	}
}

// Constructor
// Default Constructor
Airport::Airport()
{
	//cout << "Airport() called" << endl;
	this->rows = this->cols = -1;
	this->zone_filename = "";
	this->total_domestic_workers = 0;
}


// Destructor
Airport::~Airport()
{
	//cout << "~Airport() called" << endl;
}

// Getters
// Zone File Name
string Airport::GetZoneFileName()
{
	return this->zone_filename;
}

// Get Total Domestic Workers
int Airport::GetTotalDomesticWorkers()
{
	// Emtying Domestic Array
	while (!this->domestic_workers.empty())
	{
		this->domestic_workers.pop_back();
	}

	this->total_domestic_cells = this->total_cargo_cells = 0;
	// First iterate thorugh whole [airport_enviournment_grid] and
	// calculate number of domestic cells and cargo cells
	// then apply formula to calculate total remaning workers

	// Iterating through [airport_enviournment_grid]
	for (int i = 0; i < this->airport_enviournment_grid.size(); i++)
	{
		for (int j = 0; j < this->airport_enviournment_grid[i].size(); j++)
		{
			if (this->airport_enviournment_grid[i][j].GetLabelZoneName() == 'D' && 
				this->airport_enviournment_grid[i][j].GetPopulation() > 0)
			{
				// If its a Domestic Cell
				Tile temp_tile(this->airport_enviournment_grid[i][j].GetPopulation(), 0, 'D', i, j, 0, 0);
				this->domestic_workers.push_back(temp_tile);
				this->total_domestic_cells++;
			}
			else if (this->airport_enviournment_grid[i][j].GetLabelZoneName() == 'C' &&
				this->airport_enviournment_grid[i][j].GetPopulation() > 0)
			{
				// If its a Cargo Cell
				int temp = this->airport_enviournment_grid[i][j].GetPopulation();
				temp = 1 * temp;
				this->total_cargo_cells = this->total_cargo_cells + temp;
			}
		}
	}

	// Iterating through domestic_workers_vector
	int number_of_workers_needed = this->total_cargo_cells * 2;
	for (int i = 0; i < this->domestic_workers.size(); i++)
	{
		if (number_of_workers_needed == 0)
			break;
		if (domestic_workers[i].GetPopulation() == number_of_workers_needed)
		{
			// Deduce All Worker
			int temp = this->domestic_workers[i].GetPopulation();
			this->domestic_workers[i].SetPopulation(0);
			number_of_workers_needed = number_of_workers_needed - temp;
		}
		else if (domestic_workers[i].GetPopulation() > number_of_workers_needed)
		{
			// Deduce Required Workers
			int worker_in_domestic_cell = this->domestic_workers[i].GetPopulation();
			worker_in_domestic_cell = worker_in_domestic_cell - number_of_workers_needed;
			this->domestic_workers[i].SetPopulation(worker_in_domestic_cell);
			number_of_workers_needed = 0;
		}
		else if (domestic_workers[i].GetPopulation() < number_of_workers_needed &&
			this->domestic_workers[i].GetPopulation() >= 1)
		{
			// Deduce Remaining Workers
			int workers_in_domestic_cell = this->domestic_workers[i].GetPopulation();
			number_of_workers_needed = number_of_workers_needed - workers_in_domestic_cell;
			this->domestic_workers[i].SetPopulation(0);
		}
	}
	
	// calcualte again total remaining workers from domestic worker array
	int remaining_workers = 0;
	for (int i = 0; i < this->domestic_workers.size(); i++)
	{
		if (this->domestic_workers[i].GetPopulation() > 0)
		{
			remaining_workers = remaining_workers + this->domestic_workers[i].GetPopulation();
		}
	}

	return remaining_workers;
}

// Total Cargo Cells
int Airport::GetTotalCargoCells()
{
	return this->total_cargo_cells;
}

// Total Goods
int Airport::GetTotalGoods()
{
	// First Iterate trough whole [airport_enviournment_grid]
	// Then calculate total number of cargo cells and total number of international cells
	// Subtract international cells from cargo cells

	// Iterating through [airport_enviournment_grid]
	int _total_cargo_cells = 0, _total_internation_cells = 0;
	for (int i = 0; i < this->airport_enviournment_grid.size(); i++)
	{
		for (int j = 0; j < this->airport_enviournment_grid[i].size(); j++)
		{
			if (this->airport_enviournment_grid[i][j].GetLabelZoneName() == 'C' &&
				this->airport_enviournment_grid[i][j].GetPopulation() > 0)
			{
				// If Its a Cargo Cell
				int temp = this->airport_enviournment_grid[i][j].GetPopulation();
				temp = 1 * temp;
				_total_cargo_cells = _total_cargo_cells + temp;
			}
			else if (this->airport_enviournment_grid[i][j].GetLabelZoneName() == 'I' &&
				this->airport_enviournment_grid[i][j].GetPopulation() > 0)
			{
				// If Its an International Cell
				int temp = this->airport_enviournment_grid[i][j].GetPopulation();
				temp = 1 * temp;
				_total_internation_cells = _total_internation_cells + temp;
			}
		}
	}

	// subtracting international cells from cargo cells
	int res = _total_cargo_cells - _total_internation_cells;
	return res;
}

// Setters
// Zone Filenaame
void Airport::SetZoneFilename(string zone_filename)
{
	this->zone_filename = zone_filename;
}


// Member Functions
// Print
void Airport::Print()
{
	cout << "Zone Filename: " << this->zone_filename << endl;
	cout << "Rows: " << this->rows << endl;
	cout << "Cols: " << this->cols << endl;
}

// Initialize
void Airport::Initialize(string zone_filename)
{
	this->initialize(zone_filename);
}

// Print Grid
void Airport::PrintGrid()
{
	// * 'i' represents rows
	// * 'j' represents columns
	for (int j = 0; j < (this->cols * 2) + 2; j++)
	{
		cout << "-";
	}
	cout << endl;

	for (int i = 0; i < this->airport_enviournment_grid.size(); i++)
	{
		cout << "|";
		for (int j = 0; j < this->airport_enviournment_grid[i].size(); j++)
		{
			if (this->airport_enviournment_grid[i][j].GetPopulation() == 0)
			{
				cout << this->airport_enviournment_grid[i][j].GetLabelZoneName() << " ";
			}
			else if (this->airport_enviournment_grid[i][j].GetPopulation() > 0)
			{
				cout << this->airport_enviournment_grid[i][j].GetPopulation() << " ";
			}
			
		}
		cout << "|" << endl;
	}

	for (int j = 0; j < (this->cols * 2) + 2; j++)
	{
		cout << "-";
	}
	cout << endl;
}

// Perform Operations
void Airport::PerformOperations()
{
	// This will iterate through the [airport_enviournment_grid]
	// and will update cells accordingly
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->cols; j++)
		{
			if (this->airport_enviournment_grid[i][j].GetLabelZoneName() == 'D')
			{
				// For Domestic Cells
				// There are 7 rules for Domestic Cells
				// Applying Those rules accordingly

				if (this->airport_enviournment_grid[i][j].GetPopulation() == 0 && 
					(this->is_adjacent_to_a_powerline('T', i, j) || this->is_adjacent_to_a_powerline('#', i, j)))
				{
					// * 1. If a cell has a population of 0 and is adjacent to a powerline in the current time step,
					//  that cell’s population will increase by 1 in the next time step

					int current_population = this->airport_enviournment_grid[i][j].GetPopulation();
					current_population++;
					this->airport_enviournment_grid[i][j].SetPopulation(current_population);
				}
				else if (this->airport_enviournment_grid[i][j].GetPopulation() == 0 &&
					this->is_adjacent_to_cell_of_population(1, i, j))
				{
					// * 2. If a cell has a population of 0 and is adjacent to at least one cell with a population
					// of at least 1, that cell’s population will increase by 1 in the next time step

					int current_population = this->airport_enviournment_grid[i][j].GetPopulation();
					current_population++;
					this->airport_enviournment_grid[i][j].SetPopulation(current_population);
				}
				else if (this->airport_enviournment_grid[i][j].GetPopulation() == 1 &&
					this->is_adjacent_to_at_least_two_cells_of_population(1, i, j))
				{
					// * 3. If a cell has a population of 1 and is adjacent to at least two cells with a 
					// population of at least 1, that cell’s population will increase by 1 in the next time
					// step

					int current_population = this->airport_enviournment_grid[i][j].GetPopulation();
					current_population++;
					this->airport_enviournment_grid[i][j].SetPopulation(current_population);
				}
				else if (this->airport_enviournment_grid[i][j].GetPopulation() == 2 &&
					this->is_adjacent_to_at_least_number_of_cells_of_population(2, i, j, 4))
				{
					// * 4. If a cell has a population of 2 and is adjacent to at least four cells with a 
					// population of at least 2, that cell’s population will increase by 1 in the next time step

					int current_population = this->airport_enviournment_grid[i][j].GetPopulation();
					current_population++;
					this->airport_enviournment_grid[i][j].SetPopulation(current_population);
				}
				else if (this->airport_enviournment_grid[i][j].GetPopulation() == 3 &&
					this->is_adjacent_to_at_least_number_of_cells_of_population(3, i, j, 6))
				{
					// * 5. If a cell has a population of 3 and is adjacent to at least six cells with a 
					// population of at least 3, that cell’s population will increase by 1 in the next time step

					int current_population = this->airport_enviournment_grid[i][j].GetPopulation();
					current_population++;
					this->airport_enviournment_grid[i][j].SetPopulation(current_population);
				}
				else if (this->airport_enviournment_grid[i][j].GetPopulation() == 4 &&
					this->is_adjacent_to_at_least_number_of_cells_of_population(4, i, j, 8))
				{
					// * 6. If a cell has a population of 4 and is adjacent to at least eight cells with a 
					// population of at least 4, that cell’s population will increase by 1 in the next time step

					int current_population = this->airport_enviournment_grid[i][j].GetPopulation();
					current_population++;
					this->airport_enviournment_grid[i][j].SetPopulation(current_population);
				}
				
			}
			else if (this->airport_enviournment_grid[i][j].GetLabelZoneName() == 'C')
			{
				// For Cargo Cells
				// There are 6 rules for Cargo Cells
				// Applying Those Rules Accordingly

				// Calculating Total Domestic Workers
				this->calcualte_total_domestic_workers_from_airport_enviournment_grid();

				if (this->airport_enviournment_grid[i][j].GetPopulation() == 0 &&
					(this->is_adjacent_to_a_powerline('T', i, j) || this->is_adjacent_to_a_powerline('#', i, j))
					&& this->total_domestic_workers >= 2)
				{
					// * 1. If a cell has a population of 0, is adjacent to a powerline in the current 
					// time step, and there are at least 2 available workers, that cell’s population will 
					// increase by 1 in the next time step and the available workers are assigned to that job

					int current_population = this->airport_enviournment_grid[i][j].GetPopulation();
					current_population++;
					this->airport_enviournment_grid[i][j].SetPopulation(current_population);	
				}
				else if (this->airport_enviournment_grid[i][j].GetPopulation() == 0 &&
					this->is_adjacent_to_cell_of_population(1, i, j) && this->total_domestic_workers >= 2)
				{
					// * 2. If a cell has a population of 0, is adjacent to at least one cell with a 
					// population of at least 1, and there are at least 2 available workers, that cell’s 
					// population will increase by 1 in the next time step and the available workers are
					// assigned to that job

					int current_population = this->airport_enviournment_grid[i][j].GetPopulation();
					current_population++;
					this->airport_enviournment_grid[i][j].SetPopulation(current_population);
				}
				else if (this->airport_enviournment_grid[i][j].GetPopulation() == 1 &&
					this->is_adjacent_to_at_least_two_cells_of_population(1, i, j) && 
					this->total_domestic_workers >= 2)
				{
					// * 3. If a cell has a population of 1, is adjacent to at least two cells with a 
					// population of at least 1, and there are at least 2 available workers, that cell’s 
					// population will increase by 1 in the next time step and the available workers are 
					// assigned to that job

					int current_population = this->airport_enviournment_grid[i][j].GetPopulation();
					current_population++;
					this->airport_enviournment_grid[i][j].SetPopulation(current_population);
				}
				else if (this->airport_enviournment_grid[i][j].GetPopulation() == 2 &&
					this->is_adjacent_to_at_least_number_of_cells_of_population(2, i, j, 4) &&
					this->total_domestic_workers >= 2)
				{
					// * 4. If a cell has a population of 2, is adjacent to at least four cells with a 
					// population of at least 2, and there are at least 2 available workers, that cell’s 
					// population will increase by 1 in the next time step and the available workers are 
					// assigned to that job

					int current_population = this->airport_enviournment_grid[i][j].GetPopulation();
					current_population++;
					this->airport_enviournment_grid[i][j].SetPopulation(current_population);
				}

			}
			else if (this->airport_enviournment_grid[i][j].GetLabelZoneName() == 'I')
			{
				// For Internation Cells
				// There are total of 3 rules for internation cells
				// Applying those rules accordingly

				// Calculating Total Domestic Workers
				this->calcualte_total_domestic_workers_from_airport_enviournment_grid();
				// Calculating Total Cargo Cells [Goods]
				this->total_cargo_cells = this->GetTotalCargoCells();


				if (this->airport_enviournment_grid[i][j].GetPopulation() == 0 &&
					(this->is_adjacent_to_a_powerline('T', i, j) || this->is_adjacent_to_a_powerline('#', i, j))
					&& this->total_domestic_workers >= 1 && this->total_cargo_cells >= 1)
				{
					int current_population = this->airport_enviournment_grid[i][j].GetPopulation();
					current_population++;
					this->airport_enviournment_grid[i][j].SetPopulation(current_population);
				}
				else if (this->airport_enviournment_grid[i][j].GetPopulation() == 0 &&
					this->is_adjacent_to_cell_of_population(1, i, j) && this->total_domestic_workers >= 1 &&
					this->total_cargo_cells >= 1)
				{
					int current_population = this->airport_enviournment_grid[i][j].GetPopulation();
					current_population++;
					this->airport_enviournment_grid[i][j].SetPopulation(current_population);
				}
				else if (this->airport_enviournment_grid[i][j].GetPopulation() == 1 &&
					this->is_adjacent_to_at_least_two_cells_of_population(1, i, j) &&
					this->total_domestic_workers >= 1 && this->total_cargo_cells >= 1)
				{
					int current_population = this->airport_enviournment_grid[i][j].GetPopulation();
					current_population++;
					this->airport_enviournment_grid[i][j].SetPopulation(current_population);
				}

			}
		}
	}
}

// Print Domestic Workers
void Airport::PrintDomesticWorkers()
{
	int total_population = 0;
	for (int i = 0; i < this->domestic_workers.size(); i++)
	{
		total_population += this->domestic_workers[i].GetPopulation();
	}
	//cout << "Total Workers: " << total_population << " ";
}

// Print Zones Population
void Airport::PrintZonesPopulation()
{
	// Iterate through whole grid and calculate total number of 
	// 1. Domestic Cells
	// 2. Cargo Cells
	// 3. International Cells
	// 4. Pollution Cells

	int _total_domestic_cells = 0, _total_cargo_cells = 0, _total_international_cells = 0, _total_pollution_cells = 0;
	for (int i = 0; i < this->airport_enviournment_grid.size(); i++)
	{
		for (int j = 0; j < this->airport_enviournment_grid[i].size(); j++)
		{
			if (this->airport_enviournment_grid[i][j].GetPollution() > 0)
			{
				int temp = this->airport_enviournment_grid[i][j].GetPollution();
				temp = 1 * temp;
				_total_pollution_cells = _total_pollution_cells + temp;
			}
			if (this->airport_enviournment_grid[i][j].GetLabelZoneName() == 'D' && 
				this->airport_enviournment_grid[i][j].GetPopulation() > 0)
			{
				int temp = this->airport_enviournment_grid[i][j].GetPopulation();
				temp = 1 * temp;
				_total_domestic_cells = _total_domestic_cells + temp;
			}
			else if (this->airport_enviournment_grid[i][j].GetLabelZoneName() == 'C' &&
				this->airport_enviournment_grid[i][j].GetPopulation() > 0)
			{
				int temp = this->airport_enviournment_grid[i][j].GetPopulation();
				temp = 1 * temp;
				_total_cargo_cells = _total_cargo_cells + temp;
			}
			else if (this->airport_enviournment_grid[i][j].GetLabelZoneName() == 'I' &&
				this->airport_enviournment_grid[i][j].GetPopulation() > 0)
			{
				int temp = this->airport_enviournment_grid[i][j].GetPopulation();
				temp = 1 * temp;
				_total_international_cells = _total_international_cells + temp;
			}
		}
	}

	// Prtining numbers onto the screen
	cout << "Domestic Cells: " << _total_domestic_cells << endl;
	cout << "Cargo Cells: " << _total_cargo_cells << endl;
	cout << "International Cells: " << _total_international_cells << endl;
	cout << "The total amount of pollution in the zone is " << _total_pollution_cells << " units." << endl;
}

// Specific Zone Information
void Airport::SpecificZoneInformation(int x1, int y1, int x2, int y2)
{
	// Check for boundary values
	if (x2 == this->rows)
		x2--;
	if (y2 == this->cols)
		y2--;

	// This Function will take 4 coordinates and will
	// provide details described below
	// 1. Domestic Cells
	// 2. Cargo Cells
	// 3. International Cells
	// 4. Pollution

	int _total_domestic_cells = 0, _total_cargo_cells = 0, _total_international_cells = 0;
	int _total_pollution_cells = 0;
	// Iterating thorugh the user-specified grid and calculating above mentioned variables
	for (int i = x1; i <= x2; i++)
	{
		for (int j = y1; j <= y2; j++)
		{
			if (this->airport_enviournment_grid[i][j].GetPollution() > 0)
			{
				int temp = this->airport_enviournment_grid[i][j].GetPollution();
				temp = 1 * temp;
				_total_pollution_cells = _total_pollution_cells + temp;
			}
			if (this->airport_enviournment_grid[i][j].GetLabelZoneName() == 'D' &&
				this->airport_enviournment_grid[i][j].GetPopulation() > 0)
			{
				// If it's a Domestic Cell

				int temp = this->airport_enviournment_grid[i][j].GetPopulation();
				temp = 1 * temp;
				_total_domestic_cells = _total_domestic_cells + temp;
			}
			else if (this->airport_enviournment_grid[i][j].GetLabelZoneName() == 'C' &&
				this->airport_enviournment_grid[i][j].GetPopulation() > 0)
			{
				// If it's a Cargo Cell

				int temp = this->airport_enviournment_grid[i][j].GetPopulation();
				temp = 1 * temp;
				_total_cargo_cells = _total_cargo_cells + temp;
			}
			else if (this->airport_enviournment_grid[i][j].GetLabelZoneName() == 'I' &&
				this->airport_enviournment_grid[i][j].GetPopulation() > 0)
			{
				// If it's an International Cell

				int temp = this->airport_enviournment_grid[i][j].GetPopulation();
				temp = 1 * temp;
				_total_international_cells = _total_international_cells + temp;
			}
		}
	}

	// Printing Gathered Information
	cout << "Domestic Cells: " << _total_domestic_cells << endl;
	cout << "Cargo Cells: " << _total_cargo_cells << endl;
	cout << "International Cells: " << _total_international_cells << endl;
	cout << "The total amount of pollution for the requested area is " << _total_pollution_cells << " units." << endl;
}

// Spread Pollution
void Airport::SpreadPollution()
{
	// This Function will iterate through [airport_enviournment_grid] and will spread pollution adjacently

	// Iterating Through [airport_enviournment_grid]
	for(int i=0; i<this->airport_enviournment_grid.size(); i++)
	{
		for (int j = 0; j < this->airport_enviournment_grid[i].size(); j++)
		{
			if (this->airport_enviournment_grid[i][j].GetLabelZoneName() == 'C' &&
				this->airport_enviournment_grid[i][j].GetPopulation() > 1)
			{
				this->spread_pollution_adjacently(i, j);
			}
		}
	}
}

// Print Pollution Grid
void Airport::PrintPollutionGrid()
{
	// * 'i' represents rows
	// * 'j' represents columns
	for (int j = 0; j < (this->cols * 2) + 2; j++)
	{
		cout << "-";
	}
	cout << endl;

	for (int i = 0; i < this->airport_enviournment_grid.size(); i++)
	{
		cout << "|";
		for (int j = 0; j < this->airport_enviournment_grid[i].size(); j++)
		{
			cout << this->airport_enviournment_grid[i][j].GetPollution() << " ";
		}
		cout << "|" << endl;
	}

	for (int j = 0; j < (this->cols * 2) + 2; j++)
	{
		cout << "-";
	}
	cout << endl;
}