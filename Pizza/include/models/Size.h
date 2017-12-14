#ifndef SIZE_H
#define SIZE_H

#include "commonItemProperties.h"

class Size
{
    public:
        Size();
        Size(string _size, char identity, int price);

        /// Get functions
        string get_name() const;
        char get_identity() const;
        int get_price() const;

        /// Set functions
        void set_name(string name);
        void set_identity(char identity);
        void set_price(int price);

        friend ostream& operator << (ostream& out, Size& _size);

    private:
        char _size[20];
        char identity;
        int price;
};

#endif // SIZE_H
