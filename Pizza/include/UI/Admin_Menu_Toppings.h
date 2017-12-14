#ifndef ADMIN_MENU_TOPPINGS_H
#define ADMIN_MENU_TOPPINGS_H

#include "ToppingService.h"
#include "MiscUIFunctions.h"

class Admin_Menu_Toppings
{
    public:
        Admin_Menu_Toppings();
        void run();
    private:
        bool get_command();
        void add_item();
        void delete_item();
        ToppingService _service;
};

#endif // ADMIN_MENU_TOPPINGS_H
