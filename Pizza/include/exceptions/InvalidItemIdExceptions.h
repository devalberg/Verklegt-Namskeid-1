#ifndef INVALIDITEMIDEXCEPTIONS_H
#define INVALIDITEMIDEXCEPTIONS_H
#include <iostream>
using namespace std;

class InvalidItemIdExceptions
{
    public:
        InvalidItemIdExceptions();
        InvalidItemIdExceptions(bool input);
        InvalidItemIdExceptions(char type);
        string get_error();
    private:
        string message;
};

#endif // INVALIDITEMIDEXCEPTIONS_H
