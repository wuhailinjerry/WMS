#pragma once

#include "CBaseOperateFrame.h"

class CWMSInventoryList;
class CInBoundFrame : public CBaseOperateFrame
{
public:
	CInBoundFrame ( wxPanel *panel, wxFrame *frame );
	virtual ~CInBoundFrame ( );

	virtual void DoSize ( wxSize size );

private:
	CWMSInventoryList *m_InventoryCtrl;
};