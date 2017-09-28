#pragma once

class WMSConfig
{
	friend WMSConfig& getWmsConfig ( );
private:
	WMSConfig ( );

public:
	~WMSConfig ( );

	wxString getSupplierData ( );

	wxString getBigCategoryData ( const wxString &supplier );

	wxString getSmallCategoryData ( );
};

extern WMSConfig& getWmsConfig ( );

