#include <iostream>
#include <fstream>
#include "minheap.h"
#include "entry.h"
#include <string>
#include <map>
#include <Windows.h>
#include <algorithm>
#include "zip.h"
using namespace std;



//Constructor
//Default Constructor
zip::zip()
{
	cout << "zip() called" << endl;
}


// Member Functions
// Compress
void zip::Compress(string filename, string encrypt_data)
{
	compress(filename, encrypt_data);
}

// Decompress
void zip::Decompress(string filename, string decode_data)
{
	decompress(filename, decode_data);
}


// Print Encoding Table
void zip::PrintEncodingTable()
{
	int unique_symbols = 0;
	auto itr = this->encoding_table.begin();
	for (; itr != this->encoding_table.end(); itr++)
	{
		int number = atoi(itr->first.c_str());
		char display = (char)number;
		if (number == 32)
			cout << "[space]" << "\t\t" << itr->second << endl;
		else
			cout << display << "\t\t" << itr->second << endl;;
		unique_symbols++;
	}
	cout << "\n\nUnique Symbols are: [" << unique_symbols << "]\n";


	// Printing to screen
	filename = filename.erase(filename.size() - 3, 3);
	filename.append("cmp");
	ifstream fin(filename);
	string buffer;
	bool flag = true;
	cout << "Encoded Message is: ";
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			if (flag)
			{
				// this is the conding table we dont want it
				getline(fin, buffer, '\n');
				flag = false;
			}
			else
			{
				getline(fin, buffer);
				int buffer_size = buffer.size();
				for (int i = 0; i < buffer_size; i++)
				{
					cout << buffer[i];
				}
			}
		}
	}
	cout << endl;
}


// Clear Encoding Table
void zip::ClearEncodingTable()
{
	this->encoding_table.clear();
}


// Interface
void zip::Interface(int argc, char** argv)
{
	if (argc == 3)
	{
		// Now that we know there are 3 arguments
		// 1. Program name
		// 2. compress/uncompress
		// 3. filename
		string _compress = "compress", _uncompress = "decompress";
		string check(argv[1]);

		// Checking for COMPRESS
		if (check == _compress)
		{
			// Now need to check for filename
			string _filename(argv[2]);
			if (_filename.compare(_filename.size() - 4, 4, ".txt") == 0)
			{
				zip obj;
				//obj.compress(_filename);
				obj.PrintEncodingTable();
			}
			else
			{
				cout << "Invalid Filename" << endl;
			}
		}
		// Checking for UNCOMPRESS
		else if (check == _uncompress)
		{
			// Now need to check for filename
			string _filename(argv[2]);
			if (_filename.compare(_filename.size() - 4, 4, ".cmp") == 0)
			{
				zip obj;
				//obj.Decompress(_filename);
				//obj.PrintEncodingTable();
				cout << "decompression complete" << endl;
			}
			else
			{
				cout << "Invalid Filename" << endl;
			}
		}
		else
		{
			cout << "Invalid Syntax" << endl;
		}
	}
	else
	{
		cout << "Invalid Syntax" << endl;
	}
}


// Utility Functions
void zip::compress(string filename, string encrypt_data)
{
	// Just storing filename for this compression ti be used as globally in other methods
	this->filename = filename;
	/*
	// First I need to open the given file
	//Opening File
	ifstream fin(filename);
	if (fin.is_open())
	{
		string buffer;
		map<string, int> frequency_table;
		while (!fin.eof())
		{
			// If file is open
			// I will read it whole at once
			// then I will traverse through it 8-8 characters in one iteration
			getline(fin, buffer);
			int buffer_size = buffer.size();
			int j = 1;
			for (int i = 0; i < buffer_size; i++)
			{
				//frequency_table.emplace(buffer, 1);
				string a = std::to_string(buffer[i]);
				int number = atoi(a.c_str());
				auto itr = frequency_table.begin();
				bool flag = true;
				while (itr != frequency_table.end())
				{
					string check = itr->first;
					int second_number = atoi(check.c_str()) + 32;
					int third_number = atoi(check.c_str()) - 32;
					if (second_number == number)
					{
						second_number = second_number - 32;
						string insert_string = std::to_string(second_number);
						frequency_table[insert_string]++;
						flag = false;
					}
					else if (third_number == number)
					{
						third_number = third_number + 32;
						string insert_string = std::to_string(third_number);
						frequency_table[insert_string]++;
						flag = false;
					}

					itr++;
				}
				if (flag)
					frequency_table[a]++;
			}

		}
		fin.close();
		// After the while loop is terminated
		// it means that our frequency table is ready to be inserted into a min-heap

		// Creating Min-Heap
		minHeap<entry> frequency_table_heap = create_heap(frequency_table);

		// Now we have our min-heap which can be used in MAIN_LOOP to convert it into a tree
		main_loop(frequency_table_heap);
		compression(filename);
		//this->WriteKeys(this->filename);

	}
	else
		cout << "Unable tp open File" << endl;
	*/

	// First I need to open the given file
	//Opening File
	string buffer = encrypt_data;
	map<string, int> frequency_table;
	// If file is open
	// I will read it whole at once
	// then I will traverse through it 8-8 characters in one iteration
	int buffer_size = buffer.size();
	for (int i = 0; i < buffer_size; i++)
	{
		//frequency_table.emplace(buffer, 1);
		string a = std::to_string(buffer[i]);
		int number = atoi(a.c_str());
		auto itr = frequency_table.begin();
		bool flag = true;
		while (itr != frequency_table.end())
		{
			string check = itr->first;
			int second_number = atoi(check.c_str()) + 32;
			int third_number = atoi(check.c_str()) - 32;
			if (second_number == number)
			{
				second_number = second_number - 32;
				string insert_string = std::to_string(second_number);
				frequency_table[insert_string]++;
				flag = false;
			}
			else if (third_number == number)
			{
				third_number = third_number + 32;
				string insert_string = std::to_string(third_number);
				frequency_table[insert_string]++;
				flag = false;
			}

			itr++;
		}
		if (flag)
			frequency_table[a]++;
	}
	// After the while loop is terminated
	// it means that our frequency table is ready to be inserted into a min-heap

	// Creating Min-Heap
	minHeap<entry> frequency_table_heap = create_heap(frequency_table);

	// Now we have our min-heap which can be used in MAIN_LOOP to convert it into a tree
	main_loop(frequency_table_heap);
	this->compression(filename);
	//this->WriteKeys(this->filename);
}


// Write Keys
void zip::WriteKeys(string filename)
{
	// Filename is name of the file which contains key:value
	// key being the symbol and value being the code
	ifstream fin(filename);
	filename = filename.erase(filename.size() - 3, 3);
	ofstream fout(filename.append("cmp"));
	if (fin.is_open() && fout.is_open())
	{
		// Writing Encoding Table File
		auto itr = this->encoding_table.begin();
		for (; itr != this->encoding_table.end(); itr++)
		{
			fout << itr->first << ":" << itr->second << " ";
		}
		fout << endl;


		/*
		// Encoding File
		string buffer;
		while (!fin.eof())
		{
			// If file is open
			// I will read it whole at once
			// then I will traverse through it 8-8 characters in one iteration
			getline(fin, buffer, '\0');
			string temp_buffer;
			int temp_buffer_index = 0;
			int buffer_size = buffer.size();
			for (int i = 0; i <= buffer_size; i++)
			{
				temp_buffer += buffer[i];
				auto itr = encoding_table.begin();
				while (itr != encoding_table.end())
				{
					int number_one = atoi(itr->first.c_str());
					int number_two = buffer[i];
					if (number_one == number_two)
					{
						fout << itr->second;
					}
					itr++;
				}
			}
		}
		*/
		fin.close();
		fout.close();
	}
	else
		cout << "Unable to open file";
}


//Compression
void zip::compression(string filename)
{
	// Filename is name of the file which contains key:value
	// key being the symbol and value being the code
	ifstream fin(filename);
	filename = filename.erase(filename.size() - 3, 3);
	ofstream fout(filename.append("cmp"));
	if (fin.is_open() && fout.is_open())
	{
		// Writing Encoding Table File
		auto itr = this->encoding_table.begin();
		for (; itr != this->encoding_table.end(); itr++)
		{
			fout << itr->first << ":" << itr->second << " ";
		}
		fout << endl;


		// Encoding File
		string buffer;
		while (!fin.eof())
		{
			// If file is open
			// I will read it whole at once
			// then I will traverse through it 8-8 characters in one iteration
			getline(fin, buffer, '\0');
			string temp_buffer;
			int temp_buffer_index = 0;
			int buffer_size = buffer.size();
			for (int i = 0; i <= buffer_size; i++)
			{
				temp_buffer += buffer[i];
				auto itr = encoding_table.begin();
				while (itr != encoding_table.end())
				{
					int number_one = atoi(itr->first.c_str());
					int number_two = buffer[i];
					if (number_one == number_two)
					{
						fout << itr->second;
					}
					itr++;
				}
			}
		}
		fin.close();
		fout.close();
	}
	else
		cout << "Unable to open file";
}


// MAIN LOOP
void zip::main_loop(minHeap<entry>& frequency_table_heap)
{
	while (frequency_table_heap.GetSize() > 2)
	{
		// First we need to extract two minimum entries
		entry miminumOne = frequency_table_heap.ExtractMin();
		entry miminumTwo = frequency_table_heap.ExtractMin();
		entry z("-", (miminumOne.GetTermFrequency() + miminumTwo.GetTermFrequency()), &miminumOne, &miminumTwo);
		frequency_table_heap.Insert(z);
	}

	// Get Root
	entry root = frequency_table_heap.ExtractMin();
	root.GetEncodingTable(encoding_table);
}


// Create Heap
minHeap<entry> zip::create_heap(map<string, int>& frequency_table)
{
	minHeap<entry> frequency_table_heap;

	// This method will take the frequency table and will return a heap
	// constructed by that frequency table

	// To create a Min-Heap from this table
	// First I need to traverse thorugh the table
	// While traversing, I need to push those 
	// indexes as an entry object to the heap

	// Traversing thorugh the frequency table
	auto itr = frequency_table.begin();
	for (int i = 0; i < 26, itr != frequency_table.end(); i++)
	{
		if (itr->second > 0)
		{
			// It means that binary value of this decimal representation is present in the FILE
			// so we will convert that deciaml representation to binary form
			// then push it into the heap

			// Converting into binary
			string symbol = itr->first;
			entry a(symbol, itr->second, nullptr, nullptr);
			frequency_table_heap.Insert(a);
		}
		itr++;
	}

	return frequency_table_heap;
}


// Decompress
void zip::decompress(string filename, string decode_data)
{
	/*
	// At First I need to open the file and read encoding table from it
	ifstream fin(filename);
	if (fin.is_open())
	{
		string buffer;
		while (!fin.eof())
		{
			// Reading Encoding Table
			getline(fin, buffer, '\n');
			int buffer_size = buffer.size();

			// Now, tokenize the string
			// key:value[space]key:value[space]key:value
			char* token = nullptr, * ptr;
			ptr = strtok_s(&buffer[0], " ", &token);
			string key, value;
			while (ptr)
			{
				//cout << ptr << endl;
				char* temp_token = nullptr, * temp_ptr;
				temp_ptr = strtok_s(ptr, ":", &temp_token);
				while (temp_ptr)
				{
					key = temp_ptr;
					temp_ptr = strtok_s(NULL, ":", &temp_token);
					value = temp_ptr;
					temp_ptr = strtok_s(NULL, ":", &temp_token);
					this->encoding_table.emplace(value, key);
				}
				ptr = strtok_s(NULL, " ", &token);
			}
			// We have read Encoding Table now we need to uncompress file

			// Now That I have read the encoding table
			string uncompressed_filename = filename.substr(0, (filename.size() - 3));

			ofstream fout(uncompressed_filename.append("txt"));
			if (fout.is_open())
			{
				while (!fin.eof())
				{
					getline(fin, buffer, '\0');
					buffer_size = buffer.size();
					string buffer_check;

					for (int i = 0; i <= buffer_size; i++)
					{
						buffer_check += (buffer[i]);
						auto itr = encoding_table.find(buffer_check);
						if (itr != encoding_table.end())
						{
							if (buffer_check == itr->first)
							{
								int number = atoi(itr->second.c_str());
								char display = (char)number;
								fout << display;
								//fout << itr->second;
								buffer_check.clear();
							}
						}
					}
				}
			}
			else
				cout << "Unable to open file" << endl;
		}
		fin.close();
	}
	else
		cout << "Unable to open file" << endl;
	*/

	// Custom Changes
	// Now filename contains all the data which needs to be decoded

	// First I will read the encoding table from the compressed file
	// Then will use the user provided data to decode it

	// Reading Encoding Table
	filename = filename.erase(filename.size() - 3, 3);
	filename.append("cmp");
	ifstream fin(filename);
	if (fin.is_open())
	{
		string buffer;
		while (!fin.eof())
		{
			// Reading Encoding Table
			getline(fin, buffer, '\n');
			int buffer_size = buffer.size();

			// Now, tokenize the string
			// key:value[space]key:value[space]key:value
			char* token = nullptr, * ptr;
			ptr = strtok_s(&buffer[0], " ", &token);
			string key, value;
			while (ptr)
			{
				//cout << ptr << endl;
				char* temp_token = nullptr, * temp_ptr;
				temp_ptr = strtok_s(ptr, ":", &temp_token);
				while (temp_ptr)
				{
					key = temp_ptr;
					temp_ptr = strtok_s(NULL, ":", &temp_token);
					value = temp_ptr;
					temp_ptr = strtok_s(NULL, ":", &temp_token);
					this->encoding_table.emplace(value, key);
				}
				ptr = strtok_s(NULL, " ", &token);
			}
			fin.close();
		}
	}
	else
		cout << "Unable to open file" << endl;
	

	cout << "Decoded Message is: ";
	int buffer_size = decode_data.size();
	string buffer_check;

	for (int i = 0; i <= buffer_size; i++)
	{
		buffer_check += (decode_data[i]);
		auto itr = encoding_table.find(buffer_check);
		if (itr != encoding_table.end())
		{
			if (buffer_check == itr->first)
			{
				int number = atoi(itr->second.c_str());
				char display = (char)number;
				cout << display;
				//fout << itr->second;
				buffer_check.clear();
			}
		}
	}


}