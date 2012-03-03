#include <wx/wx.h>
#include "customdialog.h"

CustomDialog::CustomDialog(wxWindow* parent, int height, int width, int mines) : wxDialog(parent, wxID_ANY, wxT("Custom Field"))
{
	wxGridSizer* customSizer = new wxFlexGridSizer(3, 3, 0, 0);
	
	wxStaticText* heightText = new wxStaticText(this, wxID_ANY, wxT("Height:"), wxDefaultPosition, wxSize(-1,-1), 0);
	customSizer->Add(heightText, 1, wxALL, 5);
	
	heightInput = new wxTextCtrl(this, wxID_ANY, wxString::Format(wxT("%i"), height), wxDefaultPosition, wxDefaultSize, 0);
	customSizer->Add(heightInput, 0, wxALL, 5);
	
	wxButton* OKButton = new wxButton(this, wxID_OK, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0);
	customSizer->Add(OKButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);
	
	wxStaticText* widthText = new wxStaticText(this, wxID_ANY, wxT("Width:"), wxDefaultPosition, wxDefaultSize, 0);
	customSizer->Add(widthText, 0, wxALL, 5);
	
	widthInput = new wxTextCtrl(this, wxID_ANY, wxString::Format(wxT("%i"), width), wxDefaultPosition, wxDefaultSize, 0);
	widthInput->MoveAfterInTabOrder(heightInput);
	customSizer->Add(widthInput, 0, wxALL, 5);
	
	wxButton* cancelButton = new wxButton(this, wxID_CANCEL, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0);
	customSizer->Add(cancelButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);
	
	wxStaticText* minesText = new wxStaticText(this, wxID_ANY, wxT("Mines:"), wxDefaultPosition, wxDefaultSize, 0);
	customSizer->Add(minesText, 0, wxALL, 5);
	
	minesInput = new wxTextCtrl(this, wxID_ANY, wxString::Format(wxT("%i"), mines), wxDefaultPosition, wxDefaultSize, 0);
	minesInput->MoveAfterInTabOrder(widthInput);
	customSizer->Add(minesInput, 0, wxALL, 5);
	
	this->SetSizer(customSizer);
	customSizer->Fit(this);
}

void CustomDialog::OnExit(wxCommandEvent& WXUNUSED(event))
{	Close();
}

int CustomDialog::GetHeight()
{	return wxAtoi(heightInput->GetValue());
}

int CustomDialog::GetWidth()
{	return wxAtoi(widthInput->GetValue());
}

int CustomDialog::GetMines()
{	return wxAtoi(minesInput->GetValue());
}

BEGIN_EVENT_TABLE(CustomDialog, wxDialog)
	EVT_BUTTON(ID_OK, CustomDialog::OnExit)
END_EVENT_TABLE()
