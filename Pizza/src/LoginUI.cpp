#include "LoginUI.h"
#include "textcolors.h"
using namespace std;

<<<<<<< HEAD
char LoginUI::start_loginUI()
=======
void LoginUI::start_loginUI()
{

}


char login()
>>>>>>> 4f3574f45b2b35a21e4261409566dfe720ac6fce
{
    cout << "**********************";
    cGreen();
    cout << " WELCOME TO EMO PIZZA ";
    cWhite();
    cout << "**********************" << endl;
    cout << "Enter your cridentials down below!" << endl;

    Userpass admin = {"admin", "password"};
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
                }
            }
        }

        cout << endl;
        Userpass admin;
        admin.username = "admin";
        admin.password = "password";
        admin.type = 'a';

        Userpass sales;
        sales.username = "sales";
        sales.password = "password";
        sales.type = 's';

        Userpass baker;
        baker.username = "baker";
        baker.password = "password";
        baker.type = 'b';

        Userpass delivery;
        delivery.username = "delivery";
        delivery.password = "password";
        delivery.type = 'd';

        if (login.username == admin.username && login.password == admin.password)
        {
            cWhite();
            cout << "Password accepted, welcome ";
            cGreen();
            cout << login.username << "!" << endl;
            pass = true;
            cWhite();
            login.type = admin.type;
            Sleep(2000);
        }
        else if (login.username == sales.username && login.password == sales.password)
        {
            cWhite();
            cout << "Password accepted, welcome ";
            cGreen();
            cout << login.username << "!" << endl;
            pass = true;
            cWhite();
            login.type = sales.type;
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
            login.type = baker.type;
            Sleep(2000);
        }
        else if (login.username == delivery.username && login.password == delivery.password)
        {
            cWhite();
            cout << "Password accepted, welcome ";
            cGreen();
            cout << login.username << "!" << endl;
            pass = true;
            cWhite();
            login.type = delivery.type;
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


    return login.type;
}
void LoginUI::access(char chr)
{
    AdminUI adminUI;
    SaleUI saleUI;
    BakerUI bakerUI;
    DeliveryUI deliveryUI;

    if(chr == 'a')
    {
        adminUI.startAdminUI();
    }
    else if(chr == 's')
    {
        saleUI.startSalesUI();
    }
    else if(chr == 'b')
    {
        bakerUI.startBakerUI();
    }
    else if(chr == 'd')
    {
        deliveryUI.startDeliveryUI();
    }
}

#include "login.h"
#include "textcolors.h"

using namespace std;



