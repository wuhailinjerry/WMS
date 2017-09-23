#pragma once

#include "WidgetsPage.h"

class WMSInventoryList;
class InBoundPage : public WidgetsPage
{
public:
	InBoundPage ( wxTreebook *book, wxImageList *imaglist );
	virtual ~InBoundPage ( );

	virtual wxWindow *GetWidget ( ) const wxOVERRIDE
	{
		return nullptr;
	}

	virtual void RecreateWidget ( ) wxOVERRIDE;

	// lazy creation of the content
	virtual void CreateContent ( ) wxOVERRIDE;

private:
	WMSInventoryList *m_InventoryCtrl;

private:
	wxDECLARE_EVENT_TABLE ( );
	DECLARE_WIDGETS_PAGE ( InBoundPage )
};