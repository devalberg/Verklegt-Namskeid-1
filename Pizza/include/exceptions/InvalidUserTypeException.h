#ifndef INVALIDUSERTYPEEXCEPTION_H
#define INVALIDUSERTYPEEXCEPTION_H
#include "UniversalIncludes.h"

class InvalidUserTypeException
{
    public:
        InvalidUserTypeException();
        string get_error();
    private:
        string message;
};

#endif // INVALIDUSERTYPEEXCEPTION_H
