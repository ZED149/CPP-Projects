

#pragma once



// This is the seat class
class Seat
{
	int seatNumber;

public:	// This is where the member goes
	// Default Constructor with params
	Seat(int seat = -1);

	// Getters
	// Get Seat Number
	int GetSeatNumber();

	// Operator Overloading
	// Equal Operator
	bool operator == (const Seat& obj)const;

	// Member Functions
	// Print Details
	void PrintDetails();

	// Destructor
	~Seat();
};