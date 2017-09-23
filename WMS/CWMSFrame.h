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
	void RecreateFrame ( );

	void DoSize ( );

	void OnLogin ( wxCommandEvent& event );

protected:
	void InitBook ( );
	void OnSize ( wxSizeEvent& event );

	void OnPageChanging ( wxTreebookEvent& event );
	void OnPageChanged ( wxTreebookEvent& event );
	void OnGoToPage ( wxCommandEvent& event );

private:
	wxPanel *m_panel;
	wxTreebook *m_book;

	wxDECLARE_EVENT_TABLE ( );
};
