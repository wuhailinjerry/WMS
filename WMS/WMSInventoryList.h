#pragma once

class WMSInventoryList : public wxListCtrl
{
public:
	WMSInventoryList ( wxWindow *parent,
		const wxWindowID id,
		const wxPoint& pos,
		const wxSize& size,
		long style );

	virtual ~WMSInventoryList ( );

	void InitList ( );

	void DoSize ( wxSize size );

	void InsertItemInReportView ( int i );
};

