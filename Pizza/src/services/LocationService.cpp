#include "LocationService.h"

LocationService::LocationService()
{
    //ctor
}

////////////////////// Manipulate items ///////////////////////////
void LocationService::add_item(const Location& item)
{
    if (validate_name(item.get_name()) && validate_identity(item.get_identity()))
    {
        _repository.newItem(item);
    }
}

void LocationService::delete_item(string item_name)
{
    vector<Location> itemsList = _repository.get_items();

    bool found = false;
    for (unsigned int i = 0 ; i < itemsList.size() ; i++)
    {
        if (! itemsList[i].get_name().compare(item_name) )
        {
            itemsList.erase(itemsList.begin() + i);
            found = true;
            break;
        }
    }

    if (!found)
    {
        throw InvalidItemNameException(false);
    }

    _repository.editItem(itemsList);
}

vector<Location> LocationService::view_items()
{
    return _repository.get_items();
}

/////////////////// validate ////////////////////////

bool LocationService::validate_name(string name)
{
    if (name.length() < 1 || name.length() > MAXITEMNAMESIZE )
    {
        throw InvalidItemNameException();
    }

    vector<Location> items = _repository.get_items();

    for (unsigned int i = 0; i < items.size(); i++)
    {
        if (!name.compare(items[i].get_name()))
        {
            throw InvalidItemNameException(name);
        }
    }

    return true;
}

bool LocationService::validate_identity(char identity)
{
    if(!isalpha(identity))
    {
        throw InvalidItemIdExceptions();
    }

    vector<Location> items = _repository.get_items();

    for (unsigned int i = 0; i < items.size(); i++)
    {
        if (identity == items[i].get_identity())
        {
            throw InvalidItemIdExceptions(identity);
        }
    }

    return true;
}
