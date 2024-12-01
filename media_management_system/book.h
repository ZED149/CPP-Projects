
//#pragma once

// includes header file for BOOK.H

#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H

// including libraries
#include "mediaItem.h"
#include <string>
#include "settings.h"
using namespace std;

namespace seneca
{
	// Book class
	class Book: public MediaItem
	{
		// private data members
		string m_author;			// name of the author of the book
		string m_country;			// the country of the publication
		double m_price;				// price of the book

		// public functions
	public:
		// Contructor
		Book(string m_title, string m_summary, unsigned short m_year, string m_author, string m_country
			, double m_price);

	public:
		// member functions
		
		// display
		void display(ostream& out) const override;

		// createItem
		static Book* createItem(const string& strBook);
	};
	
}

#endif	// SENECA_BOOK_H
