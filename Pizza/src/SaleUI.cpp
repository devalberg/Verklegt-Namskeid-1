#include "SaleUI.h"
#include "textcolors.h"
#include <iostream>
#include <Windows.h>
#include "LoginUI.h"
using namespace std;

void SaleUI::startSalesUI()
{
    system("CLS");
    cDGreen();
    cout << "Logged in as: " << "PLACEHOLDER" << endl << endl;
    cWhite();
    cout << "Select what you would like to do:" << endl;
    cout << "\t1. Create an order" << endl;
    cout << "\t2. Edit an order" << endl;
    cout << "\t3. View an order" << endl;
    cout << "\t4. Delete an order" << endl << endl;

  /*  if (login.getUserType() == 'a') {
        cout << "\t8. Return to admin menu" << endl;
    } */
    cout << "\t9. Logout" << endl;
    cout << "\t0. Quit" << endl;

}

