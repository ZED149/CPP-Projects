


#include "Film.h"
#include "Event.h"
#include <iostream>
#include <string>
using namespace std;



// Constructor
// Default Constructor With Params
Film::Film(bool availability, int seating_capacity, string seating_style, string seating_critera, 
	string screen, string event_name, int totalTickets):
	Event(availability, seating_capacity, seating_style, seating_critera, event_name), 
	screen(screen), totalTickets(totalTickets)
{
	//cout << "Film(params) called" << endl;
	this->event_details.push_back(this);
}

// Getters
// Get Screen
string Film::GetScreen()
{
	return this->screen;
}

// Get Total Tickets
int Film::GetTotalTickets()
{
	return this->totalTickets;
}

// Get Event Name
string Film::GetEventName()
{
	return this->unique_event_name;
}

// Member Functions
// Print
void Film::Print()
{
	cout << "--------------------------------------------------------------" << endl;
	cout << "|\tEvent Name --> " << this->unique_event_name << endl;
	cout << "|\tAvailability --> " << boolalpha << this->availability << endl;
	cout << "|\tSeating Capacity --> " << this->seating_capacity << endl;
	cout << "|\tSeating Style --> " << this->seating_style << endl;
	cout << "|\tSeating Criteria --> " << this->seating_criteria << endl;
	cout << "|\tScreen Type --> " << this->screen << endl;
	cout << "|\tTotal Number Of Tickets Purchased Are --> " << this->totalTickets << endl;
	cout << "--------------------------------------------------------------" << endl;
}

// Buy Tickets
void Film::BuyTicket(int numberOfTickets)
{
	// Error check for negative input of number of tickets
	if (numberOfTickets < 0)
	{
		cout << "Tickets number cannot be in negative. Please enter a valid number" << endl;
	}

	// Otherwise
	// First check if we have space or our venue is full
	// NOTE --> Total space is of 200 people at a time

	if (numberOfTickets > 0 && numberOfTickets <= 200)
	{
		int temp = totalTickets + numberOfTickets;
		if (this->totalTickets < 200 && (temp <= 200))
		{
			// Now we can sell tickets
			this->totalTickets += numberOfTickets;
		}
		else if (temp > 200)
		{
			cout << "Cannot buy [" << numberOfTickets << "] tickets. Tickets left are --> " << (200 - totalTickets) << endl;
		}
	}
	else if (numberOfTickets == 0)
	{
		cout << "Cannot purchase '0' tickets. Please enter a valid amount." << endl;
	}
	else if (numberOfTickets > 200)
	{
		cout << "Cannot purchase more than 200 tickets. Please enter a valid amount." << endl;
	}
}

// Cancel Tickets
void Film::CancelTicket(int numberOfTickets)
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
	else if ((totalTickets - numberOfTickets) < 0)
	{
		cout << "Cannot cancel [" << numberOfTickets << "] tickets. Tickets purchased are --> " << totalTickets << " tickets." << endl;
	}
	else if (numberOfTickets < 0)
	{
		cout << "Cannot cancel [" << numberOfTickets << "] tickets. Please enter a valid amount" << endl;
	}
}

// Destructor
Film::~Film()
{
	//cout << "~Film() called" << endl;
	Event::DeleteFromEventDetails(this->unique_event_name);
}