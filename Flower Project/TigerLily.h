



// These are the derived class of Flower class

#include "flower.h"
#include <iostream>
#include <string>
using namespace std;
#pragma once


class TigerLily: public Flower
{
    int petalCount;
public:	// This is where the member goes
    /***************************** Constructors *****************************/

    // Default Constructor
    TigerLily(string id, string colour, float height, int petals);

    /***************************** Member Functions *****************************/

    // Display
    void display() override;
};
