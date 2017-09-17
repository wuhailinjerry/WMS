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

	// 1.管理
	wxMenu *mgrMenu = new wxMenu ( );
	mgrMenu->Append ( wxID_LOGIN, wxT ( "&登录" ), wxT ( "登录管理系统" ) );
	mgrMenu->Append ( wxID_LOGOUT, wxT ( "&注销" ), wxT ( "注销本次登录" ) );
	mgrMenu->Append ( wxID_EXIT, wxT ( "&退出\tAlt-X" ), wxT ( "退出该软件" ) );
	menuBar->Append ( mgrMenu, wxT ( "&管理" ) );

	// 2.仓库操作
	wxMenu *operatorMenu = new wxMenu ( );
	operatorMenu->Append ( wxID_INBOUND, wxT ( "&入库\tAlt-R" ), wxT ( "物品入库" ) );
	operatorMenu->Append ( wxID_OUTBOUND, wxT ( "&出库\tAlt-C" ), wxT ( "物品出库" ) );
	operatorMenu->Append ( wxID_STOCKTAKING, wxT ( "&盘点\tAlt-P" ), wxT ( "物品盘点" ) );
	menuBar->Append ( operatorMenu, wxT ( "仓库操作" ) );

	// 3.管理员操作
	wxMenu *adminMenu = new wxMenu ( );
	adminMenu->Append ( wxID_INVENTORYQUERY, wxT ( "&查询\tAlt-Q" ), wxT ( "查询库存信息" ) );
	adminMenu->AppendSeparator ( );

	wxMenu *userAccountMenu = new wxMenu ( );
	userAccountMenu->Append ( wxID_CREATEUSER, wxT ( "&创建" ), wxT ( "创建新用户" ) );
	userAccountMenu->Append ( wxID_EDITUSER, wxT ( "&编辑" ), wxT ( "编辑用户" ) );
	userAccountMenu->Append ( wxID_DELETEUSER, wxT ( "&删除" ), wxT ( "删除用户" ) );
	adminMenu->AppendSubMenu ( userAccountMenu, wxT ( "用户" ), wxT ( "编辑用户信息" ) );
	adminMenu->AppendSeparator ( );

	wxMenu *goodsMenu = new wxMenu ( );
	goodsMenu->Append ( wxID_CREATEGOODS, wxT ( "&创建" ), wxT ( "创建物品" ) );
	goodsMenu->Append ( wxID_EDITGOODS, wxT ( "&编辑" ), wxT ( "编辑物品" ) );
	goodsMenu->Append ( wxID_DELETEGOODS, wxT ( "&删除" ), wxT ( "删除物品" ) );
	adminMenu->AppendSubMenu ( goodsMenu, wxT ( "物品" ), wxT ( "编辑物品信息" ) );
	adminMenu->AppendSeparator ( );

	menuBar->Append ( adminMenu, wxT ( "管理员操作" ) );

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

	toolBar->AddTool ( wxID_INBOUND, wxT ( "入库" ),
		toolBarBitmaps[Tool_inbound], wxNullBitmap, wxITEM_NORMAL,
		wxT ( "物品入库" ) );

	toolBar->AddTool ( wxID_OUTBOUND, wxT ( "出库" ),
		toolBarBitmaps[Tool_outbound], wxNullBitmap, wxITEM_NORMAL,
		wxT ( "物品出库" ) );

	toolBar->AddTool ( wxID_STOCKTAKING, wxT ( "盘点" ), 
		toolBarBitmaps[Tool_stocktaking], wxNullBitmap, wxITEM_NORMAL,
		wxT ( "盘点店内信息" ) );

	toolBar->AddSeparator ( );

	toolBar->AddTool ( wxID_INVENTORYQUERY, wxT ( "查询" ), toolBarBitmaps[Tool_copy], 
		wxT ( "查询库存信息" ), wxITEM_NORMAL );
	
	// add a stretchable space before the "Help" button to make it
	// right-aligned
	toolBar->AddStretchableSpace ( );
	toolBar->AddTool ( wxID_HELP, wxT ( "Help" ), toolBarBitmaps[Tool_help], wxT ( "Help button" ), wxITEM_CHECK );

	// after adding the buttons to the toolbar, must call Realize() to reflect
	// the changes
	toolBar->Realize ( );
}
