
#pragma once


// This file contains the CASTLE class
#include "ROOM.h"
#include "HERO.h"
#include "PRINCESS.h"

class Castle
{
	Room rooms[13];	// contains 13 rooms
	Hero hero;
	Princess princess;

	// Utility Functions
	// Initialize
	void initialize();

	// Make Random Location
	int make_random_location();

	// Find Hero Room
	void find_hero_room(int id);

	// Pick a Valid Direction
	void pick_a_valid_direction();

public: // This is where the member goes
	// Constructor
	// Default Constructor
	Castle();

	// Member Functions

	// Initialize
	void Initialize();

	// Print
	void Print();

	// Start
	void Start();

};