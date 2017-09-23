#include "stdafx.h"
#include "OutBoundPage.h"

wxBEGIN_EVENT_TABLE ( OutBoundPage, WidgetsPage )
wxEND_EVENT_TABLE ( )

IMPLEMENT_WIDGETS_PAGE ( OutBoundPage, wxT ( "³ö¿â" ), NORMAL_CTRLS );

OutBoundPage::OutBoundPage ( wxTreebook *book, wxImageList *imaglist ) : WidgetsPage ( book, imaglist, outbound_xpm )
{
}


OutBoundPage::~OutBoundPage ( )
{
}

/*
void OutBoundPage::DoSize ( wxSize size )
{

}
*/

void OutBoundPage::RecreateWidget ( )
{

}

void OutBoundPage::CreateContent ( )
{

}
