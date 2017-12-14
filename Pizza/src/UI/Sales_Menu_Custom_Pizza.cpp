#include "Sales_Menu_Custom_Pizza.h"

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "SizeService.h"
#include "BottomService.h"
#include "PizzaService.h"
#include "ToppingService.h"

Sales_Menu_Custom_Pizza::Sales_Menu_Custom_Pizza()
{
    //ctor
}

Pizza Sales_Menu_Custom_Pizza::run()
{
    pizza.set_name("Custom Pizza");
    total_price = 0;
    total_topping_price = 0;
    while (true)
    {
        print_info();

        get_toppings();
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

        system("CLS");
        print_info();

        pizza.set_price(total_price);

        char confirm;
        cout << "Confirm pizza ('y')? ";
        cin >> confirm;
        if (confirm == 'y')
        {
            return pizza;
            break;
        }

        Pizza p;
        pizza = p;
        done = false;
        system("CLS");
    }

}

void Sales_Menu_Custom_Pizza::print_info()
{
    cout << "=====================================================" << endl;
    cout << "            Adding custom pizza to menu" << endl;
    cout << "=====================================================" << endl;


    bool seperator = false;
    if (pizza.get_toppings().size())
    {
        if (pizza.get_toppings()[0].get_counter() != 0)
        {
            seperator = true;
            cout << "Toppings added:" << endl;
        }
        for (unsigned int i = 0 ; i < pizza.get_toppings().size() ; i++)
        {
            if (pizza.get_toppings()[i].get_counter() != 0) {
                cout << right << setw(8) << "[" << pizza.get_toppings()[i].get_counter() << "]" << left << setw(32) << pizza.get_toppings()[i].get_name();
                cout << right << setw(8) << pizza.get_toppings()[i].get_price() * pizza.get_toppings()[i].get_counter() << " Kr." << endl;
            }
        }

        total_price = total_topping_price;
    }

    if (pizza.get_size().get_name() != "\0")
    {
        cout << left << setw(8) << "Size: " << setw(32) << pizza.get_size().get_name() << right << setw(10) << pizza.get_size().get_price() << " Kr." << endl;
        total_price += pizza.get_size().get_price();
    }

    if (pizza.get_bottom().get_name() != "\0")
    {
        cout << left << setw(8) << "Bottom: " << setw(32) << pizza.get_bottom().get_name() << right << setw(10) << pizza.get_bottom().get_price() << " Kr." << endl;
        total_price += pizza.get_bottom().get_price();
    }

    if (done)
    {
        cout << left << setw(8) << "Crust:";
        if (pizza.get_crust()) cout << "Yes" << endl;
        else cout << "No" << endl;

    }

    if (seperator == true)
    {
        cout << right << setw(32) << " " << right << "Total Price: " << total_price << " Kr." << endl;
        cout << "-------------------------------------------------------------------" << endl;
    }

}

void Sales_Menu_Custom_Pizza::get_toppings()
{
    char topping;

    vector<Topping> tempToppings;

    vector<Topping> toppings = t.view_items();
    bool looped = false;
    while (true)
    {

        cout << "Toppings list:" << endl;
        for (unsigned int i = 0 ; i < toppings.size() ; i++)
        {
            cout << "[" << toppings[i].get_identity() << "] - " << left << setw(32) << toppings[i].get_name() << "Price: " << right << setw(10) << toppings[i].get_price() << " Kr." << endl;
        }

        cout << "Select toppings: " << endl;
        if (looped)
        {
            cout << "type '\\' to stop adding" << endl;
        }

        cin>>topping;
        if (topping != '\\')
        {
            if (t.check_match(topping))
            {
                tempToppings.push_back(t.get_topping());
                t.collate_toppings(tempToppings);
                pizza.set_toppings(tempToppings);
                total_topping_price += t.get_topping().get_price();
                system("CLS");
                print_info();
                looped = true;
            }
            else
            {
                cout << "Invalid input!" << endl;
            }
        }
        else
        {
            system("CLS");
            print_info();
            break;
        }

    }
}

void Sales_Menu_Custom_Pizza::get_size()
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

void Sales_Menu_Custom_Pizza::get_bottom()
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
