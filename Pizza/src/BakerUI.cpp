#include "BakerUI.h"
#include <Windows.h>
void BakerUI::startBakerUI(LoginUI account)
{
    cout << "Logged in as: " << account.getUsername() << endl << endl;

    cout << "TO DO LIST:" << endl;
    cout << " \tOrder no: 1337 \n\t\tPIZZA PEPPERONI x1\n\t\tCONK, BEPIS x100 \n\t\tBreadsticks x20" << endl;
    cout << "\tComment: \n\t NO BANANAS" << endl << endl;

    cout << "Set status (write order number):" << endl;

    cout << "Other options:" << endl;
    if (account.getUserType() == 'a') {
        cout << "\t8. Back to admin menu" << endl;
    }
    cout << "\t9. Logout" << endl;
    cout << "\t0. Quit" << endl;

}
