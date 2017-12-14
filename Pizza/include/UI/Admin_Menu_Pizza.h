#ifndef ADMIN_MENU_PIZZA_H
#define ADMIN_MENU_PIZZA_H

#include "PizzaService.h"
#include "Pizza.h"
#include "MiscUIFunctions.h"


class Admin_Menu_Pizza
{
        public:
        Admin_Menu_Pizza();
        void run();
    private:
        bool get_command();
        void add_item();
        void delete_item();
        PizzaService _service;
};

#endif // ADMIN_MENU_SIDES_H
