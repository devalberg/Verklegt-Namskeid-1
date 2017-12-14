#include "Sales_Orders.h"
#include "OrderService.h"
#include <cstdlib>

#include <iostream>
using namespace std;

Sales_Orders::Sales_Orders()
{

}

void Sales_Orders::run(bool legacy)
{
    system("CLS");
    cout << "List of active orders: " << endl;
    view_orders_list(legacy);
    view_specific_order(legacy);
}
void Sales_Orders::view_orders_list(bool legacy)
{
    vector<Order> orders;

    if (!legacy)
    {
        orders = _service.view_all_active_orders();
    }
    else
    {
        orders = _service.view_all_legacy_orders();
    }
    for (unsigned int i = 0 ; i < orders.size() ; i++)
    {
        cout << orders[i].get_order_number() << " - " << orders[i].get_customer_name() << "\tStatus: " << orders[i].get_order_status() << "\tPaid: ";
        if (orders[i].get_order_paid())
        {
            cout <<"Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

}

void Sales_Orders::delete_order()
{
    system("CLS");
    view_orders_list(false);

    vector<Order> orders = _service.view_all_active_orders();

    while (true)
    {
        cout << "Choose order to delete: " << endl;
        int input;
        cin >> input;
        bool found = false;
        for (unsigned int i = 0 ; i < orders.size() ; i++)
        {
            if (input == orders[i].get_order_number())
            {
                _service.delete_order(input);
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "Invalid input";
        }
        else
        {
            break;
        }
    }
}

void Sales_Orders::view_specific_order(bool legacy)
{
    vector<Pizza> pizzas;
    vector<Drink> drinks;
    vector<Side> sides;

    vector<Order> orders;
    if (legacy)
    {
        orders = _service.view_all_legacy_orders();
    }
    else
    {
        orders = _service.view_all_active_orders();
    }

    Order order;
    while (true)
    {
        cout << "Choose order to view: " << endl;
        int input;
        cin >> input;
        bool found = false;
        for (unsigned int i = 0 ; i < orders.size() ; i++)
        {
            if (input == orders[i].get_order_number())
            {
                order = orders[i];
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "Invalid input";
        }
        else
        {
            break;
        }
    }

    pizzas = order.get_pizzas();
    sides = order.get_sides();
    drinks = order.get_drinks();

    system("CLS");
    cout << "Customer name: " << order.get_customer_name() << endl;
    cout << "Customer phone: " << order.get_customer_phone() << endl;
    cout << "Location: " << order.get_location().get_name() << endl;

    if (pizzas.size())
    {
        cout << "Pizzas:" << endl;

        for (unsigned int i = 0 ; i < pizzas.size() ; i++)
        {
            cout << "\t" << pizzas[i].get_name() << "\t" << pizzas[i].get_price() << endl;
            cout << "\t  Contains: ";

            for (unsigned int j = 0 ; j < pizzas[i].get_toppings().size() ; j++)
            {
                cout << pizzas[i].get_toppings()[j].get_counter() << pizzas[i].get_toppings()[j].get_name();
                if (pizzas[i].get_toppings()[j+1].get_name() != "\0")
                    cout << ", ";
                else break;
            }
        }
        cout << endl;
    }

    if (sides.size())
    {
        cout << "Sides: " << endl;

        for (unsigned int i = 0 ; i < sides.size() ; i++)
        {
            cout << "\t" << sides[i].get_name() << "\t" << sides[i].get_price() << endl;
        }

        cout << endl;
    }

    if (drinks.size())
    {
        cout << "Drinks: " << endl;

        for (unsigned int i = 0 ; i < drinks.size() ; i++)
        {
            cout << "\t" << drinks[i].get_name() << "\t" << drinks[i].get_price() << endl;
        }

        cout << endl;
    }

    if (order.get_comment() != "\0")
    {
        cout << "Comment: " << order.get_comment() << endl;
    }


    system("pause");
}

