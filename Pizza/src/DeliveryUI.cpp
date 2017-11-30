#include "DeliveryUI.h"
#include <Windows.h>
#include <textcolors.h>

void DeliveryUI::startDeliveryUI(LoginUI account)
{
    system("CLS");

    cDGreen();
    cout << "Logged in as: " << account.getUsername() << endl;
    cWhite();

    cout << "Orders ready for pickup:" << endl;
    cout << "\tOrder 8008:" << endl;
    cout << "\tPizza x1" << endl;
    cout << "\tConk x2" << endl << endl;

    cout << "Orders ready for delivery:" << endl;
    cout << "\tOrder 8008:" << endl;
    cout << "\tPizza x1" << endl;
    cout << "\tConk x2" << endl << endl;

    cout << "Orders being delivered:" << endl;
    cout << "\tOrder 123:" << endl;
    cout << "\tPizza x1" << endl;
    cout << "\tConk x2" << endl << endl;

    cout << "Choose order:\n" << endl;
    cout << "Order no: 3002, COMPLETE" << endl;

}
