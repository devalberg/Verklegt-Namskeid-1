#ifndef SALES_MENU_CUSTOM_PIZZA_H
#define SALES_MENU_CUSTOM_PIZZA_H

#include <Pizza.h>
#include "SizeService.h"
#include "BottomService.h"
#include "PizzaService.h"
#include "ToppingService.h"

class Sales_Menu_Custom_Pizza
{
public:
    Sales_Menu_Custom_Pizza();
    Pizza run();

private:
    Pizza pizza;
    ToppingService t;
    SizeService s;
    BottomService b;

    bool done = false;
    void get_toppings();
    void get_size();
    void get_bottom();
    int total_price;
    int total_topping_price;
    void print_info();
};

#endif // SALES_MENU_CUSTOM_PIZZA_H
