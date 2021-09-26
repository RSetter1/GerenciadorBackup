#pragma once

#include "resource.h"

class CGerenciadorBackupGUIApp : public CWinApp
{
public:
    CGerenciadorBackupGUIApp();

public:
    virtual BOOL InitInstance();

private:
    DECLARE_MESSAGE_MAP()
};

extern CGerenciadorBackupGUIApp theApp;
