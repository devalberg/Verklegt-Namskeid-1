#include "login.h"
#include "textcolors.h"

using namespace std;
bool login()
{
    cout << "**********************";
    cGreen();
    cout << " WELCOME TO EMO PIZZA ";
    cWhite();
    cout << "**********************" << endl;
    cout << "Enter your cridentials down below!" << endl;

    Userpass login;
    Userpass admin = {"admin", "password"};
    bool pass = false;
    do
    {
        cout << "Username: ";
        cin >> login.username;

        char c = ' ';
        login.password = "";
        cout << "Password: ";
        while (c!=13)
        {

            c = getch();
            if (c!=13)
            {
                if (c!=8)
                {
                    login.password+=c;
                    system("CLS");
                    cout << "**********************";
                    cGreen();
                    cout << " WELCOME TO EMO PIZZA ";
                    cWhite();
                    cout << "**********************" << endl;
                    cout << "Enter your cridentials down below!" << endl;

                    cout << "Username: " << login.username << endl;
                    cout << "Password: ";
                    for (int i = 0 ; i < login.password.length(); i++)
                    {
                        cout << "*";
                    }
                }
                else
                {
                    if (login.password.length() > 0)
                    {
                        login.password.pop_back();
                        system("CLS");
                        cout << "**********************";
                        cWhite();
                        cout << " WELCOME TO EMO PIZZA ";
                        cGreen();
                        cout << "**********************" << endl;
                        cWhite();
                        cout << "Enter your cridentials down below!" << endl;

                        cout << "Username: " << login.username << endl;
                        cout << "Password: ";
                        for (int i = 0 ; i < login.password.length(); i++)
                        {
                            cout << "*";
                        }
                    }
                }
            }
        }

        cout << endl;

        if (login.username == admin.username && login.password == admin.password)
        {
            cWhite();
            cout << "Password accepted, welcome ";
            cGreen();
            cout << login.username << "!" << endl;
            pass = true;
            cWhite();
            Sleep(2000);
        }

        else
        {
            cRed();
            cout << "Invalid username / password!" << endl;
            pass = false;
            cWhite();
        }

        cout << endl;

    }
    while (pass == false);

}

