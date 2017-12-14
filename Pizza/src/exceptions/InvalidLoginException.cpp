#include "InvalidLoginException.h"

InvalidLoginException::InvalidLoginException()
{
    message = "Invalid username / password! Please try again";
}

string InvalidLoginException::get_error()
{
    return message;
}
