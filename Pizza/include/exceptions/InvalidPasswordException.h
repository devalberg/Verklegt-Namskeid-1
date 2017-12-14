#ifndef INVALIDPASSWORDEXCEPTION_H
#define INVALIDPASSWORDEXCEPTION_H

#include "UniversalIncludes.h"

class InvalidPasswordException
{
    public:
        InvalidPasswordException();
        string get_error();

    private:
        string message;
};

#endif // INVALIDPASSWORDEXCEPTION_H
