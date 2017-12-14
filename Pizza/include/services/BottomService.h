#ifndef BOTTOMSERVICE_H
#define BOTTOMSERVICE_H

#include "Bottom.h"
#include "BottomsRepository.h"
#include "InvalidItemIdExceptions.h"
#include "InvalidItemNameException.h"
#include "InvalidItemPriceException.h"
#include "InvalidItemVeganException.h"
#include <vector>

class BottomService
{
public:
    BottomService();
    vector<Bottom> view_items();

    /// Bottom manipulations
    void add_item(const Bottom& item);
    Bottom fetch_bottom(char identity);
    void delete_item(string item_name);
    bool validate_bottom(Bottom& bottom);

    bool check_match(char identity);
    bool validate_name(string name);
    bool validate_price(int price);
    bool validate_identity(char identity);

private:
    BottomsRepository _repository;
};

#endif // SIDESERVICE_H
