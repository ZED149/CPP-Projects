
#define _CRT_SECURE_NO_WARNINGS

#include "Event.h"
#include <iostream>
#include <string>
#include "Film.h"
#include "StandUpComedy.h"
#include "LiveMusic.h"
#include "Person.h"
#include "Seat.h"
#include "PSH.h"
#include <typeinfo>
#include <Windows.h>
#include <fstream>
using namespace std;



// Static Data Members
// Event Names List
vector<string> Event::event_names;
// Event Details List
vector<Event*> Event::event_details;

vector<Person> Event::person_details;
vector<Seat> Event::seat_details;
vector<Film> Event::film_details;
vector<LiveMusic> Event::live_music_details;
vector<StandUpComedy> Event::stand_up_comedy_details;

// Utlitiy Functions
// Initialize
void Event::initialize()
{
	// This is the method which initialize all the important things for startup
	// It is called only once and is the first method to run

	//calling driver(menu) method
	driver();
}

// Driver
void Event::driver()
{
	// This is the menu code of the program
	/*
	* 1. Add a Booking.
	* 2. Cancel a Booking.
	* 3. List all Events.
	* 4. List details of a given event.
	* 5. Load data from a file.
	* 6. Save data to a file.
	*/

	// ---FROM HERE---//
	bool flag = true;
	int input = 0;
	while (flag)
	{
		system("cls");
		cout << "--MENU--" << endl;
		cout << "|\t '1' for Add a Booking for an event" << endl;
		cout << "|\t '2' for Cancel a Booking from an event" << endl;
		cout << "|\t '3' for Listing all events" << endl;
		cout << "|\t '4' for List details of a given event" << endl;
		cout << "|\t '5' Load from a file" << endl;
		cout << "|\t '6' Save to a file" << endl;

		cout << "Enter Input ..." << endl;
		cin >> input;

		// checking the input
		if (input == 1)
		{
			// Add a Booking
			string _event_name;
			cout << "Enter the event name to add booking" << endl;
			cin.ignore();
			getline(cin, _event_name);
			bool event_name_flag = false;
			
			// checking event name
			// we need to search through event_details list
			auto itr = event_details.begin();
			while (itr != event_details.end())
			{
				if ((*itr)->unique_event_name == _event_name)
				{
					// Event match found
					Film* f = dynamic_cast<Film*>(*itr);
					LiveMusic* lm = dynamic_cast<LiveMusic*>(*itr);
					StandUpComedy* suc = dynamic_cast<StandUpComedy*>(*itr);
					event_name_flag = true;
					//string check = typeid((f)).name();

					if (f != NULL)
					{
						// Film
						//cout << "It is of Film Type" << endl;
						cout << "Enter Number of tickets you want to purchase for the event [" << _event_name << "]" << endl;
						int temp = 0;
						cin >> temp;
						f->BuyTicket(temp);
					}
					else if (lm != NULL)
					{
						// Live Music
						//cout << "It is of Live Music Type" << endl;
						cout << "Enter number of tickets you want to purchase for the event [" << _event_name << "]" << endl;
						int temp = 0;
						cin >> temp;
						lm->BuyTicket(temp);
					}
					else if (suc != NULL)
					{
						// Stand Up Comedy
						//cout << "It is of Stand Up Comedy Type" << endl;
						cout << "Enter Following Details to purchase seat for the event [" << _event_name << "]" << endl;
						int seat_number = 0;
						cout << "Enter Seat Number: " << endl;
						cin >> seat_number;
						cout << "Enter Name" << endl;
						string buffer;
						cin.ignore();
						getline(cin, buffer);
						cout << "Enter Age" << endl;
						int age = 0;
						cin >> age;
						cout << "Enter Phone Number" << endl;
						int phone_number = 0;
						cin >> phone_number;

						Person p(buffer, phone_number, age);
						Seat s(seat_number);
						person_details.push_back(p);
						seat_details.push_back(s);
						auto p_itr = person_details.end() - 1;
						auto s_itr = seat_details.end() - 1;
						Person* p_temp = &(*p_itr);
						Seat* s_temp = &(*s_itr);
						suc->ReserveSeat(*p_temp, *s_temp);
					}
					f = nullptr;
					lm = nullptr;
					suc = nullptr;
				}
				itr++;
			}
			if (!event_name_flag)
			{
				cout << "Event name does't exist" << endl;
			}
		}
		else if (input == 2)
		{
			// Cancel a Booking
			string _event_name;
			cout << "Enter the event name to refund/cancel booking" << endl;
			cin.ignore();
			getline(cin, _event_name);

			// now we need to iterate thorugh the event_details list
			vector<Event*>::iterator itr = event_details.begin();
			bool event_name_flag = false;
			while (itr != event_details.end())
			{
				if ((*itr)->unique_event_name == _event_name)
				{
					// If a match is found
					event_name_flag = 1;
					Film* f = dynamic_cast<Film*>(*itr);
					LiveMusic* lm = dynamic_cast<LiveMusic*>(*itr);
					StandUpComedy* suc = dynamic_cast<StandUpComedy*>(*itr);

					if (f != NULL)
					{
						// Film
						cout << "Enter number of tickets that you want to cancel from the event [" << _event_name << "]" << endl;
						int temp = 0;
						cin >> temp;
						f->CancelTicket(temp);
					}
					else if (lm != NULL)
					{
						// Live Music
						cout << "Enter number of tickers that you want to cancel from the event [" << _event_name << "]" << endl;
						int temp = 0;
						cin >> temp;
						lm->CancelTicket(temp);
					}
					else if (suc != NULL)
					{
						// Stand Up Comedy
						cout << "Enter Following Details to cancel seat from the event [" << _event_name << "]" << endl;
						int seat_number = 0;
						cout << "Enter Seat Number: " << endl;
						cin >> seat_number;

						Person p("", 0, 0);
						Seat s(seat_number);
						suc->CancelSeat(p, s);
					}
					f = nullptr;
					lm = nullptr;
					suc = nullptr;
				}
				itr++;
			}
			if (!event_name_flag)
				cout << "Event name does't exist" << endl;
		}
		else if (input == 3)
		{
			// List All Events
			Event::ListAllEvents();
			Sleep(2000);
		}
		else if (input == 4)
		{
			// List Details of a Given Event
			cout << "Enter name of the event to find details" << endl;
			string event_name;
			cin.ignore();
			getline(cin, event_name);

			vector<Event*>::iterator itr = event_details.begin();
			bool event_name_flag = false;
			while (itr != event_details.end())
			{
				if ((*itr)->unique_event_name == event_name)
				{
					// If a match is found
					event_name_flag = true;
					cout << "Details Are: " << endl;
					(*itr)->Print();
					Sleep(5000);
				}
				itr++;
			}
			if (!event_name_flag)
				cout << "Event name doesn't exist" << endl;
		}
		else if (input == 5)
		{
			// Load from a file
			
			// opening file
			ifstream fin("../test.txt");

			// checking for errors
			if (fin.is_open())
			{
				// read file till its end
				//char buffer[5000];
				string buffer;
				while (!fin.eof())
				{
					// read whole line till endl '\n'
					getline(fin, buffer);

					// checking first word of line
					char* token = nullptr, * next_token = nullptr;
					const char* temp_buffer = buffer.c_str();
					token = strtok_s((char*)temp_buffer, "$", &next_token);
					
					// checking on the basis of token
					if (token != nullptr)
					{
						if (strcmp(token, "FILM") == 0)
						{
							// Film

							// declaring required variables
							string name, seating_style, seating_critera, screen;
							bool availability;
							int seating_capacity, total_tickets;

							// tokenizing further on the basis of delimeters ","
							int counter = 1;
							while (token)
							{
								token = strtok_s(NULL, ",", &next_token);
								switch (counter)
								{
								case 1:
									// Unique Event Name
									name = token;
									break;
								case 2:
									// Availability
									availability = (bool)token;
									break;
								case 3:
									// Seating Capacity
									seating_capacity = atoi(token);
									break;
								case 4:
									// Seating Style
									seating_style = token;
									break;
								case 5:
									// Seating Criteria
									seating_critera = token;
									break;
								case 6:
									// Screen
									screen = token;
									break;
								case 7:
									// Total Tickets
									total_tickets = atoi(token);
									break;
								}
								counter++;
							}

							// now that we have all the required values
							// we can create a FILM object and can pass these values as arguments
							Film f(availability, seating_capacity, seating_style, seating_critera, screen, name, total_tickets);
							film_details.push_back(f);

						}
						else if (strcmp(token, "LIVE_MUSIC") == 0)
						{
							// Live Music

							// declaring required variables
							string name, seating_style, seating_critera;
							bool availability;
							int seating_capacity, total_tickets;

							// tokenizing further on the basis of delimeters ","
							int counter = 1;
							while (token)
							{
								token = strtok_s(NULL, ",", &next_token);
								switch (counter)
								{
								case 1:
									// Unique Event Name
									name = token;
									break;
								case 2:
									// Availability
									availability = (bool)token;
									break;
								case 3:
									// Seating Capacity
									seating_capacity = atoi(token);
									break;
								case 4:
									// Seating Style
									seating_style = token;
									break;
								case 5:
									// Seating Criteria
									seating_critera = token;
									break;
								case 6:
									// Screen
									total_tickets = atoi(token);
									break;
								}
								counter++;
							}

							// now that we have all the required values
							// we can create a FILM object and can pass these values as arguments
							LiveMusic lm(availability, seating_capacity, seating_style, seating_critera, name, total_tickets);
							live_music_details.push_back(lm);
						}
						else if (strcmp(token, "STAND_UP_COMEDY") == 0)
						{
							// Stand Up Comedy

							// declaring required variables
							string name, seating_style, seating_critera;
							bool availability;
							int seating_capacity;

							// tokenizing further on the basis of delimeters ","
							int counter = 1;
							while (token)
							{
								token = strtok_s(NULL, ",", &next_token);
								switch (counter)
								{
								case 1:
									// Unique Event Name
									name = token;
									break;
								case 2:
									// Availability
									availability = (bool)token;
									break;
								case 3:
									// Seating Capacity
									seating_capacity = atoi(token);
									break;
								case 4:
									// Seating Style
									seating_style = token;
									break;
								case 5:
									// Seating Criteria
									seating_critera = token;
									break;
								}
								counter++;
							}

							StandUpComedy suc(availability, seating_capacity, seating_style, seating_critera, name);


							// now we need to get people data and their seats
							string person_name;
							int age, phone_number, seat_number;
							counter = 0; // reseting counter
							while (token)
							{
								token = strtok_s(NULL, ":", &next_token);
								if (token == "@")
								{
									// reset counter again
									counter = 0;
								}
								else
								{
									switch (counter)
									{
									case 1:
										// Peron Name
										person_name = token;
										break;
									case 2:
										// Age
										age = atoi(token);
										break;
									case 3:
										// Phone Number
										phone_number = atoi(token);
										break;
									case 4:
										// Seat Number
										seat_number = atoi(token);
										break;
									}
									counter++;
								}
								Person p_temp(person_name, phone_number, age);
								Seat s_temp(seat_number);
								person_details.push_back(p_temp);
								seat_details.push_back(s_temp);
								vector<Person>::iterator p_itr = person_details.end() - 1;
								vector<Seat>::iterator s_itr = seat_details.end() - 1;
								suc.ReserveSeat(*p_itr, *s_itr);
							}

							// now that we have all the required values
							// we can create a FILM object and can pass these values as arguments
							stand_up_comedy_details.push_back(suc);
						}
					}
				}

				// Now we need to insert all into event details
				// inserting film details
				auto f_itr = film_details.begin();
				while (f_itr != film_details.end())
				{
					event_names.push_back((*f_itr).GetEventName());
					event_details.push_back(&(*f_itr));
					f_itr++;
				}
				// inserting live music details
				auto lm_itr = live_music_details.begin();
				while (lm_itr != live_music_details.end())
				{
					event_names.push_back((*lm_itr).GetEventName());
					event_details.push_back(&(*lm_itr));
					lm_itr++;
				}
				// inserting stand up comedy details
				auto suc_itr = stand_up_comedy_details.begin();
				while (suc_itr != stand_up_comedy_details.end())
				{
					event_names.push_back((*suc_itr).GetEventName());
					event_details.push_back(&(*suc_itr));
					suc_itr++;
				}
			}
			else
				perror("Error opening file for loading\n");
		}
		else if (input == 6)
		{
			// Save to a file
			//ofstream out("../test.txt", ios::out);
			ofstream fout("../test.txt", ios::out);
			if (fout.is_open())
			{
				auto itr = event_details.begin();
				while (itr != event_details.end())
				{
					// dynamic casting the iterator
					Film* f = dynamic_cast<Film*>(*itr);
					LiveMusic* lm = dynamic_cast<LiveMusic*>(*itr);
					StandUpComedy* suc = dynamic_cast<StandUpComedy*>(*itr);

					// checking on the basis of its types
					if (f != NULL)
					{
						// Film

						fout << "FILM$";
						// printing base attributes
						fout << (*itr)->unique_event_name << ",";
						fout << (*itr)->availability << ",";
						fout << (*itr)->seating_capacity << ",";
						fout << (*itr)->seating_style << ",";
						fout << (*itr)->seating_criteria << ",";
						// printing derived attributes
						boolalpha;
						fout << f->GetScreen() << ",";
						fout << f->GetTotalTickets() << endl;
					}
					else if (lm != NULL)
					{
						// Live Music

						fout << "LIVE_MUSIC$";
						// printing base attributes
						fout << (*itr)->unique_event_name << ",";
						fout << (*itr)->availability << ",";
						fout << (*itr)->seating_capacity << ",";
						fout << (*itr)->seating_style << ",";
						fout << (*itr)->seating_criteria << ",";
						// printing derived attributes
						fout << lm->GetTotalTickets() << endl;
					}
					else if (suc != NULL)
					{
						// Stand Up Comedy

						fout << "STAND_UP_COMEDY$";
						// printing base attributes
						fout << (*itr)->unique_event_name << ",";
						fout << (*itr)->availability << ",";
						fout << (*itr)->seating_capacity << ",";
						fout << (*itr)->seating_style << ",";
						fout << (*itr)->seating_criteria << ",";

						// priting derived attributes
						vector<PSH> *suc_seating_array = &(suc->GetSeatingArrayReference());
						// We need to iterate through this seating array
						// but keep in mind, don't change anything
						auto temp_itr = (*suc_seating_array).begin();
						while (temp_itr != (*suc_seating_array).end())
						{
							Person p_temp = temp_itr->GetPersonDetail();
							Seat s_temp = temp_itr->GetSeatBooked();
							fout << p_temp.GetName() << ":";
							fout << p_temp.GetAge() << ":";
							fout << p_temp.GetPhoneNumber() << ":";
							fout << s_temp.GetSeatNumber() << "@";
							temp_itr++;
						}
						fout << endl;
					}
					itr++;
				}


				// need to close file before finishing
				fout.close();
			}
			else
			{
				perror("Error opening file for saving\n");
				return;
			}
		}
		else if (input == 0)
		{
			cout << "Terminating Program..." << endl;
			flag = false;
		}
		else
		{
			cout << "Invalid Input. Please enter again." << endl;
		}
	}
}

// Constructor
// Default Constructor
Event::Event()
{
	//cout << "Event() called" << endl;
	this->availability = false;
	this->seating_capacity = 0;
	this->seating_criteria = this->seating_style = "NILL";
	this->unique_event_name = "NILL";
}


// Constrcutor With Params
Event::Event(bool availability, int seating_capacity, string seating_style, string seating_criteria, 
	string event_name)
{
	//cout << "Event(params) calld" << endl;
	this->availability = availability;
	this->seating_capacity = seating_capacity;
	this->seating_style = seating_style;
	this->seating_criteria = seating_criteria;
	this->event_names.push_back(event_name);
	this->unique_event_name = event_name;
	
	
}

// Member Functions
// List All Events
void Event::ListAllEvents()
{
	cout << "--------------------------------------------------------------" << endl;
	cout << "|\tEvent Names Are As Follow: " << endl;
	auto itr = event_names.begin();
	int counter = 1;
	while (itr != event_names.end())
	{
		cout << "|\t\t" << counter++ << ".   " << *itr << "\n";
		itr++;
	}
	cout << "--------------------------------------------------------------" << endl;
	cout << endl;
}

// Delete From Event Details
void Event::DeleteFromEventDetails(string event_name)
{
	// First we will find about the event name
	auto itr = event_details.begin();
	while (itr != event_details.end())
	{
		if ((*itr)->unique_event_name == event_name)
		{
			// if a match is found
			this->event_details.erase(itr);
			return;
		}
		itr++;
	}
}

// Initialize
void Event::Initialize()
{
	initialize();
}

// Destructor
Event::~Event()
{
	//cout << "~Event() called" << endl;
	// Find that specific name of event to be removed from the list
	auto itr = this->event_names.begin();
	while (itr != this->event_names.end())
	{
		if (*itr == this->unique_event_name)
			break;
		itr++;
	}
	if(itr != this->event_names.end())
		this->event_names.erase(itr);
}