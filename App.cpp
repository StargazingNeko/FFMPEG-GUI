#include "App.h"
#include "MainFrame.h"
#include <wx/wx.h>

wxIMPLEMENT_APP(App);
//wxIMPLEMENT_APP_CONSOLE(App);

bool App::OnInit()
{
	MainFrame* mainFrame = new MainFrame("GUI");
	mainFrame->SetClientSize(600, 600);
	mainFrame->Show();
	return true;
}