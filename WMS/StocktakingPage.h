#pragma once
#include "WidgetsPage.h"
class StocktakingPage : public WidgetsPage
{
public:
	StocktakingPage ( wxTreebook *book, wxImageList *imaglist );
	~StocktakingPage ( );

	virtual wxWindow *GetWidget ( ) const wxOVERRIDE
	{
		return m_StocktakingButton;
	}

	virtual void RecreateWidget ( ) wxOVERRIDE;

	// lazy creation of the content
	virtual void CreateContent ( ) wxOVERRIDE;

private:
	wxButton *m_StocktakingButton;
	wxGrid *m_StocktakingGrid;

private:
	wxDECLARE_EVENT_TABLE ( );
	DECLARE_WIDGETS_PAGE ( StocktakingPage )
};

