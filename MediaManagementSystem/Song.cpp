#include "pch.h"
#include <string>
#include "Song.h"

using std::string;

// ???????ADD CHECK FOR EMPTY STRINGS????????
Song::Song(string title, string artist, string lyrics):
	m_sTitle(title),
	m_sArtist(artist),
	m_sLyrics(lyrics)
{}


Song::~Song()
{
}
