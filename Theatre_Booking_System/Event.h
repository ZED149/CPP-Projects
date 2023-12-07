
#pragma once

#include <iostream>
#include <vector>
#include "Person.h"
#include "Seat.h"
#include "PSH.h"
#include <string>
using namespace std;


/* This is the Event Class
 - It acts as a Base Class for the whole system
 */

class Film;
class LiveMusic;
class StandUpComedy;
class Event
{
protected:
	bool availability;
	int seating_capacity;
	string seating_style, seating_criteria;
	string unique_event_name;
	static vector<string> event_names;
	static vector<Event*> event_details;
	static vector<Person> person_details;
	static vector<Seat> seat_details;
	static vector<Film> film_details;
	static vector<LiveMusic> live_music_details;
	static vector<StandUpComedy> stand_up_comedy_details;

	// Utility Functions
	// Initialize
	static void initialize();

	// Driver 
	static void driver();

public:	// This is where the member goes
	// Constructor
	// Default Constructor
	Event();

	// Constructor with params
	// "Film" for Films
	// "StandUpComdey" for Stand Up Comedy
	// "LiveMusic" for Live Music
	Event(bool availability, int seating_capacity, string seating_style, string seating_critera, 
		string event_name);

	// Member Functions
	// Print
	virtual void Print() = 0;

	// List All Events
	static void ListAllEvents();

	// Initialize
	static void Initialize();

	// Delete From Event Details
	void DeleteFromEventDetails(string event_name);

	// Destructor
	~Event();

};