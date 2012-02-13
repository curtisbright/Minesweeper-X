#pragma once

class AboutDialog : public wxDialog 
{	private:
	enum {ID_BUTTON};
	
	public:
	AboutDialog(wxWindow* parent);
	void OnExit(wxCommandEvent& event);
	DECLARE_EVENT_TABLE()
};