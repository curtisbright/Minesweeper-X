AboutDialog::AboutDialog(wxWindow* parent) : wxDialog(parent, wxID_ANY, wxT("About"), wxDefaultPosition, wxSize(-1,-1), wxDEFAULT_DIALOG_STYLE)
{
	//this->SetSizeHints(wxDefaultSize, wxDefaultSize);
	
	wxBoxSizer* AboutSizer = new wxBoxSizer(wxHORIZONTAL);
	
	wxStaticBitmap* m_bitmap = new wxStaticBitmap(this, wxID_ANY, winmine_ico, wxDefaultPosition, wxDefaultSize, 0);
	AboutSizer->Add(m_bitmap, 0, wxALL, 5);
	
	wxBoxSizer* DescriptionSizer = new wxBoxSizer(wxVERTICAL);
	
	wxStaticText* TitleText = new wxStaticText(this, wxID_ANY, wxT("Minesweeper X"), wxDefaultPosition, wxDefaultSize, 0);
	TitleText->Wrap(-1);
	TitleText->SetFont(wxFont(12, 74, 90, 90, false, wxT("Tahoma")));
	DescriptionSizer->Add(TitleText, 0, wxALIGN_TOP|wxLEFT|wxTOP, 5);
	
	wxStaticText* VersionText = new wxStaticText(this, wxID_ANY, wxT("Version 2.0"), wxDefaultPosition, wxDefaultSize, 0);
	VersionText->Wrap(-1);
	DescriptionSizer->Add(VersionText, 0, wxLEFT, 5);
	
	wxStaticText* AuthorText = new wxStaticText(this, wxID_ANY, wxT("by Curtis Bright"), wxDefaultPosition, wxDefaultSize, 0);
	AuthorText->Wrap(-1);
	DescriptionSizer->Add(AuthorText, 0, wxLEFT, 5);
	
	wxStaticLine* Separator = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	DescriptionSizer->Add(Separator, 0, wxEXPAND | wxALL, 5);
	
	wxStaticText* OriginText1 = new wxStaticText(this, wxID_ANY, wxT("Based on the Microsoft game by"), wxDefaultPosition, wxDefaultSize, 0);
	OriginText1->Wrap(-1);
	DescriptionSizer->Add(OriginText1, 0, wxLEFT, 5);
	
	wxStaticText* OriginText2 = new wxStaticText(this, wxID_ANY, wxT("Robert Donner and Curt Johnson."), wxDefaultPosition, wxDefaultSize, 0);
	OriginText2->Wrap(-1);
	DescriptionSizer->Add(OriginText2, 0, wxLEFT, 5);
	
	wxStaticText* DescriptionText1 = new wxStaticText(this, wxID_ANY, wxT("Minesweeper X is free software, and was"), wxDefaultPosition, wxDefaultSize, 0);
	DescriptionText1->Wrap(-1);
	DescriptionSizer->Add(DescriptionText1, 0, wxLEFT|wxTOP, 5);
	
	wxStaticText* DescriptionText2 = new wxStaticText(this, wxID_ANY, wxT("written in C++ using the wxWidgets library."), wxDefaultPosition, wxDefaultSize, 0);
	DescriptionText2->Wrap(-1);
	
	DescriptionSizer->Add(DescriptionText2, 0, wxLEFT|wxRIGHT, 5);
	
	wxHyperlinkCtrl* WebsiteText = new wxHyperlinkCtrl(this, wxID_ANY, wxT("http://www.curtisbright.com/msx/"), wxT("http://www.curtisbright.com/msx/"), wxDefaultPosition, wxDefaultSize, wxHL_DEFAULT_STYLE);
	DescriptionSizer->Add(WebsiteText, 0, wxBOTTOM|wxLEFT|wxTOP, 5);
	
	wxButton* OKButton = new wxButton(this, ID_BUTTON, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0);
	DescriptionSizer->Add(OKButton, 0, wxALIGN_RIGHT|wxALL, 5);
	
	AboutSizer->Add(DescriptionSizer, 1, wxBOTTOM|wxEXPAND|wxRIGHT, 5);
	
	this->SetSizer(AboutSizer);
	this->Layout();
	AboutSizer->Fit(this);
	
	this->Centre(wxBOTH);
	
	OKButton->SetFocus();
}

void AboutDialog::OnExit(wxCommandEvent& WXUNUSED(event))
{	Close(true);
}
