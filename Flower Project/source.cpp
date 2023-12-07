



#include <iostream>
using namespace std;


// including user defined classes
#include "flower.h"
#include "flowertree.h"
#include "TigerLily.h"
#include "Sunflower.h"


int main()
{
    FlowerTree flowerTree;
    // Create flowers
    Flower* flower1 = new TigerLily("T001", "Orange", 0.8, 6);
    Flower* flower2 = new TigerLily("T002", "Yellow", 1.0, 8);
    Flower* flower3 = new Sunflower("S001", "Yellow", 1.2, 0.8);
    Flower* flower4 = new Sunflower("S002", "Orange", 1.5, 1.0);
    Flower* flower5 = new Sunflower("S003", "Black", 2.5, 3.9);
    Flower* flower6 = new Sunflower("S009", "Pink", 2.9, 4.5);
    // Insert flowers into FlowerTree
    flowerTree.insert(flower1);
    flowerTree.insert(flower2);
    flowerTree.insert(flower3);
    flowerTree.insert(flower4);
    flowerTree.insert(flower5);
    flowerTree.insert(flower6);
    // Display flowers in FlowerTree
    flowerTree.display();

    // deleting items
    delete flower1;
    delete flower2;
    delete flower3;
    delete flower4;
    delete flower5;
}