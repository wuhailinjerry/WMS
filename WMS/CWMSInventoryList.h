#pragma once

class CWMSInventoryList : public wxListCtrl
{
public:
	CWMSInventoryList ( wxWindow *parent,
		const wxWindowID id,
		const wxPoint& pos,
		const wxSize& size,
		long style );

	virtual ~CWMSInventoryList ( );

	void InitList ( );

	void DoSize ( wxSize size );

	void InsertItemInReportView ( int i );
};

