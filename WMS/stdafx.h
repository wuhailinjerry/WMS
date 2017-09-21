// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>

#include <stdio.h>
#include <tchar.h>



// TODO: reference additional headers your program requires here


#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

// #ifndef WX_PRECOMP
#include "wx/wx.h"
// #endif


#include "wx/listbase.h"
#include "wx/listctrl.h"
#include "wx/statline.h"
#include "wx/spinctrl.h"

#include "wx/valgen.h"

#include "wx/log.h"
#include "wx/settings.h"
#include "wx/sysopt.h"
#include "wx/defs.h"

#include "wx/timer.h"           // for wxStopWatch
#include "wx/colordlg.h"        // for wxGetColourFromUser
#include "wx/settings.h"
#include "wx/sysopt.h"
#include "wx/numdlg.h"

#include "WMSDefine.h"

#include "Common.h"
#include "StringProcess.h"
#include "curl/curl.h"
#include "json/json.h"