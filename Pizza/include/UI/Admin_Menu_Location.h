#ifndef ADMIN_MENU_LOCATION_H
#define ADMIN_MENU_LOCATION_H

#include "Location.h"
#include "LocationService.h"
#include "MiscUIFunctions.h"

class Admin_Menu_Location
{
    public:
        Admin_Menu_Location();
        void run();
    private:
        bool get_command();
        void add_item();
        void delete_item();
        LocationService _service;
};

#endif // ADMIN_MENU_LOCATION_H
