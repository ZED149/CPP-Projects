



#ifndef NODE_H
#define NODE_H

#include <string>
#include "DNSRecord.h"


// This is the Node class for HashTable
// Each Node contains 
/*
	key		---->	DOMAIN Name e.g https://www.google.com/search	
	record	---->	IP Address of that domain e.g 27.45.902.32
	next	---->	Next Node object
*/
class Node {
public:
    // Constructor
    // Constructor with params
    Node(const std::string& key, const DNSRecord& record);

    // Attributes
    std::string key;
    DNSRecord record;
    Node* next;
};
#endif // NODE_H