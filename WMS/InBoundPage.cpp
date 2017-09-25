#include "stdafx.h"
#include "InBoundPage.h"

#include "InventoryGrid.h"

wxBEGIN_EVENT_TABLE ( InBoundPage, WidgetsPage )
wxEND_EVENT_TABLE ( )

IMPLEMENT_WIDGETS_PAGE ( InBoundPage, wxT ( "入库" ), NORMAL_CTRLS );

InBoundPage::InBoundPage ( wxTreebook *book, wxImageList *imaglist ) : WidgetsPage ( book, imaglist, inbound_xpm )
{
	m_InventoryGrid = nullptr;
	m_InBoundButton = nullptr;
}

InBoundPage::~InBoundPage ( )
{

}

void InBoundPage::RecreateWidget ( )
{

}

void InBoundPage::CreateContent ( )
{
	// 一个顶层的布局控件
	wxBoxSizer* topSizer = new wxBoxSizer ( wxHORIZONTAL );

	m_InventoryGrid = new wxGrid ( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	wxGridTableBase *m_table = new InventoryGrid();

	m_InventoryGrid->SetTable ( m_table, true, wxGrid::wxGridSelectRows );

	m_InventoryGrid->EnableDragColMove ( );
	m_InventoryGrid->UseNativeColHeader ( );
	m_InventoryGrid->HideRowLabels ( );
	m_InventoryGrid->SetRowLabelSize ( wxGRID_AUTOSIZE );

	topSizer->Add ( m_InventoryGrid, 1, wxEXPAND );

	// 用来放置按钮的水平盒子布局控件
	wxBoxSizer* okCancelBox = new wxBoxSizer ( wxVERTICAL );
	topSizer->Add ( okCancelBox, 0, wxEXPAND );

	// login按钮
	m_InBoundButton = new wxButton ( this, wxWinID_LOGIN_OPEATOR, wxT ( "&入库" ),
		wxDefaultPosition, wxDefaultSize, 0 );
	okCancelBox->Add ( m_InBoundButton, 0, wxGROW );

	SetSizerAndFit ( topSizer );
}

