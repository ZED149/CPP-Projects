


#include "HERO.h"
#include <iostream>
#include "CHARACTER.h"
using namespace std;


// Utility Functions

// initialize
void Hero::initialize(char id, int current_room, int inventory_size, int carried_weapon_list[3])
{
	this->SetId(id);
	this->SetCurrentRoom(current_room);
	this->inventory_size = inventory_size;
	copy(carried_weapon_list, carried_weapon_list + 3, this->carried_weapon_list);
	this->carried_weapon = this->carried_weapon_list[0];
}

// Constructor
// Default Constructor
Hero::Hero() 
{
	this->fighting_stats_counter = 0;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 2; j++)
			this->fighting_stats[i][j] = 0;
};

// Constructor with params
Hero::Hero(char id, int current_room, int inventory_size, int carried_weapon_list[3]) :
	Character(id, current_room)
{
	//cout << "Hero(params) called" << endl;
	copy(carried_weapon_list, carried_weapon_list + 3, this->carried_weapon_list);
	this->carried_weapon = this->carried_weapon_list[0];
	this->inventory_size = inventory_size;
	this->fighting_stats_counter = 0;

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 2; j++)
			this->fighting_stats[i][j] = 0;
}


// Member Functions

// Print Inventory
void Hero::PrintInventory()
{
	auto print = [](int a) {
		if (a == 1)
			cout << "Sword";
		else if (a == 2)
			cout << "Stave";
		else if (a == 3)
			cout << "Fly-Spray";
		else if (a == 4)
			cout << "Magic Potion";
		else if (a == 5)
			cout << "Flamegun";
		else if (a == 0)
			cout << "No Weapon";
	};

	for (int i = 0; i < 3; i++)
	{
		cout << this->carried_weapon_list[i] << " ----> ";
		print(this->carried_weapon_list[i]);
		cout << endl;
	}
}


// Possible Directions
void Hero::PossibleDirections()
{
	auto print = [](int a)
	{
		switch (a)
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
		};
	};


	for (int i = 0; i < 4; i++)
	{
		if (i == 1)
		{
			// Top
			cout << "Top is: ";
			print(i);
			cout << endl;
		}
		else if (i == 2)
		{
			// Right
			cout << "Right is: ";
			print(i);
			cout << endl;
		}
		else if (i == 3)
		{
			// Bottom
			cout << "Bottom is: ";
			print(i);
			cout << endl;
		}
		else if (i == 4)
		{
			// Left
			cout << "Left is: ";
			print(i);
			cout << endl;
		}
	}
}


// Drop First Weapon
void Hero::DropFirstWeapon()
{
	this->carried_weapon_list[0] = 0;
	--this->inventory_size;
	this->carried_weapon = this->carried_weapon_list[0];
}


// Initialize
void Hero::Initialize(char id, int current_room, int inventory_size, int carried_weapon_list[3])
{
	this->initialize(id, current_room, inventory_size, carried_weapon_list);
}


// Print Carried Weapon
void Hero::PrintCarriedWeapon()
{
	auto print = [](int a) {
		if (a == 1)
			cout << "Sword (1)";
		else if (a == 2)
			cout << "Stave (2)";
		else if (a == 3)
			cout << "Fly-Spray (3)";
		else if (a == 4)
			cout << "Magic Potion (4)";
		else if (a == 5)
			cout << "Flamegun (5)";
		else if (a == 0)
			cout << "No weapon (0)";
		else
			cout << "No weapon" << endl;
	};

	cout << "Carried Weapon is: ----> ";
	print(this->carried_weapon);
	cout << endl;
}

// Getters

// Inventory Size
int Hero::GetInventorySize()
{
	return this->inventory_size;
}


// Get Carried Weapon
int Hero::GetCarriedWeapon()
{
	return this->carried_weapon;
}


// Setters

// Set Weapon To Inventory
void Hero::SetWeaponToInventory(int weapon_id)
{
	if (this->inventory_size == 3)
		this->inventory_size--;
	this->carried_weapon_list[this->inventory_size++] = weapon_id;
	this->carried_weapon = this->carried_weapon_list[0];
}


// Set Fightinh Stats
int Hero::SetFightingStats(int weapon_used, int peril_died)
{
	// Populate the value according to Counter;

	// setting weapon
	this->fighting_stats[this->fighting_stats_counter][0] = weapon_used;

	// setting peril
	this->fighting_stats[this->fighting_stats_counter][1] = peril_died;

	// incrementing counter
	this->fighting_stats_counter++;

	// updating his current weapon list
	for (int i = 0; i < 2; i++)
	{
		this->carried_weapon_list[i] = this->carried_weapon_list[i + 1];
	}
	this->carried_weapon_list[2] = 0; // means no weapon is present at last index

	// updating his current weapon
	this->carried_weapon = this->carried_weapon_list[0];

	// Return!
	return this->fighting_stats_counter;
}


// Print Fighting Stats
void Hero::PrintFightingStats()
{
	for (int i = 0; i < 5; i++)
	{
		if(this->fighting_stats[i]!=0)
			for (int j = 0; j < 1; j++)
			{
				cout << "Hero has used " << this->fighting_stats[i][j] << " to kill " << this->fighting_stats[i][j] << endl;
			}
	}
}