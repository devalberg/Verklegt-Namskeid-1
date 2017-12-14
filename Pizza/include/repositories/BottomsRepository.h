#ifndef BOTTOMSREPOSITORY_H
#define BOTTOMSREPOSITORY_H

#include "Bottom.h"
#include <vector>

class BottomsRepository
{
    public:
        BottomsRepository();
        /// Write types;
        void newItem(const Bottom& item);
        void editItem(vector<Bottom> items);

        /// Function called by service to get list of users;
        vector<Bottom> get_items();

    private:
        /// Reads data from datafile and stores in userList
        void readFromDatabase();

        /// Vector to keep all the users retrieved from datafile;
        vector<Bottom> itemsList;
};

#endif // SIDESREPOSITORY_H
