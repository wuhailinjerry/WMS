#pragma once

#define WMS_TITLE wxT("仓库管理系统")
#define WMS_STATUSTEXT wxT("欢迎使用仓库管理系统!!!")

#define WMS_FRAME_POS_X 1280
#define WMS_FRAME_POS_Y 720

#define ICON_SIZE         16

enum wxEventID
{
	wxID_LOGIN = 0,
	wxID_LOGOUT,
	
	wxID_INBOUND,
	wxID_OUTBOUND,
	wxID_STOCKTAKING,

	wxID_INVENTORYQUERY,

	wxID_CREATEGOODS,
	wxID_EDITGOODS,
	wxID_DELETEGOODS,
	wxID_CREATEUSER,
	wxID_EDITUSER,
	wxID_DELETEUSER,

	wxWinID_BOOKCTRL = 500,
	wxWinID_TOOLBAR,
	wxWinID_LISTINVENTORY,
	wxWinID_LOGIN_NAME,
	wxWinID_LOGIN_PWD,
	wxWinID_LOGIN_OPEATOR,

	Widgets_GoToPage = 1000,
	Widgets_GoToPageLast = Widgets_GoToPage + 100,
};

enum ePageType
{
	eLOGINPage = 0,
	eNormalPage,
	eAdminPage,
	eAllPage,
	eMaxPage,
};

enum ePageCtrl
{
	LOGIN_CTRLS  = 1 << eLOGINPage,
	NORMAL_CTRLS = 1 << eNormalPage,
	ADMIN_CTRLS  = 1 << eAdminPage,
	ALL_CTRLS    = 1 << eAllPage
};