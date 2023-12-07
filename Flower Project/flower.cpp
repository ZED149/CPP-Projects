

#include "flower.h"



#include <iostream>
#include <string>
using namespace std;


/************************ Constructor ************************/

// Default Constructor
Flower::Flower(string id, string colour, float height):
        polyphenalOxidase(id), colour(colour), height(height), growthStage(0)
{
    //cout << "Flower() called" << endl;
}

/************************ Member Functions ************************/

// Grow
void Flower::grow()
{
    height += 0.1;
    growthStage++;
}

//Display
void Flower::display()
{
    std::cout << "Flower ID: " << polyphenalOxidase << " \n Color: " << colour <<
              " \n Height: " << height << " \n Growth Stage: " << growthStage << std::endl;
}

/************************ Getters ************************/

// Get PolyphenalOxidase
string Flower::getPolyphenalOxidase()
{
    return this->polyphenalOxidase;
}

// Operator Overloading

// Less Than Operator
bool Flower::operator<(const Flower& flower)
{
    if (this->polyphenalOxidase < flower.polyphenalOxidase)
        return 1;
    else
        return 0;
}

// Greater Than Operator
bool Flower::operator>(const Flower& flower)
{
    if (this->polyphenalOxidase > flower.polyphenalOxidase)
        return true;
    else
        return false;
}

/************************ Destructor ************************/
Flower::~Flower()
{
    //cout << "~Flower() called" << endl;
}