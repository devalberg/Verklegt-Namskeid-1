#ifndef INVALIDITEMVEGANEXCEPTION_H
#define INVALIDITEMVEGANEXCEPTION_H
#include <iostream>

using namespace std;


class InvalidItemVeganException
{
    public:
        InvalidItemVeganException();
        string get_error();
    private:
        string message;
};

#endif // INVALIDITEMVEGANEXCEPTION_H
