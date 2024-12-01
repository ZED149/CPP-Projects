//
//
//
//// this is the main driver of this program
//
//// including important headers and libraries
//#include <iostream>
//using namespace std;
//#include <fstream>
//
//// including user defined header files
//#include "settings.h"
//#include "book.h"
//#include "movie.h"
//#include "tvShow.h"
//#include "collection.h"
//#include <vector>
//
////// Ensure header guards are in place
////#ifndef SENECA_SETTINGS_H
////#error "The header guard for 'settings.h' doesn't follow the convention!"
////#endif
////#ifndef SENECA_MEDIAITEM_H
////#error "The header guard for 'mediaItem.h' doesn't follow the convention!"
////#endif
////#ifndef SENECA_BOOK_H
////#error "The header guard for 'book.h' doesn't follow the convention!"
////#endif
//
//using namespace seneca;
//
//
//// loadMedia
//template<typename T>
//void loadMedia(const char* filename, vector<MediaItem*>& _T);
//
//void loadEpisodes(Collection& col, const char* filename);
//
//// Main
//int main()
//{
//	// loading books
//	cout << "Loading Books" << endl;
//	vector<MediaItem*> bookVector;
//	loadMedia<Book>("books.csv", bookVector);
//	// loading movies
//	cout << "Loading Movies" << endl;
//	vector<MediaItem*> movieVector;
//	loadMedia<Movie>("movies.csv", movieVector);
//	cout << "Loading Episodes" << endl;
//	vector<MediaItem*> episodeVector;
//	loadMedia<tvShow>("tvShows.csv", episodeVector);
//}
//
//// loadMedia
//template<typename T>
//void loadMedia(const char* filename, vector<MediaItem*>& _T)
//{
//	std::ifstream file(filename);
//	if (!file)
//	{
//		std::cerr << "ERROR: Cannot open file [" << filename << "].\n";
//	}
//
//	for (std::string record{}; std::getline(file, record); /* nothing */)
//	{
//		try
//		{
//			seneca::MediaItem* item = T::createItem(record);
//			cout << *item;
//			_T.push_back(item);
//		}
//		catch (const char* msg)
//		{
//			std::cout << "ERROR: [" << record << "] " << msg << '\n';
//		}
//		catch (...)
//		{
//			std::cout << "ERROR: Unknown error when processing file record [" << record << "].\n";
//		}
//	}
//
//	for (auto i : _T)
//	{
//		cout << *i;
//	}
//}
//
//
//void loadEpisodes(seneca::Collection& col, const char* filename)
//{
//	std::ifstream file(filename);
//	if (!file)
//	{
//		std::cerr << "ERROR: Cannot open file [" << filename << "].\n";
//		//std::exit(AppErrors::CannotOpenFile);
//	}
//
//	for (std::string record{}; std::getline(file, record); )
//	{
//		try
//		{
//			//tvShow::addEpisode(col, record);
//		}
//		catch (const char* msg)
//		{
//			std::cout << "ERROR: [" << record << "] " << msg << '\n';
//		}
//		catch (const std::string& msg)
//		{
//			std::cout << "ERROR: " << msg << '\n';
//		}
//		catch (...)
//		{
//			std::cout << "ERROR: Unknown error when processing file record [" << record << "].\n";
//			//std::exit(AppErrors::RecordParsingError);
//		}
//	}
//}