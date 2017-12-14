#include "InvalidItemNameException.h"

InvalidItemNameException::InvalidItemNameException()
{
    message = "Invalid name format! Please enter name with 3-20 characters";
}
InvalidItemNameException::InvalidItemNameException(bool input)
{
    message = "Item does not exist!";
}
InvalidItemNameException::InvalidItemNameException(string name)
{
    string str1 = "The bottom '";
    string str2 = "' already exists in our system!";
    this->message = str1 + name + str2;
}
string InvalidItemNameException::get_error()
{
    return message;
}
