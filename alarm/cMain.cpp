#include "cMain.h"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
	EVT_TIMER(10008, OnTimer)
wxEND_EVENT_TABLE()

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "wow big window", wxPoint(30, 30), wxSize(800, 600))
{
	wxBoxSizer* mSizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* timeSizer = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL);
	wxFont font(72, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);
	wxIntegerValidator<unsigned long> val = wxIntegerValidator<unsigned long>();
	val.SetMax(59);
	timer = new wxTimer(this, 10008);

	hr = new wxTextCtrl(this, 10001, "00", wxDefaultPosition, wxSize(120, 100), 0L, val);
	hr->SetDefaultStyle(wxTextAttr(wxTE_CENTRE));
	hr->SetFont(font);
	hr->Bind(wxEVT_KILL_FOCUS, &cMain::OnTextCtrlLoseFocus, this);

	colon1 = new wxStaticText(this, 10004, ":", wxDefaultPosition);
	colon1->SetFont(font);

	min = new wxTextCtrl(this, 10002, "00", wxDefaultPosition, wxSize(120, 100), 0L, val);
	min->SetDefaultStyle(wxTextAttr(wxTE_CENTRE));
	min->SetFont(font);
	min->Bind(wxEVT_KILL_FOCUS, &cMain::OnTextCtrlLoseFocus, this);

	colon2 = new wxStaticText(this, 10005, ":", wxDefaultPosition);
	colon2->SetFont(font);

	sec = new wxTextCtrl(this, 10003, "00", wxDefaultPosition, wxSize(120, 100), 0L, val);
	sec->SetDefaultStyle(wxTextAttr(wxTE_CENTRE));
	sec->SetFont(font);
	sec->Bind(wxEVT_KILL_FOCUS, &cMain::OnTextCtrlLoseFocus, this);

	startPause = new wxButton(this, 10006, "start");
	reset = new wxButton(this, 10007, "reset");

	startPause->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::OnStartPauseClicked, this);
	reset->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::OnResetClicked, this);

	mSizer->Add(timeSizer, 0, wxALIGN_CENTER);
	mSizer->Add(buttonSizer, 0, wxALIGN_CENTER);
	timeSizer->Add(hr);
	timeSizer->Add(colon1);
	timeSizer->Add(min);
	timeSizer->Add(colon2);
	timeSizer->Add(sec);
	buttonSizer->Add(startPause);
	buttonSizer->Add(reset);

	SetSizer(mSizer);
	this->CenterOnParent();
}

cMain::~cMain()
{
	delete[]timer;
}

void cMain::OnTextCtrlLoseFocus(wxFocusEvent& evt)
{
	int id = evt.GetId();
	unsigned long temp;
	if (id == 10001) 
	{
		hr->GetValue().ToULong(&temp);
		if (temp < 10)
			hr->SetValue("0" + std::to_string(temp));
		else if(temp > 99)
			hr->SetValue("00");
	}
	else if (id == 10002) 
	{
		min->GetValue().ToULong(&temp);
		if (temp < 10)
			min->SetValue("0" + std::to_string(temp));
		else if (temp > 99)
			min->SetValue("00");
	}
	else if (id == 10003)
	{
		sec->GetValue().ToULong(&temp);
		if (temp < 10)
			sec->SetValue("0" + std::to_string(temp));
		else if (temp > 99)
			sec->SetValue("00");
	}
	evt.Skip();
}

void cMain::OnStartPauseClicked(wxCommandEvent& evt)
{
	if (timer->IsRunning()) 
	{
		startPause->SetLabel("start");
		timer->Stop();
	}
	else 
	{
		timerVal = 0;
		unsigned long seconds;
		unsigned long minutes;
		unsigned long hours;
		sec->GetValue().ToULong(&seconds);
		timerVal += seconds;
		min->GetValue().ToULong(&minutes);
		timerVal += minutes * 60;
		hr->GetValue().ToULong(&hours);
		timerVal += hours * 60 * 60;
		timer->Start(1000);
		if (timerVal > 0)
			startPause->SetLabel("pause");
	}
	evt.Skip();
}

void cMain::OnResetClicked(wxCommandEvent& evt)
{
	timer->Stop();
	startPause->SetLabel("start");
	timerVal = 0;
	hr->SetValue("00");
	min->SetValue("00");
	sec->SetValue("00");
	evt.Skip();
}

void cMain::OnTimer(wxTimerEvent& evt)
{
	if (timerVal >= 0)
	{
		unsigned long hours = timerVal / 3600;
		unsigned long minutes = (timerVal - (3600 * hours)) / 60;
		unsigned long seconds = (timerVal - (3600 * hours) - (60 * minutes));
		std::string sv = hours > 9 ? std::to_string(hours) : "0" + std::to_string(hours);
		hr->SetValue(sv);
		sv = minutes > 9 ? std::to_string(minutes) : "0" + std::to_string(minutes);
		min->SetValue(sv);
		sv = seconds > 9 ? std::to_string(seconds) : "0" + std::to_string(seconds);
		sec->SetValue(sv);
		timerVal--;
	}
	else
		timer->Stop();
	evt.Skip();
}
