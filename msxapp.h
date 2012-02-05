class MSXPanel;
class MSXFrame;

class MSXApp : public wxApp
{	private:
	bool OnInit();
	wxFrame* frame;
	MSXPanel* drawPane;
};
