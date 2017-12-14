#ifndef ADMIN_MENU_BOTTOMS_H
#define ADMIN_MENU_BOTTOMS_H

#include "BottomService.h"
#include "Bottom.h"
#include "MiscUIFunctions.h"


class Admin_Menu_Bottoms
{
        public:
        Admin_Menu_Bottoms();
        void run();
    private:
        bool get_command();
        void add_item();
        void delete_item();
        BottomService _service;
};

#endif // ADMIN_MENU_SIDES_H
