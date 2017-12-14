#ifndef ADMIN_MENU_DRINKS_H
#define ADMIN_MENU_DRINKS_H

#include "DrinkService.h"
#include "Drink.h"
#include "MiscUIFunctions.h"


class Admin_Menu_Drinks
{
        public:
        Admin_Menu_Drinks();
        void run();
    private:
        bool get_command();
        void add_item();
        void delete_item();
        DrinkService _service;
};

#endif // ADMIN_MENU_SIDES_H
