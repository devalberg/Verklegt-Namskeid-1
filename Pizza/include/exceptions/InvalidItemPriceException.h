#ifndef INVALIDITEMPRICEEXCEPTION_H
#define INVALIDITEMPRICEEXCEPTION_H
#include <iostream>

using namespace std;



class InvalidItemPriceException
{
    public:
        InvalidItemPriceException();
        string get_error();
    private:
        string message;
};

#endif // INVALIDITEMPRICEEXCEPTION_H
