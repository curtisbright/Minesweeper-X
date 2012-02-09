class MSXFrame : public wxFrame
{	private:
	enum {ID_NEW, ID_BEGINNER, ID_INTERMEDIATE, ID_EXPERT, ID_CUSTOM, ID_MARKS, ID_PLAYER_NAME, ID_SAVE_VIDEO};
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnBeginner(wxCommandEvent& event);
    void OnIntermediate(wxCommandEvent& event);
    void OnExpert(wxCommandEvent& event);
    void OnCustom(wxCommandEvent& event);
    void Resize();
    MSXPanel* drawPane;
    int xNum, yNum, mNum;

	public:
	MSXFrame();
    DECLARE_EVENT_TABLE()
};

BEGIN_EVENT_TABLE(MSXFrame, wxFrame)
	EVT_MENU(wxID_EXIT,  MSXFrame::OnExit)
	EVT_MENU(ID_BEGINNER, MSXFrame::OnBeginner)
	EVT_MENU(ID_INTERMEDIATE, MSXFrame::OnIntermediate)
	EVT_MENU(ID_EXPERT, MSXFrame::OnExpert)
	EVT_MENU(ID_CUSTOM, MSXFrame::OnCustom)
	EVT_MENU(wxID_ABOUT, MSXFrame::OnAbout)
END_EVENT_TABLE()
