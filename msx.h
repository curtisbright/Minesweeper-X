#include "wx/wx.h"

class MSXPanel : public wxPanel
{	private:
	void Paint(wxPaintEvent& evt);
	void DrawBorder(wxDC& dc, int x1, int y1, int x2, int y2, int width, int colour);
	wxFrame* frame;
	
	public:
	MSXPanel(wxFrame* parent);
	DECLARE_EVENT_TABLE()
};

BEGIN_EVENT_TABLE(MSXPanel, wxPanel)
	EVT_PAINT(MSXPanel::Paint)
END_EVENT_TABLE()

class MSXApp : public wxApp
{	private:
	bool OnInit();
	wxFrame* frame;
	MSXPanel* drawPane;
};
