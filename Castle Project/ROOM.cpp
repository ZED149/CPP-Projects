


#include "ROOM.h"
#include <iostream>
using namespace std;



// Utility Functions

// initalize
void Room::initialize(string name, unsigned id, int navigation_array[4])
{
	this->name = name;
	this->id = id;
	copy(navigation_array, navigation_array + 4, this->navigation_array);
}



// Constructor
// Default Constructor
Room::Room()
{
	//cout << "Room() called" << endl;
	//srand(time(NULL));
	int temp = (rand() % 5) + 0;	// gives random weapon ID b/w [0-5] always
	this->random_weapon.SetWeaponId(temp);

	//srand(time(NULL));
	temp = (rand() % 5) + 0;	// gives random peril ID b/w [0-5] always
	this->random_peril.SetPerilId(temp);

	// I need to populate navigation array cache
	int small_hall_navigation[4] = { 7,2,0,0 };
	int throne_room_navigation[4] = { 5,3,0,1 };
	int dungeon_room_navigation[4] = { 0,0,0,2 };
	int queens_room_navigation[4] = { 0,0,0,5 };
	int bathroom_navigation[4] = { 10,4,2,0 };
	int pantry_navigation[4] = { 0,0,0,7 };
	int kitchen_navigation[4] = { 0,6,1,0 };
	int king_room_navigation[4] = { 0,9,0,0 };
	int great_hall_navigation[4] = { 12,10,0,8 };
	int loo_navigation[4] = { 0,11,5,9 };
	int library_navigation[4] = { 0,0,0,10 };
	int tower_navigation[4] = { 13,0,9,0 };
	int princess_room_navigation[4] = { 0,0,12,0 };

	for (int i = 0; i < 13; i++)
	{
		if (i == 0)
			copy(small_hall_navigation, small_hall_navigation + 4, this->navigation_array_cache[i]);
		else if (i == 1)
			copy(throne_room_navigation, throne_room_navigation + 4, this->navigation_array_cache[i]);
		else if (i == 2)
			copy(dungeon_room_navigation, dungeon_room_navigation + 4, this->navigation_array_cache[i]);
		else if (i == 3)
			copy(queens_room_navigation, queens_room_navigation + 4, this->navigation_array_cache[i]);
		else if (i == 4)
			copy(bathroom_navigation, bathroom_navigation + 4, this->navigation_array_cache[i]);
		else if (i == 5)
			copy(pantry_navigation, pantry_navigation + 4, this->navigation_array_cache[i]);
		else if (i == 6)
			copy(kitchen_navigation, kitchen_navigation + 4, this->navigation_array_cache[i]);
		else if (i == 7)
			copy(king_room_navigation, king_room_navigation + 4, this->navigation_array_cache[i]);
		else if (i == 8)
			copy(great_hall_navigation, great_hall_navigation + 4, this->navigation_array_cache[i]);
		else if (i == 9)
			copy(loo_navigation, loo_navigation + 4, this->navigation_array_cache[i]);
		else if (i == 10)
			copy(library_navigation, library_navigation + 4, this->navigation_array_cache[i]);
		else if (i == 11)
			copy(tower_navigation, tower_navigation + 4, this->navigation_array_cache[i]);
		else if (i == 12)
			copy(princess_room_navigation, princess_room_navigation + 4, this->navigation_array_cache[i]);
	}
}


// Constructor with params
Room::Room(string name, unsigned id, int navigation_array[4])
{
	//cout << "Room(params) called" << endl;
	this->name = name;
	this->id = id;
	copy(navigation_array, navigation_array + 4, this->navigation_array);
	srand(time(NULL));
	int temp = (rand() % 5) + 0;	// gives random weapon ID b/w [0-5] always
	this->random_weapon.SetWeaponId(temp);

	//srand(time(NULL));
	temp = (rand() % 5) + 0;	// gives random peril ID b/w [0-5] always
	this->random_peril.SetPerilId(temp);
}


// Getters

// Get Random Weapon
int Room::GetRandomWeapon()
{
	return this->random_weapon.GetWeaponId();
}

int Room::GetRandomPeril()
{
	return this->random_peril.GetPerilId();
}


// Get Possible Directions
int* Room::GetPossibleDirections(int current_room)
{
	auto print = [](int a)
	{
		switch (a)
		{
		case 0:
			return 0;
			break;
		case 1:
			return 1;
			break;
		case 2:
			return 2;
			break;
		case 3:
			return 3;
			break;
		case 4:
			return 4;
			break;
		case 5:
			return 5;
			break;
		case 6:
			return 6;
			break;
		case 7:
			return 7;
			break;
		case 8:
			return 8;
		case 9:
			return 9;
			break;
		case 10:
			return 10;
			break;
		case 11:
			return 11;
			break;
		case 12:
			return 12;
			break;
		case 13:
			return 13;
			break;
		};
	};

	int *temp = new int[4];
	for (int i = 0; i < 4; i++)
	{
		if (i == 0)
		{
			// Top
			temp[0] = print(this->navigation_array_cache[current_room][i]);
			cout << endl;
		}
		else if (i == 1)
		{
			// Right
			temp[1] = print(this->navigation_array_cache[current_room][i]);
		}
		else if (i == 2)
		{
			// Bottom
			temp[2] = print(this->navigation_array_cache[current_room][i]);
		}
		else if (i == 3)
		{
			// Left
			temp[3] = print(this->navigation_array_cache[current_room][i]);
		}
	}

	return temp;
}


// Initialize
void Room::Initialize(string name, unsigned id, int navigation_array[4])
{
	this->initialize(name, id, navigation_array);
}

// Print Weapon
void Room::PrintWeapon()
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
			cout << "No weapon is present (0)";
	};

	print(this->random_weapon.GetWeaponId());
}


// Possible Directions
void Room::PossibleDirections(int current_room)
{
	auto print = [](int a)
	{
		switch (a)
		{
		case 0:
			cout << "Cannot Move" << endl;
			break;
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
		if (i == 0)
		{
			// Top
			cout << "North is: ";
			print(this->navigation_array_cache[current_room][i]);
			cout << endl;
		}
		else if (i == 1)
		{
			// Right
			cout << "East is: ";
			print(this->navigation_array_cache[current_room][i]);
			cout << endl;
		}
		else if (i == 2)
		{
			// Bottom
			cout << "South is: ";
			print(this->navigation_array_cache[current_room][i]);
			cout << endl;
		}
		else if (i == 3)
		{
			// Left
			cout << "West is: ";
			print(this->navigation_array_cache[current_room][i]);
			cout << endl;
		}
	}
}


// Print Current Peril
void Room::PrintCurrentPeril(int current_peril)
{
	auto print = [](int a) {
		if (a == 1)
			cout << "Dragon (1)";
		else if (a == 2)
			cout << "Spider (2)";
		else if (a == 3)
			cout << "Wasps (3)";
		else if (a == 4)
			cout << "Enchantress (4)";
		else if (a == 5)
			cout << "Belly-Fish (5)";
		else if (a == 0)
			cout << "No peril is present";
	};

	cout << "Current Peril is: ----> ";
	print(current_peril);
	cout << endl;
}


// Setters

// Set Navigation Array
void Room::SetNavigationArray(int current_room)
{
	copy(this->navigation_array_cache[current_room], this->navigation_array_cache[current_room] + 4, this->navigation_array);
}
