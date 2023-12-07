

#include "Event.h"
#include "StandUpComedy.h"
#include <iostream>
#include "Person.h"
#include <string>
#include "Seat.h"
using namespace std;



// Constructor
// Default Constructor With Params
StandUpComedy::StandUpComedy(bool availability, int seating_capacity, string seating_style,
	string seating_criteria, string event_name): 
	Event(availability, seating_capacity, seating_style, seating_criteria, event_name)
{
	//cout << "StandUpComedy() called" << endl;
	this->event_details.push_back((this));
}

// Getters
// Get Seating Array Reference
vector<PSH>& StandUpComedy::GetSeatingArrayReference()
{
	return this->seating_array;
}

string StandUpComedy::GetEventName()
{
	return this->unique_event_name;
}

// Member Functions
// Print
void StandUpComedy::Print()
{
	if (this->seating_array.size() > 0)
	{
		cout << "--------------------------------------------------------------" << endl;
		cout << "|\tEvent Name is --> " << this->unique_event_name << endl;
		cout << "|\tAvailability --> " << boolalpha << this->availability << endl;
		cout << "|\tSeating Capacity --> " << this->seating_capacity << endl;
		cout << "|\tSeating Style --> " << this->seating_style << endl;
		cout << "|\tSeating Criteria --> " << this->seating_criteria << endl;

		// Printing Reserved Seats
		cout << "|\tReserved Seats Are As Follows --> " << endl;
		vector<PSH>::iterator seating_array_traversor = this->seating_array.begin();
		while (seating_array_traversor != this->seating_array.end())
		{
			(*seating_array_traversor).PrintAllDetails();
			cout << endl;
			seating_array_traversor++;
		}
		cout << "|\tTotal Seats Reserved Are --> " << this->seating_array.size() << endl;
		cout << "--------------------------------------------------------------" << endl;
	}
	else
		cout << "Nothing to Print..." << endl;
}

// Reserve Seat
void StandUpComedy::ReserveSeat(Person &_person, Seat &seatNumber)
{
	if (seatNumber.GetSeatNumber() >= 1 && seatNumber.GetSeatNumber() <= 200)
	{
		// First check whetehr this exist in array or not
		// checking
		vector<PSH>::iterator seating_array_traversor = this->seating_array.begin();
		while (seating_array_traversor != this->seating_array.end())
		{
			if ((*seating_array_traversor).GetSeatBooked() == seatNumber)
			{
				cout << "Error" << endl;
				cout << "Seat Already Allocated" << endl;
				cout << "Please chose a different seat number" << endl;
				return;
			}
			seating_array_traversor++;
		}

		// if it is not present in the array
		PSH temp(&_person, &seatNumber);
		this->seating_array.push_back(temp);
		int a = 1;
	}
	else
		cout << "Invalid Seat Number [1-200], your chosen seat number [" << seatNumber.GetSeatNumber() << "]" <<  endl;

}

// Cancel Seat
void StandUpComedy::CancelSeat(Person &_person, Seat &seatNumber)
{
	// First we check if the seatNumber exits or not
	// if it exists, we cancel it
	// otherwise it is an invalid number

	if (this->seating_array.size() > 0)
	{
		if (seatNumber.GetSeatNumber() >= 1 && seatNumber.GetSeatNumber() <= 200)
		{
			// First check whetehr this exist in array or not
			// checking
			vector<PSH>::iterator seating_array_traversor = this->seating_array.begin();
			while (seating_array_traversor != this->seating_array.end())
			{
				if ((*seating_array_traversor).GetSeatBooked() == seatNumber)
				{
					// removing the value if it is found
					this->seating_array.erase(seating_array_traversor);
					return;
				}
				seating_array_traversor++;
			}

			//If loops ends without returning, then the number is not present in the vector
			// we need to prompt for an error message for the user
			cout << "Error! Seat Number not present, Please Try Again..." << endl;
			cout << "Your chosen seat number is --> [" << seatNumber.GetSeatNumber() << "]" << endl;
		}
		else
			cout << "Invalid Seat Number [1-200], your chosen seat number [" << seatNumber.GetSeatNumber() << "]" << endl;
	}
	else
	{
		cout << "NOTHING TO DELETE..." << endl;
	}
}

// Destrcutor
StandUpComedy::~StandUpComedy()
{
	//cout << "~StandUpComdey() called" << endl;
}