


#include "DATE.h"
#include <iostream>
#include <string>
using namespace std;


// Constructor 
// Default Constructor
Date::Date()
{
	cout << "Date() called" << endl;
	this->date = "NULL";
}


// Operator overloading
// Output operator
ostream& operator << (ostream& out, const Date& d)
{
	out << "\tDate: " << d.date.c_str();
	return out;
}

// Input operator
istream& operator >> (istream& in, Date& d)
{
	// need to read that newline character so that date can be read accurately
	char buffer[1];
	in.getline(buffer, 1, '\n');

	// reading date in a buffer and storing it into the date object
	char abuffer[50];
	in.getline(abuffer, 50, ',');
	d.date.assign(abuffer);
	return in;
}