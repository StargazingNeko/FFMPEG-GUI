#include "App.h"
#include "MainFrame.h"
#include <wx/wx.h>

wxIMPLEMENT_APP(App);

bool App::OnInit()
{
	MainFrame* mainFrame = new MainFrame("GUI");
	mainFrame->SetClientSize(600, 350);
	mainFrame->Show();
	return true;
}