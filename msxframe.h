enum { ID_NEW, ID_BEGINNER, ID_INTERMEDIATE, ID_EXPERT, ID_CUSTOM, ID_MARKS, ID_PLAYER_NAME, ID_SAVE_VIDEO };

class MSXFrame : public wxFrame
{	private:
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnCustom(wxCommandEvent& event);
    MSXPanel* drawPane;

	public:
	MSXFrame();
    DECLARE_EVENT_TABLE()
};

BEGIN_EVENT_TABLE(MSXFrame, wxFrame)
    EVT_MENU(wxID_EXIT,  MSXFrame::OnExit)
    EVT_MENU(wxID_ABOUT, MSXFrame::OnAbout)
    EVT_MENU(ID_CUSTOM, MSXFrame::OnCustom)
END_EVENT_TABLE()
