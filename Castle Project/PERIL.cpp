

#include "PERIL.h"
#include <iostream>
using namespace std;


// Constructor
// Default Constructor
Peril::Peril()
{
	//cout << "Peril() called" << endl;
	this->id = 0;
}


// Constructor with params
Peril::Peril(unsigned id)
{
	//cout << "Peril(params) called" << endl;
	this->id = id;
}


// Setters

// Set Peril Id
void Peril::SetPerilId(int id)
{
	this->id = id;
}

// Getters

// Get Peril ID
int Peril::GetPerilId()
{
	return this->id;
}