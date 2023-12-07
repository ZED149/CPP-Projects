

#include "UNIT.h"
#include <iostream>
using namespace std;



// Constructors
// Default Constructor
UNIT::UNIT()
{
	cout << "UNIT() called" << endl;
	this->crh = 0;
	name[0] = '\0';
	id[0] = '\0';
}

// Constructor with params
UNIT::UNIT(char* name, char* id, unsigned int crh)
{
	cout << "UNIT(params) called" << endl;
	strcpy_s(this->name, strlen(name) + 1,  name);
	strcpy_s(this->id, strlen(id) + 1, id);
	this->crh = crh;
}


// Operator Overloading
// Output operator
ostream& operator << (ostream& out, const UNIT& U)
{
	out << "\tUnit ID: " << U.id << endl
		<< "\tUnit Name: " << U.name << endl
		<< "\tCredits: " << U.crh << endl;

	return out;
}

// Input operator
istream& operator >> (istream& in, UNIT& U)
{
	in >> U.name >> U.id >> U.crh;
	return in;
}

// Getters
// Get Credit