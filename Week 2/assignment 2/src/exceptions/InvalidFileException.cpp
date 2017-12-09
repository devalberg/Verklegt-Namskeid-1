#include "InvalidFileException.h"

InvalidFileException::InvalidFileException()
{
    //ctor
}

string InvalidFileException::get_error()
{
    string temp = "There exists no database! add a record to create one!";
    return temp;
}
