#include "stdafx.h"
#include "CWMSFrame.h"

#include "WMSDefine.h"

#include "Resource/WMS.xpm"

#include "Resource/inbound.xpm"
#include "Resource/outbound.xpm"
#include "Resource/stocktaking.xpm"
#include "Resource/help.xpm"

// ----------------------------------------------------------------------------
// event tables
// ----------------------------------------------------------------------------

wxBEGIN_EVENT_TABLE ( CWMSFrame, wxFrame )
wxEND_EVENT_TABLE ( )

CWMSFrame::CWMSFrame ( const wxChar *title ) : wxFrame( nullptr, wxID_ANY, title, wxDefaultPosition, wxSize ( WMS_FRAME_POS_X, WMS_FRAME_POS_Y ) )
{
	SetIcon ( wxIcon ( WMSIcon ) );

	CreateStatusBar ( );

	CreateWMSMenuBar ( );

	CreateWMSToolBar ( );
}


CWMSFrame::~CWMSFrame ( )
{

}

void CWMSFrame::CreateWMSMenuBar ( )
{
	wxMenuBar *menuBar = new wxMenuBar;

	// 1.����
	wxMenu *mgrMenu = new wxMenu ( );
	mgrMenu->Append ( wxID_LOGIN, wxT ( "&��¼" ), wxT ( "��¼����ϵͳ" ) );
	mgrMenu->Append ( wxID_LOGOUT, wxT ( "&ע��" ), wxT ( "ע�����ε�¼" ) );
	mgrMenu->Append ( wxID_EXIT, wxT ( "&�˳�\tAlt-X" ), wxT ( "�˳������" ) );
	menuBar->Append ( mgrMenu, wxT ( "&����" ) );

	// 2.�ֿ����
	wxMenu *operatorMenu = new wxMenu ( );
	operatorMenu->Append ( wxID_INBOUND, wxT ( "&���\tAlt-R" ), wxT ( "��Ʒ���" ) );
	operatorMenu->Append ( wxID_OUTBOUND, wxT ( "&����\tAlt-C" ), wxT ( "��Ʒ����" ) );
	operatorMenu->Append ( wxID_STOCKTAKING, wxT ( "&�̵�\tAlt-P" ), wxT ( "��Ʒ�̵�" ) );
	menuBar->Append ( operatorMenu, wxT ( "�ֿ����" ) );

	// 3.����Ա����
	wxMenu *adminMenu = new wxMenu ( );
	adminMenu->Append ( wxID_INVENTORYQUERY, wxT ( "&��ѯ\tAlt-Q" ), wxT ( "��ѯ�����Ϣ" ) );
	adminMenu->AppendSeparator ( );

	wxMenu *userAccountMenu = new wxMenu ( );
	userAccountMenu->Append ( wxID_CREATEUSER, wxT ( "&����" ), wxT ( "�������û�" ) );
	userAccountMenu->Append ( wxID_EDITUSER, wxT ( "&�༭" ), wxT ( "�༭�û�" ) );
	userAccountMenu->Append ( wxID_DELETEUSER, wxT ( "&ɾ��" ), wxT ( "ɾ���û�" ) );
	adminMenu->AppendSubMenu ( userAccountMenu, wxT ( "�û�" ), wxT ( "�༭�û���Ϣ" ) );
	adminMenu->AppendSeparator ( );

	wxMenu *goodsMenu = new wxMenu ( );
	goodsMenu->Append ( wxID_CREATEGOODS, wxT ( "&����" ), wxT ( "������Ʒ" ) );
	goodsMenu->Append ( wxID_EDITGOODS, wxT ( "&�༭" ), wxT ( "�༭��Ʒ" ) );
	goodsMenu->Append ( wxID_DELETEGOODS, wxT ( "&ɾ��" ), wxT ( "ɾ����Ʒ" ) );
	adminMenu->AppendSubMenu ( goodsMenu, wxT ( "��Ʒ" ), wxT ( "�༭��Ʒ��Ϣ" ) );
	adminMenu->AppendSeparator ( );

	menuBar->Append ( adminMenu, wxT ( "����Ա����" ) );

	// 4.help

	SetMenuBar ( menuBar );
}

void CWMSFrame::CreateWMSToolBar ( )
{
	long style = wxTB_FLAT | wxTB_DOCKABLE | wxTB_TEXT | wxTB_VERTICAL | wxTB_LEFT;

	auto toolBar = CreateToolBar ( style, wxWinID_TOOLBAR );

	PopulateToolbar ( );
}

void CWMSFrame::PopulateToolbar ( )
{
	auto *toolBar = GetToolBar ( );

	// Set up toolbar
	enum
	{
		Tool_inbound,
		Tool_outbound,
		Tool_stocktaking,
		Tool_copy,
		Tool_cut,
		Tool_paste,
		Tool_print,
		Tool_help,
		Tool_Max
	};

	wxBitmap toolBarBitmaps[Tool_Max];

#define INIT_TOOL_BMP(bmp) \
        toolBarBitmaps[Tool_##bmp] = wxBitmap(bmp##_xpm)

	INIT_TOOL_BMP ( inbound );
	INIT_TOOL_BMP ( outbound );
	INIT_TOOL_BMP ( stocktaking );
	INIT_TOOL_BMP ( copy );
	INIT_TOOL_BMP ( cut );
	INIT_TOOL_BMP ( paste );
	INIT_TOOL_BMP ( print );
	INIT_TOOL_BMP ( help );

	int w = toolBarBitmaps[Tool_inbound].GetWidth ( ),
		h = toolBarBitmaps[Tool_inbound].GetHeight ( );

	// this call is actually unnecessary as the toolbar will adjust its tools
	// size to fit the biggest icon used anyhow but it doesn't hurt neither
	toolBar->SetToolBitmapSize ( wxSize ( w, h ) );

	toolBar->AddTool ( wxID_INBOUND, wxT ( "���" ),
		toolBarBitmaps[Tool_inbound], wxNullBitmap, wxITEM_NORMAL,
		wxT ( "��Ʒ���" ) );

	toolBar->AddTool ( wxID_OUTBOUND, wxT ( "����" ),
		toolBarBitmaps[Tool_outbound], wxNullBitmap, wxITEM_NORMAL,
		wxT ( "��Ʒ����" ) );

	toolBar->AddTool ( wxID_STOCKTAKING, wxT ( "�̵�" ), 
		toolBarBitmaps[Tool_stocktaking], wxNullBitmap, wxITEM_NORMAL,
		wxT ( "�̵������Ϣ" ) );

	toolBar->AddSeparator ( );

	toolBar->AddTool ( wxID_INVENTORYQUERY, wxT ( "��ѯ" ), toolBarBitmaps[Tool_copy], 
		wxT ( "��ѯ�����Ϣ" ), wxITEM_NORMAL );
	
	// add a stretchable space before the "Help" button to make it
	// right-aligned
	toolBar->AddStretchableSpace ( );
	toolBar->AddTool ( wxID_HELP, wxT ( "Help" ), toolBarBitmaps[Tool_help], wxT ( "Help button" ), wxITEM_CHECK );

	// after adding the buttons to the toolbar, must call Realize() to reflect
	// the changes
	toolBar->Realize ( );
}
