#ifndef SIZEREPOSITORY_H
#define SIZESREPOSITORY_H

#include "Size.h"
#include <vector>

class SizeRepository
{
    public:
        SizeRepository();
        /// Write types;
        void newItem(const Size& item);
        void editItem(vector<Size> items);

        /// Function called by service to get list of users;
        vector<Size> get_items();

    private:
        /// Reads data from datafile and stores in userList
        void readFromDatabase();

        /// Vector to keep all the users retrieved from datafile;
        vector<Size> itemsList;
};

#endif // SIDESREPOSITORY_H
