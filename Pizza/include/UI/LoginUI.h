#ifndef LOGINUI_H
#define LOGINUI_H

#include "User.h"
#include "LoginServices.h"
#include "MiscUIFunctions.h"


class LoginUI
{
public:
    LoginUI();
    User run();
    char get_userType();

private:
    User _user;
    LoginServices _service;
    void getPasswordInput(char* password);
};

#endif // LOGINUI_H
