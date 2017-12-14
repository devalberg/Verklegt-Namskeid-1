#include "InvalidItemPriceException.h"

InvalidItemPriceException::InvalidItemPriceException()
{
    message = "Invalid price format! Please enter a number higher than 0";
}

string InvalidItemPriceException::get_error()
{
    return message;
}
