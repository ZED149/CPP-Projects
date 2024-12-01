

// this file contains the book.h implementations

// including libraries and modules
#include "book.h"
using namespace seneca;
#include <string>
using namespace std;
#include <iomanip>
#include "settings.h"
#include <sstream>
#include <stdexcept>


// Constructor
Book::Book(string m_title, string m_summary, unsigned short m_year, string m_author, string m_country
	, double m_price):
	MediaItem(m_title, m_summary, m_year), m_author(m_author), m_country(m_country), m_price(m_price)
{
#ifdef _DEBUG
	cout << "Book() called\n";
#endif
}


// member functions

// display
void Book::display(ostream& out) const 
{
#ifdef _DEBUG
	cout << "Book() display() called\n";
#endif // _DEBUG

	if (g_settings.m_tableView)
	{
		out << "B | ";
		out << std::left << std::setfill('.');
		out << std::setw(50) << this->getTitle() << " | ";
		out << std::right << std::setfill(' ');
		out << std::setw(2) << this->m_country << " | ";
		out << std::setw(4) << this->getYear() << " | ";
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
		out << this->getTitle() << " [" << this->getYear() << "] [";
		out << m_author << "] [" << m_country << "] [" << m_price << "]\n";
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
Book* Book::createItem(const string& strBook)
{
#ifdef _DEBUG
	cout << "Book() createItem() called\n";
#endif	//Debug

	std::istringstream stream(strBook);
	std::string title, summary, yearStr, author, country, priceStr;

	if (std::getline(stream, author, ',') &&
		std::getline(stream, title, ',') &&
		std::getline(stream, country, ',') &&
		std::getline(stream, priceStr, ',') &&
		std::getline(stream, yearStr, ',') &&
		std::getline(stream, summary)) {

		MediaItem::trim(title);
		MediaItem::trim(summary);
		MediaItem::trim(yearStr);
		MediaItem::trim(author);
		MediaItem::trim(country);
		MediaItem::trim(priceStr);

		try {
			unsigned short year = static_cast<unsigned short>(std::stoi(yearStr));
			double price = std::stod(priceStr);
			return new Book(title, summary, year, author, country, price);
		}
		catch (...) {
			throw std::string("Invalid record for Book: " + strBook);
		}
	}

	throw std::string("Malformed record: " + strBook);
}