#include "stdafx.h"
#include "LoginPage.h"

wxBEGIN_EVENT_TABLE ( LoginPage, WidgetsPage )
EVT_BUTTON ( wxWinID_LOGIN_OPEATOR, LoginPage::OnLogin )
wxEND_EVENT_TABLE ( )

IMPLEMENT_WIDGETS_PAGE ( LoginPage, wxT ( "Login" ), LOGIN_CTRLS );

LoginPage::LoginPage ( wxTreebook *book, wxImageList *imaglist ) : WidgetsPage ( book, imaglist, login_xpm )
{
	/*auto frameSize = m_frame->GetClientSize ( );

	// һ������Ĳ��ֿؼ�
	auto topSizer = new wxBoxSizer ( wxVERTICAL );
	m_panel->SetSizer ( topSizer );

	// �ڶ������㲼�ֿؼ����������߽�
	wxBoxSizer* boxSizer = new wxBoxSizer ( wxVERTICAL );
	topSizer->Add ( boxSizer, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5 );

	// �ո�
	boxSizer->Add ( 5, frameSize.y / 4, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5 );

	// һ��ˮƽ���ֿؼ��������û���
	wxBoxSizer* loginNameBox = new wxBoxSizer ( wxHORIZONTAL );
	boxSizer->Add ( loginNameBox, 0, wxALIGN_LEFT | wxALL, 5 );

	// ������̬�ı�
	m_nameLabel = new wxStaticText ( m_panel, wxID_STATIC,
		wxT ( "&�û�:" ), wxDefaultPosition, wxDefaultSize, 0 );
	loginNameBox->Add ( m_nameLabel, 0, wxALIGN_LEFT | wxALL, 5 );

	// һ�����������û������ı���
	m_userNameTxtCtrl = new wxTextCtrl ( m_panel, wxWinID_LOGIN_NAME, wxT ( "" ), wxDefaultPosition, wxDefaultSize, 0 );
	loginNameBox->Add ( m_userNameTxtCtrl, 0, wxGROW | wxALL, 5 );

	// һ��ˮƽ���ֿؼ�����������
	wxBoxSizer* passWordBox = new wxBoxSizer ( wxHORIZONTAL );
	boxSizer->Add ( passWordBox, 0, wxGROW | wxALL, 5 );
	// ����ؼ��ı�ǩ
	m_pwdLabel = new wxStaticText ( m_panel, wxID_STATIC,
		wxT ( "&����:" ), wxDefaultPosition, wxDefaultSize, 0 );
	passWordBox->Add ( m_pwdLabel, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5 );

	// һ����������������ı���
	m_passwordTxtCtrl = new wxTextCtrl ( m_panel, wxWinID_LOGIN_PWD, wxT ( "" ), wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD );
	passWordBox->Add ( m_passwordTxtCtrl, 0, wxGROW | wxALL, 5 );

	// ��ť֮��ķָ���
	m_line = new wxStaticLine ( m_panel, wxID_STATIC,
		wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	boxSizer->Add ( m_line, 0, wxGROW | wxALL, 5 );
	// �������ð�ť��ˮƽ���Ӳ��ֿؼ�
	wxBoxSizer* okCancelBox = new wxBoxSizer ( wxHORIZONTAL );
	boxSizer->Add ( okCancelBox, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5 );

	// login��ť
	m_loginButton = new wxButton ( m_panel, wxWinID_LOGIN_OPEATOR, wxT ( "&LOGIN" ),
		wxDefaultPosition, wxDefaultSize, 0 );
	okCancelBox->Add ( m_loginButton, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5 );*/
}


LoginPage::~LoginPage ( )
{
	
}

void LoginPage::RecreateWidget ( )
{

}

void LoginPage::CreateContent ( )
{
	
}

void LoginPage::OnLogin ( wxCommandEvent& event )
{
	
}