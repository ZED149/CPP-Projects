


#include <iostream>
#include "HashTable.h"
#include <iostream>     // added, need to be removed
using namespace std;    // added, need to be removed

// Constructor
// Construcrtor with params
HashTable::HashTable(int size) :
        size(size), table(size, nullptr)
{}

// Member Functions

// Insert
void HashTable::insert(const std::string& key, const DNSRecord& record)
{
    /*
        params:
            key		---->	DOMAIN name
            record	---->	DNS Record Object (ipAddress, TTL value)
    */

    // This function inserts key and record into the hashtable after performing hash function on key
    // there can be two scenarios
    // 1. the specified index is empty, then value is directly placed
    // 2. there is a collision occurruing at hashed index

    // we will be using Linked List (vectors) to handle collions
    // this is also called as, Open Hashing which further corresponds to chaining hashing

    // Function impleted from here

    // first perform hash of the key
    unsigned long index = this->hashFunction(key);	// contains index of the key after hashing
    index = index % 10;

    // checking if index is empty or not
    if (table[index] == nullptr)
    {
        // if index is empty, means this is the first (key, record) pair to be inserted
        // creating a node object
        Node* temp = new Node(key, record);
        // inserting into table
        //table[index] = &(*temp);
        table[index] = temp;
    }
    else
    {
        // if there is a collision
        // then, iterate till the end of the list and insert at last
        // iterating till end
        Node* curr = table[index];
        while (curr->next != nullptr)
        {
            curr = curr->next;
        }
        // now curr is at last position of that list
        // we can insert here
        // creating a new node object
        Node* temp = new Node(key, record);
        // inserting
        curr->next = temp;
        //cout << "checking" << endl;
    }
}

// Get
std::string HashTable::get(const std::string& key)
{
    int hashValue = hash(key) % size;
    Node* node = table[hashValue];
    while (node != nullptr) {
        if (node->key == key) {
            if (node->record.isExpired()) {
                remove(key);
                return "None";
            }
            return node->record.getIPAddress();
        }
        node = node->next;
    }
    return "None";
}

// Remove
void HashTable::remove(const std::string& key)
{
    // This function removes a key from the hashtable
    // the process is almost similar to insertion
    // at first, we need to find hash of the given key
    // computing hash of the given key
    unsigned long index = hashFunction(key);
    index = index % 10;
    // now there can be two conditions
    // 1.  there exist some value at given index
    // 2.	there is no value at given index

    if (table[index] != nullptr)
    {
        // there is a list at a given index
        // iterate on that list
        // 1. key can be found to delete
        // 2. key cannot be found

        // iterating on that list
        Node* curr = table[index];
        Node* prev = curr;
        // special test case, if there is only 1 item in list
        if (curr->next == nullptr)
        {
            // it means there is only one value
            // delete it right here, no need to traverse
            delete curr;
            table[index] = nullptr;
            curr = nullptr;
        }

        int first_item = 0;
        while (curr != nullptr)
        {
            if (curr->key == key && first_item == 0)
            {
                // it means, if deletion needs to be occur at head
                // then, we have to implement some different logic
                // assigning table[index] to the next item of head
                table[index] = curr->next;
                delete curr;
                curr = nullptr;
                break;
            }

            if (curr->key == key)
            {
                // key is matched
                // delete it and bind linked list
                prev->next = curr->next;
                delete curr;
                curr = nullptr;
                break;
            }

            // incrementing counter for first item
            first_item++;
            prev = curr;
            curr = curr->next;
        }
    }
}

// Display
void HashTable::display()
{
    // This function displays the contents of the hashtable onto the screen
    // it helps in understanding and monitoring the DNS cache.


    cout << "\tKEYS\t     \t\t\tPAIRS\n";
    // iterating through table
    int i = 0;
    while (i < size)
    {
        cout << "[" << i << "]" << "|";
        // checking if table[i] is NULL
        if (table[i] == nullptr)
        {
            cout << "NAN" << endl;
        }
        else
        {
            // if there is some value stored
            // then this is a linked list on which we iterate further
            Node* curr = table[i];
            while (curr != nullptr)
            {
                cout << curr->key << "\t\t|" << curr->record << ", ";
                curr = curr->next;
            }
            cout << endl;
        }
        i++;
    }
}

// Hash
int HashTable::hash(const std::string& key)
{
    unsigned long return_value = hashFunction(key);
    return_value = return_value % 10;
    return return_value;
}

// Destructor
HashTable::~HashTable()
{
    //cout << "~HashTable() called\n";
    // delete all nodes present in the table
    // To delete, traverse on table
    // if table[index] == NULL, do nothing
    // if table[index] != NULL, delete that one node or list of nodes

    // traversing on table
    int i = 0;
    while (i < size)
    {
        if(table[i] != nullptr)
        {
            // it means there exists some value
            // it can either be a single node only
            // or it can be a list of nodes
            // either way delete all

            // in case of one node
            Node* curr = table[i];
            if(curr -> next == nullptr)
            {
                // it indicates that it's the only element present
                delete curr;
                curr = nullptr;
                table[i] = nullptr;
            }
            else
            {
                // there is more than a single node present
                Node *next_one = table[i];
                while(next_one != nullptr)
                {
                    Node *temp = next_one;
                    next_one = next_one->next;
                    delete temp;
                    table[i] = next_one;
                }
            }

        }
        i++;
    }
}