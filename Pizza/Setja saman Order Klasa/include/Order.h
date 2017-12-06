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
        void add_drink(Drink current_drink);
        void add_side(Side current_side);
        void update_price();
        void print_comment();
        void change_comment();
        void change_name();
        void change_phone();
        void change_address();
        friend ostream &operator << (ostream& out, Order& current_order);


    private:
        vector <Pizza> pizza_list;
        vector <Side> sides_list;
        vector <Drink> drinks_list;
        char status;
        double total_price;
        int order_id;
        bool dilivery;
        char comment[140];
        char name[35];
        char phone[16];
        char address[32];

};

#endif // ORDER_H
