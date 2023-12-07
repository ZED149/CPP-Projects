



#include "flowertree.h"
#include <iostream>
#include <string>
#include "flower.h"
using namespace std;


// AVL Tree node
Node::Node(Flower* f) :
        flower(f), left(nullptr), right(nullptr), height(1)
{
    //cout << "Node() called" << endl;
}

// Flower Tree Class
FlowerTree::FlowerTree() :
        root(nullptr)
{
    //cout << "FlowerTree() called" << endl;
}

/************************************* Destructor *************************************/
FlowerTree::~FlowerTree()
{
    //cout << "~FlowerTree() called" << endl;
    cleanup(root);
}

/************************************* Getters *************************************/

// GetHeight
int FlowerTree::getHeight(Node* node)
{
    if (node == nullptr)
        return 0;
    return node->height;
}

// GetBalanceFactor
int FlowerTree::getBalanceFactor(Node* node)
{
    if (node == nullptr)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

//rotateLeft
Node* FlowerTree::rotateLeft(Node* z)
{
    // implement
    //cout << "RR rotation() called" << endl;
    Node* p = z->right;
    z->right= p->left;
    p->left = z;
    z->height = max(getHeight(z->left), getHeight(z->right)) + 1;
    p->height = max(getHeight(p->right), z->height) + 1;
    z = p;

    return z;
}

//rotateRight
Node* FlowerTree::rotateRight(Node* z)
{
    // implement
    //cout << "LL rotation() called" << endl;
    Node* p = z->left;
    z->left = p->right;
    p->right = z;
    z->height = max(getHeight(z->left), getHeight(z->right)) + 1;
    p->height = max(getHeight(p->left), z->height) + 1;
    z = p;

    return z;
}

//Inside Cases
//LR Rotation
void FlowerTree::doubleRotateLeft(Node& n)
{
    //cout << "LR rotation() called" << endl;
    rotateLeft((&n)->left);
    rotateRight(&n);
}


//RL Rotation
void FlowerTree::doubleRotateRight(Node& n)
{
    //cout << "RL rotation() called" << endl;
    rotateRight((&n)->right);
    rotateLeft(&n);
}

// Balance
Node* FlowerTree::balance(Node* node)
{
    // implement
    return node;
}

// InsertNode
Node* FlowerTree::insertNode(Node* node, Flower* flower)
{
    // implement
    if (node == nullptr)
    {
        node = new Node(flower);
        node->flower = flower;
        node->left= node->right= nullptr;
        node->height = 0;
        return node;
    }
    else
    {
        if (*(flower) < *(node->flower))
        {
            node->left = insertNode(node->left, flower);
            node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
            if (getBalanceFactor(node) == 1)
            {
                if (*(flower) < *(node->left->flower))	//outside case "LL rotation", means rotate towards right side
                {
                    node = rotateRight(node);
                    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
                }
                else	//inside case "LR rotation", means double rotation, first towards left then towards right
                {
                    doubleRotateLeft(*node);
                    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
                }
            }
        }
        else if (*(flower) > *(node->flower))
        {
            node->right = insertNode((node)->right, flower);
            node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
            if (getBalanceFactor(node) == -1)
            {
                if (*(flower) > *(node->right->flower))	//outside case "RR rotation", means rotate towards left side
                {
                    node = rotateLeft(node);
                    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
                }
                else	//inside case "RL rotation", means double rotation, first towards right then towards left
                {
                    doubleRotateRight(*node);
                    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
                }
            }
        }
    }
    //node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

    return node;
}

// Insert
void FlowerTree::insert(Flower* flower)
{
    root = insertNode(root, flower);
}

// DisplayInOrder
void FlowerTree::displayInOrder(Node* node)
{
    // implement
    if (node)
    {
        //this is a recursive function
        //it prints data of avl in sorted order
        //i.e from left-root-right
        //cout << "inorder() called" << endl;
        displayInOrder(node->left);
        node->flower->display();
        displayInOrder(node->right);
    }
}

// DisplayInOrder
void FlowerTree::displayIn(Node* node)
{
    // implement
    if (node)
    {
        //this is a recursive function
        //it prints data of avl in sorted order
        //i.e from left-root-right
        //cout << "inorder() called" << endl;
        node->flower->display();
        displayIn(node->left);
        displayIn(node->right);
    }
}

// Display
void FlowerTree::display()
{
    if (root == nullptr) {
        std::cout << "No flowers in the FlowerTree." << std::endl;
        return;
    }
    std::cout << "Flowers in the FlowerTree:" << std::endl;
    displayIn(root);
}

// ComparePolyPhenalOxidase
bool FlowerTree::comparePolyphenalOxidase(const std::string& id1, const std::string& id2)
{
    return id1 < id2;
}

// Cleanup
void FlowerTree::cleanup(Node* node)
{
    // implement
    if (node)
    {
        cleanup(node->left);
        cleanup(node->right);
        delete node;
        node = nullptr;
    }
}