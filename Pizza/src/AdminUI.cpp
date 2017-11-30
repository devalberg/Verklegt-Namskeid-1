#include "AdminUI.h"
#include "DeliveryUI.h"
#include "BakerUI.h"
#include "SaleUI.h"
#include <Windows.h>
#include <fstream>
void AdminUI::startAdminUI(LoginUI account)
{
    system("CLS");
    cout << "Logged in as: " << account.getUsername() << endl << endl;

    cout << "What would you like to do?" << endl;
    cout << "Manage users:" << endl;
    cout << "\t1. Add user" << endl;
    cout << "\t2. Edit user" << endl;
    cout << "\t3. Delete user" << endl << endl;

    cout << "Switch menu to: " << endl;
    cout << "\t4. Sales" << endl;
    cout << "\t5. Baker" << endl;
    cout << "\t6. Delivery" << endl << endl;

    cout << "Others:" << endl;
    cout << "\t9. Logout" << endl;
    cout << "\t0. Quit" << endl;

    selectOption(account);

}

void AdminUI::selectOption(LoginUI account)
{

    int n = 0;
    bool pass = 0;

    do
    {
        cout << "Input: ";
        cin >> n;
        if (n < 0 || n > 9)
        {
            cout << "Invalid input, try again" << endl;
            pass = 0;
        }
        else
        {
            pass = 1;
        }
    }
    while (pass == 0);

    switch (n)
    {
    case 1:
        AdminUI adminUI;
        adminUI.addUser();
        break;
    case 4:
        SaleUI saleUI;
        saleUI.startSalesUI(account);
        break;
    case 5:
        BakerUI bakerUI;
        bakerUI.startBakerUI(account);
        break;
    case 6:
        DeliveryUI deliveryUI;
        deliveryUI.startDeliveryUI(account);
        break;
    default:
        cout << ":D" << endl;
        break;
    }
}

void AdminUI::addUser()
{

    ofstream fout;
    LoginUI current;
    cin >> current;

    fout.open("Users.dat", ios::app|ios::binary);

    fout.write((char*)(&current), sizeof(LoginUI));

    fout.flush();
    fout.close();


}


