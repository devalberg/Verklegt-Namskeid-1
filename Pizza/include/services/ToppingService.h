#ifndef TOPPINGSERVICE_H
#define TOPPINGSERVICE_H

#include <vector>
#include "Topping.h"
#include "InvalidItemIdExceptions.h"
#include "InvalidItemNameException.h"
#include "InvalidItemPriceException.h"
#include "InvalidItemVeganException.h"
#include "ToppingRepository.h"

class ToppingService
{
public:
    ToppingService();
    vector<Topping> view_items();

    /// Topping manipulations
    void add_item(const Topping& item);
    void delete_item(string item_name);

    void collate_toppings(vector<Topping>& toppings);

    Topping topping;

    Topping get_topping();

    /// validations
    bool validate_name(string name);
    bool validate_price(int price);
    bool validate_identity(char identity);

    bool check_match(char identity);


private:

    ToppingRepository _repository;
};

#endif // TOPPINGSERVICE_H
