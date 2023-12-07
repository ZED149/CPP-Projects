



#include <iostream>
#include "DNSRecord.h"

// Constructor
// Constructor with params
DNSRecord::DNSRecord(const std::string& ipAddress, int ttl) :
        ipAddress(ipAddress)
{
    expirationTime = time(nullptr) + ttl;
}

// Member Functions

// isExpired
bool DNSRecord::isExpired() {
    return time(nullptr) >= expirationTime;
}

// Getters

// getIPAddress
std::string DNSRecord::getIPAddress() {
    return ipAddress;
}

// Operator Overloading

// out stream operator
std::ostream& operator<<(std::ostream& os, const DNSRecord& record) {
    os << "DNSRecord(ip_address='" << record.ipAddress << "', expiration_time=" <<
       record.expirationTime << ")";
    return os;
}