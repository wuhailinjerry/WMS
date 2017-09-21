#pragma once
#include "CBaseOperateFrame.h"
class CQueryFrame :
	public CBaseOperateFrame
{
public:
	CQueryFrame ( wxPanel *panel, wxFrame *frame );
	~CQueryFrame ( );

	virtual void DoSize ( wxSize size );
};

