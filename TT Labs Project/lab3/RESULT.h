
// This file contains the RESULT class

#pragma once

#include "UNIT.h"

// starting from here
#ifndef RESULT_H
#define RESULT_H
class Result
{
	// private data members
	UNIT u;			// Unit objext
	unsigned mark;	// object to store marks for that course

	// operator overloading
	// output operator
	friend ostream& operator << (ostream& out, const Result &r);

	// input operator
	friend istream& operator >> (istream& in, Result& r);

public:	// This is where the member goes
	// Default Constructor
	Result();

	// Constructor with params
	Result(unsigned mark, UNIT u);

	// Getters
	// GetCredits
	inline unsigned GetCredits() const
	{
		return this->u.GetCredits();
	}
};

#endif