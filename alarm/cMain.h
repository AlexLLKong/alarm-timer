#pragma once
#include "wx/wx.h"
#include "wx/valnum.h"
class cMain : public wxFrame
{
public:
	cMain();
	~cMain();

public:
	wxTextCtrl* hr = nullptr;
	wxTextCtrl* min = nullptr;
	wxTextCtrl* sec = nullptr;
	wxStaticText* colon1 = nullptr;
	wxStaticText* colon2 = nullptr;
	wxButton* startPause = nullptr;
	wxButton* reset = nullptr;
	wxTimer* timer = nullptr;

private: 
	long timerVal = 0;
private:
	void OnTextCtrlLoseFocus(wxFocusEvent& evt);
	void OnStartPauseClicked(wxCommandEvent& evt);
	void OnResetClicked(wxCommandEvent& evt);
	void OnTimer(wxTimerEvent& evt);
	wxDECLARE_EVENT_TABLE();
};

