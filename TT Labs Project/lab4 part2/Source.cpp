

// This file contains the Question 2 of Lab 4


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Standard Deviation Function Prototype
double standardDeviation(unsigned count, float mean, float *&dataArray);

int main()
{
	// opening file for reading
	ifstream fin("dataArray.txt", ios::in || ios::app);
	// checking if file is not opened
	if (!fin.is_open())
	{
		cout << "Error opening dataArray.txt for reading\n";
		return 1;
	}

	// If file is opened
	// reading count from file
	char _count[50];
	fin.getline(_count, 50, '\n');
	// converting count to integer as it cannot be a floating point
	int count = atoi(_count);

	// creating a dynamic array of N size
	float* dataArray = new float[count];

	// iterating to file till count 
	float sum = 0.0f, temp = 0.0f;
	char buffer[20];
	for (int i = 0; i < count; i++)
	{
		fin.getline(buffer, 20, ',');
		temp = atof(buffer);
		dataArray[i] = temp;
		sum += temp;
	}

	// closing file
	fin.close();

	// printing to console
	cout << "The number of floating point values (N):\t" << count << endl;
	float mean = sum/count;
	cout << "The mean of floating point values:\t" << mean << endl;
	//cout << "Address of data array before passing is: " << &dataArray << endl;
	cout << "The sample standard deviation (s):\t" << standardDeviation(count, mean, dataArray) << endl;

	// deleting dynamic dataArray
	delete [] dataArray;
}


// Standard Deviation Function Definition
double standardDeviation(unsigned count, float mean, float *&dataArray)
{
	//cout << "Address of data array after passing is: " << &dataArray << endl;
	// This function calculates the standard deviation
	// count represents N
	// mean represents average

	// implementing sigma notation
	// iterating till N times
	float sum = 0.0f;
	float temp = 0;
	for (int i = 0; i < count; i++)
	{
		temp = pow((dataArray[i] - mean), 2);
		sum += temp;
	}

	sum = sum / (count - 1);
	sum = pow(sum, 0.5);
	return sum;
}