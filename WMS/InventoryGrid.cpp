#include "stdafx.h"
#include "InventoryGrid.h"


struct stLabels
{
	InventoryColEnum eCol;
	wxString sLabels;

	bool operator < ( const stLabels &left) const
	{
		return this->eCol < left.eCol;
	}
};

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

InventoryGrid::InventoryGrid ( )
{
	std::sort ( &stLabelArray[eBeginCol], &stLabelArray[eEndCol] );
}


InventoryGrid::~InventoryGrid ( )
{
	
}

wxString InventoryGrid::GetColLabelValue ( int col )
{
	// notice that column parameter here always refers to the internal
	// column index, independently of its position on the screen

	return stLabelArray[col].sLabels;
}