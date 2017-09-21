#pragma once
#include "CBaseOperateFrame.h"
class CLoginFrame : public CBaseOperateFrame
{
public:
	CLoginFrame ( wxPanel *panel, wxFrame *frame );
	~CLoginFrame ( );

	virtual void DoSize ( wxSize size );

	void OnLogin ( wxCommandEvent& event );

private:
	wxTextCtrl *m_userNameTxtCtrl;
	wxTextCtrl *m_passwordTxtCtrl;
};