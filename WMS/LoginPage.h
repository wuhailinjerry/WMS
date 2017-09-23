#pragma once
#include "WidgetsPage.h"
class LoginPage : public WidgetsPage
{
public:
	LoginPage ( wxTreebook *book, wxImageList *imaglist );
	~LoginPage ( );

	virtual wxWindow *GetWidget ( ) const wxOVERRIDE
	{
		return m_loginButton;
	}

	virtual void RecreateWidget ( ) wxOVERRIDE;

	// lazy creation of the content
	virtual void CreateContent ( ) wxOVERRIDE;

protected:
	void OnLogin ( wxCommandEvent& event );

private:
	wxTextCtrl *m_userNameTxtCtrl;
	wxTextCtrl *m_passwordTxtCtrl;

	wxStaticText *m_nameLabel;
	wxStaticText *m_pwdLabel;
	wxStaticLine *m_line;
	wxButton *m_loginButton;

private:
	wxDECLARE_EVENT_TABLE ( );
	DECLARE_WIDGETS_PAGE ( LoginPage )
};