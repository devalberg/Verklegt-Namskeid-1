#include "InvalidSSNException.h"


InvalidSSNException::InvalidSSNException()
{
    this->SSN = "";
}


InvalidSSNException::InvalidSSNException(string SSN)
{
    this->SSN = SSN;
}

string InvalidSSNException::get_error() {

    string returnString;
    if (this->SSN == "") {
        returnString = "The SSN you entered is invalid, please enter only numbers and exactly 10 digits long";
        return returnString;
    } else {
        returnString = "The SSN '" + SSN + "' you entered does not exist in our system!";
        return returnString;
    }
}
