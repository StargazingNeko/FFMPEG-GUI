#include "FileSelect.h"
#include <wx/wx.h>


BEGIN_EVENT_TABLE(FileSelect, wxFrame)
END_EVENT_TABLE()

void FileSelect::BrowseForFile(wxCommandEvent& event)
{
	MessageBoxA(nullptr, "a", "b", 0);
	//wxFileDialog* filedl = new wxFileDialog(nullptr, "abc", wxEmptyString, wxEmptyString, "*");
};