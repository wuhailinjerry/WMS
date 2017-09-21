#pragma once

class CWMSApp : public wxApp
{
public:
	CWMSApp();
	virtual ~CWMSApp();

	virtual bool OnInit() wxOVERRIDE;

private:
	wxFrame * m_frame;

private:
	wxDECLARE_NO_COPY_CLASS( CWMSApp );
	wxDECLARE_EVENT_TABLE();
};