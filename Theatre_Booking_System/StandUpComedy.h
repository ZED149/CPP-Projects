
#pragma once



#include <iostream>
#include <vector>
#include <string>
#include "Person.h"
#include "PSH.h"
#include "Event.h"
#include "Seat.h"
using namespace std;


/*	This is the Stand Up Comedy Class
*	It is Derived from Event Class
*/
class StandUpComedy : public Event
{
	vector<PSH> seating_array;

public:	// This is where the member goes
	// Constructor
	// Default Constructor with Params
	StandUpComedy(bool availability = false, int seating_capacity = 0, string seating_style = "NILL"
		, string seating_criteria = "NILL", string event_name = "NILL");

	// Getters
	// Get Seating Array Reference
	vector<PSH>& GetSeatingArrayReference();

	// Get Event Name
	string GetEventName();

	// Member Functions
	void Print();

	// Reserve Seat
	void ReserveSeat(Person &_person, Seat &seatNumber);

	// Cancel Seat
	void CancelSeat(Person &_person, Seat &seatNumber);

	// Destructor
	virtual ~StandUpComedy();
};