

// this file contains the implementation of TvEpisode header file

// including important libraries
#include "TvEpisode.h"
using namespace std;
using namespace seneca;


// constructor
TvEpisode::TvEpisode(const TvShow* m_show, const unsigned short& m_numberOverall, const unsigned short& m_season,
	const unsigned short& m_numberInSeason, const string& m_airDate, const unsigned int& m_length,
	const string& m_title, const string& m_summary) :
	m_show(m_show), m_numberOverall(m_numberOverall), m_season(m_season), m_numberInSeason(m_numberInSeason),
	m_airDate(m_airDate), m_length(m_length), m_title(m_title), m_summary(m_summary)
{
#ifdef _DEBUG
	cout << "TvEpisode() called\n";
#endif
}
