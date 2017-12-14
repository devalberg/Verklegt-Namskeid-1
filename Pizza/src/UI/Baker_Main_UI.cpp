#include "Baker_Main_UI.h"

Baker_Main_UI::Baker_Main_UI()
{
    //ctor
}

void Baker_Main_UI::run(User user)
{
    bool cont = true;

    while(cont)
    {
        system("cls");
        cout << "==================================================" << endl;
        cout << "                    BAKER MENU" << endl;
        cout << "==================================================\n" << endl;

        cout << "Select the following commands. . ." << endl << endl;
        cout << "\t1. View orders" << endl;
        cout << "\t2. Mark ready" << endl << endl;

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

bool Baker_Main_UI::get_command(User user)
{
    START:
    string input;
    cin >> input;

    if(input == "1")
    {
        //vieworders();
    }
    else if(input == "2")
    {
        //markready();
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
