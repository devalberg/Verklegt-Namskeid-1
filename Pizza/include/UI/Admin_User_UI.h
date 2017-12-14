#ifndef ADMIN_USER_UI_H
#define ADMIN_USER_UI_H

#include "LoginServices.h"
#include "MiscUIFunctions.h"

class Admin_User_UI
{
    public:
        Admin_User_UI();
        void run();
    private:
        LoginServices _service;

        bool get_command();
        void add_user();
        void view_users();

        void edit_user();
        void delete_user();
        bool check_for_cancel(string input);
};

#endif // ADMIN_USER_UI_H
