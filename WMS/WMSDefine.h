#pragma once

#define WMS_TITLE wxT("仓库管理系统")
#define WMS_STATUSTEXT wxT("欢迎使用仓库管理系统!!!")

#define WMS_FRAME_POS_X 1280
#define WMS_FRAME_POS_Y 720

#define ICON_SIZE         16

enum wxEventID
{
	wxID_GoToPage = 0,
	wxID_LOGIN = 0,
	
	wxID_INVENTORYQUERY,

	wxID_STOCKTAKING,
	wxID_INBOUND,

	wxID_CREATEGOODS,
	wxID_EDITGOODS,
	wxID_DELETEGOODS,
	wxID_CREATEUSER,
	wxID_EDITUSER,
	wxID_DELETEUSER,
	wxID_GoToPageLast,

	wxID_LOGOUT,

	wxWinID_BOOKCTRL = 500,
	wxWinID_TOOLBAR,
	wxWinID_LISTINVENTORY,
	wxWinID_LOGIN_NAME,
	wxWinID_LOGIN_PWD,
	wxWinID_LOGIN_OPEATOR,
};

enum ePageType
{
	eLoginPage = 0,
	eNormalPage,
	eAdminPage,
	eAllPage,
	eMaxPage,
};

enum ePageCtrl
{
	LOGIN_CTRLS  = 1 << eLoginPage,
	NORMAL_CTRLS = 1 << eNormalPage,
	ADMIN_CTRLS  = 1 << eAdminPage,
	ALL_CTRLS    = 1 << eAllPage
};

enum InventoryColEnum
{
	eBeginCol = 0,
	eSupplier = 0,   // 供应商
	eBigCategory,    // 物品大类
	eSmallCategory,  // 物品小类
	eGoodsName,      // 物品名称
	eMeasurement,    // 计量单位
	eGoodsCount,     // 物品个数
	eGoodsPrice,     // 单价
	eTotalPrice,     // 总价
	eValidityPeriod, // 保质期
	eOperator,       // 操作人
	eEndCol = eOperator,
	eMaxCol,
};

#define SUPPLIER_COLSIZE 150
#define INIT_ROW_COUNT 20

struct stLabels
{
	InventoryColEnum eCol;
	wxString sLabels;

	bool operator < ( const stLabels &left ) const
	{
		return this->eCol < left.eCol;
	}
};