#pragma once
#include "WidgetsPage.h"
class QueryPage :
	public WidgetsPage
{
public:
	QueryPage ( wxTreebook *book, wxImageList *imaglist );
	~QueryPage ( );

	virtual wxWindow *GetWidget ( ) const wxOVERRIDE
	{
		return nullptr;
	}

	virtual void RecreateWidget ( ) wxOVERRIDE;

	// lazy creation of the content
	virtual void CreateContent ( ) wxOVERRIDE;

private:
	wxDECLARE_EVENT_TABLE ( );
	DECLARE_WIDGETS_PAGE ( QueryPage )
};

