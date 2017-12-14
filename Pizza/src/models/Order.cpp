#include "Order.h"
Order::Order()
{
    this->customer_name[0] = '\0';
    this->customer_phone[0] = '\0';
    this->comment[0] = '\0';

    this->status = 0;
    this->delivery = 0;
    this->paid = 0;
    this->order_number = 0;
}

Order::Order(vector<Pizza> pizzas, vector<Side> sides, vector<Drink> drinks, string customer_name, string customer_phone, string comment, Location location, bool delivery, bool paid)
{
    for (unsigned int i = 0 ; i < pizzas.size() ; i++)
    {
        this->pizzas[i] = pizzas[i];
    }

    for (unsigned int i = 0 ; i < sides.size() ; i++)
    {
        this->sides[i] = sides[i];
    }


    for (unsigned int i = 0 ; i < drinks.size() ; i++)
    {
        this->drinks[i] = drinks[i];
    }

    strcpy(this->customer_name, customer_name.c_str());
    strcpy(this->customer_phone, customer_phone.c_str());
    strcpy(this->comment, comment.c_str());

    this->location = location;
    this->delivery = delivery;
    this->paid = paid;
}

void Order::set_order_number(int number)
{
    this->order_number = number;
}

void Order::set_order_status(int status)
{
    this->status = status;
}

int Order::get_order_number()
{
    return this->order_number;
}

void Order::set_paid(bool paid)
{
    this->paid = paid;
}

int Order::get_order_status()
{
    return this->status;
}

bool Order::get_order_paid()
{
    return this->paid;
}

vector<Pizza> Order::get_pizzas()
{
    vector <Pizza> temp;
    unsigned int i = 0;
    while (pizzas[i].get_name() != "\0")
    {
        temp.push_back(pizzas[i]);
        i++;
    }
    return temp;
}

vector<Side> Order::get_sides()
{
    vector <Side> temp;
    unsigned int i = 0;
    while (sides[i].get_name() != "\0")
    {
        temp.push_back(sides[i]);
        i++;
    }
    return temp;
}
vector<Drink> Order::get_drinks()
{
    vector <Drink> temp;
    unsigned int i = 0;
    while (drinks[i].get_name() != "\0")
    {
        temp.push_back(drinks[i]);
        i++;
    }
    return temp;
}

string Order::get_customer_name()
{
    return string(this->customer_name);
}
string Order::get_customer_phone()
{
    return string(this->customer_phone);
}
string Order::get_comment()
{
    return string(this->comment);
}

Location Order::get_location()
{
    return this->location;
}
