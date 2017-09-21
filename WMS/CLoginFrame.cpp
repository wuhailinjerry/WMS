#include "stdafx.h"
#include "CLoginFrame.h"

CLoginFrame::CLoginFrame ( wxPanel *panel, wxFrame *frame ) : CBaseOperateFrame ( panel, frame )
{
	auto frameSize = frame->GetClientSize ( );

	// 一个顶层的布局控件
	wxBoxSizer* topSizer = new wxBoxSizer ( wxVERTICAL );
	m_frame->SetSizer ( topSizer );

	// 第二个顶层布局控件用来产生边界
	wxBoxSizer* boxSizer = new wxBoxSizer ( wxVERTICAL );
	topSizer->Add ( boxSizer, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5 );

	// 空格
	boxSizer->Add ( 5, frameSize.y / 4, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5 );

	// 一个水平布局控件用来放用户名
	wxBoxSizer* loginNameBox = new wxBoxSizer ( wxHORIZONTAL );
	boxSizer->Add ( loginNameBox, 0, wxALIGN_LEFT | wxALL, 5 );

	// 产生静态文本
	wxStaticText* nameLabel = new wxStaticText ( m_frame, wxID_STATIC,
		wxT ( "&用户:" ), wxDefaultPosition, wxDefaultSize, 0 );
	loginNameBox->Add ( nameLabel, 0, wxALIGN_LEFT | wxALL, 5 );

	// 一个用于输入用户名的文本框
	m_userNameTxtCtrl = new wxTextCtrl ( m_frame, wxWinID_LOGIN_NAME, wxT(""), wxDefaultPosition, wxDefaultSize, 0 );
	loginNameBox->Add ( m_userNameTxtCtrl, 0, wxGROW | wxALL, 5 );

	// 一个水平布局控件用来放密码
	wxBoxSizer* passWordBox = new wxBoxSizer ( wxHORIZONTAL );
	boxSizer->Add ( passWordBox, 0, wxGROW | wxALL, 5 );
	// 密码控件的标签
	wxStaticText* pwdLabel = new wxStaticText ( m_frame, wxID_STATIC,
		wxT ( "&密码:" ), wxDefaultPosition, wxDefaultSize, 0 );
	passWordBox->Add ( pwdLabel, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5 );

	// 一个用于输入密码的文本框
	m_passwordTxtCtrl = new wxTextCtrl ( m_frame, wxWinID_LOGIN_PWD, wxT ( "" ), wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD );
	passWordBox->Add ( m_passwordTxtCtrl, 0, wxGROW | wxALL, 5 );
	
	// 按钮之间的分割线
	wxStaticLine* line = new wxStaticLine ( m_frame, wxID_STATIC,
		wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	boxSizer->Add ( line, 0, wxGROW | wxALL, 5 );
	// 用来放置按钮的水平盒子布局控件
	wxBoxSizer* okCancelBox = new wxBoxSizer ( wxHORIZONTAL );
	boxSizer->Add ( okCancelBox, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5 );
	
	// login按钮
	wxButton* loginButton = new wxButton ( m_frame, wxWinID_LOGIN_OPEATOR, wxT ( "&LOGIN" ),
		wxDefaultPosition, wxDefaultSize, 0 );
	okCancelBox->Add ( loginButton, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5 );
}


CLoginFrame::~CLoginFrame ( )
{
}

void CLoginFrame::DoSize ( wxSize size )
{
	
}

void CLoginFrame::OnLogin ( wxCommandEvent& event )
{
	wxMessageDialog * dial = new wxMessageDialog ( NULL, m_passwordTxtCtrl->GetValue(), m_userNameTxtCtrl->GetValue(), wxOK );
	dial->ShowModal ( );

//	delete dial;
}
