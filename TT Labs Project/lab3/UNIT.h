
#pragma once
#include <iostream>
using namespace std;


// This the UNIT class
// Declaring some global variables
const unsigned Max_Name_Size = 100;
const unsigned Max_Id_Size = 10;

#ifndef UNIT_H
#define UNIT_H

// Class starting from here
class UNIT
{
	// private data members
	char name[Max_Name_Size];
	char id[Max_Id_Size];
	unsigned int crh;

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