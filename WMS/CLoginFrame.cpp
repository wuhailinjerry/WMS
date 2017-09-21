#include "stdafx.h"
#include "CLoginFrame.h"

CLoginFrame::CLoginFrame ( wxPanel *panel, wxFrame *frame ) : CBaseOperateFrame ( panel, frame )
{
	auto frameSize = frame->GetClientSize ( );

	// һ������Ĳ��ֿؼ�
	wxBoxSizer* topSizer = new wxBoxSizer ( wxVERTICAL );
	m_frame->SetSizer ( topSizer );

	// �ڶ������㲼�ֿؼ����������߽�
	wxBoxSizer* boxSizer = new wxBoxSizer ( wxVERTICAL );
	topSizer->Add ( boxSizer, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5 );

	// �ո�
	boxSizer->Add ( 5, frameSize.y / 4, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5 );

	// һ��ˮƽ���ֿؼ��������û���
	wxBoxSizer* loginNameBox = new wxBoxSizer ( wxHORIZONTAL );
	boxSizer->Add ( loginNameBox, 0, wxALIGN_LEFT | wxALL, 5 );

	// ������̬�ı�
	wxStaticText* nameLabel = new wxStaticText ( m_frame, wxID_STATIC,
		wxT ( "&�û�:" ), wxDefaultPosition, wxDefaultSize, 0 );
	loginNameBox->Add ( nameLabel, 0, wxALIGN_LEFT | wxALL, 5 );

	// һ�����������û������ı���
	m_userNameTxtCtrl = new wxTextCtrl ( m_frame, wxWinID_LOGIN_NAME, wxT(""), wxDefaultPosition, wxDefaultSize, 0 );
	loginNameBox->Add ( m_userNameTxtCtrl, 0, wxGROW | wxALL, 5 );

	// һ��ˮƽ���ֿؼ�����������
	wxBoxSizer* passWordBox = new wxBoxSizer ( wxHORIZONTAL );
	boxSizer->Add ( passWordBox, 0, wxGROW | wxALL, 5 );
	// ����ؼ��ı�ǩ
	wxStaticText* pwdLabel = new wxStaticText ( m_frame, wxID_STATIC,
		wxT ( "&����:" ), wxDefaultPosition, wxDefaultSize, 0 );
	passWordBox->Add ( pwdLabel, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5 );

	// һ����������������ı���
	m_passwordTxtCtrl = new wxTextCtrl ( m_frame, wxWinID_LOGIN_PWD, wxT ( "" ), wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD );
	passWordBox->Add ( m_passwordTxtCtrl, 0, wxGROW | wxALL, 5 );
	
	// ��ť֮��ķָ���
	wxStaticLine* line = new wxStaticLine ( m_frame, wxID_STATIC,
		wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	boxSizer->Add ( line, 0, wxGROW | wxALL, 5 );
	// �������ð�ť��ˮƽ���Ӳ��ֿؼ�
	wxBoxSizer* okCancelBox = new wxBoxSizer ( wxHORIZONTAL );
	boxSizer->Add ( okCancelBox, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5 );
	
	// login��ť
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
