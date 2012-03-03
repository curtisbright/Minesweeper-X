#pragma once

class CustomDialog : public wxDialog 
{	private:
	enum{ID_OK};
	void OnExit(wxCommandEvent& event);
	wxTextCtrl* heightInput;
	wxTextCtrl* widthInput;
	wxTextCtrl* minesInput;
	
	public:
	CustomDialog(wxWindow* parent, int height, int width, int mines); 
	int GetHeight();
	int GetWidth();
	int GetMines();
	DECLARE_EVENT_TABLE()
};
