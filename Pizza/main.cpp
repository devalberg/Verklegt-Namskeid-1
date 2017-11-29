#include "LoginUI.h"
#include "textcolors.h"
#include "SaleUI.h"
#include <iostream>
using namespace std;

int main()
{
    cWhite();
    if (login() == 'a') {
        system("CLS");
        cout << "hello";
    };


    return 0;
}
