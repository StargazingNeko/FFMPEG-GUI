#include "MainFrame.h"
#include "Codecs.h"
#include "FileSelect.h"
#include "Tasks.h"
#include <string>
#include <wx/wx.h>
#include <wx/spinctrl.h>

BEGIN_EVENT_TABLE(MainFrame, wxFrame)
END_EVENT_TABLE()

std::string FFMPEGCommand[3] = { "FilePath", "FileName" , "FileOut" };
wxString vCodecChoices[] = { "" };
wxTextCtrl* fileLocationBox;
wxComboBox* vFormatSelection;
wxListBox* vCodecSelection;
wxComboBox* aCodecSelection;
wxSpinCtrl* startHour;
wxSpinCtrl* startMin;
wxSpinCtrl* startSec;
wxSpinCtrl* startMS;
wxSpinCtrl* trimHour;
wxSpinCtrl* trimMin;
wxSpinCtrl* trimSec;
wxSpinCtrl* trimMS;
wxTextCtrl* fileOutput;
wxCheckBox* trimVideo;


MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
	
	wxPanel* panel = new wxPanel(this);

	fileLocationBox = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(100, 50), wxSize(300, -1), wxCB_READONLY);
	wxButton* browse = new wxButton(panel, wxID_ANY, "Browse", wxPoint(400, 50), wxSize(100, -1));
	Bind(wxEVT_BUTTON, &MainFrame::BrowseForFile, this, browse->GetId());

	wxString formatChoices[5] = { "COPY", "MP4", "WEBM", "GIF (Unsupported)", "MP3" };

	vFormatSelection = new wxComboBox(panel, wxID_ANY, wxEmptyString, wxPoint(100, 100), wxSize(95, -1), 5, formatChoices, wxCB_READONLY);
	vFormatSelection->Select(0);
	Bind(wxEVT_COMBOBOX, &MainFrame::VCodecChanged, this, vFormatSelection->GetId());

	vCodecSelection = new wxListBox(panel, wxID_ANY, wxPoint(100, 153), wxSize(95, -1), 3, vCodecChoices);
	vCodecSelection->Clear();
	vCodecSelection->Append("copy");
	vCodecSelection->Select(0);

	wxString aCodecChoices[6] = { "COPY", "AAC", "MP3", "WAV", "FLAC", "NONE" };
	aCodecSelection = new wxComboBox(panel, wxID_ANY, wxEmptyString, wxPoint(200, 100), wxSize(95, -1), 6, aCodecChoices, wxCB_READONLY);
	aCodecSelection->Select(0);

	trimVideo = new wxCheckBox(panel, wxID_ANY, " Trim Video", wxPoint(440, 167));

	startHour = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(215, 150), wxSize(40, -1));
	startHour->SetMax(59);
	wxStaticText* sH = new wxStaticText(panel, wxID_ANY, "H", wxPoint(200, 155), wxSize(-1, -1));

	startMin = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(277, 150), wxSize(40, -1));
	startMin->SetMax(59);
	wxStaticText* sM = new wxStaticText(panel, wxID_ANY, "M", wxPoint(260, 155), wxSize(-1, -1));

	startSec = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(333, 150), wxSize(40, -1));
	startSec->SetMax(59);
	wxStaticText* sS = new wxStaticText(panel, wxID_ANY, "S", wxPoint(320, 155), wxSize(-1, -1));

	startMS = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(395, 150), wxSize(40, -1));
	startMS->SetMax(999);
	wxStaticText* sMS = new wxStaticText(panel, wxID_ANY, "MS", wxPoint(375, 155), wxSize(-1, -1));

	trimHour = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(215, 180), wxSize(40, -1));
	trimHour->SetMax(59);
	wxStaticText* tH = new wxStaticText(panel, wxID_ANY, "H", wxPoint(200, 185), wxSize(-1, -1));
	
	trimMin = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(277, 180), wxSize(40, -1));
	trimMin->SetMax(59);
	wxStaticText* tM = new wxStaticText(panel, wxID_ANY, "M", wxPoint(260, 185), wxSize(-1, -1));

	trimSec = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(333, 180), wxSize(40, -1));
	trimSec->SetMax(59);
	wxStaticText* tS = new wxStaticText(panel, wxID_ANY, "S", wxPoint(320, 185), wxSize(-1, -1));

	trimMS = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(395, 180), wxSize(40, -1));
	trimMS->SetMax(999);
	wxStaticText* tMS = new wxStaticText(panel, wxID_ANY, "MS", wxPoint(375, 185), wxSize(-1, -1));

	fileOutput = new wxTextCtrl(panel, wxID_ANY, "o.mp4", wxPoint(100, 300), wxSize(175, -1));
	wxButton* runButton = new wxButton(panel, wxID_ANY, "Run", wxPoint(275, 300), wxSize(100, -1));
	Bind(wxEVT_BUTTON, &MainFrame::RunFFMPEG, this, runButton->GetId());
};





void MainFrame::VCodecChanged(wxCommandEvent &event)
{
	vCodecSelection->Clear();
	switch (vFormatSelection->GetSelection())
	{
	case 0:
		vCodecSelection->Append("copy");
		return;
	case 1:
		for (int i = 0; i < 3; i++)
		{
			vCodecSelection->Append(Codecs::MP4[i]);
		}
		vCodecSelection->Select(0);
		return;
	case 2:
		for (int i = 0; i < 3; i++)
		{
			vCodecSelection->Append(Codecs::WEBM[i]);
		}
		return;
	case 3:
		return;
	case 4:
		for (int i = 0; i < 2; i++)
		{
			vCodecSelection->Append(Codecs::MP3[i]);
		}
		return;
	default:
		return;
	}
}





void MainFrame::BrowseForFile(wxCommandEvent& event)
{
	FileSelect* fs = new FileSelect();
};





void MainFrame::SetFilePath(std::string FilePath, std::string FileName)
{
	FFMPEGCommand[0] = FilePath;
	FFMPEGCommand[1] = FileName;
	fileLocationBox->Clear();
	fileLocationBox->WriteText(FilePath);
};





std::string MainFrame::TrimPath()
{
	int FileLength = FFMPEGCommand[1].length();
	int FileNameStart = FFMPEGCommand[0].find_last_of("\\")+1;

	std::string trimmedPath = FFMPEGCommand[0].replace(FileNameStart, FileLength, "");
	return trimmedPath;
}




std::string MainFrame::CraftRunString(bool trimVideo)
{
	std::string runString;
	std::string audio;

	if (aCodecSelection->GetStringSelection().Lower() == "none")
	{
		audio = Tasks::StripAudioTask();
	}
	else
	{
		audio = " -c:a " + aCodecSelection->GetStringSelection().Lower();
	}

	if (trimVideo)
	{
		runString = ("ffmpeg -i \""
			+ fileLocationBox->GetValue() + "\"")
			+ Tasks::MP4Task(true, vCodecSelection->GetStringSelection(), "veryslow", 60)
			+ audio
			+ Tasks::TrimVideoTask(startHour->GetValue(), startMin->GetValue(), startSec->GetValue(), startMS->GetValue(), trimHour->GetValue(), trimMin->GetValue(), trimSec->GetValue(), trimMS->GetValue())
			+ " "
			+ TrimPath()
			+ fileOutput->GetValue();
	}
	else
	{
		runString = "ffmpeg -i \""
			+ fileLocationBox->GetValue() + "\""
			+ Tasks::MP4Task(true, vCodecSelection->GetStringSelection(), "veryslow", 60)
			+ audio
			+ " " + TrimPath()
			+ fileOutput->GetValue();
	}

	return runString;
}





void MainFrame::RunFFMPEG(wxCommandEvent& event)
{
	if (Tasks::ContainsIllegalCharacters(fileOutput->GetValue()))
	{
		MessageBoxA(nullptr, "Output cannot contain characters\n \\/:*?\"<>|'", nullptr, 0);
		return;
	}

	wchar_t runString[1024] = { 0 };
	mbstowcs(runString, CraftRunString(trimVideo->IsChecked()).c_str(), 1024);

	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	DWORD dwErr = 0;
	AllocConsole();
	FILE* fDummy;
	freopen_s(&fDummy, "CONIN$", "r", stdin);
	freopen_s(&fDummy, "CONOUT$", "w", stderr);
	freopen_s(&fDummy, "CONOUT$", "w", stdout);
	std::wcout << std::endl << runString << std::endl << std::endl;
	BOOL bFFMPEGProcess = CreateProcess(NULL, runString, NULL, NULL, TRUE, NORMAL_PRIORITY_CLASS, NULL, NULL, &si, &pi);
	if (bFFMPEGProcess)
	{
		AttachConsole(pi.dwProcessId);
		WaitForSingleObject(pi.hProcess, INFINITE);
		GetExitCodeProcess(pi.hProcess, &dwErr);
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
		std::cout << "\nDone!";
		std::cout << "\nPress any key to close this window...";
		char uinput = getchar();
		fclose(stdin);
		fclose(stderr);
		fclose(stdout);
		FreeConsole();
		return;
	}

	fclose(stdin);
	fclose(stderr);
	fclose(stdout);
	MessageBoxA(nullptr, "Error something went wrong with launching FFMPEG", nullptr, 0);
	FreeConsole();
};