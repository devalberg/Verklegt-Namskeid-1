#ifndef ORDER_H
#define ORDER_H
#include "Pizza.h"
#include "Side.h"
#include "Drink.h"



class Order
{
    public:
        Order();
        void add_pizza(Pizza current_pizza);
        friend ostream &operator << (ostream& out, Order& current_order);


    private:
        vector <Pizza> pizza_list;
        vector <Side> sides_list;
        vector <Drink> drinks_list;
        char status;
        double total_price;
        int id_num;
        bool dilivery;

};

#endif // ORDER_H
