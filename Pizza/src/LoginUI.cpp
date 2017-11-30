#include "AdminUI.h"
#include "SaleUI.h"
#include "BakerUI.h"
#include "DeliveryUI.h"
#include "textcolors.h"
#include "LoginUI.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
#include <vector>
#include <fstream>
using namespace std;

LoginUI(char* username, char* password, char userType) {
    int len = strlen(username);
    if (len > 19) {
        return; // TODO: PRINT OUT MESSAGE WHY THIS FAILS
    }
    len = strlen(password);
    if (len > 19) {
        return; // TODO: PRINT OUT MESSAGE WHY THIS FAILS
    }

    strcpy(this->username, username);
    strcpy(this->password, password);
    this->userType = userType;

}

void LoginUI::start_loginUI()
{
    cout << "**********************";
    cGreen();
    cout << " WELCOME TO EMO PIZZA ";
    cWhite();
    cout << "**********************" << endl;
    cout << "Enter your cridentials down below!" << endl;

    LoginUI login;
    bool pass = false;
    do
    {
        cout << "Username: ";
        cin >> login.username;

        char c = ' ';
        string tempPass;
        cout << "Password: ";
        while (c!=13)
        {

            c = getch();
            if (c!=13)
            {
                if (c!=8)
                {
                    tempPass+= c;
                    system("CLS");
                    cout << "**********************";
                    cGreen();
                    cout << " WELCOME TO EMO PIZZA ";
                    cWhite();
                    cout << "**********************" << endl;
                    cout << "Enter your cridentials down below!" << endl;

                    cout << "Username: " << login.username << endl;
                    cout << "Password: ";
                    for (unsigned int i = 0 ; i < tempPass.length(); i++)
                    {
                        cout << "*";
                    }
                }
                else
                {
                    if (tempPass.length() > 0)
                    {
                        tempPass.pop_back();
                        system("CLS");
                        cout << "**********************";
                        cGreen();
                        cout << " WELCOME TO EMO PIZZA ";
                        cWhite();
                        cout << "**********************" << endl;
                        cout << "Enter your cridentials down below!" << endl;

                        cout << "Username: " << login.username << endl;
                        cout << "Password: ";
                        for (unsigned int i = 0 ; i < tempPass.length(); i++)
                        {
                            cout << "*";
                        }
                    }
                }
            }
        }

        cout << endl;

        ////////////// NEW ////////////////
        ifstream fin;
        fin.open("Users.dat", ios::binary);

        fin.seekg(0,fin.end);
        int number_of_users = fin.tellg()/sizeof(LoginUI);
        fin.seekg(0, fin.beg);

        LoginUI *users = new LoginUI[number_of_users];
        fin.read((char*)(users), sizeof(LoginUI)*number_of_users);

        fin.close();

        bool match = false;


        for (int i = 0; i < number_of_users; i++)
        {
            if(login.username == users[i].username && login.password == users[i].password)
            {
                match = true;
                login.userType = users[i].userType;
                break;
            }
            else
            {
                match = false;
            }
        }

        if(match)
        {
            cWhite();
            cout << "Password accepted, welcome ";
            cGreen();
            cout << login.username << "!" << endl;
            pass = true;
            cWhite();
            Sleep(1000);
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



    /*
            /////////////OLD :D///////////

            LoginUI admin;
            admin.username = "admin";
            admin.password = "password";
            admin.userType = 'a';

            LoginUI sales;
            sales.username = "sales";
            sales.password = "password";
            sales.userType = 's';

            LoginUI baker;
            baker.username = "baker";
            baker.password = "password";
            baker.userType = 'b';

            LoginUI delivery;
            delivery.username = "delivery";
            delivery.password = "password";
            delivery.userType = 'd';

            if (login.username == admin.username && login.password == admin.password)
            {
                cWhite();
                cout << "Password accepted, welcome ";
                cGreen();
                cout << login.username << "!" << endl;
                pass = true;
                cWhite();
                login.userType = admin.userType;
                Sleep(1000);
            }
            else if (login.username == sales.username && login.password == sales.password)
            {
                cWhite();
                cout << "Password accepted, welcome ";
                cGreen();
                cout << login.username << "!" << endl;
                pass = true;
                cWhite();
                login.userType = sales.userType;
                Sleep(2000);
            }
            else if (login.username == baker.username && login.password == baker.password)
            {
                cWhite();
                cout << "Password accepted, welcome ";
                cGreen();
                cout << login.username << "!" << endl;
                pass = true;
                cWhite();
                login.userType = baker.userType;
                Sleep(1000);
            }
            else if (login.username == delivery.username && login.password == delivery.password)
            {
                cWhite();
                cout << "Password accepted, welcome ";
                cGreen();
                cout << login.username << "!" << endl;
                pass = true;
                cWhite();
                login.userType = delivery.userType;
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

    */

    username = login.username;
    password = login.password;
    userType = login.userType;

}
void LoginUI::access()
{
    LoginUI account;
    account.username = username;
    account.password = password;
    account.userType = userType;

    if(userType == 'a')
    {
        AdminUI adminUI;
        adminUI.startAdminUI(account);
    }
    else if(userType == 's')
    {
        SaleUI saleUI;
        saleUI.startSalesUI(account);
    }
    else if(userType == 'b')
    {
        BakerUI bakerUI;
        bakerUI.startBakerUI(account);
    }
    else if(userType == 'd')
    {
        DeliveryUI deliveryUI;
        deliveryUI.startDeliveryUI(account);
    }
}

char LoginUI::getUserType()
{
    return userType;
}

char LoginUI::getUsername()
{
    return username;
}

istream& operator >> (istream& in, LoginUI& account)
{

    in >> account.username >> account.password >> account.userType;

    return in;
}

