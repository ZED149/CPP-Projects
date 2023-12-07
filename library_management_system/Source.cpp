


#include <iostream>
#include <Windows.h>
#include <fstream>
using namespace std;



/******************************** Function Definitions ********************************/
char FILENAME[] = "C:/Users/salma/Desktop/university work/library_management_system/library_management_system/books.txt";
void read_from_file(char book_name[][100], char book_number[][100], char book_department[][100], char book_availability[][100], int& total_number_of_books, char issued_details_to[][100]);
void add_book_to_file(char* path_of_file, int size);
void initialize_array(char arr[][100]);
void print(char book_name[][100], char book_number[][100], char book_department[][100], char book_availability[][100], int size, char issued_details_to[][100]);
void delete_book_from_file(char book_name[][100], char book_number[][100], char book_department[][100], char book_availability[][100], int& total_number_of_books, char issued_details_to[][100]);
void update_book_from_file(char book_name[][100], char book_number[][100], char book_department[][100], char book_availability[][100], int& total_number_of_books, char issued_details_to[][100]);
void menu(char book_name[][100], char book_number[][100], char book_department[][100], char book_availability[][100], int& total_number_of_books, char issued_details_to[][100]);
void available_books(char book_name[][100], char book_number[][100], char book_department[][100], char book_availability[][100], int& total_number_of_books, char issued_details_to[][100]);
void see_issue_record(char book_name[][100], char book_number[][100], char book_department[][100], char book_availability[][100], int& total_number_of_books, char issued_details_to[][100]);



/******************************** Main() Function ********************************/
int main()
{
	//First we need to get data from file
	//variables
	char book_name[10][100], book_number[10][100], book_department[10][100], book_availability[10][100];
	char issued_details_to[10][100];
	int total_number_of_books = 0;
	char path_of_file[] = {*FILENAME};

	//Initializing all arrays to NULL
	initialize_array(book_name);
	initialize_array(book_number);
	initialize_array(book_department);
	initialize_array(book_availability);
	initialize_array(issued_details_to);


	//MENU
	menu(book_name, book_number, book_department, book_availability, total_number_of_books, issued_details_to);
}//main



/******************************** Function Prototypes ********************************/
void menu(char book_name[][100], char book_number[][100], char book_department[][100], char book_availability[][100], int& total_number_of_books, char issued_details_to[][100])
{
	cout << "menu() called" << endl;
	char path_of_file[] = { *FILENAME };
	bool flag = true;
	int choice = 0;

	system("cls");
	do
	{
		cout << "Enter Choice" << endl;
		cout << "Press 1 to read all books" << endl;
		cout << "Press 2 to add a new book" << endl;
		cout << "Press 3 to update an excisting book" << endl;
		cout << "Press 4 to delete an excisting book" << endl;
		cout << "Press 5 to see available books" << endl;
		cout << "Press 6 to see issue record" << endl;
		cout << "Press 7 to exit the program" << endl;
		cin >> choice;

		if (choice == 1)	//read
		{
			system("cls");
			read_from_file(book_name, book_number, book_department, book_availability, total_number_of_books, issued_details_to);
			print(book_name, book_number, book_department, book_availability, total_number_of_books, issued_details_to);
		}
		else if (choice == 2)	//add
		{
			system("cls");
			add_book_to_file(path_of_file, total_number_of_books);
			read_from_file(book_name, book_number, book_department, book_availability, total_number_of_books, issued_details_to);
			print(book_name, book_number, book_department, book_availability, total_number_of_books, issued_details_to);
		}
		else if (choice == 3)	//update
		{
			system("cls");
			update_book_from_file(book_name, book_number, book_department, book_availability, total_number_of_books, issued_details_to);
			read_from_file(book_name, book_number, book_department, book_availability, total_number_of_books, issued_details_to);
			print(book_name, book_number, book_department, book_availability, total_number_of_books, issued_details_to);
		}
		else if (choice == 4)	//delete
		{
			system("cls");
			delete_book_from_file(book_name, book_number, book_department, book_availability, total_number_of_books, issued_details_to);
			read_from_file(book_name, book_number, book_department, book_availability, total_number_of_books, issued_details_to);
			print(book_name, book_number, book_department, book_availability, total_number_of_books, issued_details_to);
		}
		else if (choice == 5)	//available books
		{
			system("cls");
			available_books(book_name, book_number, book_department, book_availability, total_number_of_books, issued_details_to);
		}
		else if (choice == 6)	//see issue record
		{
			system("cls");
			see_issue_record(book_name, book_number, book_department, book_availability, total_number_of_books, issued_details_to);
		}
		else if (choice == 7)	//exit program
			flag = false;
		else	//invalid input
			cout << "Invalid Choice, Please Try Again" << endl;
	} while (flag);
}//menu

void update_book_from_file(char book_name[][100], char book_number[][100], char book_department[][100], char book_availability[][100], int &total_number_of_books, char issued_details_to[][100])
{
	system("cls");
	cout << "update_book_from_file() called" << endl;
	print(book_name, book_number, book_department, book_availability, total_number_of_books, issued_details_to);
	int index = 0;
	cout << "Enter number of book you want to update/edit" << endl;
	cin >> index;
	if (index >= 1 && index <= 10)
	{
		index--;
		char book_name_edited[100], book_number_edited[100], book_department_edited[100];
		char issued_details[100];
		bool book_availability_edited = false;
		cout << "Enter Book Name (edited)" << endl;
		cin.ignore();
		cin.getline(book_name_edited, 100);
		cout << "Enter Book Number (edited)" << endl;
		cin.getline(book_number_edited, 100);
		cout << "Enter Book Department (edited)" << endl;
		cin.getline(book_department_edited, 100);
		cout << "Either the book is available or not [1/0] (edited)" << endl;
		cin >> book_availability_edited;
		cout << "If the book is issued enter roll number else enter '-'" << endl;
		cin.ignore();
		cin.getline(issued_details, 100);

		strcpy_s(book_name[index], strlen(book_name_edited) + 1, book_name_edited);
		strcpy_s(book_number[index], strlen(book_number_edited) + 1, book_number_edited);
		strcpy_s(book_department[index], strlen(book_department_edited) + 1, book_department_edited);
		strcpy_s(issued_details_to[index], strlen(issued_details) + 1, issued_details);
		if(book_availability_edited)
			strcpy_s(book_availability[index], 10 , "Available");
		else
			strcpy_s(book_availability[index], 2 , "-");


		//Now we need to add these details to the file
		//Opening File
		ofstream fout(FILENAME);

		if (fout.is_open())
		{
			fout << "Book Name" << "\t" << "Book Number" << "\t" << "Book Department" << "\t" << "Book Availability" << "\t" << "Issued Details" << endl;
			for (int i = 0; i < total_number_of_books; i++)
			{
				if (i == total_number_of_books - 1)
					fout << book_name[i] << "\t" << book_number[i] << "\t" << book_department[i] << "\t" << book_availability[i] << "\t" << issued_details_to[i];
				else
					fout << book_name[i] << "\t" << book_number[i] << "\t" << book_department[i] << "\t" << book_availability[i] << "\t" << issued_details_to[i] << endl;
			}
		}
		else
			cout << "Unable to open file" << endl;
	}
}//update_book_from_file

void print(char book_name[][100], char book_number[][100], char book_department[][100], char book_availability[][100], int size, char issued_details_to[][100])
{
	cout << "print() called" << endl;
	//printing data
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << "#" << " " << book_name[i] << "\t\t" << book_number[i] << "\t\t" << book_department[i] << "\t\t" << book_availability[i] << "\t\t" << issued_details_to[i] << endl;
	}
}//print

void delete_book_from_file(char book_name[][100], char book_number[][100], char book_department[][100], char book_availability[][100], int& total_number_of_books, char issued_details_to[][100])
{
	//system("cls");
	print(book_name, book_number, book_department, book_availability, total_number_of_books, issued_details_to);
	cout << "Enter the number of book you want to delete" << endl;
	int number = 0;
	cin >> number;
	if (number >= 1 && number <= 10)
	{
		ofstream fout(FILENAME);
		if (fout.is_open())
		{
			if (number == total_number_of_books)
			{
				total_number_of_books--;
				fout << "Book Name" << "\t" << "Book Number" << "\t" << "Book Department" << "\t" << "Book Availability" << "\t" << "Issued Details" << endl;
				for (int i = 0; i < total_number_of_books; i++)
				{
					if (i == (number - 1))
						continue;
					if (i == total_number_of_books - 1)
						fout << book_name[i] << "\t" << book_number[i] << "\t" << book_department[i] << "\t" << book_availability[i] << "\t" << issued_details_to[i];
					else
						fout << book_name[i] << "\t" << book_number[i] << "\t" << book_department[i] << "\t" << book_availability[i] << "\t" << issued_details_to[i] << endl;
				}
			}
			else
			{
				fout << "Book Name" << "\t" << "Book Number" << "\t" << "Book Department" << "\t" << "Book Availability" << "\t" << "Issued Details" << endl;
				for (int i = 0; i < total_number_of_books; i++)
				{
					if (i == (number - 1))
						continue;
					if (i == total_number_of_books - 1)
						fout << book_name[i] << "\t" << book_number[i] << "\t" << book_department[i] << "\t" << book_availability[i] << "\t" << issued_details_to[i];
					else
						fout << book_name[i] << "\t" << book_number[i] << "\t" << book_department[i] << "\t" << book_availability[i] << "\t" << issued_details_to[i] << endl;
				}
				--total_number_of_books;
			}
		}
		else
			cout << "Unable to open file" << endl;
	}
	else
		return;
}

void read_from_file(char book_name[][100], char book_number[][100], char book_department[][100], char book_availability[][100], int &total_number_of_books, char issued_details_to[][100])
{
	cout << "read_from_file() called" << endl;
	ifstream fin(FILENAME);
	total_number_of_books = 0;

	if (fin.is_open())
	{
		char buffer[500];
		fin.getline(buffer, 500, '\n');
		int indexi = 0;
		char name[100], number[100], department[100], availability[100], issued_details[100];
		while (!fin.eof())
		{
			//fin >> name >> number >> department;
			fin >> name >> number >> department >> availability >> issued_details;
			strcpy_s(book_name[indexi], strlen(name) + 1, name);
			strcpy_s(book_number[indexi], strlen(number) + 1, number);
			strcpy_s(book_department[indexi], strlen(department) + 1, department);
			strcpy_s(book_availability[indexi], strlen(availability) + 1, availability);
			strcpy_s(issued_details_to[indexi], strlen(issued_details) + 1, issued_details);
			indexi++;
			total_number_of_books++;
		}
	}
	else
		cout << "Unable to open file" << endl;

}//read_from_file

void initialize_array(char arr[][100])
{
	//initializing array to '-1'
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 100; j++)
			arr[i][j] = '\0';
	}
}//initialize_array

void add_book_to_file(char* path_of_file, int size)
{
	cout << "add_book_to_file() called" << endl;
	
	if (size <= 9)
	{
		//First we need to prompt data from user
		char book_name[100], book_number[100], book_department[100];
		bool book_availability = false;
		cin.ignore();
		cout << "Enter Book Name" << endl;
		cin.getline(book_name, 100);
		cout << "Enter Book Number" << endl;
		cin.getline(book_number, 100);
		cout << "Enter Book Department" << endl;
		cin.getline(book_department, 100);
		cout << "Either the book is available or not [1/0]" << endl;
		cin >> book_availability;

		//Now we need to add these details to the file
		//Opening File
		ofstream fout(FILENAME, ios::app);

		if (fout.is_open())
		{
			if (book_availability)
				fout << endl << book_name << '\t' << book_number << "\t" << book_department << "\t" << "Available" << "\t" << "Not-Issued";
			else
				fout << endl << book_name << '\t' << book_number << "\t" << book_department << "\t" << "-" << "\t" << "Not-Issued";
		}
		else
			cout << "Unable to open file" << endl;
	}
	else
		return;
}//add_book_to_file

void available_books(char book_name[][100], char book_number[][100], char book_department[][100], char book_availability[][100], int& total_number_of_books, char issued_details_to[][100])
{
	cout << "available_books() called" << endl;
	for (int i = 0; i < total_number_of_books; i++)
	{
		if(book_availability[i][0] == 'A')
			cout << i + 1 << "#" << " " << book_name[i] << "\t\t" << book_number[i] << "\t\t" << book_department[i] << "\t\t" << book_availability[i] << "\t\t" << issued_details_to[i] << endl;
	}
}

void see_issue_record(char book_name[][100], char book_number[][100], char book_department[][100], char book_availability[][100], int& total_number_of_books, char issued_details_to[][100])
{
	cout << "see_issue_record() called" << endl;
	for (int i = 0; i < total_number_of_books; i++)
		if (issued_details_to[i][0] == 'l')
			cout << i + 1 << "#" << " " << book_name[i] << "\t\t" << book_number[i] << "\t\t" << book_department[i] << "\t\t" << book_availability[i] << "\t\t" << issued_details_to[i] << endl;
}