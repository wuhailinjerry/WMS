#pragma once
#include "CBaseOperateFrame.h"
class COutBoundFrame :
	public CBaseOperateFrame
{
public:
	COutBoundFrame ( wxPanel *panel, wxFrame *frame );
	virtual ~COutBoundFrame ( );

	virtual void DoSize ( wxSize size );
};

