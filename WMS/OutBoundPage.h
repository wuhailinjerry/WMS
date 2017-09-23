#pragma once
#include "WidgetsPage.h"
class OutBoundPage :
	public WidgetsPage
{
public:
	OutBoundPage ( wxTreebook *book, wxImageList *imaglist );
	virtual ~OutBoundPage ( );

	virtual wxWindow *GetWidget ( ) const wxOVERRIDE
	{
		return nullptr;
	}

	virtual void RecreateWidget ( ) wxOVERRIDE;

	// lazy creation of the content
	virtual void CreateContent ( ) wxOVERRIDE;

private:
	wxDECLARE_EVENT_TABLE ( );
	DECLARE_WIDGETS_PAGE ( OutBoundPage )
};

