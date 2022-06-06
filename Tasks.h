#pragma once
#include <wx/wx.h>

class Tasks
{
public:
	//Video Tasks
	static wxString MP4Task(bool usePresets, wxString codec, wxString quality, int framerate = 0);
	static wxString WEBMTask(wxString quality, int framerate = 0);
	static wxString GIFTask(wxString quality, int framerate = 0);

	static wxString TrimVideoTask(int startHour, int startMin, int startSec, int startMS, int trimHour, int trimMin, int trimSec, int trimMS);

	//Audio Tasks
	static wxString MP3Task(wxString quality);
	static wxString StripAudioTask();

	//Other Tasks
	static bool ContainsIllegalCharacters(wxString);

private:
	static inline int _framerate = 30;
};