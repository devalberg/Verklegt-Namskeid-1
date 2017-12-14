#ifndef INVALIDLOGINEXCEPTION_H
#define INVALIDLOGINEXCEPTION_H

#include "UniversalIncludes.h"

class InvalidLoginException
{
    public:
        InvalidLoginException();
        string get_error();

    private:
        string message;
};

#endif // INVALIDLOGINEXCEPTION_H
