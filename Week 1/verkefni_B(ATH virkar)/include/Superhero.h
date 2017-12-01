#ifndef SUPERHERO_H
#define SUPERHERO_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;
int const MAX_SIZE = 36;
int const MAX_POWER = 9;

class Superhero
{
    public:
        Superhero();
        Superhero(char ary[], int _age, char _power);
        void cahr_ary_input(char ary[], int max_size_arr);
        void cahr_ary_output(char ary[], int max_size_arr);
        void name_cahr_ary_output(char ary[], int max_size_arr);
        char get_power_char();
        void input_true_power(char current_power);
        void string_to_arr(string _string);


        friend ostream& operator << (ostream& out, Superhero& current_hero);
        friend istream& operator >> (istream& in,  Superhero& current_hero);

    private:
        char name[MAX_SIZE];
        int name_lenght;
        int age;
        char power;
        char true_power[MAX_POWER];

};

#endif // SUPERHERO_H
