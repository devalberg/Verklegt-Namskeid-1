#include "InvalidUserTypeException.h"

InvalidUserTypeException::InvalidUserTypeException()
{
    message = "Invalid user type, please enter only 'a' for admin, 's' for sales, 'b' for baker, 'd' for delivery";
}

string InvalidUserTypeException::get_error()
{
    return message;
}
