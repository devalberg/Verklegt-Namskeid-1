#include "LoginUI.h"
#include "textcolors.h"
#include "SaleUI.h"
#include <iostream>
using namespace std;


int main()
{
    LoginUI login("admin", "admin", 'a');
    login.start_loginUI();
    login.access();
return 0;
}
