#include "login.h"

bool login()
{
    cout << "**********************";
    SetConsoleTextAttribute(GetStdHandle( STD_OUTPUT_HANDLE), 10);
    cout << " WELCOME TO EMO PIZZA ";
    SetConsoleTextAttribute(GetStdHandle( STD_OUTPUT_HANDLE), 15);
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
                    SetConsoleTextAttribute(GetStdHandle( STD_OUTPUT_HANDLE), 10);
                    cout << " WELCOME TO EMO PIZZA ";
                    SetConsoleTextAttribute(GetStdHandle( STD_OUTPUT_HANDLE), 15);
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
                        SetConsoleTextAttribute(GetStdHandle( STD_OUTPUT_HANDLE), 10);
                        cout << " WELCOME TO EMO PIZZA ";
                        SetConsoleTextAttribute(GetStdHandle( STD_OUTPUT_HANDLE), 15);
                        cout << "**********************" << endl;
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
            SetConsoleTextAttribute(GetStdHandle( STD_OUTPUT_HANDLE), 10);
            cout << "Password accepted, welcome ";
            SetConsoleTextAttribute(GetStdHandle( STD_OUTPUT_HANDLE), 15);
            cout << login.username << "!" << endl;
            pass = true;
            SetConsoleTextAttribute(GetStdHandle( STD_OUTPUT_HANDLE), 15);
            Sleep(2000);
        }

        else
        {
            SetConsoleTextAttribute(GetStdHandle( STD_OUTPUT_HANDLE), 12);
            cout << "Invalid username / password!" << endl;
            pass = false;
            SetConsoleTextAttribute(GetStdHandle( STD_OUTPUT_HANDLE), 15);
        }

        cout << endl;

    }
    while (pass == false);

}

