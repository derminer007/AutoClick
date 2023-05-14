#pragma once
#include <wx/wx.h>
class Fenster : public wxFrame
{
private:
	wxPanel* panel;
	wxButton* b1;
	wxTextCtrl* t1;

	wxBoxSizer* s1;

	DECLARE_EVENT_TABLE()
public:
	Fenster();
	~Fenster();

	void OnClose(wxCloseEvent& evt);
};

