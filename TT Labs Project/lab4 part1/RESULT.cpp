


#include "RESULT.h"
#include <iostream>
using namespace std;


// Constructors
// Default Constructor
Result::Result()
{
	cout << "Result() called" << endl;
	this->mark = 0;
}

// Constructor with params
Result::Result(unsigned mark, UNIT u)
{
	cout << "Result(params) called" << endl;
	this->mark = mark;
	this->u = u;
}

// Operator Overloading
// Output operator
ostream& operator << (ostream& out, const Result& r)
{
	out << r.u
		<< "\tMarks: " << r.mark << endl
		<< r.d << endl;

	return out;
}

istream& operator >> (istream& in, Result& r)
{
	in >> r.d >> r.mark >> r.u;

	return in;
}