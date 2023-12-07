




#include "Sunflower.h"
#include <iostream>
#include <string>
using namespace std;


/***************************** Constructors *****************************/

// Default Constructor
Sunflower::Sunflower(string id, string colour, float height, float size) :
        Flower(id, colour, height), seedSize(size)
{
    //cout << "SunFlower() called" << endl;
}

/***************************** Member Functions *****************************/

// Display
void Sunflower::display()
{
    std::cout << "Sunflower - ";
    Flower::display();
    std::cout << "Seed Size: " << seedSize << std::endl;
}