#pragma once
#include "wx/wx.h"
#include "Fenster.h"

class AutoClick : public wxApp
{
private:
	Fenster* f1;
public:
	virtual bool OnInit();
};