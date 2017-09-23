#include "stdafx.h"
#include "WMSInventoryList.h"


WMSInventoryList::WMSInventoryList ( wxWindow *parent,
	const wxWindowID id,
	const wxPoint& pos,
	const wxSize& size,
	long style )
	: wxListCtrl ( parent, id, pos, size, style )
{
	InitList ( );
}


WMSInventoryList::~WMSInventoryList ( )
{

}

void WMSInventoryList::InitList ( )
{
	// note that under MSW for SetColumnWidth() to work we need to create the
	// items with images initially even if we specify dummy image id

	const static wxString itemArray[] =
	{
		wxT ( "物品编号" ),
		wxT ( "供应商" ),
		wxT ( "物品大类" ),
		wxT ( "物品小类" ),
		wxT ( "物品名字" ),
		wxT ( "计量单位" ),
		wxT ( "库存量" ),
		wxT ( "入库时间" ),
		wxT ( "失效日期" ),
	};

	for ( size_t i = 0; i < ARRAYSIZE ( itemArray ); i++ )
	{
		wxListItem itemCol;
		itemCol.SetText ( itemArray[i] );
		itemCol.SetAlign ( wxLIST_FORMAT_CENTRE );
		InsertColumn ( i, itemCol );
	}

#if 0
	// to speed up inserting we hide the control temporarily
	Hide ( );

//	wxStopWatch sw;

	for ( int i = 0; i < 10; i++ )
	{
		InsertItemInReportView ( i );
	}

	Show ( );

	// we leave all mask fields to 0 and only change the colour
	wxListItem item;
	item.m_itemId = 0;
	item.SetTextColour ( *wxRED );
	SetItem ( item );

	item.m_itemId = 2;
	item.SetTextColour ( *wxGREEN );
	SetItem ( item );
	item.m_itemId = 4;
	item.SetTextColour ( *wxLIGHT_GREY );
	item.SetFont ( *wxITALIC_FONT );
	item.SetBackgroundColour ( *wxRED );
	SetItem ( item );

	SetTextColour ( *wxBLUE );

	// Set images in columns
	SetItemColumnImage ( 1, 1, 0 );

	wxListItem info;
	info.SetImage ( 0 );
	info.SetId ( 3 );
	info.SetColumn ( 2 );
	SetItem ( info );

	// test SetItemFont too
	SetItemFont ( 0, *wxITALIC_FONT );

	SetColumnWidth ( 0, wxLIST_AUTOSIZE );
	SetColumnWidth ( 1, wxLIST_AUTOSIZE );
	SetColumnWidth ( 2, wxLIST_AUTOSIZE_USEHEADER );
#endif
}

void WMSInventoryList::DoSize ( wxSize size  )
{
	SetSize ( 0, 0, size.x - 5, size.y - 5 );
}

void WMSInventoryList::InsertItemInReportView ( int i )
{
	wxString buf;
	buf.Printf ( wxT ( "This is item %d" ), i );
	long tmp = InsertItem ( i, buf, 0 );
	SetItemData ( tmp, i );

	buf.Printf ( wxT ( "Col 1, item %d" ), i );
	SetItem ( tmp, 1, buf );

	buf.Printf ( wxT ( "Item %d in column 2" ), i );
	SetItem ( tmp, 2, buf );
}
