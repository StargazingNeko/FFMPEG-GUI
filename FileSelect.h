#pragma once
#include <wx/wx.h>

class FileSelect : public wxFrame
{
public:
	wxWindowID FSFID;
	std::string FilePath;
	std::string FileName;
	FileSelect();
	void BrowseForFile();

};
