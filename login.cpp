#include "login.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
using namespace std;


bool login()
{
    Userpass login;
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
            cout << "Password accepted" << endl;
            pass = true;
            SetConsoleTextAttribute(GetStdHandle( STD_OUTPUT_HANDLE), 10);
        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle( STD_OUTPUT_HANDLE), 12);
            cout << "Invalid username / password!" << endl;
            pass = false;
        }

        cout << endl;

    }
    while (pass == false);

}

void check() {
    cout << "nigger";
}
