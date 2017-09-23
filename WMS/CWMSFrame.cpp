#include "stdafx.h"
#include "CWMSFrame.h"

#include "WMSInventoryList.h"

#include "LoginPage.h"
#include "InBoundPage.h"
#include "OutBoundPage.h"
#include "QueryPage.h"

const wxChar *WidgetsCategories[eMaxPage] =
{
	wxT ( "登录操作" ),
	wxT ( "库存操作" ),
	wxT ( "管理员操作" ),
	wxT ( "ALL" )
};

// ----------------------------------------------------------------------------
// event tables
// ----------------------------------------------------------------------------

wxBEGIN_EVENT_TABLE ( CWMSFrame, wxFrame )
EVT_SIZE ( CWMSFrame::OnSize )
EVT_BUTTON ( wxWinID_LOGIN_OPEATOR, CWMSFrame::OnLogin )
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
//	sizerTop->Add ( 0, 5, 0, wxGROW ); // spacer in between

	m_panel->SetSizer ( sizerTop );

//	RecreateFrame ( );
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

				menuPages->AppendRadioItem ( Widgets_GoToPage + nPage, radioLabel );
			}

			// consider only for treebook architecture (with subpages)
			nPage++;
		}
	}

	GetMenuBar ( )->Append ( menuPages, wxT ( "&Page" ) );

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

	/*const bool pageSet = wxPersistentRegisterAndRestore ( m_book );

	// for treebook page #0 is empty parent page only so select the first page
	// with some contents
	if ( !pageSet )
	{
		m_book->SetSelection ( 1 );
	}
*/

	// but ensure that the top of the tree is shown nevertheless
	wxTreeCtrl * const tree = m_book->GetTreeCtrl ( );

	wxTreeItemIdValue cookie;
	tree->EnsureVisible ( tree->GetFirstChild ( tree->GetRootItem ( ), cookie ) );
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

	toolBar->AddTool ( wxID_INVENTORYQUERY, wxT ( "查询" ), toolBarBitmaps[Tool_find], 
		wxT ( "查询库存信息" ), wxITEM_NORMAL );
	
	// add a stretchable space before the "Help" button to make it
	// right-aligned
	toolBar->AddStretchableSpace ( );
	toolBar->AddTool ( wxID_HELP, wxT ( "Help" ), toolBarBitmaps[Tool_help], wxT ( "Help button" ), wxITEM_CHECK );

	// after adding the buttons to the toolbar, must call Realize() to reflect
	// the changes
	toolBar->Realize ( );
}

void CWMSFrame::RecreateFrame ( )
{
	// wxLC_REPORT | wxLC_SINGLE_SEL
	/*if ( nullptr != m_opFrame )
	{
		delete m_opFrame;
	}

	switch ( m_eFrameType )
	{
		case eLoginPage:
		{
			m_opFrame = new CLoginPage ( m_panel, this );
		}
		break;

		case eInBoundPage:
		{
			m_opFrame = new CInBoundPage ( m_panel, this );
		}
		break;

		case eOutBoundPage:
		{
			m_opFrame = new COutBoundPage ( m_panel, this );
		}
		break;

		case eQueryPage:
		{
			m_opFrame = new CQueryPage ( m_panel, this );
		}
		break;

		default:
		{
			return;
		}
		break;
	}

	m_opFrame->CreateContent ( );
	DoSize ( );*/
}

void CWMSFrame::DoSize ( )
{
	/*if ( nullptr == m_opFrame )
	{
		return;
	}

	m_opFrame->DoSize ( GetClientSize ( ) );*/
}

void CWMSFrame::OnLogin ( wxCommandEvent& event )
{
	/*CLoginPage *pFrame = static_cast< CLoginPage * >(m_opFrame);
	
	if ( pFrame->OnLogin ( event ) )
	{
	//	m_eFrameType = eInBoundFrame;
		RecreateFrame ( );
	}*/
}

void CWMSFrame::OnSize ( wxSizeEvent& event )
{
	DoSize ( );
	event.Skip ( );
}

void CWMSFrame::OnPageChanging ( wxTreebookEvent& event )
{

}

void CWMSFrame::OnPageChanged ( wxTreebookEvent& event )
{

}

void CWMSFrame::OnGoToPage ( wxCommandEvent& event )
{

}
