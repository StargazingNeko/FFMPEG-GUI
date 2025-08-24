#pragma once
#include <wx/wx.h>
#include <string>

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title);
	void VCodecChanged(wxCommandEvent &event);
	void RunFFMPEG(wxCommandEvent& event);
	void BrowseForFile(wxCommandEvent& event);
	static void SetFilePath(std::string FilePath, std::string FileName);
	std::string TrimPath();

	DECLARE_EVENT_TABLE()
};