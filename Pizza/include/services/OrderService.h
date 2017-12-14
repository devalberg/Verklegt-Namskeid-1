#ifndef ORDERSERVICE_H
#define ORDERSERVICE_H

#include "Order.h"
#include "OrderRepository.h"

class OrderService
{
    public:
        OrderService();
        void create_order(Order& order);

        void set_order_paid(int order_number, bool paid);
        void set_order_status(int order_number, int status);

        void delete_order(int number);

        vector<Order> view_all_active_orders();
        Order view_an_order(int number);

        vector<Order> view_all_legacy_orders();
        Order view_a_legacy_order(int number);

    private:
        OrderRepository _repository;
        int assign_order_number();

};

#endif // ORDERSERVICE_H
