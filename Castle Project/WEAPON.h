
#pragma once



// This file contains the Weapon class

/*
	Weapons Information and their ID's
	-> Sword		----> 1
	-> Stave		----> 2
	-> Fly-Spray	----> 3
	-> Magic Potion ----> 4
	-> Flamegun		----> 5
*/


class  Weapon
{
	unsigned id;	// Stores ID of the weapon

public:	// This is where the member goes
	// Constructor
	// Default Constructor
	Weapon();

	// Constructor with params
	Weapon(unsigned id);

	// Getters

	// Get Weapon Id
	int GetWeaponId();

	// Setters

	// Set Weapon Id
	void SetWeaponId(int id);
};