#ifndef ORDER_H
#define ORDER_H
#include "Pizza.h"
#include "Drink.h"
#include "Side.h"


class Order
{
    public:
        Order();


    private:
        vector <Pizza> pizza_list;
        vector <Side> sides_list;
        vector <Drink> drinks_list;
        char status;
        double total_price;

};

#endif // ORDER_H
