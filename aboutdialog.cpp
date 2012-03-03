#include <wx/wx.h>
#include <wx/hyperlink.h>
#include <wx/statline.h>
#include "aboutdialog.h"
#include "graphics/winmine_ico.xpm"

AboutDialog::AboutDialog(wxWindow* parent) : wxDialog(parent, wxID_ANY, wxT("About"))
{
	wxBoxSizer* aboutSizer = new wxBoxSizer(wxHORIZONTAL);
	
	wxStaticBitmap* icon = new wxStaticBitmap(this, wxID_ANY, wxIcon(winmine_ico), wxDefaultPosition, wxDefaultSize, 0);
	aboutSizer->Add(icon, 0, wxALL, 5);
	
	wxBoxSizer* descriptionSizer = new wxBoxSizer(wxVERTICAL);
	
	wxStaticText* titleText = new wxStaticText(this, wxID_ANY, wxT("Minesweeper X"), wxDefaultPosition, wxDefaultSize, 0);
	titleText->SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	descriptionSizer->Add(titleText, 0, wxALIGN_TOP|wxLEFT|wxTOP, 5);
	
	wxStaticText* versionText = new wxStaticText(this, wxID_ANY, wxT("Version 2.0"), wxDefaultPosition, wxDefaultSize, 0);
	descriptionSizer->Add(versionText, 0, wxLEFT, 5);
	
	wxStaticText* authorText = new wxStaticText(this, wxID_ANY, wxT("by Curtis Bright"), wxDefaultPosition, wxDefaultSize, 0);
	descriptionSizer->Add(authorText, 0, wxLEFT, 5);
	
	wxStaticLine* separator = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	descriptionSizer->Add(separator, 0, wxEXPAND | wxALL, 5);
	
	wxStaticText* originText = new wxStaticText(this, wxID_ANY, wxT("Based on the Microsoft game by Robert Donner and Curt Johnson."), wxDefaultPosition, wxDefaultSize, 0);
	originText->Wrap(300);
	descriptionSizer->Add(originText, 0, wxLEFT, 5);
	
	wxStaticText* descriptionText = new wxStaticText(this, wxID_ANY, wxT("Minesweeper X is free software, and was developed using the wxWidgets library."), wxDefaultPosition, wxDefaultSize, 0);
	descriptionText->Wrap(300);
	descriptionSizer->Add(descriptionText, 0, wxLEFT|wxTOP|wxRIGHT, 5);
	
	wxHyperlinkCtrl* websiteText = new wxHyperlinkCtrl(this, wxID_ANY, wxT("http://www.curtisbright.com/msx/"), wxT("http://www.curtisbright.com/msx/"), wxDefaultPosition, wxDefaultSize, wxHL_DEFAULT_STYLE);
	descriptionSizer->Add(websiteText, 0, wxBOTTOM|wxLEFT|wxTOP, 5);
	
	wxButton* OKButton = new wxButton(this, wxID_CANCEL, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0);
	descriptionSizer->Add(OKButton, 0, wxALIGN_RIGHT|wxALL, 5);
	
	aboutSizer->Add(descriptionSizer, 1, wxBOTTOM|wxEXPAND|wxRIGHT, 5);
	
	this->SetSizer(aboutSizer);
	aboutSizer->Fit(this);
	
	OKButton->SetFocus();
}
