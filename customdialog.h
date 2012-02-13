#pragma once

class CustomDialog : public wxDialog 
{	private:
	enum{ID_OK};
	void OnExit(wxCommandEvent& event);
	wxTextCtrl* HeightInput;
	wxTextCtrl* WidthInput;
	wxTextCtrl* MinesInput;
	
	public:
	CustomDialog(wxWindow* parent, int height, int width, int mines); 
	int getHeight();
	int getWidth();
	int getMines();
	DECLARE_EVENT_TABLE()
};
