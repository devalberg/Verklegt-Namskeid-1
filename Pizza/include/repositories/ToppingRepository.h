#ifndef TOPPINGREPOSITORY_H
#define TOPPINGREPOSITORY_H

#include "Topping.h"
#include <vector>

class ToppingRepository
{
    public:
        ToppingRepository();
        /// Write types;
        void newItem(const Topping& item);
        void editItem(vector<Topping> items);

        /// Function called by service to get list of users;
        vector<Topping> get_items();

    private:
        /// Reads data from datafile and stores in userList
        void readFromDatabase();

        /// Vector to keep all the users retrieved from datafile;
        vector<Topping> itemsList;
};

#endif // TOPPINGREPOSITORY_H
