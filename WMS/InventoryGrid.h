#pragma once

enum InventoryColEnum
{
	eBeginCol = 0,
	eSupplier = 0,   // ��Ӧ��
	eBigCategory,    // ��Ʒ����
	eSmallCategory,  // ��ƷС��
	eGoodsName,      // ��Ʒ����
	eMeasurement,    // ������λ
	eGoodsCount,     // ��Ʒ����
	eGoodsPrice,     // ����
	eTotalPrice,     // �ܼ�
	eValidityPeriod, // ������
	eOperator,       // ������
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

