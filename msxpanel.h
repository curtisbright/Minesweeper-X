class MSXPanel : public wxPanel
{	private:
	void Paint(wxPaintEvent& evt);
	void DrawBorder(wxDC& dc, int x1, int y1, int x2, int y2, int width, int colour);
	MSXFrame* frame;
	wxMemoryDC* button;
	wxMemoryDC* led;
	wxMemoryDC* blocks;
	
	public:
	MSXPanel(MSXFrame* parent);
	DECLARE_EVENT_TABLE()
};

BEGIN_EVENT_TABLE(MSXPanel, wxPanel)
	EVT_PAINT(MSXPanel::Paint)
END_EVENT_TABLE()
