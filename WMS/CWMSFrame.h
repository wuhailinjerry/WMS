#pragma once

class WidgetsPage;
class CWMSFrame : public wxFrame
{
public:
	CWMSFrame( const wxChar *title );
	virtual ~CWMSFrame();

	void CreateWMSMenuBar ( );
	void CreateWMSToolBar ( );
	void PopulateToolbar ( );

protected:
	void InitBook ( );

	void OnExit ( wxCommandEvent& event );

	void OnPageChanging ( wxTreebookEvent& event );
	void OnPageChanged ( wxTreebookEvent& event );
	void OnGoToPage ( wxCommandEvent& event );

	WidgetsPage *CurrentPage ( );

private:
	wxPanel *m_panel;
	wxTreebook *m_book;

	wxDECLARE_EVENT_TABLE ( );
};
