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
	return wxT ( "s_�Ϻ�ˮ����˾,b_����ˮ����˾,n_�Ͼ�ˮ����˾,c_����ˮ����˾,n_��ͨˮ����˾" );
}

wxString WMSConfig::getBigCategoryData ( const wxString &supplier )
{
	return wxT ( "r_��,y_��,m_��,x_Ϻ" );
}

wxString WMSConfig::getSmallCategoryData ( )
{
	return wxT ("b_����Ϻ,n_�ϼ�Ϻ,s_������" );
}
