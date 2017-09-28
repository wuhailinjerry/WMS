#include "stdafx.h"
#include "StocktakingGrid.h"

#include "WMSConfig.h"

static stLabels stLabelArray[] =
{
	{ eSupplier, "供应商" },
	{ eBigCategory, "物品大类" },
	{ eSmallCategory, "物品小类" },
	{ eGoodsName, "物品名称" },
	{ eMeasurement, "计量单位" },
	{ eGoodsCount, "物品个数" },
	{ eGoodsPrice, "单价" },
	{ eTotalPrice, "总价" },
	{ eValidityPeriod, "保质期" },
	{ eOperator, "操作人" },
};

StocktakingGrid::StocktakingGrid ( )
{
	std::sort ( &stLabelArray[eBeginCol], &stLabelArray[eEndCol] );
}


StocktakingGrid::~StocktakingGrid ( )
{

}

wxString StocktakingGrid::GetValue ( int row, int col )
{
	auto itor = m_StocktakingDataMap.find ( row );
	if ( itor == m_StocktakingDataMap.end ( ) )
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

void StocktakingGrid::SetValue ( int row, int col, const wxString& value )
{
	stStocktakingData *pData = nullptr;
	auto itor = m_StocktakingDataMap.find ( row );
	if ( itor == m_StocktakingDataMap.end ( ) )
	{
		stStocktakingData stData;
		pData = &stData;
		m_StocktakingDataMap[row] = stData;
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

wxString StocktakingGrid::GetTypeName ( int row, int col )
{
	switch ( col )
	{
		case eSupplier:
		{
			return wxString::Format ( wxT ( "%s:%s" ), wxGRID_VALUE_CHOICE, getWmsConfig ( ).getSupplierData ( ).c_str ( ) );
		}
		break;

		case eBigCategory:
		{
			wxString strVal = GetValue ( row, eSupplier );
			if ( !strVal.IsNull ( ) )
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


wxString StocktakingGrid::GetColLabelValue ( int col )
{
	// notice that column parameter here always refers to the internal
	// column index, independently of its position on the screen

	return stLabelArray[col].sLabels;
}