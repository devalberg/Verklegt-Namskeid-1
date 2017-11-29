#include "Superhero.h"

Superhero::Superhero()
{
    this->age = 0;
    this->name = "";
    this->power = 'n';
}

Superhero::Superhero(string _name, int _age, char _power)
{
    this->name = _name;
    this->age = _age;
    this->power = _power;
    this->true_power = TruePower(_power);
}

string Superhero::TruePower(char power)
{
    if(power == 'f' || power == 'F')
    {
        return "Flying";
    }
    else if(power == 'g' || power == 'G')
    {
        return "Giant";
    }
    else if(power == 'h' || power == 'H')
    {
        return "Hacker";
    }
    else if(power == 'n' || power == 'N')
    {
        return "None";
    }

    return "Weakling";
}


ostream& operator << (ostream& out, const Superhero& current_hero)
{


    out << "Hero name: " << current_hero.name << endl;
    out << "Hero age: " << current_hero.age << endl;
    out << "Hero power: " << current_hero.true_power << endl << endl;

    return out;
}

istream& operator >> (istream& in, Superhero& current_hero)
{
    cout << "Please enter your hero's name: ";
        in >> current_hero.name;
    cout << "Please enter your hero's age: ";
        in >> current_hero.age;
    cout << "Please enter your hero power: ";
        in >> current_hero.power;

        return in;
}

void Superhero::set_name(string _name)
{
    this->name = _name;
}


