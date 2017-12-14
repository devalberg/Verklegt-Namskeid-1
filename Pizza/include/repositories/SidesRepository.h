#ifndef SIDESREPOSITORY_H
#define SIDESREPOSITORY_H

#include "Side.h"
#include <vector>

class SidesRepository
{
    public:
        SidesRepository();
        /// Write types;
        void newItem(const Side& item);
        void editItem(vector<Side> items);

        /// Function called by service to get list of users;
        vector<Side> get_items();

    private:
        /// Reads data from datafile and stores in userList
        void readFromDatabase();

        /// Vector to keep all the users retrieved from datafile;
        vector<Side> itemsList;
};

#endif // SIDESREPOSITORY_H
