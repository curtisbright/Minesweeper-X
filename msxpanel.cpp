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
	
	ButtonState = BUTTON_HAPPY;
	ButtonClick = false;
	GameAsleep = false;
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
	ButtonState = type;
}

bool MSXPanel::OnButton(wxPoint pos)
{	int width, height;
	GetClientSize(&width, &height);
	wxRect* Capture = new wxRect((width-24)>>1, 16, 24, 24);
	return Capture->Contains(pos);
}

/* Left Button Press */
void MSXPanel::LButtonDown(wxMouseEvent& event)
{	// Ignore click if window has just activated
	if(IgnoreClick){IgnoreClick=false; return;}
	
	// Ignore click if the button has been pressed
	if(ButtonClick){return;}
	
	// Check the status of game
	if(GameAsleep){return;}
	
	// Capture the mouse
	if(!HasCapture()){CaptureMouse();}
	
	// Check if click is over the button
	if(OnButton(event.GetPosition()))
	{	ButtonClick = true;
		DrawButton(BUTTON_DOWN);
		return;
	}
	
	DrawButton(BUTTON_CAUTION);
}

/* Right Button Press */
void MSXPanel::RButtonDown(wxMouseEvent& WXUNUSED(event))
{	// Ignore click if window has just activated
	if(IgnoreClick){IgnoreClick=false; return;}
	
	// Ignore click if the button has been pressed
	if(ButtonClick){return;}
}

/* Middle Button Press */
void MSXPanel::MButtonDown(wxMouseEvent& WXUNUSED(event))
{	// Ignore click if window has just activated
	if(IgnoreClick){IgnoreClick=false; return;}

	// Ignore click if the button has been pressed
	if(ButtonClick){return;}
	
	// Check the status of game
	if(GameAsleep){return;}
	
	// Capture the mouse
	if(!HasCapture()){CaptureMouse();}
	
	DrawButton(BUTTON_CAUTION);
}

/* Left Button Release */
void MSXPanel::LButtonUp(wxMouseEvent& event)
{	// Check if button has been clicked
	if(ButtonClick)
	{	ButtonClick = false;
		DrawButton(BUTTON_HAPPY);
		if(OnButton(event.GetPosition()))
		{	// Process new game
		}
		
		// Release the mouse
		if(HasCapture()){ReleaseMouse();}
		return;
	}
	
	// Release the mouse
	if(HasCapture()){ReleaseMouse();}
	
	DrawButton(BUTTON_HAPPY);
}

/* Right Button Release */
void MSXPanel::RButtonUp(wxMouseEvent& WXUNUSED(event))
{	// Ignore click if the button has been pressed
	if(ButtonClick){return;}
	
	// Release the mouse
	if(HasCapture()){ReleaseMouse();}
	
	DrawButton(BUTTON_HAPPY);
}

/* Middle Button Release */
void MSXPanel::MButtonUp(wxMouseEvent& WXUNUSED(event))
{	// Ignore click if the button has been pressed
	if(ButtonClick){return;}
	
	// Release the mouse
	if(HasCapture()){ReleaseMouse();}
	
	DrawButton(BUTTON_HAPPY);
}

/* Mouse Move Event */
void MSXPanel::MouseMove(wxMouseEvent& event)
{	// Window was not just activated
	IgnoreClick = false;
	
	// Check if button has been clicked
	if(ButtonClick)
	{	if(OnButton(event.GetPosition()))
			DrawButton(BUTTON_DOWN);
		else
			DrawButton(BUTTON_HAPPY);
	}
	
	// Debugging
	printf("(%i %i) (", event.GetX(), event.GetY());
	if(event.m_leftDown)printf("l");
	if(event.m_middleDown)printf("m");
	if(event.m_rightDown)printf("r");
	printf(")\n");
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
	
	dc.Blit((width-24)>>1, 16, 24, 24, button, 0, ButtonState);
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
