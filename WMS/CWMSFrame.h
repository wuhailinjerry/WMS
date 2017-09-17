#pragma once

class CWMSFrame : public wxFrame
{
public:
	CWMSFrame( const wxChar *title );
	~CWMSFrame();

	void CreateWMSMenuBar ( );
	void CreateWMSToolBar ( );
	void PopulateToolbar ( );

	wxDECLARE_EVENT_TABLE ( );
};

