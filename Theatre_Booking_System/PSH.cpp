


#include <iostream>
#include "PSH.h"
#include "Person.h"
#include "Seat.h"
using namespace std;



// Constructor
// Default Constructor
PSH::PSH()
{
	//cout << "PSH() called" << endl;
	this->_personDetail = nullptr;
	this->_seatBooked = nullptr;
}

// Constructor with Params
PSH::PSH(Person* _personDetail, Seat* _seatBooked)
{
	//cout << "PSH(params) called" << endl;
	this->_personDetail = _personDetail;
	this->_seatBooked = _seatBooked;
}

// Getters
// Get Person Detail
Person& PSH::GetPersonDetail()
{
	return *(this->_personDetail);
}

// Get Seat Booked
Seat& PSH::GetSeatBooked()
{
	return *(this->_seatBooked);
}

// Member Functions
// Print All Details
void PSH::PrintAllDetails()
{
	this->_personDetail->PrintDetails();
	cout << "\t";
	this->_seatBooked->PrintDetails();
}

// Destructor
PSH::~PSH()
{
	//cout << "~PSH() called" << endl;
	/*delete this->_seatBooked;   
	delete this->_personDetail;*/
	this->_seatBooked = nullptr;
	this->_personDetail = nullptr;
}