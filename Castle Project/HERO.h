
#pragma once


// This file contains the HERO class
// It will inherit some basic characteristics from CHARACTER class
#include "CHARACTER.h"

class Hero : public Character
{
	int carried_weapon;
	int carried_weapon_list[3];
	int inventory_size;
	int fighting_stats[5][2];	// stores stats about which wepaon used to kill which peril
	int fighting_stats_counter;

	// Utility Functions
	void initialize(char id, int current_room, int inventory_size, int carried_weapon_list[3]);

public:	// This is where the member goes
	// Constructor 
	// Default Constructor
	Hero();

	// Constructor with params
	Hero(char id, int current_room, int inventory_size, int carried_weapon_list[3]);

	// Member Functions

	// Print Inventory
	void PrintInventory();

	// Drop First Weapon
	void DropFirstWeapon();

	// Initialize
	void Initialize(char id, int current_room, int inventory_size, int carried_weapon_list[3]);

	// Possible Directions
	void PossibleDirections();

	// Print Carried Weapon
	void PrintCarriedWeapon();

	// Print Fighting Stats
	void PrintFightingStats();


	// Getters
	
	// Inventory Size
	int GetInventorySize();

	// Get Carried Weapon
	int GetCarriedWeapon();


	// Setters

	// Set Weapon To Inventory
	void SetWeaponToInventory(int weapon_id);

	// Set Fighting Stats
	int SetFightingStats(int weapon_used, int peril_died);
};