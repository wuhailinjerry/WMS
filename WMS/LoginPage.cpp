#include "stdafx.h"
#include "LoginPage.h"

wxBEGIN_EVENT_TABLE ( LoginPage, WidgetsPage )
EVT_BUTTON ( wxWinID_LOGIN_OPEATOR, LoginPage::OnLogin )
wxEND_EVENT_TABLE ( )

IMPLEMENT_WIDGETS_PAGE ( LoginPage, wxT ( "Login" ), LOGIN_CTRLS );

LoginPage::LoginPage ( wxTreebook *book, wxImageList *imaglist ) : WidgetsPage ( book, imaglist, login_xpm )
{
	m_userNameTxtCtrl = nullptr;
	m_passwordTxtCtrl = nullptr;

	m_nameLabel = nullptr;
	m_pwdLabel = nullptr;
	m_line = nullptr;
	m_loginButton = nullptr;
}


LoginPage::~LoginPage ( )
{
	
}

void LoginPage::RecreateWidget ( )
{

}

void LoginPage::CreateContent ( )
{
	// 一个顶层的布局控件
	auto topSizer = new wxBoxSizer ( wxVERTICAL );

	// 第二个顶层布局控件用来产生边界
	wxBoxSizer* boxSizer = new wxBoxSizer ( wxVERTICAL );
	topSizer->Add ( boxSizer, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 15 );

	// 空格
//	boxSizer->Add ( 5, frameSize.y / 4, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5 );

	// 一个水平布局控件用来放用户名
	wxBoxSizer* loginNameBox = new wxBoxSizer ( wxHORIZONTAL );
	boxSizer->Add ( loginNameBox, 0, wxALIGN_LEFT | wxALL, 15 );

	// 产生静态文本
	m_nameLabel = new wxStaticText ( this, wxID_STATIC,
		wxT ( "&用户:" ), wxDefaultPosition, wxDefaultSize, 0 );
	loginNameBox->Add ( m_nameLabel, 0, wxALIGN_LEFT | wxALL, 15 );

	// 一个用于输入用户名的文本框
	m_userNameTxtCtrl = new wxTextCtrl ( this, wxWinID_LOGIN_NAME, wxT ( "" ), wxDefaultPosition, wxDefaultSize, 0 );
	loginNameBox->Add ( m_userNameTxtCtrl, 0, wxGROW | wxALL, 15 );

	// 一个水平布局控件用来放密码
	wxBoxSizer* passWordBox = new wxBoxSizer ( wxHORIZONTAL );
	boxSizer->Add ( passWordBox, 0, wxGROW | wxALL, 15 );
	// 密码控件的标签
	m_pwdLabel = new wxStaticText ( this, wxID_STATIC,
		wxT ( "&密码:" ), wxDefaultPosition, wxDefaultSize, 0 );
	passWordBox->Add ( m_pwdLabel, 0, wxALIGN_CENTER_VERTICAL | wxALL, 15 );

	// 一个用于输入密码的文本框
	m_passwordTxtCtrl = new wxTextCtrl ( this, wxWinID_LOGIN_PWD, wxT ( "" ), wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD );
	passWordBox->Add ( m_passwordTxtCtrl, 0, wxGROW | wxALL, 15 );

	// 按钮之间的分割线
	m_line = new wxStaticLine ( this, wxID_STATIC,
		wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	boxSizer->Add ( m_line, 0, wxGROW | wxALL, 15 );
	// 用来放置按钮的水平盒子布局控件
	wxBoxSizer* okCancelBox = new wxBoxSizer ( wxHORIZONTAL );
	boxSizer->Add ( okCancelBox, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 15 );

	// login按钮
	m_loginButton = new wxButton ( this, wxWinID_LOGIN_OPEATOR, wxT ( "&LOGIN" ),
		wxDefaultPosition, wxDefaultSize, 0 );
	okCancelBox->Add ( m_loginButton, 0, wxALIGN_CENTER_VERTICAL | wxALL, 15 );

	SetSizer ( topSizer );
}

void LoginPage::OnLogin ( wxCommandEvent& event )
{
	
}