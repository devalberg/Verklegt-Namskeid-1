#ifndef LOGINUI_H
#define LOGINUI_H
#include "AdminUI.h"
#include "SaleUI.h"
#include "BakerUI.h"
#include "DeliveryUI.h"
#include "textcolors.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

using namespace std;


class LoginUI
{
    public:
        char start_loginUI();
        void access(char chr);
};

struct Userpass
{
    std::string username;
    std::string password;
    char type;
};

char login();


#endif // LOGINUI_H
