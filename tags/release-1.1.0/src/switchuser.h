/* SLiM - Simple Login Manager
   Copyright (C) 1997, 1998 Per Liden
   Copyright (C) 2004 Simone Rota <sip@varlock.com>
   Copyright (C) 2004 Johannes Winkelmann <jw@tks6.net>
      
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
*/

#ifndef _SWITCHUSER_H_
#define _SWITCHUSER_H_

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>
#include <paths.h>
#include <iostream>
#include "const.h"
#include "cfg.h"


class SwitchUser {
public:
    SwitchUser(struct passwd *pw, Cfg *c);
    ~SwitchUser();
    void Login(const char* cmd);

private:
    SwitchUser();
    void SetEnvironment();
    void SetUserId();
    void Execute(const char* cmd);
    char* BaseName(const char* name);
    char* StrConcat(const char* str1, const char* str2);
    Cfg* cfg;
    struct passwd *Pw;
};


#endif

