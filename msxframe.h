#pragma once
class MSXPanel;

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