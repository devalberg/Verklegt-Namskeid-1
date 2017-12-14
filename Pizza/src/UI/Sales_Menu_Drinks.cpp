#include "Sales_Menu_Drinks.h"

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

Sales_Menu_Drinks::Sales_Menu_Drinks()
{
    //ctor
}

vector<Drink> Sales_Menu_Drinks::run()
{
    while (true)
    {
        total_price = 0;

        print_info();
        get_drinks();

        char confirm;

        cout << "Confirm to add this list? ('y'): ";
        cin >> confirm;
        if (confirm == 'y')
        {
            return this->drinks;
        }

        drinks.clear();
    }
}

void Sales_Menu_Drinks::print_info()
{
    system("CLS");
    cout << "================================================" << endl;
    cout << "             Adding drinks to order" << endl;
    cout << "================================================" << endl;

    if (drinks.size())
    {
        for (unsigned int i = 0 ; i < drinks.size() ; i++)
        {
            cout << left << setw(32) << drinks[i].get_name() << right << setw(8) << drinks[i].get_price() << " Kr." << endl;
        }
        cout << right << setw(32) << "Total price: " << total_price << endl;
        cout << "-----------------------------------------------------------" << endl;
    }


}

void Sales_Menu_Drinks::get_drinks()
{
    char input;
    vector<Drink> _d = d.view_items();


    while (true)
    {
        cout << "List of drinks available:" << endl;

        for (unsigned int i = 0 ; i < _d.size() ; i++)
        {
            cout << "\t[" << _d[i].get_identity() << "] - " << left << setw(32) << _d[i].get_name() << right << setw(8) << _d[i].get_price() << " Kr."<< endl;
        }

        cout << "Choose drinks (type '\\' to end input): ";
        cin >> input;
        if (input != '\\')
        {
            if(d.check_match(input))
            {
                drinks.push_back(d.get_drink());
                total_price += d.get_drink().get_price();
                print_info();
            }
            else
            {
                cout << "Invalid input!" << endl;
            }
        }
        else
        {
            break;
        }
    }
}

