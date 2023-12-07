
#pragma once
#include <iostream>
using namespace std;


// This the UNIT class
// Declaring some global variables
const unsigned Max_Id_Size = 10;

#ifndef UNIT_H
#define UNIT_H

// Class starting from here
class UNIT
{
	// private data members
	string name;				// holds course name
	char id[Max_Id_Size];		// holds course ID
	unsigned int crh;			// holds course credit hours

	// Operator Overloading
	// overloading stream operators
	// output operator
	friend ostream& operator << (ostream& out, const UNIT& U);
	// input operator
	friend istream& operator >> (istream& in, UNIT& U);

	// Returns number of credits



public:	// This is where the member goes
	// Default constructor
	UNIT();

	// Constructor with params
	UNIT(char* name, char* id, unsigned int crh);

	// Getters
	// GetCredits
	inline unsigned GetCredits() const
	{
		return crh;
	}

	// Setters
	void SetCredits(const unsigned val)
	{
		this->crh = val;
	}

};

#endif