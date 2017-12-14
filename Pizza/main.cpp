#include <iostream>
#include "LoginUI.h"
#include "Admin_Main_UI.h"

#include "Sales_Menu_Pizza.h"
#include "Sales_Menu_Custom_Pizza.h"
#include "Sales_Menu_Drinks.h"
#include "Sales_Menu_Sides.h"
#include "Sales_Create_Order.h"
#include "Sales_Orders.h"
using namespace std;

int main()
{
    while (true)
    {
        LoginUI login;
        User user = login.run();

        char currentType = login.get_userType();

        if (currentType == 'a')
        {
            Admin_Main_UI a;
            a.run(user);
        }
        else if (currentType == 's')
        {
            Sales_Main_UI s;
            s.run(user);
        }
        else if (currentType == 'b')
        {
            Baker_Main_UI b;
            b.run(user);
        }
        else if (currentType == 'c')
        {
            Cashier_Main_UI c;
            c.run(user);
        }
    }

 //   Sales_Menu_Pizza s;
  //   s.run();

     //Sales_Menu_Custom_Pizza s;
   //    s.run();

  //Sales_Create_Order o;
  //o.run();

    return 0;
}
