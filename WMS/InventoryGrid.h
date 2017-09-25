#pragma once

enum InventoryColEnum
{
	eBeginCol = 0,
	eSupplier = 0,   // 供应商
	eBigCategory,    // 物品大类
	eSmallCategory,  // 物品小类
	eGoodsName,      // 物品名称
	eMeasurement,    // 计量单位
	eGoodsCount,     // 物品个数
	eGoodsPrice,     // 单价
	eTotalPrice,     // 总价
	eValidityPeriod, // 保质期
	eOperator,       // 操作人
	eEndCol = eOperator,
	eMaxCol,
};

#define INIT_ROW_COUNT 50

class InventoryGrid : public wxGridTableBase
{
public:
	InventoryGrid ( );
	~InventoryGrid ( );

	virtual int GetNumberRows ( ) wxOVERRIDE
	{
		return m_nRows;
	}
	virtual int GetNumberCols ( ) wxOVERRIDE
	{
		return eMaxCol;
	}

	virtual wxString GetValue ( int row, int col ) wxOVERRIDE
	{
		return wxString ( );
	}

	virtual void SetValue ( int, int, const wxString& ) wxOVERRIDE
	{
		wxFAIL_MSG ( "shouldn't be called" );
	}

	virtual wxString GetColLabelValue ( int col ) wxOVERRIDE;

	virtual void SetColLabelValue ( int, const wxString& ) wxOVERRIDE
	{
		wxFAIL_MSG ( "shouldn't be called" );
	}

private:
	int m_nRows = INIT_ROW_COUNT;
};

