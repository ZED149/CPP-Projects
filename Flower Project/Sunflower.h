



// This is the derived class of Flower class
#pragma once

#include "flower.h"
#include <iostream>
#include <string>
using namespace std;


class Sunflower: public Flower
{
    float seedSize;
public:	// This is where the member goes
    /***************************** Constructors *****************************/

    // Default Constructor
    Sunflower(string id, string colour, float height, float size);

    /***************************** Member Functions *****************************/

    // Display
    void display() override;
};
