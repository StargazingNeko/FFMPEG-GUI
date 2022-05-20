#include "MainFrame.h"
#include "Codecs.h"
#include "FileSelect.h"
#include <string>
#include <wx/wx.h>
#include <wx/spinctrl.h>

BEGIN_EVENT_TABLE(MainFrame, wxFrame)
END_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
	Codecs codecs;


	wxPanel* panel = new wxPanel(this);

	wxTextCtrl* fileLocationBox = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(100, 50), wxSize(300, -1));
	wxButton* browse = new wxButton(panel, wxID_ANY, "Browse", wxPoint(400, 50), wxSize(100, -1));
	Bind(wxEVT_BUTTON, &FileSelect::BrowseForFile, this, browse->GetId());

	wxString formatChoices[5] = { "MP4", "GIF", "WEBM", "MP3", "COPY" };

	wxComboBox* formatSelection = new wxComboBox(panel, wxID_ANY, wxEmptyString, wxPoint(100, 100), wxSize(95, -1), 5, formatChoices);
	formatSelection->Select(0);

	//wxArrayString vcodecChoices(2, codecs.MP4);
	wxString vcodecChoices[2]{ "liba","libb" };
	//if (formatSelection->GetSelection() == 0)
	//{
	//	vcodecChoices (2, codecs.MP4);
	//}
	//else
	//{
	//	vcodecChoices()
	//}

	//wxListBox* vCodexSelection = new wxListBox(panel, wxID_ANY, wxPoint(100, 150), wxSize(95, -1), vcodecChoices);
	wxListBox* vCodexSelection = new wxListBox(panel, wxID_ANY, wxPoint(100, 150), wxSize(95, -1), 2, vcodecChoices);
	vCodexSelection->Select(0);

	wxString acodecChoices[2] = { "MP3", "a" };
	wxComboBox* audioSelection = new wxComboBox(panel, wxID_ANY, wxEmptyString, wxPoint(200, 100), wxSize(95, -1), 2, acodecChoices);
	audioSelection->Select(0);

	wxSpinCtrl* startHour = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(215, 150), wxSize(40, -1));
	startHour->SetMax(59);
	wxStaticText* sH = new wxStaticText(panel, wxID_ANY, "H", wxPoint(200, 155), wxSize(-1, -1));

	wxSpinCtrl* startMin = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(277, 150), wxSize(40, -1));
	startMin->SetMax(59);
	wxStaticText* sM = new wxStaticText(panel, wxID_ANY, "M", wxPoint(260, 155), wxSize(-1, -1));

	wxSpinCtrl* startSec = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(333, 150), wxSize(40, -1));
	startSec->SetMax(59);
	wxStaticText* sS = new wxStaticText(panel, wxID_ANY, "S", wxPoint(320, 155), wxSize(-1, -1));

	wxSpinCtrl* startMS = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(395, 150), wxSize(40, -1));
	startMS->SetMax(999);
	wxStaticText* sMS = new wxStaticText(panel, wxID_ANY, "MS", wxPoint(375, 155), wxSize(-1, -1));



	wxSpinCtrl* trimHour = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(215, 180), wxSize(40, -1));
	trimHour->SetMax(59);
	wxStaticText* tH = new wxStaticText(panel, wxID_ANY, "H", wxPoint(200, 185), wxSize(-1, -1));

	wxSpinCtrl* trimMin = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(277, 180), wxSize(40, -1));
	trimMin->SetMax(59);
	wxStaticText* tM = new wxStaticText(panel, wxID_ANY, "M", wxPoint(260, 185), wxSize(-1, -1));

	wxSpinCtrl* trimSec = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(333, 180), wxSize(40, -1));
	trimSec->SetMax(59);
	wxStaticText* tS = new wxStaticText(panel, wxID_ANY, "S", wxPoint(320, 185), wxSize(-1, -1));

	wxSpinCtrl* trimMS = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(395, 180), wxSize(40, -1));
	trimMS->SetMax(999);
	wxStaticText* tMS = new wxStaticText(panel, wxID_ANY, "MS", wxPoint(375, 185), wxSize(-1, -1));

	wxTextCtrl* fileOutput = new wxTextCtrl(panel, wxID_ANY, "o.mp4", wxPoint(100, 300), wxSize(175, -1));
	wxButton* runButton = new wxButton(panel, wxID_ANY, "Run", wxPoint(275, 300), wxSize(100, -1));
	Bind(wxEVT_BUTTON, &MainFrame::RunFFMPEG, this, runButton->GetId());


};

/*std::string FileSelect::BrowseForFile(wxCommandEvent& event)
{
	return std::string();
};*/

std::string MainFrame::GetFilePath()
{

	return std::string();
};

void MainFrame::RunFFMPEG(wxCommandEvent& event)
{
	MessageBoxA(nullptr, "Run", "run", 0);
};

struct MainFrame::FFMPEGCommand
{
	std::string FileName;
	std::string FilePath;
	std::string FileOutName;
};