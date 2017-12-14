#include "SizeService.h"

SizeService::SizeService()
{
    //ctor
}

////////////////////// Manipulate items ///////////////////////////
void SizeService::add_item(const Size& item)
{
    if (validate_name(item.get_name()) && validate_identity(item.get_identity()) && validate_price(item.get_price()))
    {
        _repository.newItem(item);
    }
}

void SizeService::delete_item(string item_size)
{
    vector<Size> itemsList = _repository.get_items();

    bool found = false;
    for (unsigned int i = 0 ; i < itemsList.size() ; i++)
    {
        if (! itemsList[i].get_name().compare(item_size) )
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

vector<Size> SizeService::view_items()
{
    return _repository.get_items();
}


///////////////////// VALIDATIONS ////////////////////////////////////
bool SizeService::validate_name(string name)
{
    if (name.length() < 1 || name.length() > MAXITEMNAMESIZE )
    {
        throw InvalidItemNameException();
    }

    vector<Size> items = _repository.get_items();

    for (unsigned int i = 0; i < items.size(); i++)
    {
        if (!name.compare(items[i].get_name()))
        {
            throw InvalidItemNameException(name);
        }
    }

    return true;
}

bool SizeService::validate_identity(char identity)
{
    if(!isalpha(identity))
    {
        throw InvalidItemIdExceptions();
    }

    vector<Size> items = _repository.get_items();

    for (unsigned int i = 0; i < items.size(); i++)
    {
        if (identity == items[i].get_identity())
        {
            throw InvalidItemIdExceptions(identity);
        }
    }
    return true;
}

bool SizeService::check_match(char identity)
{
    vector<Size> items = _repository.get_items();
    for (unsigned int i = 0; i < items.size(); i++)
    {
        if (identity == items[i].get_identity())
        {
            return true;
        }
    }

    return false;
}

bool SizeService::validate_price(int price)
{
    if(price <= 0)
    {
        throw InvalidItemPriceException();
    }
    return true;
}
