
#pragma once
#include <iostream>
#include "WEAPON.h"
#include "PERIL.h"
using namespace std;

// This file contains the ROOM class


class Room
{
	string name;	// stores the name of the room
	unsigned id;	// stores the ID of the room
	int navigation_array[4];	// stores which room can be accessed using this room
	Weapon random_weapon;	// Contains the random weapon present in that room
	Peril random_peril;	// contains the random peril present in that room
	int navigation_array_cache[13][4];	// stores the all possible ways to move from a room


	// Utility Functions
	void initialize(string name, unsigned id, int navigation_array[4]);

public:	// This is where the member goes
	// Constructor
	// Default Constructor
	Room();
	// Constructor with params
	Room(string name, unsigned id, int navigation_array[4]);

	// Getters

	// Get Random Weapon
	int GetRandomWeapon();

	// Get Random Peril
	int GetRandomPeril();

	// Get Possible Directions
	int* GetPossibleDirections(int current_room);


	// Member Functions

	// Initialize
	void Initialize(string name, unsigned id, int navigation_array[4]);

	// Print Weapon
	void PrintWeapon();

	// Possible Directions
	void PossibleDirections(int current_room);

	// Print Currnet Peril
	void PrintCurrentPeril(int current_peril);

	// Setters

	// Set Navigation Array
	void SetNavigationArray(int current_room);
};

