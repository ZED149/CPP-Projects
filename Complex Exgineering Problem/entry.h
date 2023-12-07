
#pragma once

#include <iostream>
#include <string>
#include <Windows.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;


class entry
{
	// Private Data Members
	string symbol;
	long long int term_frequency;

	entry* left_child;
	entry* right_child;


	// Utility Functions
	// Copy Wrapper
	void copy_wrapper(entry& currObject, const entry& objptrObject)
	{
		copy(currObject.left_child, objptrObject.left_child);
		copy(currObject.right_child, objptrObject.right_child);

		if (objptrObject.left_child == nullptr)
			currObject.left_child = nullptr;
		if (objptrObject.right_child == nullptr)
			currObject.right_child = nullptr;
	}


	// Copy
	void copy(entry*& curr, entry* objptr)
	{
		//Using Pre Order
		if (objptr)
		{
			curr = new entry(objptr->symbol, objptr->term_frequency);
			copy(curr->left_child, objptr->left_child);
			copy(curr->right_child, objptr->right_child);
		}
	}


	// Encoding Table Wrapper
	void encoding_table_wrapper(entry& root, map<string, string>& encoding_table)
	{
		if (root.left_child == nullptr && root.right_child == nullptr)
		{
			encoding_table.emplace(root.symbol, "0");
			return;
		}

		this->encoding_table(root.left_child, encoding_table, "0");
		this->encoding_table(root.right_child, encoding_table, "1");
	}


	// Encoding Table
	void encoding_table(entry*& curr, map<string, string>& encoding_table, string ancestor_array)
	{
		if (curr)
		{
			if (curr->left_child == nullptr && curr->right_child == nullptr)
			{
				//cout << ancestor_array << endl;
				encoding_table.emplace(curr->symbol, ancestor_array);
				return;
			}

			this->encoding_table(curr->left_child, encoding_table, ancestor_array.append("0"));
			ancestor_array = ancestor_array.substr(0, (ancestor_array.size() - 1));
			this->encoding_table(curr->right_child, encoding_table, ancestor_array.append("1"));
		}
	}


	// Delete
	void Delete(entry*& curr)
	{
		if (curr)
		{
			Delete(curr->left_child);
			Delete(curr->right_child);
			delete curr;
			curr = nullptr;
		}
	}

public:	// This is where the member goes
	//Constructors
	//Default Constructor with params
	entry(string symbol = "-", long long int term_frequency = -1, entry* left_child = nullptr, entry* right_child = nullptr) :
		symbol(symbol), term_frequency(term_frequency)
	{
		//cout << "entry() called" << endl;
		if (left_child)
			this->left_child = new entry(*left_child);
		else
			this->left_child = nullptr;
		if (right_child)
			this->right_child = new entry(*right_child);
		else
			this->right_child = nullptr;
	}


	// Copy Constructor
	entry(const entry& obj)
	{
		this->symbol = obj.symbol;
		this->term_frequency = obj.term_frequency;

		// recursively copy data of left and right child
		copy_wrapper(*this, obj);
	}


	// Operator Overloading
	// Less Than Operator "<"
	const int operator < (const entry& obj)const
	{
		return this->term_frequency < obj.term_frequency ? true : false;
	}


	// Greater Than Operator ">"
	const int operator > (const entry& obj)const
	{
		return this->term_frequency > obj.term_frequency ? true : false;
	}


	// Assignment Operator "="
	const entry& operator = (const entry& obj)
	{
		this->symbol = obj.symbol;
		this->term_frequency = obj.term_frequency;

		// recursively copy data of left and right child
		copy_wrapper(*this, obj);

		return *this;
	}


	// Getters
	// Get Term Frequency
	int GetTermFrequency()
	{
		return this->term_frequency;
	}


	// Get Encoding Table
	void GetEncodingTable(map<string, string>& encoding_table)
	{
		// This method will take that specific root [entry-object]
		// and will convert it into the encoding table

		this->encoding_table_wrapper(*this, encoding_table);
	}


	// Destructor
	~entry()
	{
		//cout << "~entry() called" << endl;
		if (this->left_child)
		{
			Delete(this->left_child);
			this->left_child = nullptr;
		}
		else
			this->left_child = nullptr;
		if (this->right_child)
		{
			Delete(this->right_child);
			this->right_child = nullptr;
		}
		else
			this->right_child = nullptr;
		this->term_frequency = -1;
		this->symbol = '/';
	}
};