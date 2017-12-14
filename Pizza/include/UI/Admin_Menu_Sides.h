#ifndef ADMIN_MENU_SIDES_H
#define ADMIN_MENU_SIDES_H

#include "SideService.h"
#include "MiscUIFunctions.h"


class Admin_Menu_Sides
{
        public:
        Admin_Menu_Sides();
        void run();
    private:
        bool get_command();
        void add_item();
        void delete_item();
        SideService _service;
};

#endif // ADMIN_MENU_SIDES_H
