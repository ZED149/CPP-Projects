



#pragma once

// This is the Base Flower class

// including required headers
#include <iostream>
using namespace std;
#include <string>

class Flower
{
protected:
    string polyphenalOxidase;
    string colour;
    float height;
    int growthStage;

public:	// This is where the member goes

    /************************ Constructor ************************/
    // Default Constructor
    Flower(string id, string colour, float height);

    /************************ Member Functions ************************/

    // Grow
    virtual void grow();

    // Display
    virtual void display();

    /************************ Getters ************************/

    // GetPolyphenalOxidase
    // Added member function to get polyphenaloxidase
    string getPolyphenalOxidase();

    // Operator Overloading

    // Less Than Operator
    bool operator < (const Flower& flower);

    // Greater Than Operator
    bool operator > (const Flower& flower);

    /************************ Destructor ************************/
    ~Flower();

};
