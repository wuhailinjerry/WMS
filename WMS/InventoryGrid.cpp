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