
#ifndef SENECA_SPELLCHECKER_H
#define SENECA_SPELLCHECKER_H
//#pragma once

#include <iostream>
#include <string>

namespace seneca
{
	class SpellChecker
	{
        static const size_t MAX_WORDS = 10;
        std::string m_badWords[MAX_WORDS]{};
        std::string m_goodWords[MAX_WORDS]{};
        size_t m_wordCount{ 0 };

        size_t m_replacements[MAX_WORDS]{}; // Tracks the number of replacements per word

    public:
        explicit SpellChecker(const std::string& filename);
        void operator()(std::string& text);
        void showStatistics(std::ostream& out = std::cout) const;
	};
}
#endif
