#pragma once

#define WMS_TITLE wxT("�ֿ����ϵͳ")
#define WMS_STATUSTEXT wxT("��ӭʹ�òֿ����ϵͳ!!!")

#define WMS_FRAME_POS_X 1280
#define WMS_FRAME_POS_Y 720


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


	wxWinID_TOOLBAR = 500,
};