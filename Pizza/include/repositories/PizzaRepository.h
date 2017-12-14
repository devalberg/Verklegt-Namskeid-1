#ifndef PIZZAREPOSITORY_H
#define PIZZAREPOSITORY_H

#include "Pizza.h"
#include <vector>

class PizzaRepository
{
    public:
        PizzaRepository();
        /// Write types;
        void newItem(const Pizza& item);
        void editItem(vector<Pizza> items);

        /// Function called by service to get list of users;
        vector<Pizza> get_items();

    private:
        /// Reads data from datafile and stores in userList
        void readFromDatabase();

        /// Vector to keep all the users retrieved from datafile;
        vector<Pizza> itemsList;
};

#endif // SIDESREPOSITORY_H
