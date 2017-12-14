#ifndef PIZZASERVICE_H
#define PIZZASERVICE_H

#include "Pizza.h"
#include "PizzaRepository.h"
#include "InvalidItemIdExceptions.h"
#include "InvalidItemNameException.h"
#include "InvalidItemPriceException.h"
#include "InvalidItemVeganException.h"
#include <vector>

class PizzaService
{
    public:
    PizzaService();
    vector<Pizza> view_items();

    /// Pizza manipulations
    void add_item(const Pizza& item);
    void delete_item(string item_name);

    bool check_match(char input);
    bool validate_name(string name);
    bool validate_id(char id);
    Pizza get_pizza();
    Pizza finalize_pizza_admin(string name, char identity, Size& _size, Bottom& bottom, vector<Topping> toppings, bool crust, int price);

private:
    PizzaRepository _repository;
    Pizza pizza;

};

#endif // SIDESERVICE_H
