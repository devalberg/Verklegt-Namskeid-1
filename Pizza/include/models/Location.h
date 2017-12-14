#ifndef LOCATION_H
#define LOCATION_H

#include "commonItemProperties.h"

class Location
{
    public:
        Location();
        Location(string name, char identity);

        /// Get functions
        string get_name() const;
        char get_identity() const;

        /// Set functions
        void set_name(string name);
        void set_identity(char identity);

        friend ostream& operator << (ostream& out, Location& location);

    private:
        char name[MAXITEMNAMESIZE];
        char identity;
};

#endif // LOCATION_H
