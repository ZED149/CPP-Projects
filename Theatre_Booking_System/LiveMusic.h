

#pragma once
#include "Event.h"


/*  This is the Live Music Class
	This is a dervied class from Event Class*/

class LiveMusic : public Event
{
	int totalTickets;

public: // This is where the member goes

	// Constructor
	// Default Constructor
	LiveMusic();

	// Constructor With Params
	LiveMusic(bool, int, string, string, string, int total_tickets = 0);

	// Getters
	// Get Total Tickets
	int GetTotalTickets();

	// Get Event Name
	string GetEventName();

	// Member Functions
	// Print
	void Print();

	// Buy Ticket
	// Enter Number Of Tickets One Wants To Purchase
	void BuyTicket(int numberOfTickets);

	// Cancel Tickets
	// Enter Number Of Tickets One Wants To Cancel
	void CancelTicket(int numberOfTickets);

	// Destructor
	virtual ~LiveMusic();
};