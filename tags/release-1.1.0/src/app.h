/* SLiM - Simple Login Manager
   Copyright (C) 1997, 1998 Per Liden
   Copyright (C) 2004 Simone Rota <sip@varlock.com>
   Copyright (C) 2004 Johannes Winkelmann <jw@tks6.net>
      
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
*/

#ifndef _APP_H_
#define _APP_H_

#include <X11/Xlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <setjmp.h>
#include <stdlib.h>
#include <iostream>
#include "panel.h"
#include "cfg.h"

using namespace std;

class App {
public:
    App(int argc, char** argv);
    ~App();
    void Run();
    int GetServerPID();
    void StopServer();
    
    // Lock functions
    void GetLock();
    void RemoveLock();

private:
    void Login();
    void Reboot();
    void Halt();
    void Console();
    void Exit();
    void KillAllClients(Bool top);
    void ReadConfig();
    void OpenLog();
    void CloseLog();

    // Server functions
    int StartServer();
    int ServerTimeout(int timeout, char *string);
    int WaitForServer();
    
    // Private data
    Window Root;
    Display* Dpy;
    int Scr;
    Panel* LoginPanel;
    int ServerPID;

    // Options
    char* DispName;

    Cfg cfg;

    XpmAttributes BackgroundPixmapAttributes;
    Pixmap BackgroundPixmap;

    void setBackground();
};


#endif
