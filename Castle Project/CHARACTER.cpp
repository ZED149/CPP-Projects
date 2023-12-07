

#include "CHARACTER.h"
#include <iostream>
using namespace std;


// Constructor
// Default Constructor
Character::Character() {};

// Constructor with params
Character::Character(char id, int current_room)
{
	//cout << "Character(params) called" << endl;
	this->id = id;
	this->current_room = current_room;
}


// Getters

// Get Current Room
int Character::GetCurrentRoom()
{
	return this->current_room;
}

// Setters

// Set Cuurent Room
void Character::SetCurrentRoom(int current_room)
{
	this->current_room = current_room;
}

// Set ID
void Character::SetId(char id)
{
	this->id = id;
}