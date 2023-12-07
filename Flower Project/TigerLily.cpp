


#include "TigerLily.h"
#include <iostream>
#include <string>
using namespace std;


/***************************** Constructors *****************************/

// Default Constructor
TigerLily::TigerLily(string id, string colour, float height, int petals) :
        Flower(id, colour, height), petalCount(petals)
{
    //cout << "TigerLily() called" << endl;
}

/***************************** Constructors *****************************/

// Display
void TigerLily::display()
{
    std::cout << "Tiger Lily - ";
    Flower::display();
    std::cout << " Petal Count: " << petalCount << std::endl;
}