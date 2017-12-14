#include "InvalidUsernameException.h"

InvalidUsernameException::InvalidUsernameException()
{
    this->message = "";
}

InvalidUsernameException::InvalidUsernameException(string username, bool exist)
{
    if (!exist)
    {
        string str1 = "The username '";
        string str2 = "' does not exist in our system!";
        this->message = str1 + username + str2;
    }
    else
    {
        string str1 = "The username '";
        string str2 = "' already exists in our system!";
        this->message = str1 + username + str2;
    }
}

string InvalidUsernameException::get_error()
{
    if (message == "")
    {
        string str = "Invalid username format! Please enter username with 3-20 characters";
        return str;
    }
    else
    {
        return message;
    }
}
