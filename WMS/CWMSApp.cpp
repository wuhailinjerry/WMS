#include "stdafx.h"
#include "CWMSApp.h"

#include "CWMSFrame.h"
#include "WMSDefine.h"

wxIMPLEMENT_APP( CWMSApp );

wxDECLARE_APP( CWMSApp );

BEGIN_DECLARE_EVENT_TYPES()
END_DECLARE_EVENT_TYPES()

wxBEGIN_EVENT_TABLE(CWMSApp, wxApp)
wxEND_EVENT_TABLE()

CWMSApp::CWMSApp()
{

}


CWMSApp::~CWMSApp()
{
}

bool CWMSApp::OnInit()
{
	wxSetlocale(LC_ALL, "");
	if (!wxApp::OnInit())
	{
		return false;
	}

	m_frame = new CWMSFrame( WMS_TITLE );

	// Show the frame
	m_frame->Show(true);

	m_frame->SetStatusText ( WMS_STATUSTEXT );

	wxInitAllImageHandlers ( );

	return true;
}
