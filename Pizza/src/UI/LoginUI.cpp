#include "LoginUI.h"
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include "MiscUIFunctions.h"
using namespace std;
LoginUI::LoginUI()
{
    //ctor
}

User LoginUI::run()
{
    system("CLS");
    cout << "-------------------------------------------------" << endl;
    cout << "               WELCOME TO EMO PIZZA" << endl;
    cout << "-------------------------------------------------" << endl << endl;
    cout << "Enter your credentials below:" << endl;

    string username;
    char password[MAXPASSWORD];
    User tempUser;
    while (true)
    {
        cout << "Username: ";
        cin >> username;
        if (check_for_cancel(username)) exit(0);
        cout << "Password: ";
        getPasswordInput(password);
        cout << endl;
        if (check_for_cancel(password)) exit(0);
        tempUser.set_username(username);
        tempUser.set_password(password);

        if (_service.login(tempUser))
        {
            cout << "Password accepted! welcome, ";
            _user = tempUser;
            cout << _user;
            cout << endl;
            _user = tempUser;
            system("pause");
            break;
        }
        else
        {
            cout << "Username / Password incorrect, try again" << endl << endl;
        }
    }
    return tempUser;
}

void LoginUI::getPasswordInput(char* password)
{

    int characterPosition = 0;
    char c = ' ';
    do
    {
        c = getch();
        if (c == 13)
        {
            password[characterPosition] = '\0';
            break;
        }
        if (c == 8)
        {
            if (characterPosition > 0)
            {
                characterPosition--;
                password[characterPosition] = '\0';
                cout << "\b \b";
            }
        }
        else
        {
            password[characterPosition] = c;
            characterPosition++;
            cout << '*';
        }
    }
    while (c != 13);
    password[characterPosition] = '\0';

}

char LoginUI::get_userType()
{
    return this->_user.get_userType();
}
