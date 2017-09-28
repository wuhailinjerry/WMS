#include "stdafx.h"
#include "WMSConfig.h"


WMSConfig& getWmsConfig ( )
{
	static WMSConfig config;
	return config;
}

WMSConfig::WMSConfig ( )
{
}

WMSConfig::~WMSConfig ( )
{

}

wxString WMSConfig::getSupplierData ( )
{
	return wxT ( "s_上海水产公司,b_北京水产公司,n_南京水产公司,c_常州水产公司,n_南通水产公司" );
}

wxString WMSConfig::getBigCategoryData ( const wxString &supplier )
{
	return wxT ( "r_肉,y_鱼,m_米,x_虾" );
}

wxString WMSConfig::getSmallCategoryData ( )
{
	return wxT ("b_北极虾,n_南极虾,s_三文鱼" );
}
