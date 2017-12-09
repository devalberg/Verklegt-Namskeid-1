#ifndef ORDER_H
#define ORDER_H
#include "Pizza.h"
#include "Side.h"
#include "Drink.h"


class Order
{
    public:
        Order();
        unsigned int get_order_id();
        unsigned int get_number_of_sides();

        void add_pizza(Pizza current_pizza);
        void add_drink(Drink current_drink);
        void add_side(Side current_side);
        void update_price();
        void print_comment();
        void change_status(int status);
        void change_order_id(int k);
        void change_comment();
        void change_name();
        void change_phone();
        void change_address();
        void take_drink_order(Order& current_order);
        void take_side_order(Order& current_order);


        friend ostream &operator << (ostream& out, Order& current_order);
        friend istream &operator >> (istream& in, Order& current_order);


    private:
      //vector <Pizza> pizza_list;
      //Pizza pizza_list[20];
      //vector <Side> sides_list;
        Side sides_list[MAX_SIDES];
        Drink drinks_list[MAX_DRINKS];
      //vector <Drink> drinks_list;
        int status;
        double total_price;
        unsigned int order_id;
        unsigned int number_of_sides;
        bool dilivery;
        char comment[256];
        char name[64];
        char address[32];
        char phone[16];
};

#endif // ORDER_H
