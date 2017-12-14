#ifndef DRINKSERVICE_H
#define DRINKSERVICE_H

#include "Drink.h"
#include "DrinksRepository.h"
#include "InvalidItemIdExceptions.h"
#include "InvalidItemNameException.h"
#include "InvalidItemPriceException.h"
#include <vector>

class DrinkService
{
    public:
    DrinkService();
    vector<Drink> view_items();

    /// Drink manipulations
    void add_item(const Drink& item);
    void delete_item(string item_name);

    /// validations
    bool validate_name(string name);
    bool validate_identity(char identity);
    bool validate_price(int price);
    void add_by_char(vector<Drink> drink_vector, vector<Drink>& drink_list, char input);
    char is_char_in_vector(vector<char> _vector, char _input);
    Drink* vector_to_array(vector<Drink> drink_vector);

    bool check_match(char input);
    Drink get_drink();


private:
    DrinksRepository _repository;
    Drink drink;
};

#endif // SIDESERVICE_H
