#include "Location.h"

Location::Location()
{
    this->name[0] = '\0';
    this->identity = '\0';
}

Location::Location(string name, char identity)
{
    strcpy(this->name,name.c_str());
    this->identity = identity;
}


/// GET FUNCTIONS

string Location::get_name() const
{
    return string(this->name);
}
char Location::get_identity() const
{
    return this->identity;
}

/// SET FUNCTIONS

void Location::set_name(string name)
{
    strcpy(this->name,name.c_str());
}

void Location::set_identity(char identity)
{
    this->identity = identity;
}

ostream& operator << (ostream& out, Location& location)
{
    out << string(location.name);
    return out;
}
