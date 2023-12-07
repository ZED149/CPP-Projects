

#pragma once


#include <iostream>
#include <string>
using namespace std;

// This is the Person Class
class Person
{
	string fullName;
	int phoneNumber, age;

public:	// This is where the member goes
	// Constructor
	// Default Constructor with Params
	Person(string fullName = "NILL", int phoneNumber = 000, int age = -1);

	// Getters
	// Get Age
	int GetAge();

	// Get Name
	string GetName();

	// Get Phone Number
	int GetPhoneNumber();

	// Operator Overloading
	// Equal Operator
	bool operator == (const Person& obj) const;

	// Member Functions
	// Print Details
	void PrintDetails();

	// Destructor
	~Person();
};