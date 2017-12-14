#ifndef DRINKSREPOSITORY_H
#define DRINKSREPOSITORY_H

#include "Drink.h"
#include <vector>

class DrinksRepository
{
    public:
        DrinksRepository();
        /// Write types;
        void newItem(const Drink& item);
        void editItem(vector<Drink> items);

        /// Function called by service to get list of users;
        vector<Drink> get_items();

    private:
        /// Reads data from datafile and stores in userList
        void readFromDatabase();

        /// Vector to keep all the users retrieved from datafile;
        vector<Drink> itemsList;
};

#endif // SIDESREPOSITORY_H
