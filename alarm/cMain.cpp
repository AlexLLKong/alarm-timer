#include "cMain.h"

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "alarm-timer", wxPoint(30, 30), wxSize(800, 600))
{
	wxBoxSizer* mSizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* subSizer = new wxBoxSizer(wxHORIZONTAL);
	wxFont font(72, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);

	hr = new wxTextCtrl(this, 10001, "00", wxDefaultPosition, wxSize(120, 100));
	hr->SetDefaultStyle(wxTextAttr(wxTE_CENTRE));
	hr->SetFont(font);

	colon1 = new wxStaticText(this, 10004, ":", wxDefaultPosition);
	colon1->SetFont(font);

	min = new wxTextCtrl(this, 10002, "00", wxDefaultPosition, wxSize(120, 100));
	min->SetDefaultStyle(wxTextAttr(wxTE_CENTRE));
	min->SetFont(font);

	colon2 = new wxStaticText(this, 10005, ":", wxDefaultPosition);
	colon2->SetFont(font);

	sec = new wxTextCtrl(this, 10003, "00", wxDefaultPosition, wxSize(120, 100));
	sec->SetDefaultStyle(wxTextAttr(wxTE_CENTRE));
	sec->SetFont(font);

	mSizer->Add(subSizer, 0, wxALIGN_CENTER);
	subSizer->Add(hr);
	subSizer->Add(colon1);
	subSizer->Add(min);
	subSizer->Add(colon2);
	subSizer->Add(sec);

	SetSizer(mSizer);
	this->CenterOnParent();
}

cMain::~cMain()
{
	delete[]hr;
	delete[]min;
	delete[]sec;
}
