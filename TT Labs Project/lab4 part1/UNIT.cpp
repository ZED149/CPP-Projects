

#include "UNIT.h"
#include <iostream>
using namespace std;



// Constructors
// Default Constructor
UNIT::UNIT()
{
	cout << "UNIT() called" << endl;
	this->crh = 0;
	name = "";
	id[0] = '\0';
}

// Constructor with params
UNIT::UNIT(char* name, char* id, unsigned int crh)
{
	cout << "UNIT(params) called" << endl;
	strcpy_s((char*)this->name.c_str(), strlen(name) + 1, name);
	strcpy_s(this->id, strlen(id) + 1, id);
	this->crh = crh;
}


// Operator Overloading
// Output operator
ostream& operator << (ostream& out, const UNIT& U)
{
	out << "\tUnit ID: " << U.id << endl
		<< "\tUnit Name: " << U.name.c_str() << endl
		<< "\tCredits: " << U.crh << endl;

	return out;
}

// Input operator
istream& operator >> (istream& in, UNIT& U)
{
	char buffer[500];
	in.getline(buffer, 500, ',');
	U.name.assign(buffer);
	//in.getline((char*)U.name.c_str(), 100, ',');
	in >> U.id >> U.crh;
	return in;
}

// Getters
// Get Credit