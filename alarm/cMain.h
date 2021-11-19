#pragma once
#include "wx/wx.h"
class cMain :public wxFrame
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
};

