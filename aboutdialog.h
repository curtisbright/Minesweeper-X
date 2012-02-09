class AboutDialog : public wxDialog 
{	private:
	enum {ID_BUTTON};
	
	public:
	AboutDialog(wxWindow* parent, wxIcon& icon);
	void OnExit(wxCommandEvent& event);
	DECLARE_EVENT_TABLE()
};

BEGIN_EVENT_TABLE(AboutDialog, wxDialog)
	EVT_BUTTON(ID_BUTTON, AboutDialog::OnExit)
END_EVENT_TABLE()
