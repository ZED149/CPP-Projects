


#include "WEAPON.h"
#include <iostream>
using namespace std;


// Constructor
// Default Constructor
Weapon::Weapon()
{
	//cout << "Weapon() called" << endl;
	this->id = 0;
}

// Constructor with params
Weapon::Weapon(unsigned id)
{
	//cout << "Weapon(params) called" << endl;
	this->id = id;
}


// Getters

// Get Weapon Id
int Weapon::GetWeaponId()
{
	return this->id;
}


// Setters

// Set Weapon Id
void Weapon::SetWeaponId(int id)
{
	this->id = id;
}