#include "msx.h"

MSXPanel::MSXPanel(wxFrame* parent) : wxPanel(parent)
{	frame = parent;
}

void MSXPanel::DrawBorder(wxDC& dc, int x1, int y1, int x2, int y2, int width, int colour)
{	
	if(colour&1)
		dc.SetPen(*wxWHITE_PEN);
	else
		dc.SetPen(wxPen(wxColor(128,128,128)));
	for(int i=0; i<width; i++)
	{	dc.DrawLine(x1+i, y1+i, x1+i, y2-i);
		dc.DrawLine(x1+i, y1+i, x2-i, y1+i);
	}
	
	if(colour==0)
		dc.SetPen(*wxWHITE_PEN);
	else
		dc.SetPen(wxPen(wxColor(128,128,128)));
	for(int i=0; i<width; i++)
	{	dc.DrawLine(x2-i+1, y2-i, x1+i+1, y2-i);
		dc.DrawLine(x2-i, y2-i+1, x2-i, y1+i+1);
	}
}

void MSXPanel::Paint(wxPaintEvent& event)
{	wxPaintDC dc(this);
	int width, height;
	frame->GetClientSize(&width, &height);
	DrawBorder(dc, 0, 0, width-1, height-1, 3, 1);
	DrawBorder(dc, 9, 52, width-10, height-10, 3, 0);
	DrawBorder(dc, 9, 9, width-10, 45, 2, 0);
	DrawBorder(dc, 16, 15, 56, 39, 1, 0);
	DrawBorder(dc, width-59, 15, width-19, 39, 1, 0);
	DrawBorder(dc, ((width-24)>>1)-1, 15, ((width-24)>>1)+24, 40, 1, 2);
}

bool MSXApp::OnInit()
{
	frame = new wxFrame((wxFrame*)NULL, -1, wxT("Minesweeper X"), wxPoint(50,50), wxSize(-1,-1), wxDEFAULT_FRAME_STYLE&~(wxRESIZE_BORDER|wxMAXIMIZE_BOX));
	drawPane = new MSXPanel((wxFrame*)frame);
	drawPane->SetBackgroundColour(wxColour(192,192,192));
	
	frame->SetClientSize(0x118,0x143);
	frame->Show();
	
	return true;
} 

IMPLEMENT_APP(MSXApp)
