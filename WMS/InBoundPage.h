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
		return m_InBoundButton;
	}

	virtual void RecreateWidget ( ) wxOVERRIDE;

	// lazy creation of the content
	virtual void CreateContent ( ) wxOVERRIDE;

private:
	wxButton *m_InBoundButton;
	wxGrid *m_InventoryGrid;

private:
	wxDECLARE_EVENT_TABLE ( );
	DECLARE_WIDGETS_PAGE ( InBoundPage )
};