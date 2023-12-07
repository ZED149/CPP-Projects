


#include "Node.h"

// Constructor
// Constructor with params
Node::Node(const std::string& key, const DNSRecord& record) : key(key), record(record),
                                                              next(nullptr)
{}