#include "Admin_Menu_Management.h"

#include <iostream>
#include <cstdlib>
#include "Admin_Menu_Toppings.h"
#include "Admin_Menu_Sides.h"
#include "Admin_Menu_Drinks.h"
#include "Admin_Menu_Bottoms.h"
#include "Admin_Menu_Sizes.h"
#include "Admin_Menu_Pizza.h"
using namespace std;

Admin_Menu_Management::Admin_Menu_Mangement()
{
    //ctor
}

void Admin_Menu_Management::run()
{
    bool cont = true;
    while (cont)
    {
        system("cls");
        cout << "=============================================" << endl;
        cout << "           Pizzeria Menu Management" << endl;
        cout << "=============================================" << endl << endl;

        cout << "Choose what menu you would like to edit:" << endl;
        cout << "Pizza:" << endl;
        cout << "\t1. Menu Pizza" << endl;
        cout << "\t2. Toppings" << endl;
        cout << "\t3. Bottoms" << endl;
        cout << "\t4. Size" << endl << endl;

        cout << "Sides and drinks" << endl;
        cout << "\t5. Sides" << endl;
        cout << "\t6. Drinks" << endl << endl;

        cout << "Type in the choice or type 'back' to go back to main admin menu" << endl;

        cont = get_command();
    }
}

bool Admin_Menu_Management::get_command()
{
START:
    string input;
    cin >> input;

    if (input == "1")
    {
        Admin_Menu_Pizza p;
        p.run();
    }
    else if (input == "2")
    {
        Admin_Menu_Toppings t;
        t.run();
    }
    else if (input == "3")
    {
        Admin_Menu_Bottoms b;
        b.run();
    }
    else if (input == "4")
    {
        Admin_Menu_Sizes sS;
        sS.run();
    }
    else if (input == "5")
    {
        Admin_Menu_Sides s;
        s.run();
    }
    else if (input == "6")
    {
        Admin_Menu_Drinks d;
        d.run();
    }
    else if (input == "back")
    {
        return false;
    }
    else
    {
        cout << "Invalid input, please try again" << endl;
        goto START;
    }

    return true;
}
