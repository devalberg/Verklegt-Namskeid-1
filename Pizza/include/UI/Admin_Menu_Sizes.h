#ifndef ADMIN_MENU_SIZES_H
#define ADMIN_MENU_SIZES_H

#include "SizeService.h"
#include "Size.h"
#include "MiscUIFunctions.h"

class Admin_Menu_Sizes
{
        public:
        Admin_Menu_Sizes();
        void run();
    private:
        bool get_command();
        void add_item();
        void delete_item();
        SizeService _service;
};

#endif // ADMIN_MENU_SIDES_H
