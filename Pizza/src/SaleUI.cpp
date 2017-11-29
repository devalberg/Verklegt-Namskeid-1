#include "SaleUI.h"
#include "textcolors.h"
#include <iostream>
#include <Windows.h>
#include <LoginUI.h>
using namespace std;

void SaleUI::startSalesUI()
{
    system("CLS");
    cDGreen();
    cout << "Logged in as: " << "PLACEHOLDER" << endl << endl;
    cWhite();
    cout << "Select what you would like to do:" << endl;
    cout << "1. Create an order" << endl;
    cout << "2. Edit an order" << endl;
    cout << "3. View an order" << endl;
    cout << "4. Delete an order" << endl;

    cout << "9. Logout" << endl;
}

