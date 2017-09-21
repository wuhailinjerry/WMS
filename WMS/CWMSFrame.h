#pragma once

class CBaseOperateFrame;
class CWMSFrame : public wxFrame
{
public:
	CWMSFrame( const wxChar *title );
	virtual ~CWMSFrame();

	void CreateWMSMenuBar ( );
	void CreateWMSToolBar ( );
	void PopulateToolbar ( );
	void RecreateFrame ( );

	void DoSize ( );

	void OnLogin ( wxCommandEvent& event );

protected:
	void OnSize ( wxSizeEvent& event );
private:
	wxPanel *m_panel;

	eFrameType m_eFrameType;
	CBaseOperateFrame *m_opFrame;

	wxDECLARE_EVENT_TABLE ( );
};
