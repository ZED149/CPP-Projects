



#pragma once
#include <iostream>
#include <string>
#include "Event.h"
using namespace std;


// This is the File Class
// It will inherit from Event class




class Film : public Event
{
	string screen;
	int totalTickets;
public:	// This is where the menber goes
	// Constructor
	// Default Constructor with params
	Film(bool availability = false, int seating_capacity = 0, string seating_style = "NILL",
		string seating_critera = "NILL", string screen = "NILL", string event_name = "NILL",
		int totalTickets = 0);

	// Getters
	// Get Screen
	string GetScreen();

	// Get Total Tickets
	int GetTotalTickets();
	
	// Get Event Name
	string GetEventName();

	// Member Functions
	// Print
	void Print();

	// Buy Ticket
	// One Should Enter The Number Of Tickets That One Wants To Purchase
	void BuyTicket(int numberOfTickets);

	// Cancel Ticket
	// One Should Enter The Number Of Tickets That One Wants To Cancel
	void CancelTicket(int numberOfTickets);

	// Destructor
	virtual ~Film();
};