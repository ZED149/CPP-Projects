
#pragma once


// This file contains the PRINCESS class
// It will inherit some basic characteristics from CHARACTER class

#include "CHARACTER.h"

class Princess : public Character
{
	// Utility Functions
	
	// intialize
	void initialize(char id, int current_room);
public:	// This is where the member goes
	// Constructor 
	// Default Constructor
	Princess();

	// Constrcutor with params
	Princess(char id, int current_room);

	// Member Functions

	// Initialize
	void Initialize(char id, int current_room);

	// Print Room and Id
	void PrintRoomAndId(int current_room);
};