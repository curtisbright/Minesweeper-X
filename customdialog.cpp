CustomDialog::CustomDialog(wxWindow* parent) : wxDialog(parent, wxID_ANY, wxT("Custom Field"), wxPoint(-1,-1), wxSize(-1,-1), wxDEFAULT_DIALOG_STYLE)
{
	//this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxGridSizer* gSizer1;
	gSizer1 = new wxFlexGridSizer( 3, 3, 0, 0 );
	
	m_height = new wxStaticText( this, wxID_ANY, wxT("Height:"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_height->Wrap( -1 );
	gSizer1->Add( m_height, 1, wxALL, 5 );
	
	m_textCtrl2 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gSizer1->Add( m_textCtrl2, 0, wxALL, 5 );
	
	m_OK = new wxButton( this, wxID_ANY, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer1->Add( m_OK, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_width = new wxStaticText( this, wxID_ANY, wxT("Width:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_width->Wrap( -1 );
	gSizer1->Add( m_width, 0, wxALL, 5 );
	
	m_textCtrl3 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gSizer1->Add( m_textCtrl3, 0, wxALL, 5 );
	
	m_cancel = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer1->Add( m_cancel, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_mines = new wxStaticText( this, wxID_ANY, wxT("Mines:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_mines->Wrap( -1 );
	gSizer1->Add( m_mines, 0, wxALL, 5 );
	
	m_textCtrl4 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gSizer1->Add( m_textCtrl4, 0, wxALL, 5 );
	
	this->SetSizer( gSizer1 );
	this->Layout();
	gSizer1->Fit( this );
	
	this->Centre( wxBOTH );
}

CustomDialog::~CustomDialog()
{
}
