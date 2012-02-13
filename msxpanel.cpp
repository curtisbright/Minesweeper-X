#include <wx/wx.h>
#include "msxframe.h"
#include "msxpanel.h"
#include "graphics/button_bmp.xpm"
#include "graphics/led_bmp.xpm"
#include "graphics/blocks_bmp.xpm"

#define BUTTON_DOWN    0
#define BUTTON_WIN     24
#define BUTTON_LOSE    48
#define BUTTON_CAUTION 72
#define BUTTON_HAPPY   96

MSXPanel::MSXPanel(MSXFrame* parent) : wxPanel(parent)
{	frame = parent;

	wxBitmap* buttonbmp = new wxBitmap(button_bmp);
	wxBitmap* ledbmp = new wxBitmap(led_bmp);
	wxBitmap* blocksbmp = new wxBitmap(blocks_bmp);
	button = new wxMemoryDC(*buttonbmp);
	led = new wxMemoryDC(*ledbmp);
	blocks = new wxMemoryDC(*blocksbmp);
}

void MSXPanel::DrawBorder(wxDC& dc, int x1, int y1, int x2, int y2, int width, int colour)
{	
	if(colour&1)
		dc.SetPen(*wxWHITE_PEN);
	else
		dc.SetPen(wxPen(wxColor(128, 128, 128)));
	for(int i=0; i<width; i++)
	{	dc.DrawLine(x1+i, y1+i, x1+i, y2-i);
		dc.DrawLine(x1+i, y1+i, x2-i, y1+i);
	}
	
	if(colour==0)
		dc.SetPen(*wxWHITE_PEN);
	else
		dc.SetPen(wxPen(wxColor(128, 128, 128)));
	for(int i=0; i<width; i++)
	{	dc.DrawLine(x1+i+1, y2-i, x2-i+1, y2-i);
		dc.DrawLine(x2-i, y1+i+1, x2-i, y2-i+1);
	}
}

void MSXPanel::DrawButton(int type)
{	wxClientDC dc(this);
	int width, height;
	frame->GetClientSize(&width, &height);
	dc.Blit((width-24)>>1, 16, 24, 24, button, 0, type);
}

bool MSXPanel::OnButton(wxPoint pos)
{	int width, height;
	GetClientSize(&width, &height);
	wxRect* Capture = new wxRect((width-24)>>1, 16, 24, 24);
	if(!Capture->Contains(pos))
		return false;
	DrawButton(BUTTON_DOWN);
}

void MSXPanel::LButtonDown(wxMouseEvent& event)
{	/*if(IgnoreClick)
	{	IgnoreClick = false;
		return;
	}*/
	if(!HasCapture())
		CaptureMouse();
	if(OnButton(event.GetPosition()))
		return;
}

void MSXPanel::RButtonDown(wxMouseEvent& WXUNUSED(event))
{	if(!HasCapture())
		CaptureMouse();
}

void MSXPanel::MButtonDown(wxMouseEvent& WXUNUSED(event))
{	if(!HasCapture())
		CaptureMouse();
}

void MSXPanel::LButtonUp(wxMouseEvent& WXUNUSED(event))
{	DrawButton(BUTTON_HAPPY);
	if(HasCapture())	
		ReleaseMouse();
}

void MSXPanel::RButtonUp(wxMouseEvent& WXUNUSED(event))
{	if(HasCapture())
		ReleaseMouse();
}

void MSXPanel::MButtonUp(wxMouseEvent& WXUNUSED(event))
{	if(HasCapture())
		ReleaseMouse();
}

void MSXPanel::MouseMove(wxMouseEvent& event)
{	printf("(%i %i)\n", event.GetX(), event.GetY());
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
	
	dc.Blit((width-24)>>1, 16, 24, 24, button, 0, BUTTON_HAPPY);
}

BEGIN_EVENT_TABLE(MSXPanel, wxPanel)
	EVT_PAINT(MSXPanel::Paint)
	EVT_LEFT_DOWN(MSXPanel::LButtonDown)
	EVT_RIGHT_DOWN(MSXPanel::RButtonDown)
	EVT_MIDDLE_DOWN(MSXPanel::MButtonDown)
	EVT_LEFT_UP(MSXPanel::LButtonUp)
	EVT_RIGHT_UP(MSXPanel::RButtonUp)
	EVT_MIDDLE_UP(MSXPanel::MButtonUp)
	EVT_LEFT_DCLICK(MSXPanel::LButtonDown)
	EVT_RIGHT_DCLICK(MSXPanel::RButtonDown)
	EVT_MIDDLE_DCLICK(MSXPanel::MButtonDown)
	EVT_MOTION(MSXPanel::MouseMove)
END_EVENT_TABLE()
