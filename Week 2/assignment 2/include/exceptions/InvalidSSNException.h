#ifndef INVALIDSSNEXCEPTION_H
#define INVALIDSSNEXCEPTION_H

#include <string>

using namespace std;
class InvalidSSNException
{
    public:
        InvalidSSNException(); /// creates error saying does not have 10 characters;
        InvalidSSNException(string SSN); /// creates error that SSN does not exist in database;
        string get_error(); /// returns error depending on what was created;

    private:
        string SSN = "";
};

#endif // INVALIDSSNEXCEPTION_H
