

//#pragma once
// this file contains the TvEpisode class

// including important libraries

#include "tvShow.h"
#include <string>
#include <iostream>
// SENECA namespace
namespace seneca
{	
	// TvEpisode class
	class TvEpisode
	{
	public:
		const TvShow* m_show{};
		unsigned short m_numberOverall{};
		unsigned short m_season{};
		unsigned short m_numberInSeason{};
		string m_airDate{};
		unsigned int m_length{};
		string m_title{};
		string m_summary{};

	public:
		// constructor
		TvEpisode(const TvShow* m_show, const unsigned short& m_numberOverall, const unsigned short& m_season,
			const unsigned short& m_numberInSeason, const string& m_airDate, const unsigned int& m_length,
			const string& m_title, const string& m_summary);

		size_t getLength() const { return m_length; }

		const string& getTitle() const  { return m_title; }

	};
}
