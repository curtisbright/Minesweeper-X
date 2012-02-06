class CustomDialog : public wxDialog 
{	private:
	enum{ID_OK, ID_CANCEL};
	
	public:
	CustomDialog(wxWindow* parent); 
	void OnExit(wxCommandEvent& event);
	DECLARE_EVENT_TABLE()
};

BEGIN_EVENT_TABLE(CustomDialog, wxDialog)
	EVT_BUTTON(ID_OK, CustomDialog::OnExit)
	EVT_BUTTON(ID_CANCEL, CustomDialog::OnExit)
END_EVENT_TABLE()
