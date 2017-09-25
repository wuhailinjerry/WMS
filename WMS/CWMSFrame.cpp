#include "stdafx.h"
#include "CWMSFrame.h"

#include "WMSInventoryList.h"

#include "LoginPage.h"
#include "InBoundPage.h"
#include "OutBoundPage.h"
#include "QueryPage.h"

const wxChar *WidgetsCategories[eMaxPage] =
{
	wxT ( "��¼����" ),
	wxT ( "������" ),
	wxT ( "����Ա����" ),
	wxT ( "ALL" )
};

// ----------------------------------------------------------------------------
// event tables
// ----------------------------------------------------------------------------

wxBEGIN_EVENT_TABLE ( CWMSFrame, wxFrame )

EVT_MENU ( wxID_EXIT, CWMSFrame::OnExit )

EVT_TREEBOOK_PAGE_CHANGING ( wxID_ANY, CWMSFrame::OnPageChanging )

wxEND_EVENT_TABLE ( )

CWMSFrame::CWMSFrame ( const wxChar *title ) : wxFrame( nullptr, wxID_ANY, title, wxDefaultPosition, wxSize ( WMS_FRAME_POS_X, WMS_FRAME_POS_Y ) )
{
	SetIcon ( wxIcon ( WMSIcon ) );

	CreateStatusBar ( );

	CreateWMSMenuBar ( );

//	CreateWMSToolBar ( );

	m_panel = new wxPanel ( this, wxID_ANY );

	wxSizer *sizerTop = new wxBoxSizer ( wxVERTICAL );

	// we have 2 panes: book with pages demonstrating the controls in the
	// upper one and the log window with some buttons in the lower

	int style = wxBK_DEFAULT;
	// Uncomment to suppress page theme (draw in solid colour)
	//style |= wxNB_NOPAGETHEME;

	m_book = new wxTreebook ( m_panel, wxWinID_BOOKCTRL, wxDefaultPosition, wxDefaultSize, style, "Widgets" );

	InitBook ( );

	sizerTop->Add ( m_book, 1, wxGROW | (wxALL & ~(wxTOP | wxBOTTOM)), 10 );

	m_panel->SetSizer ( sizerTop );
}


CWMSFrame::~CWMSFrame ( )
{
	
}

// array of pages
WX_DEFINE_ARRAY_PTR ( WidgetsPage *, ArrayWidgetsPage );

void CWMSFrame::InitBook ( )
{
	wxImageList *imageList = new wxImageList ( ICON_SIZE, ICON_SIZE );

	wxImage img ( bookctrl_xpm );
	imageList->Add ( wxBitmap ( img.Scale ( ICON_SIZE, ICON_SIZE ) ) );

	ArrayWidgetsPage pages[eMaxPage];
	wxArrayString labels[eMaxPage];

	wxMenu *menuPages = new wxMenu;
	unsigned int nPage = 0, nFKey = 0;
	int cat, imageId = 1;

	// we need to first create all pages and only then add them to the book
	// as we need the image list first
	//
	// we also construct the pages menu during this first iteration
	for ( cat = 0; cat < eMaxPage; cat++ )
	{
		nPage++; // increase for parent page

		for ( WidgetsPageInfo *info = WidgetsPage::ms_widgetPages; info; info = info->GetNext ( ) )
		{
			if ( (info->GetCategories ( ) & (1 << cat)) == 0 )
				continue;

			WidgetsPage *page = (*info->GetCtor ( ))( m_book, imageList);

			pages[cat].Add ( page );

			labels[cat].Add ( info->GetLabel ( ) );
			if ( cat == eAllPage )
			{
				wxString radioLabel ( info->GetLabel ( ) );
				nFKey++;
				if ( nFKey <= 12 )
				{
					radioLabel << wxT ( "\tF" ) << nFKey;
				}
			}

			// consider only for treebook architecture (with subpages)
			nPage++;
		}
	}

	m_book->AssignImageList ( imageList );

	for ( cat = 0; cat < eMaxPage; cat++ )
	{
		m_book->AddPage ( nullptr, WidgetsCategories[cat], false, 0 );


		// now do add them
		size_t count = pages[cat].GetCount ( );
		for ( size_t n = 0; n < count; n++ )
		{
			m_book->AddSubPage
			(
				pages[cat][n],
				labels[cat][n],
				false, // don't select
				imageId++
			);
		}
	}

	Connect ( wxID_ANY, wxEVT_TREEBOOK_PAGE_CHANGED, wxTreebookEventHandler ( CWMSFrame::OnPageChanged ) );

	m_book->SetSelection ( 1 );

	// but ensure that the top of the tree is shown nevertheless
	wxTreeCtrl * const tree = m_book->GetTreeCtrl ( );

	wxTreeItemIdValue cookie;
	tree->EnsureVisible ( tree->GetFirstChild ( tree->GetRootItem ( ), cookie ) );
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
		Tool_find,
		Tool_help,
		Tool_Max
	};

	wxBitmap toolBarBitmaps[Tool_Max];

#define INIT_TOOL_BMP(bmp) \
        toolBarBitmaps[Tool_##bmp] = wxBitmap(bmp##_xpm)

	INIT_TOOL_BMP ( inbound );
	INIT_TOOL_BMP ( outbound );
	INIT_TOOL_BMP ( stocktaking );
	INIT_TOOL_BMP ( find );
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

	toolBar->AddTool ( wxID_INVENTORYQUERY, wxT ( "��ѯ" ), toolBarBitmaps[Tool_find], 
		wxT ( "��ѯ�����Ϣ" ), wxITEM_NORMAL );
	
	// add a stretchable space before the "Help" button to make it
	// right-aligned
	toolBar->AddStretchableSpace ( );
	toolBar->AddTool ( wxID_HELP, wxT ( "Help" ), toolBarBitmaps[Tool_help], wxT ( "Help button" ), wxITEM_CHECK );

	// after adding the buttons to the toolbar, must call Realize() to reflect
	// the changes
	toolBar->Realize ( );
}

void CWMSFrame::OnExit ( wxCommandEvent& event )
{
	Close ( );
}

void CWMSFrame::OnPageChanging ( wxTreebookEvent& event )
{
	if ( !m_book->GetPage ( event.GetSelection ( ) ) )
	{
		event.Veto ( );
	}
}

void CWMSFrame::OnPageChanged ( wxTreebookEvent& event )
{
	const int sel = event.GetSelection ( );

	// adjust "Page" menu selection
	wxMenuItem *item = GetMenuBar ( )->FindItem ( Widgets_GoToPage + sel );
	if ( item )
	{
		item->Check ( );
	}

	// create the pages on demand, otherwise the sample startup is too slow as
	// it creates hundreds of controls
	WidgetsPage *curPage = CurrentPage ( );
	if ( curPage->GetChildren ( ).empty ( ) )
	{
		wxWindowUpdateLocker noUpdates ( curPage );
		curPage->CreateContent ( );
		//curPage->Layout();
		curPage->GetSizer ( )->Fit ( curPage );

		wxTreebook *book = wxStaticCast ( curPage->GetParent ( ), wxTreebook );
		wxSize size;
		for ( size_t i = 0; i < book->GetPageCount ( ); ++i )
		{
			wxWindow *page = book->GetPage ( i );
			if ( page )
			{
				size.IncTo ( page->GetSize ( ) );
			}
		}
		curPage->SetSize ( size );
	}
	// re-apply the attributes to the widget(s)
	curPage->SetUpWidget ( );

	event.Skip ( );
}

void CWMSFrame::OnGoToPage ( wxCommandEvent& event )
{
	m_book->SetSelection ( event.GetId ( ) - Widgets_GoToPage );
}

WidgetsPage * CWMSFrame::CurrentPage ( )
{
	wxWindow *page = m_book->GetCurrentPage ( );

	return wxStaticCast ( page, WidgetsPage );
}
