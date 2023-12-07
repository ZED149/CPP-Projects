
#pragma once


// This file contains the Character class
// Character class is the base class that can be used to inherit for different characters in game

class Character
{
	char id;	// stores ID of the character
	int current_room;	// stores current room of the character

public:	// This is where the member goes
	// Constructor
	// Default Constructor
	Character();

	// Constructor with params
	Character(char id, int current_room);

	// Getters

	// Get Current Room
	int GetCurrentRoom();

	// Setters

	// Set Current Room
	void SetCurrentRoom(int current_room);

	// Set ID
	void SetId(char id);
};