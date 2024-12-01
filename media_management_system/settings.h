
//#pragma once

#ifndef SENECA_SETTINGS_H
#define SENECA_SETTINGS_H

namespace seneca
{
	class Settings
	{
	public:
		bool m_tableView{ false };		// decides to display output in table or not
		int m_maxSummaryWidth{ 80 };		// maximum width of a text of summary when printing to console

		Settings() = default;
	};

	// global Settings() object/instance
	extern Settings g_settings;
}
#endif	// SENECA_COLLECTION_H
