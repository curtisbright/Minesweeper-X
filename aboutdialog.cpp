#include <wx/wx.h>
#include <wx/hyperlink.h>
#include <wx/statline.h>
#include "aboutdialog.h"
#include "graphics/winmine_ico.xpm"

AboutDialog::AboutDialog(wxWindow* parent) : wxDialog(parent, wxID_ANY, wxT("About"))
{	wxBoxSizer* aboutSizer = new wxBoxSizer(wxHORIZONTAL);
	wxStaticBitmap* icon = new wxStaticBitmap(this, wxID_ANY, wxIcon(winmine_ico));
	wxBoxSizer* descriptionSizer = new wxBoxSizer(wxVERTICAL);
	wxStaticText* titleText = new wxStaticText(this, wxID_ANY, wxT("Minesweeper X"));
	titleText->SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Tahoma")));
	wxStaticText* versionText = new wxStaticText(this, wxID_ANY, wxT("Version 2.0"));
	wxStaticText* authorText = new wxStaticText(this, wxID_ANY, wxT("by Curtis Bright"));
	wxStaticLine* separator = new wxStaticLine(this);
	wxStaticText* originText = new wxStaticText(this, wxID_ANY, wxT("Based on the Microsoft game by"));
	wxStaticText* originText2 = new wxStaticText(this, wxID_ANY, wxT("Robert Donner and Curt Johnson."));
	wxStaticText* descriptionText = new wxStaticText(this, wxID_ANY, wxT("Minesweeper X is free software, and was"));
	wxStaticText* descriptionText2 = new wxStaticText(this, wxID_ANY, wxT("developed using the wxWidgets library."));
	wxHyperlinkCtrl* websiteText = new wxHyperlinkCtrl(this, wxID_ANY, wxT("http://www.curtisbright.com/msx/"), wxT("http://www.curtisbright.com/msx/"));
	wxButton* OKButton = new wxButton(this, wxID_CANCEL, wxT("OK"));

	descriptionSizer->Add(titleText, 0, wxALIGN_TOP|wxLEFT|wxTOP, 5);
	descriptionSizer->Add(versionText, 0, wxLEFT, 5);
	descriptionSizer->Add(authorText, 0, wxLEFT, 5);
	descriptionSizer->Add(separator, 0, wxEXPAND|wxALL, 5);
	descriptionSizer->Add(originText, 0, wxLEFT, 5);
	descriptionSizer->Add(originText2, 0, wxLEFT, 5);
	descriptionSizer->Add(descriptionText, 0, wxLEFT|wxTOP|wxRIGHT, 5);
	descriptionSizer->Add(descriptionText2, 0, wxLEFT|wxRIGHT, 5);
	descriptionSizer->Add(websiteText, 0, wxBOTTOM|wxLEFT|wxTOP, 5);
	descriptionSizer->Add(OKButton, 0, wxALIGN_RIGHT|wxALL, 5);
	
	aboutSizer->Add(icon, 0, wxALL, 5);
	aboutSizer->Add(descriptionSizer, 1, wxBOTTOM|wxEXPAND|wxRIGHT, 5);
	this->SetSizer(aboutSizer);
	aboutSizer->Fit(this);
	
	OKButton->SetFocus();
}
