#include "Superhero.h"




/// 3) Prompt user
///     - Banna tveggja stafa tolur?
/// 4) Display individual hero

void welcome_user()
{
    cout << "Wellcome to Hero Creator." << endl << endl;
    cout << "To view all saved heroes enter 'v'." << endl;
    cout << "To add new heroes enter the amount of of heroes you would like to create(1-9):" << endl;
}

void input_heros(int number_of_heros)
{
    ofstream fout;

        fout.open("hero_bin.dat", ios::app|ios::binary);


    for(int i = 0; i<number_of_heros; i++)
    {
        Superhero current_hero;
        cout << "Hero #" << i+1 << endl;
        cin >> current_hero;
        fout.write((char*) (&current_hero), sizeof(Superhero));
    }
        fout.close();
}

int prompt_user()
{
    char input;
    /// Baeta vid individual hero

    do {
    cin >> input;
    if(input > 48 && input < 58)
        {
            return input - 48;
        }
    else if (input == 'v')
    {
        return 'v';
    }
    else
    {
        cout << "That input is invalid, please try again." << endl;
    }

    }while((input != 'v') || (input > 48 && input < 58));

    return 0;
}

void display_all_heroes()
{
    ///Version 2, virkar ekki

    ifstream fin;


    fin.open("hero_bin.dat", ios::binary);

    fin.seekg(0,fin.end);
    int number_of_heroes = fin.tellg() / sizeof(Superhero);
    fin.seekg(0, fin.beg);

    for(int i = 0; i < number_of_heroes; i++)
    {
        Superhero current_hero;
        fin.read((char*)(&current_hero), sizeof(Superhero)); /// Forritid crash'ar her
        cout << current_hero << endl;
    }
}

bool continue_program(int& number_of_heroes)
{
    char input;

    cout << endl << "What would you like to do now?" << endl;
    cout << "view heroes 'v', create more heroes(1-9), quit 'q':" << endl;

    /// Baeta vid individual hero

    do {
        cin >> input;
        if(input > 48 && input < 58)
        {
                number_of_heroes = input - 48;
                return 1;
        }
        else if (input == 'v')
        {
                number_of_heroes = 'v';
                return 1;
        }
        else if (input == 'q')
        {
                number_of_heroes = 'q';
                return 0;
        }
        else
        {
            cout << "That input is invalid, please try again." << endl;
        }

    }while((input != 'v') || (input != 'q') || (input > 48 && input < 58));

    return true;
}



int main()
{

    welcome_user();
    int number_of_heros = prompt_user();

    do{
        if(number_of_heros == 'v')
        {
            display_all_heroes();
        }
        else if(number_of_heros > 0 && number_of_heros < 10)
        {
            input_heros(number_of_heros);
        }
    }while(continue_program(number_of_heros) == true);

    return 0;
}
