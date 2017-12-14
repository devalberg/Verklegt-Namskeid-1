#include "Sales_Menu_Sides.h"

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

Sales_Menu_Sides::Sales_Menu_Sides()
{
    //ctor
}

vector<Side> Sales_Menu_Sides::run()
{
    while (true)
    {
        total_price = 0;

        print_info();
        get_sides();

        char confirm;

        cout << "Confirm to add this list? ('y'): ";
        cin >> confirm;
        if (confirm == 'y')
        {
            return this->sides;
        }

        sides.clear();
    }
}

void Sales_Menu_Sides::print_info()
{
    system("CLS");
    cout << "================================================" << endl;
    cout << "             Adding sides to order" << endl;
    cout << "================================================" << endl;

    if (sides.size())
    {
        for (unsigned int i = 0 ; i < sides.size() ; i++)
        {
            cout << left << setw(32) << sides[i].get_name() << right << setw(8) << sides[i].get_price() << " Kr." << endl;
        }
        cout << right << setw(32) << "Total price: " << total_price << endl;
        cout << "-----------------------------------------------------------" << endl;
    }
}

void Sales_Menu_Sides::get_sides()
{
    char input;
    vector<Side> _s = s.view_items();


    while (true)
    {
        cout << "List of sides available:" << endl;

        for (unsigned int i = 0 ; i < _s.size() ; i++)
        {
            cout << "\t[" << _s[i].get_identity() << "] - " << left << setw(32) << _s[i].get_name() << right << setw(8) << _s[i].get_price() << " Kr."<< endl;
        }

        cout << "Choose sides (type '\\' to end input): ";
        cin >> input;
        if (input != '\\')
        {
            if(s.check_match(input))
            {
                sides.push_back(s.get_side());
                total_price += s.get_side().get_price();
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
