
// Q2

#pragma once

#include <fstream>
#include <string>
#include <iostream>
using namespace std;


// this file contains my_read class
class MyRead
{
public:	// This is where the member goes
	// Constructor
	// Default Constructor
	MyRead(){}

	// Constructor with params
	MyRead(const char* filename)
	{
		if (!filename)
		{
			cerr << "Filename cannot be NULL" << endl;
			exit(0);
		}
		// This is Q2

		// creating stream for reading
		ifstream fin(filename, ios::in);
		// checking for error
		if (!fin.is_open())
		{
			cerr << "Error opening file for reading" << endl;
			exit(0);
		}

		// If file is opened and ready for reading

		// reading from file
		string buffer;
		int lines = 0, characters = 0, words = 0;
		while (!fin.eof())
		{
			getline(fin, buffer, '\n');
			lines++;
			characters += buffer.size();

			char* token = nullptr, * context = nullptr;
			token = strtok_s((char*)buffer.c_str(), " ", &context);
			while (token)
			{
				words++;
				token = strtok_s(NULL, " ", &context);
			}
		}

		characters += lines - 1;
		cout << "Lines are: " << lines << endl;
		cout << "Characters are: " << characters << endl;
		cout << "Words are: " << words << endl;
	}
};