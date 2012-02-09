MSXFrame::MSXFrame() : wxFrame((wxFrame*)NULL, -1, wxT("Minesweeper X"), wxPoint(50,50), wxSize(-1,-1), wxDEFAULT_FRAME_STYLE&~(wxRESIZE_BORDER|wxMAXIMIZE_BOX))
{	
	xNum = 16;
	yNum = 16;
	mNum = 40;
	
	drawPane = new MSXPanel((MSXFrame*)this);
	drawPane->SetBackgroundColour(wxColour(192, 192, 192));
	
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
	
	Resize();
}

void MSXFrame::OnExit(wxCommandEvent& WXUNUSED(event))
{	Close(true);
}

void MSXFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{	AboutDialog dialog(this);
	dialog.ShowModal();
}

void MSXFrame::OnCustom(wxCommandEvent& WXUNUSED(event))
{	CustomDialog dialog(this, yNum, xNum, mNum);
	if(dialog.ShowModal() == wxID_OK)
	{	yNum = dialog.getHeight();
		xNum = dialog.getWidth();
		mNum = dialog.getMines();
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
