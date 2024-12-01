
#ifndef SENECA_COLLECTION_H
#define SENECA_COLLECTION_H
//#pragma once

#include "mediaItem.h"
#include <vector>
#include <string>
#include "settings.h"
#include <functional>
#include <algorithm>
#include <iostream>
//#include "tvShow.h"
using namespace std;

namespace seneca
{
    //class TvShow;
	class Collection
	{
		string name;
        vector<MediaItem*> m_items;
        std::function<void(const Collection&, const MediaItem&)> m_observer; // Observer function
	public:
		Collection(string name):
			name(name){}

        // Overloaded output operator
        friend std::ostream& operator<<(std::ostream& os, const Collection& collection) 
        {
            if (g_settings.m_tableView) {
                for (const auto* item : collection.m_items) {
                    os << *item << '\n';
                }
            }
            else {
                for (const auto* item : collection.m_items) {
                    item->display(os);
                    os << "------------------\n";
                }
            }
            return os;
        }

        // Access MediaItem by title
        MediaItem* operator[](const std::string& title) const
        {
            // extract show id's stored in tv show then compare them with the id that is passed
            for (auto item : this->m_items)
            {
                if (item->getTitle() == title)
                    return item;
                //TvShow::checkId(title);
            }
            return nullptr;
        }

        Collection& operator+=(MediaItem* item)
        {
            if (item) {
                bool alreadyExists = std::any_of(m_items.begin(), m_items.end(),
                    [item](const MediaItem* existingItem) {
                        return existingItem->getTitle() == item->getTitle();
                    });
                if (!alreadyExists) {
                    m_items.push_back(item);
                    if (m_observer) {
                        m_observer(*this, *item);
                    }
                }
                else {
                    delete item; // Prevent memory leak for duplicate items
                }
            }
            return *this;
        }

        void setObserver(std::function<void(const Collection&, const MediaItem&)> observer)
        {
            m_observer = observer;
        }

        // Get size of collection
        size_t size() const { return m_items.size(); }

        // Access MediaItem by index
        MediaItem* operator[](size_t index) const
        {
            return (index < m_items.size()) ? m_items[index] : nullptr;
        }

        // Remove quotes from titles and summaries
        void removeQuotes()
        {
            for (auto* item : m_items) {
                std::string title = item->getTitle();
                std::string summary = item->getSummary();

                // Simulate the behavior of `trim` manually here
                size_t start = title.find_first_not_of(' "');
                size_t end = title.find_last_not_of(' "');
                if (start != std::string::npos && end != std::string::npos) {
                    title = title.substr(start, end - start + 1);
                }
                else {
                    title.clear();
                }

                start = summary.find_first_not_of(' ');
                end = summary.find_last_not_of(' ');
                if (start != std::string::npos && end != std::string::npos) {
                    summary = summary.substr(start, end - start + 1);
                }
                else {
                    summary.clear();
                }

                item->setTitle(title);
                item->setSummary(summary);
            }
        }

        // Sort items by a specified key
        void sort(const std::string& key)
        {
            if (key == "title") {
                std::sort(m_items.begin(), m_items.end(),
                    [](const MediaItem* a, const MediaItem* b) { return a->getTitle() < b->getTitle(); });
            }
            else if (key == "year") {
                std::sort(m_items.begin(), m_items.end(),
                    [](const MediaItem* a, const MediaItem* b) { return a->getYear() < b->getYear(); });
            }
        }

        // find
        vector<MediaItem*>* collectionFind(const string& title)
        {
            return &m_items;
        }
	};
}
#endif