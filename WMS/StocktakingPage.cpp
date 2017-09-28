#include "stdafx.h"
#include "StocktakingPage.h"

#include "StocktakingGrid.h"

wxBEGIN_EVENT_TABLE ( StocktakingPage, WidgetsPage )
wxEND_EVENT_TABLE ( )

IMPLEMENT_WIDGETS_PAGE ( StocktakingPage, wxT ( "�̵�" ), NORMAL_CTRLS );

StocktakingPage::StocktakingPage ( wxTreebook *book, wxImageList *imaglist ) : WidgetsPage ( book, imaglist, stocktaking_xpm )
{
	m_StocktakingButton = nullptr;
	m_StocktakingGrid = nullptr;
}


StocktakingPage::~StocktakingPage ( )
{

}

void StocktakingPage::RecreateWidget ( )
{

}

void StocktakingPage::CreateContent ( )
{
	// һ������Ĳ��ֿؼ�
	wxBoxSizer* topSizer = new wxBoxSizer ( wxHORIZONTAL );

	m_StocktakingGrid = new wxGrid ( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	wxGridTableBase *m_table = new StocktakingGrid ( );

	m_StocktakingGrid->SetTable ( m_table, true, wxGrid::wxGridSelectRows );
	m_StocktakingGrid->EnableDragColMove ( );
	m_StocktakingGrid->UseNativeColHeader ( );
	m_StocktakingGrid->HideRowLabels ( );
	m_StocktakingGrid->SetRowLabelSize ( wxGRID_AUTOSIZE );

	m_StocktakingGrid->SetColSize ( eSupplier, SUPPLIER_COLSIZE );
	m_StocktakingGrid->SetColLabelAlignment ( wxALIGN_CENTRE, wxALIGN_CENTRE );

	topSizer->Add ( m_StocktakingGrid, 1, wxEXPAND );

	// �������ð�ť��ˮƽ���Ӳ��ֿؼ�
	wxBoxSizer* okCancelBox = new wxBoxSizer ( wxVERTICAL );
	topSizer->Add ( okCancelBox, 0, wxEXPAND );

	// login��ť
	m_StocktakingButton = new wxButton ( this, wxWinID_LOGIN_OPEATOR, wxT ( "&�̵�" ),
		wxDefaultPosition, wxDefaultSize, 0 );
	okCancelBox->Add ( m_StocktakingButton, 0, wxGROW );

	SetSizerAndFit ( topSizer );
}
