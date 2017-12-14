#include "InvalidItemVeganException.h"

InvalidItemVeganException::InvalidItemVeganException()
{
    message = "Invalid input, please enter a letter ('y' = yes, anything else = no)";
}
string InvalidItemVeganException::get_error()
{
        return message;
}
