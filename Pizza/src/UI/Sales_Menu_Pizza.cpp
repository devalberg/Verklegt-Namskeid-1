#include "Sales_Menu_Pizza.h"

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;
Sales_Menu_Pizza::Sales_Menu_Pizza()
{
    //ctor
}

Pizza Sales_Menu_Pizza::run()
{
    while (true)
    {
        print_info();

        get_pizza();
        get_size();
        get_bottom();

        char crust;
        cout << "Cheese crust ('y'): ";
        cin >> crust;
        if (crust == 'y')
        {
            pizza.set_crust(true);
        }
        else
        {
            pizza.set_crust(false);
        }
        done = true;

        total_price = pizza.get_price() + pizza.get_bottom().get_price() + pizza.get_size().get_price();

        system("CLS");
        print_info();

        char confirm;
        cout << "Confirm pizza ('y')? ";
        cin >> confirm;
        if (confirm == 'y')
        {
            return pizza;
            break;
        }
        system("CLS");
        Pizza p;
        pizza = p;
        done = false;
    }

}

void Sales_Menu_Pizza::print_info()
{
    cout << "==========================================" << endl;
    cout << "            Adding pizza to order" << endl;
    cout << "==========================================" << endl;

    bool seperator = 0;

    if (pizza.get_name() != "\0")
    {
        cout << left << setw(8) << "Pizza: " << setw(32) << pizza.get_name() << right << setw(10) << pizza.get_price() << " Kr." << endl;
        seperator = 1;
    }

    if (pizza.get_size().get_name() != "\0")
    {
        cout << left << setw(8) << "Size: " << setw(32) << pizza.get_size().get_name() << right << setw(10) << pizza.get_size().get_price() << " Kr." << endl;
    }

    if (pizza.get_bottom().get_name() != "\0")
    {
        cout << left << setw(8) << "Bottom: " << setw(32) << pizza.get_bottom().get_name() << right << setw(10) << pizza.get_bottom().get_price() << " Kr." << endl;
    }

    if (done)
    {
        cout << left << setw(8) << "Crust:";
        if (pizza.get_crust()) cout << "Yes" << endl;
        else cout << "No" << endl;
        cout << right << setw(33) << " " << right << "Total Price: " << total_price << " Kr." << endl;
    }

    if (seperator)
    {
        cout << "-------------------------------------------------------------------" << endl;
    }

}

void Sales_Menu_Pizza::get_pizza()
{
    char pizza;



    vector<Pizza> pizzas = p.view_items();

    cout << "Pizza list:" << endl;
    for (unsigned int i = 0 ; i < pizzas.size() ; i++)
    {
        cout << "[" << pizzas[i].get_identity() << "] - " << left << setw(5) << pizzas[i].get_name() << "Price: " << pizzas[i].get_price() << " Kr." << endl;
        cout << "    Contains: ";

        for (unsigned int j = 0 ; j < pizzas.size() ; j++)
        {
            cout << pizzas[i].get_toppings()[j].get_name() << "[" << pizzas[i].get_toppings()[j].get_counter() << "]";
            if (pizzas[i].get_toppings()[j+1].get_identity()) cout << ", ";
            else break;
        }
        cout << endl;
    }

    while (true)
    {
        cout << "Choose pizza: ";
        cin >> pizza;
        if (p.check_match(pizza))
        {
            this->pizza = p.get_pizza();
            system("CLS");
            print_info();
            break;
        }
        else
        {
            cout << "Invalid input!" << endl;
        }
    }
}

void Sales_Menu_Pizza::get_size()
{
    char _size;


    vector<Size> sizes = s.view_items();

    cout << "Size list:" << endl;
    for (unsigned int i = 0 ; i < sizes.size() ; i++)
    {
        cout << "[" << sizes[i].get_identity() << "] - " << left << setw(5) << sizes[i].get_name() << "Price: " << sizes[i].get_price() << " Kr." << endl;
    }

    while (true)
    {
        cout << "Choose size: ";
        cin >> _size;
        if (s.check_match(_size))
        {
            this->pizza.set_size(_size);
            system("CLS");
            print_info();
            break;
        }
        else
        {
            cout << "Invalid input!" << endl;
        }
    }
}

void Sales_Menu_Pizza::get_bottom()
{
    char bottom;


    vector<Bottom> bottoms = b.view_items();

    cout << "Bottom list:";
    for (unsigned int i = 0 ; i < bottoms.size() ; i++)
    {
        cout << "[" << bottoms[i].get_identity() << "] - " << left << setw(5) << bottoms[i].get_name() << "Price: " << bottoms[i].get_price() << " Kr." << endl;
    }

    while (true)
    {
        cout << "Choose bottom: ";
        cin >> bottom;
        if (b.check_match(bottom))
        {
            this->pizza.set_bottom(bottom);
            system("CLS");
            print_info();
            break;
        }
        else
        {
            cout << "Invalid input!" << endl;
        }
    }
}
