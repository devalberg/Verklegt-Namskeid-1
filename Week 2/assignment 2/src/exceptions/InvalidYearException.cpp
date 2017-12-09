#include "InvalidYearException.h"
#include <sstream>
InvalidYearException::InvalidYearException()
{
    this->year = -1;
}

InvalidYearException::InvalidYearException(int year)
{
    this->year = year;
}

string InvalidYearException::get_error()
{

    string temp;
    if (year == -1)
    {
        temp = "Invalid year entered! (Only 1900 - Current year)";
        return temp;
    }
    else
    {
        stringstream ss;
        ss << year << endl;
        string theYear = ss.str();

        string temp1 = "The year ";
        string temp2 = " does not have any record entries.";
        temp = temp1 + theYear + temp2;

        return temp;
    }
}
