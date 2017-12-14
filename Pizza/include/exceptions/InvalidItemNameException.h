#ifndef INVALIDITEMNAMEEXCEPTION_H
#define INVALIDITEMNAMEEXCEPTION_H
#include <iostream>

using namespace std;


class InvalidItemNameException
{
    public:
        InvalidItemNameException();
        InvalidItemNameException(string name);
        InvalidItemNameException(bool input);
        string get_error();

    private:
        string message;
};

#endif // INVALIDITEMNAMEEXCEPTION_H
