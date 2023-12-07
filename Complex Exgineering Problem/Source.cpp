


#include <iostream>
#include "zip.h"
#include <string>
using namespace std;



int main(int argc, char** argv)
{
	////Checking Interface
	//zip::Interface(argc, argv);

	string filename = "D:/test/test.txt";
	zip obj;
	// Encrypted Data
	cout << "Enter Data to be Encryted" << endl;
	string encrypt_data;
	string keys_file = filename;
	getline(cin, encrypt_data);
	// Keys File
	cout << "Enter File to write keys" << endl;
	getline(cin, keys_file);
	ofstream fout(filename);
	for (int i = 0; i < encrypt_data.size(); i++)
		fout << encrypt_data[i];
	fout.close();
	obj.Compress(filename, encrypt_data);
	obj.PrintEncodingTable();
	obj.WriteKeys(keys_file);
	cout << "Enter Data you want to decode" << endl;
	string decode_data;
	getline(cin, decode_data, '\n');
	obj.ClearEncodingTable();
	obj.Decompress(filename, decode_data);
	cout << "\n----------------------------" << endl;
}