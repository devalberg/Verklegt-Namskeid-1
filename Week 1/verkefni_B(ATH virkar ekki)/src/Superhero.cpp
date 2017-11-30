#include "Superhero.h"


Superhero::Superhero()
{
    this->age = 0;
    this->name[0] = '/';
    this->power = 'n';
}

Superhero::Superhero(char _name[], int _age, char _power)
{
    cahr_ary_input(_name, MAX_SIZE);
    this->age = _age;
    this->power = _power;
    input_true_power(_power);
}

void Superhero::input_true_power(char current_power)
{
    if(power == 'f' || power == 'F')
    {
        this->true_power[0] = 'F';
        this->true_power[1] = 'l';
        this->true_power[2] = 'y';
        this->true_power[3] = 'i';
        this->true_power[4] = 'n';
        this->true_power[5] = 'g';
        this->true_power[6] = '/';
    }
    else if(power == 'g' || power == 'G')
    {
        this->true_power[0] = 'G';
        this->true_power[1] = 'i';
        this->true_power[2] = 'a';
        this->true_power[3] = 'n';
        this->true_power[4] = 't';
        this->true_power[5] = '/';
    }
    else if(power == 'h' || power == 'H')
    {
        this->true_power[0] = 'H';
        this->true_power[1] = 'a';
        this->true_power[2] = 'c';
        this->true_power[3] = 'k';
        this->true_power[4] = 'e';
        this->true_power[5] = 'r';
        this->true_power[6] = '/';    }

    else if(power == 'n' || power == 'N')
    {
        this->true_power[0] = 'N';
        this->true_power[1] = 'o';
        this->true_power[2] = 'n';
        this->true_power[3] = 'e';
        this->true_power[4] = '/';
    }
    else
    {
        this->true_power[0] = 'W';
        this->true_power[1] = 'e';
        this->true_power[2] = 'a';
        this->true_power[3] = 'k';
        this->true_power[4] = 'l';
        this->true_power[5] = 'i';
        this->true_power[6] = 'n';
        this->true_power[7] = 'g';
        this->true_power[8] = '/';
    }
}


ostream& operator << (ostream& out, Superhero& current_hero)
{


    out << "Hero name: ";
    current_hero.cahr_ary_output(current_hero.name, MAX_SIZE);
    out << endl;
    out << "Hero age: " << current_hero.age << endl;
    out << "Hero power: ";

    current_hero.cahr_ary_output(current_hero.true_power, MAX_POWER);
    out  << endl << endl;

    return out;
}

istream& operator >> (istream& in, Superhero& current_hero)
{
    cout << "Note: To complete name, enter '/'" << endl;

    cout << "Please enter your hero's name: ";
         current_hero.cahr_ary_input((current_hero.name), MAX_SIZE);
    cout << "Please enter your hero's age: ";
        in >> current_hero.age;
    cout << "Please enter your hero power: ";
        in >> current_hero.power;
        current_hero.input_true_power(current_hero.power);

        return in;
}

void Superhero::cahr_ary_input(char ary[], int max_size_arr)
{
    char input;
    for (int i = 0; i < max_size_arr; i++)
    {
        cin >> input;
        if (input != '/')
        {
            ary[i] = input;
        }
        else
        {
            ary[i] = '/';
            i = max_size_arr;
        }
    }
}

void Superhero::cahr_ary_output(char ary[], int max_size_arr)
{

    for(int i = 0; i < max_size_arr; i++)
    {
        if(ary[i] != '/')
        {
        cout << ary[i];
        }
        else(i = max_size_arr);
    }
}
char Superhero::get_power_char()
{
    return this->power;
}

