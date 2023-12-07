


#include <iostream>
#include <unistd.h>
#include "HashTable.h"
#include "DNSRecord.h"
using namespace std;
int main() {

     //Custom Testing
    HashTable hashTable(10);
    hashTable.insert("www.example.com", DNSRecord("192.168.1.100", 1)); // Record expires in 60 seconds
    hashTable.insert("www.google.com", DNSRecord("192.168.23.98", 9999999)); // Record expires in 60 seconds
    hashTable.insert("www.facebook.com", DNSRecord("23.68.3.8", 1)); // Record expires in 60 seconds
    hashTable.insert("www.youtube.com", DNSRecord("45.8.2.9", 1)); // Record expires in 60 seconds
    hashTable.insert("www.tiktok.com", DNSRecord("1.1.239.8", 1)); // Record expires in 60 seconds
    hashTable.insert("www.instagram.com", DNSRecord("35.76.567.43", 1)); // Record expires in 60 seconds
    hashTable.insert("www.snapchat.com", DNSRecord("8.6.6.6", 1)); // Record expires in 60 seconds
    std::cout << hashTable.get("www.example.com") << std::endl; // Output: 192.168.1.100
    hashTable.display();
    sleep(6); // Sleep for more than the record's TTL to simulate expiration
    std::cout << hashTable.get("www.example.com") << std::endl; // Output: None
    hashTable.display();
    cout << "Now removing facebook from table" << endl;
    hashTable.remove("www.facebook.com");
    hashTable.display();
    cout << "Now removing snapchat but using get function" << endl;
    cout << hashTable.get("www.snapchat.com") << endl;
    hashTable.display();
    cout << "Now checking google ttl working or not" << endl;
    cout << hashTable.get("www.google.com") << endl;
    return 0;

    /*HashTable hashTable(10);
    hashTable.insert("www.example.com", DNSRecord("192.168.1.100", 5)); // Record expires in 60 seconds
    std::cout << hashTable.get("www.example.com") << std::endl; // Output: 192.168.1.100
    sleep(6); // Sleep for more than the record's TTL to simulate expiration
    std::cout << hashTable.get("www.example.com") << std::endl; // Output: None
    hashTable.display();*/
    return 0;
}