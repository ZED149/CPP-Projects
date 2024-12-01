

//#pragma once
#ifndef SENECA_MOVIE_H
#define SENECA_MOVIE_H
// this file contains the movie.h code

// including libraries and modules
#include "mediaItem.h"
#include <string>
using namespace std;


// SENECA namespace
namespace seneca
{
	// movie class
	class Movie : public MediaItem
	{
	public:
		// constructor
		Movie(const string& m_title, const string& m_summary, const unsigned short year);

		// member functions

		// display
		void display(ostream& out) const override;

		// createItem
		static Movie* createItem(const string& strMovie);
	};
}
#endif
