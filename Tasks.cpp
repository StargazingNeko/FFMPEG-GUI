#include "Tasks.h"
#include <wx/wx.h>



//Video Tasks
wxString Tasks::MP4Task(bool usePresets, wxString codec, wxString quality, int framerate)
{
    usePresets = true; //TODO: Remove once codec configuration is implemented
    quality = "veryslow"; //TODO: Remove once codec configuration is implemented



    if (usePresets)
    {
        if (framerate == 0)
            framerate = _framerate;

        return " -c:v " + codec + " -preset " + quality + " -filter:v fps=" + std::to_string(framerate);
    }

    return " -c:v " + codec + " -crf " + quality + " -filter:v fps=" + std::to_string(framerate);
}

wxString Tasks::WEBMTask(wxString quality, int framerate)
{
    if (framerate == 0)
        framerate = _framerate;

    return std::string();
}

wxString Tasks::GIFTask(wxString quality, int framerate)
{
    if (framerate == 0)
        framerate = _framerate;

    return std::string();
}



wxString Tasks::TrimVideoTask(int startHour, int startMin, int startSec, int startMS, int trimHour, int trimMin, int trimSec, int trimMS)
{
    wxString r = " -ss " + std::to_string(startHour) + ":" + std::to_string(startMin) + ":" + std::to_string(startSec) + "." + std::to_string(startMS)
        + " -t " + std::to_string(trimHour) + ":" + std::to_string(trimMin) + ":" + std::to_string(trimSec) + "." + std::to_string(trimMS);
    return r;
}






//Audio Tasks
wxString Tasks::MP3Task(wxString quality)
{
    return std::string();
}

wxString Tasks::StripAudioTask()
{
    return "-an";
}




//Other Tasks
bool Tasks::ContainsIllegalCharacters(wxString FilePath)
{
    return FilePath.find_first_of("\\/:*?\"<>|'") != std::string::npos;
}
