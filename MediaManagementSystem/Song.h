#pragma once
#include <string>
using std::string;

class Song
{
	string m_sTitle;
	string m_sArtist;
	string m_sLyrics;
	string m_lowerCaseTitle;
public:
	Song(const string title="", const string artist="", const string lyrics="");
	~Song();

	const string GetTitle() { return m_sTitle; }
	const string GetArtist() { return m_sArtist; }
	const string GetLyrics() { return m_sLyrics; }
	const string GetLowerCaseTitle() { return m_lowerCaseTitle; }


	void SetTitle(const string title) { m_sTitle = title; }
	void SetArtist(const string artist) { m_sArtist = artist; }
	void SetLyrics(const string lyrics) { m_sLyrics = lyrics; }
	void SetLowerCaseTitle(const string lctitle) { m_lowerCaseTitle = lctitle; }

	bool operator >(const Song& s);

};

