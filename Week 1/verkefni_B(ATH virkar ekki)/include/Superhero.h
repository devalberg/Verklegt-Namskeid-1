#ifndef SUPERHERO_H
#define SUPERHERO_H
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Superhero
{
    public:
        Superhero();
        Superhero(string _name, int _age, char _power);
        void set_name(string _name);
        friend ostream& operator << (ostream& out, const Superhero& current_hero);
        friend istream& operator >> (istream& in,  Superhero& current_hero);

    private:
        string name;
        int age;
        char power;
        string true_power;
        string TruePower(char power);

};

#endif // SUPERHERO_H
