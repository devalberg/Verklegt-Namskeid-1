#ifndef SALES_CREATE_ORDER_H
#define SALES_CREATE_ORDER_H

#include "Sales_Menu_Custom_Pizza.h"
#include "Sales_Menu_Pizza.h"
#include "Sales_Menu_Sides.h"
#include "Sales_Menu_Drinks.h"
#include "OrderService.h"
#include "Location.h"

class Sales_Create_Order
{
    public:
        Sales_Create_Order();
        void run();
    private:
        OrderService _service;
        void print_order();
        void get_input();

        void delete_items();
        void delete_pizza();
        void delete_side();
        void delete_drink();

        Location location;
        string customer_name;
        string customer_phone;
        string comment;
        bool paid;
        bool delivery;
        vector<Drink> drinks;
        vector<Side> sides;
        vector<Pizza> pizzas;
};

#endif // SALES_CREATE_ORDER_H
