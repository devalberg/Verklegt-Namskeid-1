#ifndef BAKER_MAIN_UI_H
#define BAKER_MAIN_UI_H
#include "User.h"
#include <stdlib.h>


class Baker_Main_UI
{
    public:
        Baker_Main_UI();
        void run(User user);

    private:
        bool get_command(User user);
};

#endif // BAKER_MAIN_UI_H
