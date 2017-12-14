#ifndef SALES_MENU_DRINKS_H
#define SALES_MENU_DRINKS_H

#include "Drink.h"
#include "DrinkService.h"
#include <vector>

class Sales_Menu_Drinks
{
    public:
        Sales_Menu_Drinks();
        vector<Drink> run();

    private:
        DrinkService d;
        vector<Drink> drinks;
        int total_price;
        void print_info();
        void get_drinks();
};

#endif // SALES_MENU_DRINKS_H
