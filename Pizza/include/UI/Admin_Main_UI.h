#ifndef ADMIN_MAIN_UI_H
#define ADMIN_MAIN_UI_H

#include "Admin_User_UI.h"
#include "Admin_Menu_Management.h"
#include "MiscUIFunctions.h"
#include "Admin_Menu_Location.h"
#include "Sales_Main_UI.h"
#include "Baker_Main_UI.h"
#include "Cashier_Main_UI.h"
#include "User.h"

class Admin_Main_UI
{
    public:
        Admin_Main_UI();
        void run(User user);

    private:
        bool get_command(User user);

};

#endif // ADMIN_MAIN_UI_H
