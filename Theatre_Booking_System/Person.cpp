

#include <iostream>
#include <string>
#include "Person.h"
using namespace std;



// Constructor
// Default Constructor With Params
Person::Person(string fullName, int phoneNumber, int age):
	fullName(fullName), phoneNumber(phoneNumber), age(age)
{
	//cout << "Person(params) called" << endl;
}

// Getters
// Get Age
int Person::GetAge()
{
	return this->age;
}

// Get Name
string Person::GetName()
{
	return this->fullName;
}

// Get Phone Number
int Person::GetPhoneNumber()
{
	return this->phoneNumber;
}

// Operator Overloading
// Equal Operator
bool Person::operator==(const Person& obj) const
{
	if (this->fullName == obj.fullName &&
		this->phoneNumber == obj.phoneNumber &&
		this->age == obj.age)
	{
		return true;
	}
	else
		return false;
}

// Member Functions
// Print Details
void Person::PrintDetails()
{
	cout << "|\tFULL NANE --> " << this->fullName;
	cout << "\tPHONE NUMBER --> " << this->phoneNumber;
	cout << "\tAGE --> " << this->age;
}

// Destructor
Person::~Person()
{
	//cout << "~Person() called" << endl;
}