#pragma once

struct stStocktakingData
{
	stStocktakingData ( )
	{
		nGoodsCount = 0;
		fGoodsPrice = 0.0;
		fTotalPrice = 0.0;
		nGoodsId = 0;
	}
	wxString strSupplier;
	wxString strBigCategory;
	wxString strSmallCategory;
	wxString strGoodsName;
	wxString strMeasurement;

	unsigned long nGoodsCount;
	double fGoodsPrice;
	double fTotalPrice;
	wxString strValidityPeriod;
	unsigned long nGoodsId;
};

class StocktakingGrid : public wxGridTableBase
{
public:
	StocktakingGrid ( );
	~StocktakingGrid ( );

	virtual int GetNumberRows ( ) wxOVERRIDE
	{
		return m_nRows;
	}
	virtual int GetNumberCols ( ) wxOVERRIDE
	{
		return eMaxCol;
	}

	virtual wxString GetValue ( int row, int col ) wxOVERRIDE;

	virtual void SetValue ( int row, int col, const wxString& value ) wxOVERRIDE;

	virtual wxString GetTypeName ( int row, int col ) wxOVERRIDE;

	virtual wxString GetColLabelValue ( int col ) wxOVERRIDE;

	virtual void SetColLabelValue ( int, const wxString& ) wxOVERRIDE
	{
		wxFAIL_MSG ( "shouldn't be called" );
	}

private:
	int m_nRows = INIT_ROW_COUNT;

	std::map<uint32_t, stStocktakingData> m_StocktakingDataMap;
};

