#include "BottomService.h"

BottomService::BottomService()
{
    //ctor
}

////////////////////// Manipulate items ///////////////////////////
void BottomService::add_item(const Bottom& item)
{
    if (validate_name(item.get_name()) && validate_identity(item.get_identity()) && validate_price(item.get_price()))
    {
        _repository.newItem(item);
    }
}

void BottomService::delete_item(string item_name)
{
    vector<Bottom> itemsList = _repository.get_items();

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

vector<Bottom> BottomService::view_items()
{
    return _repository.get_items();
}


////////////////////////////////////// Validations /////////////////////////////////////////
Bottom BottomService::fetch_bottom(char identity)
{
    vector<Bottom> bottoms_db = _repository.get_items();

    for (unsigned int i = 0; i < bottoms_db.size(); i++)
    {
        if (identity == bottoms_db[i].get_identity())
        {
            return bottoms_db[i];
        }
    }
       throw InvalidItemIdExceptions(false);
}

bool BottomService::validate_name(string name)
{
    if (name.length() < 1 || name.length() > MAXITEMNAMESIZE )
    {
        throw InvalidItemNameException();
    }

    vector<Bottom> items = _repository.get_items();

    for (unsigned int i = 0; i < items.size(); i++)
    {
        if (!name.compare(items[i].get_name()))
        {
            throw InvalidItemNameException(name);
        }
    }

    return true;
}

bool BottomService::validate_identity(char identity)
{
    if(!isalpha(identity))
    {
        throw InvalidItemIdExceptions();
    }

    vector<Bottom> items = _repository.get_items();

    for (unsigned int i = 0; i < items.size(); i++)
    {
        if (identity == items[i].get_identity())
        {
            throw InvalidItemIdExceptions(identity);
        }
    }
    return true;
}

bool BottomService::validate_price(int price)
{
    if(price <= 0)
    {
        throw InvalidItemPriceException();
    }
    return true;
}


bool BottomService::check_match(char identity)
{
    vector<Bottom> items = _repository.get_items();
    for (unsigned int i = 0; i < items.size(); i++)
    {
        if (identity == items[i].get_identity())
        {
            return true;
        }
    }

    return false;
}
