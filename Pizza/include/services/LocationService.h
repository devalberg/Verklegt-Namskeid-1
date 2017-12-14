#ifndef LOCATIONSERVICE_H
#define LOCATIONSERVICE_H

#include "Location.h"
#include "LocationRepository.h"
#include "InvalidItemIdExceptions.h"
#include "InvalidItemNameException.h"
#include "InvalidItemPriceException.h"
#include <vector>

class LocationService
{
    public:
    LocationService();
    vector<Location> view_items();

    /// Drink manipulations
    void add_item(const Location& item);
    void delete_item(string item_name);

    /// validations
    bool validate_name(string name);
    bool validate_identity(char identity);

private:
    LocationRepository _repository;
};

#endif // LOCATIONSERVICE_H
