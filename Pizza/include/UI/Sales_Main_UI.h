#ifndef SALES_MAIN_UI_H
#define SALES_MAIN_UI_H
#include <stdlib.h>
#include "User.h"


class Sales_Main_UI
{
    public:
        Sales_Main_UI();
        void run(User user);

    private:
        bool get_command(User user);
};

#endif // SALES_MAIN_UI_H
