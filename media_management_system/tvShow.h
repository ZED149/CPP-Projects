

#ifndef SENECA_TVSHOW_H
#define SENECA_TVSHOW_H
// this file contains the tvShow header code

//#pragma once
// including important libraries
#include "mediaItem.h"
#include <vector>
#include "collection.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>
//#include "TvEpisode.h"
#include "collection.h"
using namespace std;	
using namespace seneca;

// SENECA namespace
namespace seneca
{
	class Collection;
	class TvEpisode;

	// tvShow class
	class TvShow : public MediaItem
	{
		//friend class Collection;
		string m_id;
		vector<TvEpisode> m_episodes;
		static vector<TvEpisode> _m_episodes;

	public:
		// constructor
		TvShow(const string& m_title, const string& m_summary, const unsigned short year, string m_id,
			vector<TvEpisode> m_episodes);

		// member functions

		// display
		void display(ostream& out) const override;

		// getId
		string getId() { return this->m_id; }

		static void checkId(const string& title)
		{

		}

		// addEpisode
		//template<typename Collection_t>
		static void addEpisode(Collection& col, const string& strEpisode);

		// createItem
		static TvShow* createItem(const string& strShow);

		unsigned int getEpisodeAverageLength() const;

		std::vector<std::string> getLongEpisodes(unsigned int minLength = 30) const;
	};
}
#endif