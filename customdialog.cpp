#include <wx/wx.h>
#include "customdialog.h"

CustomDialog::CustomDialog(wxWindow* parent, int height, int width, int mines) : wxDialog(parent, wxID_ANY, wxT("Custom Field"))
{	wxGridSizer* customSizer = new wxFlexGridSizer(3, 3, 0, 0);
	wxStaticText* heightText = new wxStaticText(this, wxID_ANY, wxT("Height:"));
	heightInput = new wxTextCtrl(this, wxID_ANY, wxString::Format(wxT("%i"), height), wxDefaultPosition, wxSize(50, -1));
	wxButton* OKButton = new wxButton(this, wxID_OK, wxT("OK"));
	wxStaticText* widthText = new wxStaticText(this, wxID_ANY, wxT("Width:"));
	widthInput = new wxTextCtrl(this, wxID_ANY, wxString::Format(wxT("%i"), width), wxDefaultPosition, wxSize(50, -1));
	widthInput->MoveAfterInTabOrder(heightInput);
	wxButton* cancelButton = new wxButton(this, wxID_CANCEL, wxT("Cancel"));
	wxStaticText* minesText = new wxStaticText(this, wxID_ANY, wxT("Mines:"));
	minesInput = new wxTextCtrl(this, wxID_ANY, wxString::Format(wxT("%i"), mines), wxDefaultPosition, wxSize(50, -1));
	minesInput->MoveAfterInTabOrder(widthInput);
	
	customSizer->Add(heightText, 1, wxALL, 5);
	customSizer->Add(heightInput, 0, wxALL, 5);
	customSizer->Add(OKButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);
	customSizer->Add(widthText, 0, wxALL, 5);
	customSizer->Add(widthInput, 0, wxALL, 5);
	customSizer->Add(cancelButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);
	customSizer->Add(minesText, 0, wxALL, 5);
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
