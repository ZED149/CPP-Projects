


#include "PRINCESS.h"
#include <iostream>
using namespace std;



// Utility Functions

// initialize
void Princess::initialize(char id, int current_room)
{
	this->SetId(id);
	this->SetCurrentRoom(current_room);
}

// Constructor 
// Default Constructor
Princess::Princess() {};

// Constructor with params
Princess::Princess(char id, int current_room) :
	Character(id, current_room)
{
	//cout << "Princess(params) called" << endl;
}


// Member Functions

// Initialize
void Princess::Initialize(char id, int current_room)
{
	this->initialize(id, current_room);
}


// Print Room and ID
void Princess::PrintRoomAndId(int current_room)
{
	switch (current_room)
	{
	case 1:
		cout << "Small Hall with ID (1)" << endl;
		break;
	case 2:
		cout << "Throne Room with ID (2)" << endl;
		break;
	case 3:
		cout << "Dungeon with ID (3)" << endl;
		break;
	case 4:
		cout << "Queen's Bedroom with ID (4)" << endl;
		break;
	case 5:
		cout << "Bathroom with ID (5)" << endl;
		break;
	case 6:
		cout << "Pantry with ID (6)" << endl;
		break;
	case 7:
		cout << "Kitchen with ID (7)" << endl;
		break;
	case 8:
		cout << "King's Room with ID (8)" << endl;
		break;
	case 9:
		cout << "Great Hall with ID (9)" << endl;
		break;
	case 10:
		cout << "Loo with ID (10)" << endl;
		break;
	case 11:
		cout << "Library with ID (11)" << endl;
		break;
	case 12:
		cout << "Tower with ID (12)" << endl;
		break;
	case 13:
		cout << "Princess Room with ID (13)" << endl;
		break;
	}
}