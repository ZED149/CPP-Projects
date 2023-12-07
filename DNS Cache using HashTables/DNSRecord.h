



#ifndef DNSRECORD_H
#define DNSRECORD_H


#include <string>
#include <ctime>

// This is the DNS Record class
// Each instance contains 
/*
			ipAddress		---->	192.168.1.1
			expirationTime	---->	time to live (TTL)
*/
class DNSRecord
{
public:
    // Constructor
    // Constructor with params
    DNSRecord(const std::string& ipAddress, int ttl);

    // Member Functions

    // isExpired
    bool isExpired();

    // Getters

    // getIPAddress
    std::string getIPAddress();

    // Operator Overloading

    // out stream operator
    friend std::ostream& operator<<(std::ostream& os, const DNSRecord& record);
private:
    std::string ipAddress;	// e.g = 192.168.0.1
    time_t expirationTime;	// also known as TTL, means Time To Live
};
#endif // DNSRECORD_H