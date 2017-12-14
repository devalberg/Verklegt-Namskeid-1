#ifndef SALES_MENU_PIZZA_H
#define SALES_MENU_PIZZA_H

#include <Pizza.h>
#include "SizeService.h"
#include "BottomService.h"
#include "PizzaService.h"

class Sales_Menu_Pizza
{
public:
    Sales_Menu_Pizza();
    Pizza run();

private:
    Pizza pizza;
    PizzaService p;
    BottomService b;
    SizeService s;

    bool done = false;
    void get_pizza();
    void get_size();
    void get_bottom();
    int total_price;
    void print_info();
};

#endif // SALES_MENU_PIZZA_H
