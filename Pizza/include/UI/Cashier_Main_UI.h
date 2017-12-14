#ifndef CASHIER_MAIN_UI_H
#define CASHIER_MAIN_UI_H
#include <stdlib.h>
#include "User.h"


class Cashier_Main_UI
{
    public:
        Cashier_Main_UI();
        void run(User user);

    private:
        bool get_command(User user);
};

#endif // CASHIER_MAIN_UI_H
