#ifndef SALES_MENU_SIDES_H
#define SALES_MENU_SIDES_H

#include <vector>
#include "Side.h"
#include "SideService.h"
using namespace std;


class Sales_Menu_Sides
{
    public:
        Sales_Menu_Sides();
        vector<Side> run();

    private:
        SideService s;
        vector<Side> sides;
        int total_price;
        void print_info();
        void get_sides();
};

#endif // SALES_MENU_SIDES_H
