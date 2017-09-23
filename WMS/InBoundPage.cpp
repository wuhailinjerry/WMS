#include "stdafx.h"
#include "InBoundPage.h"

#include "WMSInventoryList.h"

wxBEGIN_EVENT_TABLE ( InBoundPage, WidgetsPage )
wxEND_EVENT_TABLE ( )

IMPLEMENT_WIDGETS_PAGE ( InBoundPage, wxT ( "入库" ), NORMAL_CTRLS );

InBoundPage::InBoundPage ( wxTreebook *book, wxImageList *imaglist ) : WidgetsPage ( book, imaglist, inbound_xpm )
{
	// 一个顶层的布局控件
	/*wxBoxSizer* topSizer = new wxBoxSizer ( wxVERTICAL );
	m_panel->SetSizer ( topSizer );

	m_InventoryCtrl = new CWMSInventoryList ( m_panel, wxWinID_LISTINVENTORY,
		wxDefaultPosition, wxDefaultSize,
		wxLC_REPORT | wxLC_SINGLE_SEL | wxBORDER_THEME | wxLC_EDIT_LABELS );

	topSizer->Add ( m_InventoryCtrl );
	m_InventoryCtrl->InitList ( );*/
}

InBoundPage::~InBoundPage ( )
{

}

/*
void InBoundPage::DoSize ( wxSize size )
{
	m_InventoryCtrl->DoSize ( size );
}*/

void InBoundPage::RecreateWidget ( )
{

}

void InBoundPage::CreateContent ( )
{
	
}

