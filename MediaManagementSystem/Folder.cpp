#include "pch.h"
#include <string>
#include "Collection.h"
#include "Song.h"
#include "Folder.h"

using std::string;

Folder::Folder(string folderName):
	m_sFolderName(folderName)
{}


Folder::~Folder()
{
}
