#ifndef ADMINUI_H
#define ADMINUI_H
#include <iostream>
#include "LoginUI.h"
using namespace std;


class AdminUI
{
    public:
        void startAdminUI(LoginUI account);
        void addUser();
    private:
        void selectOption(LoginUI account);
};

#endif // ADMINUI_H
