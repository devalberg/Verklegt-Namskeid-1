#include "InvalidPasswordException.h"

InvalidPasswordException::InvalidPasswordException()
{
    message = "Invalid password format, please enter at least 3 characters (max 20)";
}

string InvalidPasswordException::get_error()
{
    return message;
}
