class CustomDialog : public wxDialog 
{	private:
	wxStaticText* m_height;
	wxTextCtrl* m_textCtrl2;
	wxButton* m_OK;
	wxStaticText* m_width;
	wxTextCtrl* m_textCtrl3;
	wxButton* m_cancel;
	wxStaticText* m_mines;
	wxTextCtrl* m_textCtrl4;
	
	public:
	CustomDialog(wxWindow* parent); 
	~CustomDialog();
};
