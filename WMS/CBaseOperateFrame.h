#pragma once
class CBaseOperateFrame
{
public:
	CBaseOperateFrame ( wxPanel *panel, wxFrame *frame );
	virtual ~CBaseOperateFrame ( );

	virtual void DoSize ( wxSize size ) = 0;
protected:
	wxPanel *m_panel;
	wxFrame *m_frame;
};

