
#pragma once


#include <string>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
using namespace std;


// This is the ship class
class ship
{
	// Private Data Members
	string name;	// Name
	string direction;	// Direction
	int size;	// Size


	// Utility Functions

	// Add To Plane
	void add_to_plane(char map[][10], bool bool_array[100])
	{
		bool flag = true;
		try
		{
			while (flag)
			{
				// First we generate a random number from range 0 - 99
				// Generating a random number
				srand(time(0));
				int rnumber;

				rnumber = (rand() % 99);
				//rnumber = 56;
				cout << "Random Number is: " << rnumber << endl;

				// Now we need to check whether this number is inside the bounds
				// of map or not

				// Determing row on map
				int row = 0, col = 0;
				if (rnumber > 10)
					row = rnumber / 10;
				else
					row = rnumber;

				if (rnumber > 10)
					col = rnumber % 10;
				else
					col = rnumber;

				// This will insert the ship horizontally
				if ((rnumber)+this->size - 1 <= (row * 10) + 9)		// Boundary Check [Horizontally]
				{
					flag = false;
					// First need to check whether there is some other ship
					// already present or not
					// if present get rnumber again else proceed
					int bool_array_index = (row * 10) + col;
					int temp_bool_array_index = bool_array_index;
					bool is_present = false;
					for (int i = 0; i < this->size; i++)
						if (bool_array[temp_bool_array_index++] == false)
							is_present = true;
					if (is_present == true)
					{
						// need to find some random number again
						flag = true;
					}
					else
					{
						// no ship is present at the current location
						// We can accomodate it on map horizontally
						int temp = col;
						int antemp = this->size;

						while (antemp > 0)
						{
							map[row][temp++] = 'h';
							bool_array[bool_array_index++] = false;
							antemp--;
						}
						this->direction = "horizontal";

						// For Developing Purpose Only
						//// Now we need to print this map onto the screen
						//for (int i = 0; i < 10; i++)
						//{
						//	for (int j = 0; j < 10; j++)
						//		cout << map[i][j] << "\t";
						//	cout << endl << endl;;
						//}
					}
				}
				else if ((10 - (row + size) >= 0))		// Boundary Check [Vertically]
				{
					// This will insert the ship vertically
					flag = false;
					// First need to check whether there is some other ship
					// already present or not
					// if present get rnumber again else proceed
					int bool_array_index = (row * 10) + col;
					int temp_bool_array_index = bool_array_index;
					bool is_present = false;
					for (int i = 0; i < this->size; i++, temp_bool_array_index += 10)
					{
						if (bool_array[temp_bool_array_index] == false)
							is_present = true;

					}
					if (is_present == true)
					{
						// need to find some random number again
						flag = true;
					}
					else
					{
						// no ship is present at the current location
						// We can accomodate it on map vertically
						int temp = row;
						int antemp = this->size;

						while (antemp > 0)
						{
							map[temp++][col] = 'v';
							bool_array[bool_array_index] = false;
							bool_array_index += 10;
							antemp--;
						}
						this->direction = "vertical";

						// For Developing Purpose Only
						//// Now we need to print this map onto the screen
						//for (int i = 0; i < 10; i++)
						//{
						//	for (int j = 0; j < 10; j++)
						//		cout << map[i][j] << "\t";
						//	cout << endl << endl;;
						//}
					}
				}
				else
					flag = true;
			}
		}
		catch (exception& e)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 20); // Red With Background
			cout << "EXCEPTION MESSAGE" << e.what() << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // white
		}
	}

public:	// This is where the member goes
	// Constructor with params
	ship(string name, int size, char map[][10], bool bool_array[100]) :
		name(name), size(size)
	{
		if (size < 0)
			this->size *= -1;
		//cout << "ship() with params called" << endl;
		
		// This function will add this ship to the plane(map)
		this->add_to_plane(map, bool_array);
	}
};