#include "Sales_Main_UI.h"
#include "Sales_Menu_Pizza.h"
#include "Sales_Orders.h"
#include "Sales_Create_Order.h"
Sales_Main_UI::Sales_Main_UI()
{

}

void Sales_Main_UI::run(User user)
{
    bool cont = true;

    while(cont)
    {
        system("cls");
        cout << "==================================================" << endl;
        cout << "                    SALES MENU" << endl;
        cout << "==================================================\n" << endl;

        cout << "Select the following commands. . ." << endl << endl;
        cout << "\t1. Create order" << endl;
        cout << "\t2. View active orders" << endl;
        cout << "\t3. View legacy orders" << endl;
        cout << "\t4. Delete order" << endl << endl;

        if(user.get_userType() == 'a')
        {
            cout << "Type 'back' to go back to admin menu or type 'exit' / 'quit' to terminate program" << endl;
        }
        else
        {
            cout << "Type 'logout' to logout or type 'exit' / 'quit' to terminate program" << endl;
        }


        cont = get_command(user);
    }
}

bool Sales_Main_UI::get_command(User user)
{
    START:
    string input;
    cin >> input;

    Sales_Orders s;
    Sales_Create_Order c;


    if(input == "1")
    {
       c.run();
    }
    else if(input == "2")
    {
        s.run(false);
    }
    else if(input == "3")
    {
        s.run(true);
    }
    else if(input == "4")
    {
        s.delete_order();
    }
    else if(input == "back" && user.get_userType() == 'a')
    {
        return false;
    }
    else if(input == "logout" && user.get_userType() != 'a')
    {
        return false;
    }
    else if(input == "exit" || input == "quit")
    {
        exit(0);
    }
    else
    {
        cout << "Invalid input! try again..." << endl;
        goto START;
    }

}


