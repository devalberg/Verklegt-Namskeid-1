#include "Admin_Main_UI.h"

#include <iostream>
#include <cstdlib>
using namespace std;

Admin_Main_UI::Admin_Main_UI()
{

}
void Admin_Main_UI::run(User user)
{
    bool cont = true;
    while (cont)
    {
        system("cls");
        cout << "==================================================" << endl;
        cout << "                    ADMIN MENU" << endl;
        cout << "==================================================\n" << endl;

        cout << "Select the following commands. . .\n" << endl;
        cout << "\t1. Go to Restaurant menu management" << endl;
        cout << "\t2. Go to Users management" << endl;
        cout << "\t3. Go to Location management\n" << endl;

        cout << "Switch to different user menu:\n" << endl;
        cout << "\t7. Sales menu" << endl;
        cout << "\t8. Baker menu" << endl;
        cout << "\t9. Delivery menu\n" << endl;

        cout << "Type 'logout' to logout or type 'exit' / 'quit' to terminate program" << endl;

        cont = get_command(user);
    }
}

bool Admin_Main_UI::get_command(User user)
{
START:
    string input;
    cin >> input;

    if (input == "1")
    {
        Admin_Menu_Management m;
        m.run();
    }
    else if (input == "2")
    {
        Admin_User_UI a;
        a.run();
    }
    else if (input == "3")
    {
        Admin_Menu_Location l;
        l.run();
    }
    else if (input == "7")
    {
        Sales_Main_UI s;
        s.run(user);
    }
    else if (input == "8")
    {
        Baker_Main_UI b;
        b.run(user);
    }
    else if (input == "9")
    {
        Cashier_Main_UI c;
        c.run(user);
    }
    else if (input == "logout")
    {
        return false;
    }
    else if (input == "exit" || input == "quit")
    {
        exit(0);
    }
    else
    {
        cout << "Invalid input! try again..." << endl;
        goto START;
    }

    return true;
}
