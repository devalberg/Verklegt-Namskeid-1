#ifndef ORDER_H
#define ORDER_H
#include "Pizza.h"
#include "Side.h"
#include "Drink.h"



class Order
{
    public:
        Order(double _total_price);
        void add_pizza(Pizza current_pizza);
        void add_drink(Drink current_drink);
        void add_side(Side current_side);
        friend ostream &operator << (ostream& out, Order& current_order);


    private:
        vector <Pizza> pizza_list;
        vector <Side> sides_list;
        vector <Drink> drinks_list;
        char status;
        double total_price;
        int order_id;
        bool dilivery;

};

#endif // ORDER_H
