#include <wx/wx.h>
#include "msxframe.h"
#include "msxpanel.h"
#include "customdialog.h"
#include "aboutdialog.h"
#include "graphics/winmine_ico.xpm"

MSXFrame::MSXFrame() : wxFrame((wxFrame*)NULL, -1, wxT("Minesweeper X"), wxPoint(80, 80), wxDefaultSize, wxDEFAULT_FRAME_STYLE&~(wxRESIZE_BORDER|wxMAXIMIZE_BOX))
{	
	xNum = 16;
	yNum = 16;
	mNum = 40;
	
	panel = new MSXPanel((MSXFrame*)this);
	panel->SetBackgroundColour(wxColour(192, 192, 192));
	
	wxMenuBar *menu_bar = new wxMenuBar;
	wxMenu *game_menu = new wxMenu;
	wxMenu *extras_menu = new wxMenu;
	wxMenu *help_menu = new wxMenu;
	
	game_menu->Append(ID_NEW, wxT("&New"));
	game_menu->AppendSeparator();
	game_menu->Append(ID_BEGINNER, wxT("&Beginner"));
	game_menu->Append(ID_INTERMEDIATE, wxT("&Intermediate"));
	game_menu->Append(ID_EXPERT, wxT("&Expert"));
	game_menu->Append(ID_CUSTOM, wxT("&Custom..."));
	game_menu->AppendSeparator();
	game_menu->Append(ID_MARKS, wxT("&Marks (?)"));
	game_menu->AppendSeparator();
	game_menu->Append(wxID_EXIT, wxT("E&xit"));
	extras_menu->Append(ID_PLAYER_NAME, wxT("&Player Name..."));
	extras_menu->Append(ID_SAVE_VIDEO, wxT("&Save Video"));
	help_menu->Append(wxID_ABOUT, wxT("&About..."));
	
	menu_bar->Append(game_menu, wxT("&Game"));
	menu_bar->Append(extras_menu, wxT("&Extras"));
	menu_bar->Append(help_menu, wxT("&Help"));
	SetMenuBar(menu_bar);
	SetIcon(winmine_ico);
	
	Resize();
}

void MSXFrame::OnExit(wxCommandEvent& WXUNUSED(event))
{	Close();
}

void MSXFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{	AboutDialog dialog(this);
	dialog.ShowModal();
}

void MSXFrame::OnCustom(wxCommandEvent& WXUNUSED(event))
{	CustomDialog dialog(this, yNum, xNum, mNum);
	if(dialog.ShowModal() == wxID_OK)
	{	yNum = dialog.GetHeight();
		xNum = dialog.GetWidth();
		mNum = dialog.GetMines();
		Resize();
	}
}

void MSXFrame::OnBeginner(wxCommandEvent& WXUNUSED(event))
{	yNum = 8;
	xNum = 8;
	mNum = 10;
	Resize();
}

void MSXFrame::OnIntermediate(wxCommandEvent& WXUNUSED(event))
{	yNum = 16;
	xNum = 16;
	mNum = 40;
	Resize();
}

void MSXFrame::OnExpert(wxCommandEvent& WXUNUSED(event))
{	yNum = 16;
	xNum = 30;
	mNum = 99;
	Resize();
}

void MSXFrame::Resize()
{	SetClientSize(xNum*16+24, yNum*16+67);
}

void MSXFrame::Activate(wxActivateEvent& WXUNUSED(event))
{	panel->ignoreClick = true;
}

BEGIN_EVENT_TABLE(MSXFrame, wxFrame)
	EVT_MENU(wxID_EXIT,  MSXFrame::OnExit)
	EVT_MENU(ID_BEGINNER, MSXFrame::OnBeginner)
	EVT_MENU(ID_INTERMEDIATE, MSXFrame::OnIntermediate)
	EVT_MENU(ID_EXPERT, MSXFrame::OnExpert)
	EVT_MENU(ID_CUSTOM, MSXFrame::OnCustom)
	EVT_MENU(wxID_ABOUT, MSXFrame::OnAbout)
	EVT_ACTIVATE(MSXFrame::Activate)
END_EVENT_TABLE()
