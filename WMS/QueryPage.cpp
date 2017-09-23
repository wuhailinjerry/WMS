#include "stdafx.h"
#include "QueryPage.h"

wxBEGIN_EVENT_TABLE ( QueryPage, WidgetsPage )
wxEND_EVENT_TABLE ( )

IMPLEMENT_WIDGETS_PAGE ( QueryPage, wxT ( "≤È—Ø" ), ADMIN_CTRLS );

QueryPage::QueryPage ( wxTreebook *book, wxImageList *imaglist ) : WidgetsPage ( book, imaglist, find_xpm )
{
}


QueryPage::~QueryPage ( )
{
}

/*
void QueryPage::DoSize ( wxSize size )
{

}
*/

void QueryPage::RecreateWidget ( )
{

}

void QueryPage::CreateContent ( )
{

}
