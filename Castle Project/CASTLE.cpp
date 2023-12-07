


#include "CASTLE.h"
#include <iostream>
#include "ROOM.h"
#include <Windows.h>
#include <cstdlib>
#include <time.h>
#include "HERO.h"
#include "PRINCESS.h"
#include <map>
using namespace std;

// Utility Functions

// initalize
void Castle::initialize()
{
	// we have 13 rooms array in our castle
	// we just need to put data in them

	int small_hall_navigation[4] = { 7,2,0,0 };
	this->rooms[0].Initialize("Small Hall", 1, small_hall_navigation);

	int throne_room_navigation[4] = { 5,3,0,1 };
	this->rooms[1].Initialize("Throne Room", 2, throne_room_navigation);

	int dungeon_room_navigation[4] = { 0,0,0,2 };
	this->rooms[2].Initialize("Dungeon", 3, dungeon_room_navigation);

	int queens_room_navigation[4] = { 0,0,0,5 };
	this->rooms[3].Initialize("Queen's Bedroom", 4, queens_room_navigation);

	int bathroom_navigation[4] = { 10,4,2,0 };
	this->rooms[4].Initialize("Bathroom", 5, bathroom_navigation);

	int pantry_navigation[4] = { 0,0,0,7 };
	this->rooms[5].Initialize("Pantry", 6, pantry_navigation);

	int kitchen_navigation[4] = { 0,6,1,0 };
	this->rooms[6].Initialize("Kitchen", 7, kitchen_navigation);

	int king_room_navigation[4] = { 0,9,0,0 };
	this->rooms[7].Initialize("King's Bedroom", 8, king_room_navigation);

	int great_hall_navigation[4] = { 12,10,0,8 };
	this->rooms[8].Initialize("Great Hal", 9, great_hall_navigation);

	int loo_navigation[4] = { 0,11,5,9 };
	this->rooms[9].Initialize("Loo", 10, loo_navigation);

	int library_navigation[4] = { 0,0,0,10 };
	this->rooms[10].Initialize("Library", 11, library_navigation);

	int tower_navigation[4] = { 13,0,9,0 };
	this->rooms[11].Initialize("Tower", 12, tower_navigation);

	int princess_room_navigation[4] = { 0,0,12,0 };
	this->rooms[12].Initialize("Princess Room", 13, princess_room_navigation);
}

// Find Hero Room
void Castle::find_hero_room(int id)
{
	bool check_peril = this->rooms[id-1].GetRandomPeril();
}

// make random location
int Castle::make_random_location()
{
	//srand(time(NULL));
	int temp = (rand() % 13) + 0;	// will give a random number b/w [0-13] always
	return temp;
}


// Pick a Valid Direction
void Castle::pick_a_valid_direction()
{
	// first i need to check in which room hero is?
	int current_room = this->hero.GetCurrentRoom();

	// now i need to know his valid directions
	cout << "Possible Directions are: " << endl;
	this->rooms->PossibleDirections(current_room - 1);
	int* arr = this->rooms->GetPossibleDirections(current_room - 1);

	// printing arr
	for (int i = 0; i < 4; i++)
		cout << arr[i] << ", ";
	cout << endl;

	cout << "Enter in which room you want to enter?" << endl;
	cout << "Options are already displayed above" << endl;
	int answer;
	bool answer_flag = true;
	while (answer_flag)
	{
		cout << "Room Number? ----> ";
		cin >> answer;
		if (answer == 0)
		{
			// hero cannot move here
			cout << "Hero cannot move here. Please select a valid room" << endl;
			continue;
		}

		// i need to validate user input here
		int counter = 0;
		for (int i = 0; i < 4; i++)
			if (answer != arr[i])
			{
				// it means that user has selected some invalid index
				counter++;
			}
			else
			{
				answer_flag = false;
				break;
			}

		// if counter == 4
		// it means hero has not made a choice from specified rooms
		if (counter == 4)
		{
			cout << "Invalid index. Please select a valid room" << endl;
		}
	}


	// deleting dynamically allocated array
	delete[] arr;

	// now that i have validated user input i can change heroe's current room
	this->hero.SetCurrentRoom(answer);
}




// Constructor 
// Default Constructor
Castle::Castle()
{
	this->Initialize();
}

// Member Functions

// Initialize
void Castle::Initialize()
{
	this->initialize();
}

// Print
void Castle::Print()
{
	// 1. Hero current room
	// 2. Hero possible directions
	// 3. Hero weapons carried list
	// 4. Hero current weapon
	// 5. Peril(s) battle and result
	// 6. Princess current location

	system("cls");
	cout << "------------------------------------------------------------------------------------------------" << endl;
	cout << "Hero Current Room is: " << this->hero.GetCurrentRoom() << endl;
	cout << "Hero Possible Directions are: " << endl;
	this->rooms->PossibleDirections(this->hero.GetCurrentRoom() - 1);
	cout << "Hero Weapons Carried List is: " << endl;
	this->hero.PrintInventory();
	this->hero.PrintCarriedWeapon();
	cout << "Princess Current Room is: ----> ";
	this->princess.PrintRoomAndId(this->princess.GetCurrentRoom());
	cout << "Peril(s) battle and resutls are as follow" << endl;
	this->hero.PrintFightingStats();

	cout << "Press enter to continue" << endl;
	cin.get();

}

// Start
void Castle::Start()
{
	cout << "Program is starting...." << endl;
	cout << "Wait 3 sec(s)" << endl;
	//Sleep(3000);

	// Setting random location of princess
	srand((unsigned)time(NULL));
	int current_room = this->make_random_location();
	this->princess.Initialize('p', current_room);

	// Setting random location of hero
	current_room = this->make_random_location();
	int current_weapon_list[3] = {4,4,3};
	this->hero.Initialize('h', current_room, 3,current_weapon_list);


	// Game Loop starts here
	bool game_flag = true;
	while (game_flag)
	{
		// this is just a check that if princess is already outside of the castle then we can end game here
		if (this->princess.GetCurrentRoom() == 0)
		{
			// it means princess is outside of the castle
			cout << "Princess is outside" << endl;
			cout << "Game ends" << endl;
			exit(0);
		}


		// We need to check if both hero and princess are outside
		// If YES then the game ends there and don't need to proceed further
		if (hero.GetCurrentRoom() == 0 && princess.GetCurrentRoom() == 0)
		{
			cout << "Game Ends()" << endl;
			exit(0);
		}


		if (hero.GetCurrentRoom() == 0 && princess.GetCurrentRoom() != 0)
		{
			// It means hero is already outside but princess is not outside
			// so he has to go inside the castle and retrive pricess to WIN game

			// so we give random locations to both hero and pricess again

			// assigning random location to pricess
			current_room = this->make_random_location();
			princess.SetCurrentRoom(current_room);

			// assigning random location to hero
			current_room = this->make_random_location();
			hero.SetCurrentRoom(current_room);
			this->rooms[this->hero.GetCurrentRoom()].SetNavigationArray(this->hero.GetCurrentRoom() - 1);

			continue;
		}


		if (hero.GetCurrentRoom() != 0)
		{
			// If hero is not outside
			// It means he is presnet inside some room of the castle 

			// We need to check whether princess is present in that room or not
			if (princess.GetCurrentRoom() == hero.GetCurrentRoom())
			{
				// Both hero and pricess are in the same room
				// now her room changes as per hero room
			}

			if (princess.GetCurrentRoom() != hero.GetCurrentRoom())
			{
				// There is some peril waving around

				// First check either there is some kind of monster present there or not
				// If present 
				int check_peril_exist = this->rooms[hero.GetCurrentRoom() - 1].GetRandomPeril();
				if (check_peril_exist != 0)
				{
					cout << "Battle Alert!" << endl;

					// Ask the user either he wants to flee or not
					cout << "Do you want to flee or not?" << endl;
					// printing hero carried weapon
					this->hero.PrintCarriedWeapon();
					// printing current peril
					this->rooms[this->hero.GetCurrentRoom() - 1].PrintCurrentPeril(check_peril_exist);
					char answer;
					cin >> answer;

					if (answer == 'y')
					{
						// Yes the hero wants to flee

						// needs to check if princess is with hero or not
						if (hero.GetCurrentRoom() == princess.GetCurrentRoom())
						{
							// yes the princess is with hero

							// assign random locations to both princess and hero
							// assigning random location to pricess
							current_room = this->make_random_location();
							princess.SetCurrentRoom(current_room);

							// assigning random location to hero
							current_room = this->make_random_location();
							hero.SetCurrentRoom(current_room);

							continue;
						}
						else
						{
							// no the princess is not with hero

							// only assign random location to hero
							// assigning random location to hero
							current_room = this->make_random_location();
							hero.SetCurrentRoom(current_room);

							continue;
						}

					}
					else if (answer == 'n')
					{
						// No the hero doesn't want to flee
						// need to check if he is carrying the right weapon or not

						if (hero.GetCarriedWeapon() == this->rooms[hero.GetCurrentRoom() - 1].GetRandomPeril())
						{
							// Yes he has the right weapon
							// he won battle and removed peril
							// now i need to remove his carried weapon and update his carried weapon list
							if ((this->hero.SetFightingStats(this->hero.GetCarriedWeapon(), this->rooms[this->hero.GetCurrentRoom() - 1].GetRandomPeril())) >= 5)
							{
								cout << "Hero has fought 5 Peril(s)";
								cout << "\nSo the game ends here" << endl;
								exit(0);
							}
							else
							{
								cout << "You have fought: ";
								this->rooms[this->hero.GetCurrentRoom() - 1].PrintCurrentPeril(this->rooms[this->hero.GetCurrentRoom() - 1].GetRandomPeril());
								cout << "and you have won" << endl;
							}

							// Listing Hero's inventory
							cout << "Now printing Hero's Inventory" << endl;
							cout << "Hero's Inventory" << endl;
							hero.PrintInventory();
							// I need to check is there some weapon present in room or not
							int check_weapon_exist = this->rooms[hero.GetCurrentRoom() - 1].GetRandomWeapon();
							if (check_weapon_exist != 0)
							{
								// it means that weapon is present
								cout << "Weapon Present is: ";
								this->rooms[hero.GetCurrentRoom() - 1].PrintWeapon();
								cout << endl;

								// Ask the user whether he wants it or not
								cout << "Either you want weapon or not?" << endl;
								char answer;
								cin >> answer;
								if (answer == 'y')
								{
									// Yes the user wants the new weapon
									// we need to check if hero inventory is full or not
									if (hero.GetInventorySize() <= 3)
									{
										// There is space for a weapon
										hero.SetWeaponToInventory(check_weapon_exist);
									}
									else
									{
										// Inventory is full
										hero.DropFirstWeapon();
									}
								}
							}
						}
						else
						{
							// No he doesn't have the right weapon
							cout << "Defeat" << endl;
							cout << "END!" << endl;
							exit(0);
						}
					}
				}
				else
				{
					cout << "Hero's Inventory" << endl;
					hero.PrintInventory();
					// I need to check is there some weapon present in room or not
					int check_weapon_exist = this->rooms[hero.GetCurrentRoom() - 1].GetRandomWeapon();
					if (check_weapon_exist != 0)
					{
						// it means that weapon is present
						cout << "Weapon Present is: \t";
						this->rooms[hero.GetCurrentRoom()].PrintWeapon();
						cout << endl;

						// Ask the user whether he wants it or not
						cout << "Either you want weapon or not?" << endl;
						char answer;
						cin >> answer;
						if (answer == 'y')
						{
							// Yes the user wants the new weapon
							// we need to check if hero inventory is full or not
							if (hero.GetInventorySize() < 3)
							{
								// There is space for a weapon
								hero.SetWeaponToInventory(check_weapon_exist);
							}
							else
							{
								// Inventory is full
								hero.DropFirstWeapon();
								// Now add weapon to the inventory
								// ?????????
							}
						}
					}
				}
				
			}
		}

		// jinga minga
		// pick a valid direction here
		// ask the user to pick a valid direction
		this->Print();
		this->pick_a_valid_direction();
	}
}