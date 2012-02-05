#include "wx/wx.h"
#include "msxapp.h"
#include "msxpanel.h"
#include "msxframe.h"
#include "customdialog.h"
#include "msxpanel.cpp"
#include "msxframe.cpp"
#include "customdialog.cpp"

bool MSXApp::OnInit()
{
	frame = new MSXFrame();
	frame->SetClientSize(0x118,0x143);
	frame->Show();
	
	return true;
} 

IMPLEMENT_APP(MSXApp)
