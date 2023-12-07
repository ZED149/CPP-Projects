


// This is the FlowerTree class
// This is basically the AVL Tree node class
// Each node contains
/*
	1. Flower*	---> type Data
	2. Node*	---> Left
	3. Node*	---> Right
	4. int		---> height
*/
#pragma once
#include <iostream>
#include <string>
#include "flower.h"
using namespace std;


// AVL Tree Node
class Node
{
public:
    Flower* flower;
    Node* left;
    Node* right;
    int height;

    /***************************** Constructor *****************************/

    // Default Constructor
    Node(Flower* f);
};



class FlowerTree
{
private:
    Node* root;

    /***************************** Helper Functions *****************************/

    // Cleanup
    void cleanup(Node* node);

    // GetHeight
    int getHeight(Node* node);

    // GetBalanceFactor
    int getBalanceFactor(Node* node);

    // RotateLeft
    Node* rotateLeft(Node* z);

    // RotateRight
    Node* rotateRight(Node* z);

    // Balance
    Node* balance(Node* node);

    // InsertNode
    Node* insertNode(Node* node, Flower* flower);

    //DisplayInOrder
    void displayInOrder(Node* node);

    // DisplayIn
    void displayIn(Node* node);

    // ComparePolyPhenalOxidase
    // Added helper function to compare two flower ID's
    bool comparePolyphenalOxidase(const string& id1, const string& id2);

public:	//This is where the constructor goes
    FlowerTree();
    ~FlowerTree();

    /***************************** Member Functions *****************************/

    // Insert
    void insert(Flower* flower);

    // Display
    void display();

    //Inside Cases
    //LR Rotation
    void doubleRotateLeft(Node& n);


    //RL Rotation
    void doubleRotateRight(Node& n);
};

