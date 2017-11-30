#include "SaleUI.h"
#include "textcolors.h"
#include <iostream>
#include <Windows.h>
#include "LoginUI.h"
using namespace std;

void SaleUI::startSalesUI(LoginUI account)
{
    system("CLS");
    cDGreen();
    cout << "Logged in as: " << account.getUsername() << endl << endl;
    cWhite();
    cout << "Select what you would like to do:" << endl;
    cout << "\t1. Create an order" << endl;
    cout << "\t2. Edit an order" << endl;
    cout << "\t3. View an order" << endl;
    cout << "\t4. Delete an order" << endl << endl;


    cout << "Others:" << endl;
    if (account.getUserType() == 'a') {
        cout << "\t8. Back to admin menu" << endl;
    }
    cout << "\t9. Logout" << endl;
    cout << "\t0. Quit" << endl;

}

