#include "OrderService.h"

OrderService::OrderService()
{
    //ctor
}

void OrderService::create_order(Order& order)
{
    order.set_order_number(assign_order_number());
    order.set_order_status(PREPARING);
    _repository.newItem(order);
}
void OrderService::set_order_paid(int order_number, bool paid)
{
    vector<Order> orders = _repository.get_items();

    for (unsigned int i = 0 ; i < orders.size() ; i++)
    {
        if (order_number == orders[i].get_order_number())
        {
            orders[i].set_paid(paid);
            _repository.editItem(orders);
            break;
        }
    }
}

void OrderService::set_order_status(int order_number, int status)
{
    vector<Order> orders = _repository.get_items();

    for (unsigned int i = 0 ; i < orders.size() ; i++)
    {
        if (order_number == orders[i].get_order_number())
        {
            orders[i].set_order_status(status);
            _repository.editItem(orders);
            break;
        }
    }

}

void OrderService::delete_order(int number)
{
    vector<Order> orders = _repository.get_items();

    for (unsigned int i = 0 ; i < orders.size() ; i++)
    {
        if (number == orders[i].get_order_number())
        {
            orders[i].set_order_status(-1);
            _repository.moveToLegacy(orders[i]);
            orders.erase(orders.begin() + i);
            _repository.editItem(orders);
            break;
        }
    }
}
vector<Order> OrderService::view_all_active_orders()
{
    vector<Order> orders = _repository.get_items();
    return orders;
}
Order OrderService::view_an_order(int number)
{
    vector<Order> orders = _repository.get_items();

    for (unsigned int i = 0 ; i < orders.size() ; i++)
    {
        if(orders[i].get_order_number() == number)
        {
            return orders[i];
        }
    }

    Order order;

    return order;

}


vector<Order> OrderService::view_all_legacy_orders()
{
    vector<Order> orders = _repository.get_legacy_items();
    return orders;
}
Order OrderService::view_a_legacy_order(int number)
{
    vector<Order> orders = _repository.get_legacy_items();

    for (unsigned int i = 0 ; i < orders.size() ; i++)
    {
        if(orders[i].get_order_number() == number)
        {
            return orders[i];
        }
    }

    Order order;

    return order;
}

int OrderService::assign_order_number()
{
    int active_count = _repository.get_items().size();
    int legacy_count = _repository.get_legacy_items().size();

    int order_number = active_count+legacy_count;

    return order_number;
}


