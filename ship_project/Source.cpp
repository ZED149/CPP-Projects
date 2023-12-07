

#include <iostream>
#include "ship.h"
using namespace std;


// Print Board
void print_board(char map[][10]);

// Initialize Plane
void initialize_plane(char map[][10])
{

	// Initializing all the indexes with a specific character
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			map[i][j] = '@';
		}
	}

	// Now we need to print this map onto the screen
	print_board(map);
}



int main()
{
	int age = 5;
	cout << age << endl;
	cout << "Starting Program" << endl;
	char map[10][10];
	bool bool_array[100];
	initialize_plane(map);

	//creating a ship object
	ship fridget("fridget", 2, map, bool_array);
	ship sub("sub", 3, map, bool_array);
	ship destroyer("destroyer", 3, map, bool_array);
	ship battleship("battleship", 4, map, bool_array);
	ship aircraftcarrier("aircraftcarrier", 5, map, bool_array);

	// Now ships are created and we need to let user pick a number 
	// if number corresponds to any of the ship then its hit (X) else miss (O)

	int target = 0;
	system("cls");
	print_board(map);
	cout << "Enter Number" << endl;

	while (cin >> target)
	{
		if (target == -1)
		{
			cout << "Exiting Program" << endl;
			exit(-1);
		}
		int row = target / 10;
		int col = target % 10;
		if (map[row][col] == 'h')
		{
			cout << "Hit Horizontally" << endl;
			map[row][col] = 'X';
		}
		else if (map[row][col] == 'v')
		{
			cout << "Hit Vertically" << endl;
			map[row][col] = 'X';
		}
		else
		{
			cout << "Miss" << endl;
			map[row][col] = 'O';
		}
		print_board(map);

		Sleep(2000);
		system("cls");
		print_board(map);
		cout << "Enter Number" << endl;
	}
}









// Function Definitons
// Print Board
void print_board(char map[][10])
{
	cout << "\t";
	for (int i = 0; i < 10; i++)
		cout << i << "\t";

	cout << endl << "\t";
	for (int i = 0; i < 10; i++)
		cout << "|" << "\t";

	/*cout << endl;
	for (int i = 0; i < 10; i++)
		cout << "v" << "\t";*/

	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << i << "-->\t";
		for (int j = 0; j < 10; j++)
		{
			cout << map[i][j] << "\t";
		}
		cout << endl << endl;;
	}
}