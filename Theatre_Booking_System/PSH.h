
#pragma once


#include "Person.h"
#include "Seat.h"

// PSH means Person Seating History
// It contains a pointer of a Person Object
// and the pointer of the seat object it has booked


class PSH
{
	Person* _personDetail;
	Seat* _seatBooked;

public:	// This is where the member goes
	// Constructor
	// Default Constructor
	PSH();

	// Constructor With Params
	PSH(Person* _personDetail, Seat* _seatBooked);

	// Getters
	// Get Person Detail
	Person& GetPersonDetail();

	// Get Seat Booked
	Seat& GetSeatBooked();

	// Member Functions
	// Print All Details
	void PrintAllDetails();

	// Destructor
	~PSH();
};