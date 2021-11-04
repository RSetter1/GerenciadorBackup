#pragma once

#define VC_EXTRALEAN
#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS
#define _AFX_ALL_WARNINGS

#include "targetver.hpp"

#include <afxwin.h>
#include <afxext.h>
#include <afxdtctl.h>
#include <afxcmn.h>
#include <afxcontrolbars.h>
#include <afxdialogex.h>

#include "resource.h"

#include "FolderEdit.hpp"
#include "ButtonBackup.hpp"

typedef UCHAR FLAG;

#pragma comment(linker, "/manifestdependency:\" \
    type='win32'                                \
    name='Microsoft.Windows.Common-Controls'    \
    version='6.0.0.0'                           \
    processorArchitecture='*'                   \
    publicKeyToken='6595b64144ccf1df'           \
    language='*'                                \" \
")

#include "..\..\..\vendors\xlistview\XListView.h"

