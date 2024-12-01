

// this file contains the implementation of movie class

// including libraries
#include "movie.h"
#include <string.h>
using namespace std;
using namespace seneca;
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include "settings.h"


// constructor
Movie::Movie(const string& m_title, const string& m_summary, const unsigned short year):
	MediaItem(m_title, m_summary, year)
{
#ifdef _DEBUG
	cout << "Movie() called\n";
#endif
}


// member functions

// display
void Movie::display(ostream& out) const
{
#ifdef _DEBUG
	cout << "Movie() display() called\n";
#endif

	if (g_settings.m_tableView)
	{
		out << "M | ";
		out << std::left << std::setfill('.');
		out << std::setw(50) << this->getTitle() << " | ";
		out << std::right << std::setfill(' ');
		out << std::setw(9) << this->getYear() << " | ";
		out << std::left;
		if (g_settings.m_maxSummaryWidth > -1)
		{
			if (static_cast<short>(this->getSummary().size()) <=
				g_settings.m_maxSummaryWidth)
				out << this->getSummary();
			else
				out << this->getSummary().substr(0, g_settings.m_maxSummaryWidth - 3) <<
				"...";
		}
		else
			out << this->getSummary();
		out << std::endl;
	}
	else
	{
		size_t pos = 0;
		out << this->getTitle() << " [" << this->getYear() << "]\n";
		out << std::setw(this->getTitle().size() + 7) << std::setfill('-') << "" << '\n';
		while (pos < this->getSummary().size())
		{
			out << " " << this->getSummary().substr(pos, g_settings.m_maxSummaryWidth)
				<< '\n';
			pos += g_settings.m_maxSummaryWidth;
		}
		out << std::setw(this->getTitle().size() + 7) << std::setfill('-') << ""
			<< std::setfill(' ') << '\n';
	}
}


// createItem
Movie* Movie::createItem(const string& movieStr)
{
#ifdef _DEBUG
	cout << "Movie() createItem() called\n";
#endif

	std::istringstream stream(movieStr);
	std::string title, summary, yearStr;

	if (std::getline(stream, title, ',') &&
		std::getline(stream, yearStr, ',') &&
		std::getline(stream, summary, ',')) {

		MediaItem::trim(title);
		MediaItem::trim(summary);
		MediaItem::trim(yearStr);

		try {
			unsigned short year = static_cast<unsigned short>(std::stoi(yearStr));
			return new Movie(title, summary, year);
		}
		catch (...) {
			throw std::string("Invalid record for Movie: " + movieStr);
		}
	}

	throw std::string("Malformed record: " + movieStr);
}