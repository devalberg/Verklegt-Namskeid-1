#ifndef SIZESERVICE_H
#define SIZESERVICE_H

#include "Size.h"
#include "SizeRepository.h"
#include "InvalidItemIdExceptions.h"
#include "InvalidItemNameException.h"
#include "InvalidItemPriceException.h"
#include "InvalidItemVeganException.h"
#include <vector>

class SizeService
{
public:
    SizeService();
    vector<Size> view_items();

    /// Size manipulations
    void add_item(const Size& item);
    void delete_item(string item_name);

    bool check_match(char identity);
    bool validate_name(string name);
    bool validate_price(int price);
    bool validate_identity(char identity);

private:
    SizeRepository _repository;
};

#endif // SIDESERVICE_H
