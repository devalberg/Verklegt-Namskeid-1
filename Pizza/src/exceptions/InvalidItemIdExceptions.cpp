#include "InvalidItemIdExceptions.h"

InvalidItemIdExceptions::InvalidItemIdExceptions()
{
    message = "Invalid shortcut, please enter a letter";
}

InvalidItemIdExceptions::InvalidItemIdExceptions(bool input)
{
    if (input)
    {
        message = "The ID you chose already exists in our system";
    }
    else
    {
        message = "The ID you chose does not exist";
    }
}

InvalidItemIdExceptions::InvalidItemIdExceptions(char type)
{
    if (type == 't')
    {
        message = "One of the toppings you chose does not exist in the system";
    }
    else if ( type == 'b')
    {
        message = "The bottom you chose does not exist in the system";
    }
    else if ( type == 's')
    {
        message = "The size you chose does not exist in the system";
    }

}

string InvalidItemIdExceptions::get_error()
{
    return message;
}
