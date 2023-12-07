


#include "LiveMusic.h"
#include "Event.h"
#include <iostream>
#include <string>
using namespace std;




// Constructors
// Default Constructor
LiveMusic::LiveMusic()
{
	//cout << "LiveMusic() called" << endl;
	this->totalTickets = 0;
	this->unique_event_name = "NILL";
}

// Constructor With Params
LiveMusic::LiveMusic(bool availability, int seating_capacity, string seating_style, string seating_criteria,
	string event_name, int total_tickets): 
	Event(availability, seating_capacity, seating_style, seating_criteria, event_name)
{
	this->totalTickets = total_tickets;
	this->event_details.push_back((this));
}

// Getters
// Get Total Tickets
int LiveMusic::GetTotalTickets()
{
	return this->totalTickets;
}

// Get Event Name
string LiveMusic::GetEventName()
{
	return this->unique_event_name;
}

// Member Functions
// Print
void LiveMusic::Print() 
{
	cout << "--------------------------------------------------------------" << endl;
	cout << "|\tEvent Name is --> " << this->unique_event_name << endl;
	cout << "|\tAvailability --> " << boolalpha << this->availability<< endl;
	cout << "|\tSeating Capacity --> " << this->seating_capacity << endl;
	cout << "|\tSeating Style --> " << this->seating_style << endl;
	cout << "|\tSeating Criteria --> " << this->seating_criteria << endl;
	cout << "|\tTotal Tickets Sold Are --> " << this->totalTickets << endl;
	cout << "--------------------------------------------------------------" << endl;
}

// Buy Ticket
void LiveMusic::BuyTicket(int numberOfTickets)
{
	// Error checking for a negative number of tickets
	if (numberOfTickets < 0)
	{
		cout << "Cannot buy [" << numberOfTickets << "] tickets. Please enter a valid amount" << endl;
		return;
	}


	// First check if we have space or our venue is full
	// NOTE --> Total space is of 300 people at a time

	if (numberOfTickets > 0 && numberOfTickets <= 300)
	{
		int temp = totalTickets + numberOfTickets;
		if (this->totalTickets < 300 && (temp <= 300))
		{
			// Now we can sell tickets
			this->totalTickets += numberOfTickets;
		}
		else if (temp > 300)
		{
			cout << "Cannot buy [" << numberOfTickets << "] tickets. Tickets left are --> " << (300 - totalTickets) << endl;
		}
	}
	else if (numberOfTickets == 0)
	{
		cout << "Cannot purchase '0' tickets. Please enter a valid amount." << endl;
	}
	else if (numberOfTickets > 300)
	{
		cout << "Cannot purchase more than 300 tickets. Please enter a valid amount." << endl;
	}
}

// Cancel Tickets
void LiveMusic::CancelTicket(int numberOfTickets)
{
	// Error checking for a negative number of tickets
	if (numberOfTickets < 0)
	{
		cout << "Cannot cancel [" << numberOfTickets << "] tickets. Please enter a valid amount" << endl;
		return;
	}


	// First we need to check whether there are as many tickets available than one wants to cancel
	// and total tickets are not ZERO

	int temp = totalTickets - numberOfTickets;
	if (totalTickets > 0 && (temp >= 0))
	{
		totalTickets -= numberOfTickets;
	}
	else if((totalTickets - numberOfTickets) < 0)
	{
		cout << "Cannot cancel [" << numberOfTickets << "] tickets. Tickets purchased are --> " << totalTickets << " tickets." << endl;
	}
	else if (numberOfTickets < 0)
	{
		cout << "Cannot cancel [" << numberOfTickets << "] tickets. Please enter a valid amount" << endl;
	}
}

// Destructor
LiveMusic::~LiveMusic()
{
	//cout << "~LiveMusic() called" << endl;
}