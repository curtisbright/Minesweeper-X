CustomDialog::CustomDialog(wxWindow* parent) : wxDialog(parent, wxID_ANY, wxT("Custom Field"), wxPoint(-1,-1), wxSize(-1,-1), wxDEFAULT_DIALOG_STYLE)
{
	//this->SetSizeHints(wxDefaultSize, wxDefaultSize);
	
	wxGridSizer* CustomSizer = new wxFlexGridSizer(3, 3, 0, 0);
	
	wxStaticText* HeightText = new wxStaticText(this, wxID_ANY, wxT("Height:"), wxDefaultPosition, wxSize(-1,-1), 0);
	HeightText->Wrap(-1);
	CustomSizer->Add(HeightText, 1, wxALL, 5);
	
	wxTextCtrl* HeightInput = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	CustomSizer->Add(HeightInput, 0, wxALL, 5);
	
	wxButton* OKButton = new wxButton(this, wxID_OK, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0);
	CustomSizer->Add(OKButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);
	
	wxStaticText* WidthText = new wxStaticText(this, wxID_ANY, wxT("Width:"), wxDefaultPosition, wxDefaultSize, 0);
	WidthText->Wrap(-1);
	CustomSizer->Add(WidthText, 0, wxALL, 5);
	
	wxTextCtrl* WidthInput = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	WidthInput->MoveAfterInTabOrder(HeightInput);
	CustomSizer->Add(WidthInput, 0, wxALL, 5);
	
	wxButton* CancelButton = new wxButton(this, wxID_CANCEL, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0);
	CustomSizer->Add(CancelButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);
	
	wxStaticText* MinesText = new wxStaticText(this, wxID_ANY, wxT("Mines:"), wxDefaultPosition, wxDefaultSize, 0);
	MinesText->Wrap(-1);
	CustomSizer->Add(MinesText, 0, wxALL, 5);
	
	wxTextCtrl* MinesInput = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	MinesInput->MoveAfterInTabOrder(WidthInput);
	CustomSizer->Add(MinesInput, 0, wxALL, 5);
	
	this->SetSizer(CustomSizer);
	this->Layout();
	CustomSizer->Fit(this);
	
	this->Centre(wxBOTH);
}

void CustomDialog::OnExit(wxCommandEvent& WXUNUSED(event))
{	Close(true);
}
