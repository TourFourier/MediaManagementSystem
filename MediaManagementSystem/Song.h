#pragma once
#include <string>
using std::string;

class Song
{
	string m_sTitle;
	string m_sArtist;
	string m_sLyrics;
public:
	Song(const string title, const string artist, const string lyrics);
	~Song();

	const string GetTitle() { return m_sTitle; }
	const string GetArtist() { return m_sArtist; }
	const string GetLyrics() { return m_sLyrics; }

	void SetTitle(const string title) { m_sTitle = title; }
	void SetArtist(const string artist) { m_sArtist = artist; }
	void SetLyrics(const string lyrics) { m_sLyrics = lyrics; }
};

