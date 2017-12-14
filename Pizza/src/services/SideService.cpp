#include "SideService.h"

SideService::SideService()
{
    //ctor
}

////////////////////// Manipulate items ///////////////////////////
void SideService::add_item(const Side& item)
{
    if (validate_name(item.get_name()) && validate_identity(item.get_identity()) && validate_price(item.get_price()))
    {
        _repository.newItem(item);
    }
}

void SideService::delete_item(string item_name)
{
    vector<Side> itemsList = _repository.get_items();

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

vector<Side> SideService::view_items()
{
    return _repository.get_items();
}

char SideService::is_char_in_vector(vector<char> _vector, char _input)
{
     for(unsigned int i = 0; i < _vector.size(); i++)
    {
        if(_input == _vector[i])
        {
            return true;
        }
    }
    return false;
}

void SideService::add_by_char(vector<Side> side_vector, vector<Side>& side_list, char input)
{
        for(unsigned int i = 0; i < side_vector.size(); i++)
        {
            if(side_vector[i].get_identity() == input)
            {
                side_list.push_back(side_vector[i]);
                break;
            }
        }
}

///////////////////////// VALIDATIONS ////////////////////////////////////
bool SideService::validate_name(string name)
{
    if (name.length() < 1 || name.length() > MAXITEMNAMESIZE )
    {
        throw InvalidItemNameException();
    }

    vector<Side> items = _repository.get_items();

    for (unsigned int i = 0; i < items.size(); i++)
    {
        if (!name.compare(items[i].get_name()))
        {
            throw InvalidItemNameException(name);
        }
    }

    return true;
}

bool SideService::validate_identity(char identity)
{
    if(!isalpha(identity))
    {
        throw InvalidItemIdExceptions();
    }

    vector<Side> items = _repository.get_items();

    for (unsigned int i = 0; i < items.size(); i++)
    {
        if (identity == items[i].get_identity())
        {
            throw InvalidItemIdExceptions(identity);
        }
    }
    return true;
}

bool SideService::validate_price(int price)
{
    if(price <= 0)
    {
        throw InvalidItemPriceException();
    }
    return true;
}


bool SideService::check_match(char identity)
{
    vector<Side> items = _repository.get_items();
    for (unsigned int i = 0; i < items.size(); i++)
    {
        if (identity == items[i].get_identity())
        {
            this->side = items[i];
            return true;
        }
    }

    return false;
}

Side SideService::get_side()
{
    return this->side;
}

