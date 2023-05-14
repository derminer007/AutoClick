#include "Fenster.h"

Fenster::Fenster() : wxFrame(nullptr, wxID_ANY, "Lellek_Fenster_ÜÖÄ", wxPoint(500, 500), wxSize(500, 500))
{
	//panel = new wxPanel(this, wxID_ANY);
	//panel->SetBackgroundColour(wxColour(255,255,255));

	b1 = new wxButton(this, wxID_ANY, "Butt");
	t1 = new wxTextCtrl(this, wxID_ANY, "N1");

	s1 = new wxBoxSizer(wxVERTICAL);
	//s1->Add(panel);
	s1->Add(b1, 0, wxALL | wxALIGN_CENTER, 5);
	s1->Add(t1, 0, wxALIGN_CENTER, 5);

	this->SetBackgroundColour(wxColour(255, 255, 255));
	this->SetSizer(s1);
	//s1->Fit(this);
}

Fenster::~Fenster()
{
	
}

void Fenster::OnClose(wxCloseEvent& evt)
{
	exit(0);
}

// Muss in Implementierung sein
BEGIN_EVENT_TABLE(Fenster, wxFrame)
	EVT_CLOSE(Fenster::OnClose)
END_EVENT_TABLE()