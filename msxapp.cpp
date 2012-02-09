#include <wx/wx.h>
#include <wx/hyperlink.h>
#include <wx/statline.h>
#include "msxapp.h"
#include "msxpanel.h"
#include "msxframe.h"
#include "customdialog.h"
#include "aboutdialog.h"
#include "msxpanel.cpp"
#include "msxframe.cpp"
#include "customdialog.cpp"
#include "aboutdialog.cpp"

bool MSXApp::OnInit()
{
	frame = new MSXFrame();
	frame->Show();
	
	return true;
} 

IMPLEMENT_APP(MSXApp)
