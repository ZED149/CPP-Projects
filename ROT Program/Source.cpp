


#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;


// Functions Prototypes
string ROT_13(const char* str)
{
	string temp(str);

	// iterating through temp
	for (int i = 0; i < temp.size(); i++)
	{
		// condition for space character '32'
		if (temp[i] == 32)
			continue;

		if (temp[i] >= 65 && temp[i] <= 77)
		{
			// +13
			temp[i] = temp[i] + 13;
		}
		else
		{
			// -13
			temp[i] = temp[i] - 13;
		}
	}

	return temp;
}

int main()
{
	/*
	* 1. Ask user whether to encode or decode, if no then terminate
	* 2. If user want to encode then take input string from the user
	* 3. Now encode this string according to the rot-13 algoritm
	* 4. Output it to the screen
	* NOTE: String won't be more then 25 characters. Space will be replaced with space and there would be no punctuation in the string
	*/


	// Taking input from user
	string buffer;
	cout << "Enter encode|decode" << endl;
	//getline(cin, buffer, '\n');		// breaks input at new line character
	buffer = "decode";
	
	// comparing input string
	if (strcmp("encode", buffer.c_str()) == 0)
	{
		cout << "Enter string to be encoded" << endl;
		string encoded_string;
		//getline(cin, encoded_string, '\n');
		encoded_string = "ALPHABET ALPHABET    ALPHABET           ALPHABET";
		string check = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

		// Iterating through the string
		
		string str = ROT_13(check.c_str());
		cout << str << endl;
	}
	else if (strcmp("decode", buffer.c_str()) == 0)
	{
		cout << "Enter string to be decoded" << endl;
		string encoded_string;
		//getline(cin, encoded_string, '\n');
		encoded_string = "NYCUNORG NYCUNORG NYCUNORG     NYCUNORG     NYCUNORG            NYCUNORG";
		string check = "NOPQRSTUVWXYZABCDEFGHIJKLM";

		// Iterating through the string

		string str = ROT_13(check.c_str());
		cout << str << endl;
	}

}