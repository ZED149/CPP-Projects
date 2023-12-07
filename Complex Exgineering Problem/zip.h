
#pragma once



#include <iostream>
#include <fstream>
#include "minheap.h"
#include "entry.h"
#include <string>
#include <map>
#include <Windows.h>
#include <algorithm>
using namespace std;



// This is a program which can be used to compress or 
// decompress files.

class zip
{
	// Private Data Members
	map<string, string> encoding_table;
	string filename;

	// Utility Functions
	void compress(string filename, string encrypt_data);


	//Compression
	void compression(string filename);


	// MAIN LOOP
	void main_loop(minHeap<entry>& frequency_table_heap);


	// Create Heap
	minHeap<entry> create_heap(map<string, int>& frequency_table);


	// Decompress
	void decompress(string filename, string decode_data);


public:	// This is where the member goes
	//Constructor
	//Default Constructor
	zip();


	// Member Functions
	// Compress
	void Compress(string filename, string encrypt_data);


	// Decompress
	void Decompress(string filename, string decode_data);


	// Write Keys
	void WriteKeys(string filename);


	// Print Encoding Table
	void PrintEncodingTable();


	// Clear Encoding Table
	void ClearEncodingTable();


	// Interface
	static void Interface(int argc, char** argv);
};