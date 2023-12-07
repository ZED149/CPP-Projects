

#include "Seat.h"
#include <iostream>
using namespace std;



// Constructor
// Default Constructor
Seat::Seat(int seatNumber) :
	seatNumber(seatNumber)
{
	//cout << "Seat(params) called" << endl;
}

// Getters
// Get Seat Number
int Seat::GetSeatNumber()
{
	return this->seatNumber;
}

// Operator Overloading
// Equal Operator
bool Seat::operator== (const Seat& obj)const
{
	if (this->seatNumber == obj.seatNumber)
		return true;
	else
		return false;
}

// Member Functions
// Print Details
void Seat::PrintDetails()
{
	cout << "Seat Booked -- > " << this->seatNumber;
}

// Destructor
Seat::~Seat()
{
	//cout << "~Seat() called" << endl;
}