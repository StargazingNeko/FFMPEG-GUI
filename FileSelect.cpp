#include "FileSelect.h"
#include "MainFrame.h"
#include <wx/wx.h>

std::string FilePath;
std::string FileName;

FileSelect::FileSelect()
{
	BrowseForFile();
}


const wxChar *FILETYPES = _T(
	"MP4|*mp4;*MP4|"
	"FLV|*flv;*FLV|"
	"WEBM|*webm;*WEBM|"
	"All files|*.*"
);

void FileSelect::BrowseForFile()
{

	wxFileDialog* filedlg = new wxFileDialog(this, "Select File to Convert", wxEmptyString, wxEmptyString, FILETYPES);
	if (~filedlg->ShowModal() == wxID_OK)
	{
		delete filedlg;
		wxWindow::Close();
		return;
	}

	MainFrame::SetFilePath(FilePath = filedlg->GetPath(),FileName = filedlg->GetFilename());
	delete filedlg;
	wxWindow::Close();
};