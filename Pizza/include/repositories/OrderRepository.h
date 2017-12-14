#ifndef ORDERREPOSITORY_H
#define ORDERREPOSITORY_H

#include "Order.h"
#include <vector>

class OrderRepository
{
    public:
        OrderRepository();
        void newItem(const Order& item);
        vector<Order> get_items();
        vector<Order> get_legacy_items();
        void editItem(vector<Order> items);
        void moveToLegacy(const Order& item);


    private:
        void readFromDatabase();
        void readFromLegacy();
        vector<Order> itemsList;
};

#endif // ORDERREPOSITORY_H
