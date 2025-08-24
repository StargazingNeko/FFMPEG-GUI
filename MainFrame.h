#pragma once
#include <wx/wx.h>
#include <string>

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title);
	void RunFFMPEG(wxCommandEvent& event);
	struct FFMPEGCommand;
	std::string GetFilePath();
	


	DECLARE_EVENT_TABLE()
};