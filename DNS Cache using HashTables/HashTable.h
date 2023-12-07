



#ifndef HASHTABLE_H
#define HASHTABLE_H


#include <vector>
#include "Node.h"

// This is the HashTable class
class HashTable {
public:
    // Constructor
    // Constructor with params
    HashTable(int size);

    // Member Functions

    // Insert
    void insert(const std::string& key, const DNSRecord& record);

    // Get
    std::string get(const std::string& key);

    // Remove
    void remove(const std::string& key);

    // Display
    void display();

    // Destructor
    ~HashTable();
private:
    int size;	// size of the hashtable
    std::vector<Node*> table;	// HashTable
    std::hash<std::string> hashFunction;	// hashfunction
    // This is the core function which returns the hashed value of a key
    int hash(const std::string& key);	// hash
};
#endif // HASHTABLE_H