#include "pch.h"
#include <string>
#include<algorithm>
#include "Song.h"

using std::string;

// ???????ADD CHECK FOR EMPTY STRINGS????????
Song::Song(string title, string artist, string lyrics):
	m_sTitle(title),
	m_sArtist(artist),
	m_sLyrics(lyrics)
{
	transform(title.begin(), title.end(), title.begin(), ::tolower);
	m_lowerCaseTitle = title;
}


Song::~Song()
{
}


bool Song::operator >(const Song& s)
{
		if (m_lowerCaseTitle > s.m_lowerCaseTitle)
		{
			return true;
		}
		return false;
}