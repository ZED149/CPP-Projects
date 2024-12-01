#include "spellChecker.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
using namespace seneca;


SpellChecker::SpellChecker(const std::string& filename)
{
    std::ifstream file(filename);
    if (!file)
    {
        throw std::string("Cannot open file [") + filename + "]";
    }

    std::string line;
    while (std::getline(file, line) && m_wordCount < MAX_WORDS)
    {
        std::istringstream iss(line);
        std::string badWord, goodWord;

        if (iss >> badWord >> goodWord)
        {
            m_badWords[m_wordCount] = badWord;
            m_goodWords[m_wordCount] = goodWord;
            ++m_wordCount;
        }
    }
}

void SpellChecker::operator()(std::string& text)
{
    for (size_t i = 0; i < m_wordCount; ++i)
    {
        size_t pos = 0;
        while ((pos = text.find(m_badWords[i], pos)) != std::string::npos)
        {
            text.replace(pos, m_badWords[i].length(), m_goodWords[i]);
            ++m_replacements[i];
            pos += m_goodWords[i].length();
        }
    }
}

void SpellChecker::showStatistics(std::ostream& out) const
{
    out << "Spellchecker Statistics\n";
    for (size_t i = 0; i < m_wordCount; ++i)
    {
        out << std::setw(15) << std::left << m_badWords[i] << " : " << m_replacements[i] << " replacements\n";
    }
}
