#ifndef SIDESERVICE_H
#define SIDESERVICE_H

#include "Side.h"
#include "SidesRepository.h"
#include "InvalidItemIdExceptions.h"
#include "InvalidItemNameException.h"
#include "InvalidItemPriceException.h"
#include "InvalidItemVeganException.h"
#include <vector>

class SideService
{
    public:
    SideService();
    vector<Side> view_items();

    /// Side manipulations
    void add_item(const Side& item);
    void delete_item(string item_name);

    /// Validations
    bool validate_name(string name);
    bool validate_identity(char identity);
    bool validate_price(int price);
    char is_char_in_vector(vector<char> _vector, char _input);
    void add_by_char(vector<Side> side_vector, vector<Side>& side_list, char input);

    bool check_match(char input);
    Side get_side();

private:
    Side side;
    SidesRepository _repository;
};

#endif // SIDESERVICE_H
