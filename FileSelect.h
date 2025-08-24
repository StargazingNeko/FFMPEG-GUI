#pragma once
#include <wx/wx.h>

class FileSelect : wxFrame
{
public:
	void BrowseForFile(wxCommandEvent& event);

	DECLARE_EVENT_TABLE()
};