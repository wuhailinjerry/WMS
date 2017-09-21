#include "stdafx.h"
#include "CInBoundFrame.h"

#include "CWMSInventoryList.h"

CInBoundFrame::CInBoundFrame ( wxPanel *panel, wxFrame *frame ) : CBaseOperateFrame ( panel, frame )
{
	m_InventoryCtrl = new CWMSInventoryList ( m_panel, wxWinID_LISTINVENTORY,
		wxDefaultPosition, wxDefaultSize,
		wxLC_REPORT | wxLC_SINGLE_SEL | wxBORDER_THEME | wxLC_EDIT_LABELS );

	m_InventoryCtrl->InitList ( );
}

CInBoundFrame::~CInBoundFrame ( )
{

}

void CInBoundFrame::DoSize ( wxSize size )
{

}

