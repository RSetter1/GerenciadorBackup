#pragma once

#include "resource.h"

class CGerenciadorBackupGUIApp : public CWinApp
{
public:
    CGerenciadorBackupGUIApp();

public:
    virtual BOOL InitInstance();

    DECLARE_MESSAGE_MAP()
};

extern CGerenciadorBackupGUIApp theApp;
