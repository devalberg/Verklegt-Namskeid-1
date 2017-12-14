#ifndef LOCATIONREPOSITORY_H
#define LOCATIONREPOSITORY_H

#include "Location.h"
#include <vector>


class LocationRepository
{
    public:
        LocationRepository();
        /// Write types;
        void newItem(const Location& item);
        void editItem(vector<Location> items);

        /// Function called by service to get list of users;
        vector<Location> get_items();

    private:
        /// Reads data from datafile and stores in userList
        void readFromDatabase();

        /// Vector to keep all the users retrieved from datafile;
        vector<Location> itemsList;
};

#endif // LOCATIONREPOSITORY_H
