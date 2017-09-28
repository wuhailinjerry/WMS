#include "stdafx.h"
#include "InBoundGrid.h"

#include "WMSConfig.h"

static stLabels stLabelArray[] =
{
	{ eSupplier, "��Ӧ��" },
	{ eBigCategory, "��Ʒ����" },
	{ eSmallCategory, "��ƷС��" },
	{ eGoodsName, "��Ʒ����" },
	{ eMeasurement, "������λ" },
	{ eGoodsCount, "��Ʒ����" },
	{ eGoodsPrice, "����" },
	{ eTotalPrice, "�ܼ�" },
	{ eValidityPeriod, "������" },
	{ eOperator, "������" },
};

InBoundGrid::InBoundGrid ( )
{
	std::sort ( &stLabelArray[eBeginCol], &stLabelArray[eEndCol] );
}


InBoundGrid::~InBoundGrid ( )
{
	
}

wxString InBoundGrid::GetValue ( int row, int col )
{
	auto itor = m_InventoryDataMap.find ( row );
	if ( itor == m_InventoryDataMap.end ( ) )
	{
		return wxEmptyString;
	}

	switch ( col )
	{
		case eSupplier:
		{
			return itor->second.strSupplier;
		}
		break;

		case eBigCategory:
		{
			return itor->second.strBigCategory;
		}
		break;

		case eSmallCategory:
		{
			return itor->second.strSmallCategory;
		}
		break;

		case eGoodsName:
		{
			return itor->second.strGoodsName;
		}
		break;

		case eMeasurement:
		{
			return itor->second.strMeasurement;
		}
		break;

		case eGoodsCount:
		{
			return wxString::Format ( wxT ( "%d" ), itor->second.nGoodsCount );
		}
		break;

		case eGoodsPrice:
		{
			return wxString::Format ( wxT ( "%f" ), itor->second.fGoodsPrice );
		}
		break;

		case eTotalPrice:
		{
			return wxString::Format ( wxT ( "%f" ), itor->second.fTotalPrice );
		}
		break;

		case eValidityPeriod:
		{
			return itor->second.strValidityPeriod;
		}
		break;

		case eOperator:
		{
			return "";
		}

		default:
		{
			wxFAIL_MSG ( wxT ( "unknown column" ) );
		}
		break;
	}

	return wxEmptyString;
}

void InBoundGrid::SetValue ( int row, int col, const wxString& value )
{
	stInBoundData *pData = nullptr;
	auto itor = m_InventoryDataMap.find ( row );
	if ( itor == m_InventoryDataMap.end() )
	{
		stInBoundData stData;
		pData = &stData;
		m_InventoryDataMap[row] = stData;
	}
	else
	{
		pData = &(itor->second);
	}

	switch ( col )
	{
		case eSupplier:
		{
			pData->strSupplier = value;
		}
		break;

		case eBigCategory:
		{
			pData->strBigCategory = value;
		}
		break;

		case eSmallCategory:
		{
			pData->strSmallCategory = value;
		}
		break;

		case eGoodsName:
		{
			pData->strGoodsName = value;
		}
		break;

		case eMeasurement:
		{
			pData->strMeasurement = value;
		}
		break;

		case eGoodsCount:
		{
			value.ToULong ( &pData->nGoodsCount );
		}
		break;

		case eGoodsPrice:
		{
			value.ToDouble ( &pData->fGoodsPrice );
		}
		break;

		case eTotalPrice:
		{
			value.ToDouble ( &pData->fTotalPrice );
		}
		break;

		case eValidityPeriod:
		{
			pData->strValidityPeriod = value;
		}
		break;

		default:
		{
			wxFAIL_MSG ( wxT ( "unknown column" ) );
		}
		break;
	}
}

wxString InBoundGrid::GetTypeName ( int row, int col )
{
	switch ( col )
	{
		case eSupplier:
		{
			return wxString::Format ( wxT ( "%s:%s" ), wxGRID_VALUE_CHOICE, getWmsConfig().getSupplierData().c_str() );
		}
		break;

		case eBigCategory:
		{
			wxString strVal = GetValue ( row, eSupplier );
			if ( !strVal.IsNull() )
			{
				return wxString::Format ( wxT ( "%s:%s" ), wxGRID_VALUE_CHOICE, getWmsConfig ( ).getBigCategoryData ( strVal ).c_str ( ) );
			}
		}
		break;

		case eSmallCategory:
		{

		}
		break;

		case eGoodsName:
		{

		}
		break;

		case eMeasurement:
		{

		}
		break;

		case eGoodsCount:
		{

		}
		break;

		case eGoodsPrice:
		{

		}
		break;

		case eTotalPrice:
		{

		}
		break;

		case eValidityPeriod:
		{

		}
		break;

		case eOperator:
		{

		}
		break;

		default:
		{
			wxFAIL_MSG ( wxT ( "unknown column" ) );
		}
		break;

	}

	return wxGRID_VALUE_STRING;
}


wxString InBoundGrid::GetColLabelValue ( int col )
{
	// notice that column parameter here always refers to the internal
	// column index, independently of its position on the screen

	return stLabelArray[col].sLabels;
}