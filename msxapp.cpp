#include <wx/wx.h>
#include "msxapp.h"
#include "msxframe.h"

bool MSXApp::OnInit()
{
	wxFrame* frame = new MSXFrame();
	frame->Show();
	
	return true;
} 

IMPLEMENT_APP(MSXApp)
