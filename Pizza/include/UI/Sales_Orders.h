#ifndef SALES_ORDERS_H
#define SALES_ORDERS_H

#include "OrderService.h"

class Sales_Orders
{
    public:
        Sales_Orders();

        void run(bool legacy);
        void view_orders_list(bool legacy);
        void edit_order();
        void delete_order();

    private:
        OrderService _service;
        void view_specific_order(bool legacy);

};

#endif // SALES_ORDERS_H
