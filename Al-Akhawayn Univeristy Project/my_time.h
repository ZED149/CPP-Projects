

// Q1


#pragma once


#include <iostream>
// This file contains the my_time class


struct MyTime
{
	// private variables
	int hours;		// to store hours
	int minutes;	// to store minutes
	int seconds;	// to store seconds

public:	// This is where the member goes
	// Constructor
	// Default Constructor
	MyTime() 
	{
		std::cout << "MyTime() called" << std::endl;
		this->hours = this->minutes = this->seconds = 0;
	};
};