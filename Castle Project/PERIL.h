
#pragma once


// This file contains the PERIL class

// Perils information and their ID's
/*
	-> Dragon		----> 1
	-> Spider		----> 2
	-> Wasps		----> 3
	-> Enchantress	----> 4
	-> Belly-fish	----> 5
*/

class Peril
{
	unsigned id;	// Stores the information of Peril ID

public:	// This is where the member goes
	// Constructor
	// Default Constructor
	Peril();
	// Constructor with params
	Peril(unsigned id);

	// Setters

	// Set Peril ID
	void SetPerilId(int id);

	// Getters

	// Get Peril ID
	int GetPerilId();
};