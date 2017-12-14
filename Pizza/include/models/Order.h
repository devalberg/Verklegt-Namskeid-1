#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include "Pizza.h"
#include "Side.h"
#include "Drink.h"
#include "Location.h"

enum STATUS {PREPARING, WAITING_FOR_PICKUP, DELIVERED};

class Order
{
public:
    Order();
    Order(vector<Pizza> pizzas, vector<Side> sides, vector<Drink> drinks, string customer_name, string customer_phone, string comment, Location location, bool delivery, bool paid);

    int get_order_number();
    int get_order_status();
    bool get_order_paid();

    vector<Pizza> get_pizzas();
    vector<Side> get_sides();
    vector<Drink> get_drinks();

    string get_customer_name();
    string get_customer_phone();
    string get_comment();

    Location get_location();
    void set_order_number(int number);
    void set_order_status(int status);
    void set_paid(bool paid);


private:
    Pizza pizzas[50];
    Side sides[50];
    Drink drinks[50];

    char customer_name[50];
    char customer_phone[50];
    char comment[250];

    Location location;
    int status;
    bool delivery;
    bool paid;
    int order_number;
};

#endif // ORDER_H
