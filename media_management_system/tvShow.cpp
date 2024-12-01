

// this file contatins the implementations of the TvShow header file


// including important libraries
#include "settings.h"
#include "tvShow.h"
#include <string>
#include <stdexcept>
#include <iomanip>
#include "collection.h"
#include "TvEpisode.h"
#include <sstream>
#include "collection.h"
using namespace std;
using namespace seneca;

vector<TvEpisode> TvShow::_m_episodes;

// constructor
TvShow::TvShow(const string& m_title, const string& m_summary, const unsigned short year, string m_id,
	vector<TvEpisode> m_episodes):
	MediaItem(m_title, m_summary, year), m_id(m_id), m_episodes(m_episodes)
{
#ifdef _DEBUG
	cout << "tvShow() called\n";
#endif
}

// member functions

// display
void TvShow::display(ostream& out) const
{
#ifdef _DEBUG
	cout << "tvShow() display() called\n";
#endif

	if (g_settings.m_tableView)
	{
		out << "S | ";
		out << std::left << std::setfill('.');
		out << std::setw(50) << this->getTitle() << " | ";
		out << std::right << std::setfill(' ');
		out << std::setw(2) << this->m_episodes.size() << " | ";
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
		out << this->getTitle() << " [" << this->getYear() << "]\n";
		out << std::setw(this->getTitle().size() + 7) << std::setfill('-') << "" << '\n';
		while (pos < this->getSummary().size())
		{
			out << " " << this->getSummary().substr(pos, g_settings.m_maxSummaryWidth)
				<< '\n';
			pos += g_settings.m_maxSummaryWidth;
		}
		for (auto& item : m_episodes)
		{
			out << std::setfill('0') << std::right;
			out << " " << 'S' << std::setw(2) << item.m_season
				<< 'E' << std::setw(2) << item.m_numberInSeason << ' ';
			if (item.m_title != "")
				out << item.m_title << '\n';
			else
				out << "Episode " << item.m_numberOverall << '\n';
			pos = 0;
			while (pos < item.m_summary.size())
			{
				out << " " << item.m_summary.substr(pos,
					g_settings.m_maxSummaryWidth - 8) << '\n';
				pos += g_settings.m_maxSummaryWidth - 8;
			}
		}
		out << std::setw(this->getTitle().size() + 7) << std::setfill('-') << ""
			<< std::setfill(' ') << '\n';
	}

}

// createItem
TvShow* TvShow::createItem(const string& strShow)
{
#ifdef _DEBUG
	cout << "tvShow() createItem() called\n";
#endif

	std::istringstream stream(strShow);
	std::string id, title, yearStr, summary;

	if (std::getline(stream, id, ',') &&
		std::getline(stream, title, ',') &&
		std::getline(stream, yearStr, ',') &&
		std::getline(stream, summary)) {
		MediaItem::trim(id);
		MediaItem::trim(title);
		MediaItem::trim(yearStr);
		MediaItem::trim(summary);

		try {
			unsigned short year = static_cast<unsigned short>(std::stoi(yearStr.c_str()));
			vector<TvEpisode> some;
			return new TvShow(title, summary, year, id, some);
		}
		catch (...) {
			throw std::string("Invalid TV Show record: " + strShow);
		}
	}

	throw std::string("Malformed TV Show record: " + strShow);
}

// addEpisode

//template<typename Collection_t>
void TvShow::addEpisode(Collection& col, const string& strEpisode)
{
#ifdef _DEBUG
	cout << "tvShow() addEpisode() called\n";
#endif

	std::istringstream stream(strEpisode);
	string id, overallNumStr, seasonNumStr, episodeNumStr, airDate, lengthStr, title, summary;

	if (std::getline(stream, id, ',') &&
		std::getline(stream, overallNumStr, ',') &&
		std::getline(stream, seasonNumStr, ',') &&
		std::getline(stream, episodeNumStr, ',') &&
		std::getline(stream, airDate, ',') &&
		std::getline(stream, lengthStr, ',') &&
		std::getline(stream, title, ',') &&
		std::getline(stream, summary)) {
		MediaItem::trim(id);
		MediaItem::trim(overallNumStr);
		MediaItem::trim(seasonNumStr);
		MediaItem::trim(episodeNumStr);
		MediaItem::trim(airDate);
		MediaItem::trim(lengthStr);
		MediaItem::trim(title);
		MediaItem::trim(summary);

		try {
			const unsigned short overallNum = std::stoul(overallNumStr);
			unsigned short seasonNum;
			if (seasonNumStr == "")
				seasonNum = 1;
			else
				seasonNum = std::stoul(seasonNumStr);
			unsigned short episodeNum = std::stoul(episodeNumStr);
			unsigned short length = std::stoul(lengthStr);

			TvShow* some = nullptr;
			TvEpisode episode(some, overallNum, seasonNum, episodeNum, airDate, length, title, summary);
			vector<MediaItem*>* check = col.collectionFind(title);
			TvShow* _TvShow = nullptr;
			for (auto item : *check)
			{
				if (item->getTitle() == title)
					_TvShow = dynamic_cast<TvShow*>(item);
				TvShow* minga = dynamic_cast<TvShow*>(item);
				if (minga->getId() == id)
					_TvShow = minga;
			}
			//auto _TvShow = dynamic_cast<TvShow*>(col[id]);
			
			if (_TvShow) {
				_m_episodes.push_back(episode);	// changed here
				return;
			}
			else {
				throw std::string("TV Show ID [" + id + "] not found.");
			}
		}
		catch (...) {
			throw std::string("Invalid episode record: " + strEpisode);
		}
	}
	else {
		throw std::string("Malformed episode record: " + strEpisode);

	}
}

unsigned int TvShow::getEpisodeAverageLength() const {
	if (m_episodes.empty()) {
		return 0;
	}

	unsigned int totalLength = 0;
	for (const auto& episode : m_episodes) {
		totalLength += episode.getLength();
	}

	return totalLength / m_episodes.size();
}

std::vector<std::string> TvShow::getLongEpisodes(unsigned int minLength) const {
	std::vector<std::string> longEpisodes;
	for (const auto& episode : m_episodes) {
		if (episode.getLength() >= minLength) {
			longEpisodes.push_back(episode.getTitle());
		}
	}
	return longEpisodes;
}