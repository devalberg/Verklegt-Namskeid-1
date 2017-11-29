#ifndef LOGINUI_H
#define LOGINUI_H
#include "AdminUI.h"
#include "SaleUI.h"
#include "BakerUI.h"
#include "DeliveryUI.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>


class LoginUI
{
    public:
        void start_loginUI();
};

struct Userpass
{
    std::string username;
    std::string password;
    char type;
};

char login();


#endif // LOGINUI_H
