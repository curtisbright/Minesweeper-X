#pragma once
class MSXFrame;

class MSXPanel : public wxPanel
{	private:
	void Paint(wxPaintEvent& event);
	void DrawBorder(wxDC& dc, int x1, int y1, int x2, int y2, int width, int colour);
	MSXFrame* frame;
	wxMemoryDC* button;
	wxMemoryDC* led;
	wxMemoryDC* blocks;
	void LButtonDown(wxMouseEvent& event);
	void RButtonDown(wxMouseEvent& event);
	void MButtonDown(wxMouseEvent& event);
	void LButtonUp(wxMouseEvent& event);
	void RButtonUp(wxMouseEvent& event);
	void MButtonUp(wxMouseEvent& event);
	void MouseMove(wxMouseEvent& event);
	bool OnButton(wxPoint pos);
	bool buttonClick;
	int buttonState;
	bool gameAsleep;
	
	public:
	MSXPanel(MSXFrame* parent);
	void DrawButton(int type);
	bool ignoreClick;
	DECLARE_EVENT_TABLE()
};
