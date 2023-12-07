

#pragma once

#include <iostream>
using namespace std;


// This file contains the DATE class


// class starts from here
#ifndef DATE_H
#define DATE_H
class Date
{
	// private data members
	string date;	// This object holds the DATE e.g (30 December 2016)

public:	// This is where the member goes
	// Constructors
	// Default Constructor
	Date();

	// Getters
	// Setters
	// Operator overloading
	// Output operator
	friend ostream& operator << (ostream& out, const Date& d);

	// Input operator
	friend istream& operator >> (istream& in, Date& d);
};

#endif