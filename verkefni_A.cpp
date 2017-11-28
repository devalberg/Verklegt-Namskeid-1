#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;
void read();
void write();

int main()
{
    char type = 0;
    do
    {
        cout << "Would you like to:" << endl;
        cout << "Read(r)\t\tWrite(w)\tQuit(q)?" << endl;

        cin >> type;
        type = tolower(type);

        if (type == 'r')
        {
            read();
        }

        if (type == 'w')
        {
            write();
        }

    }
    while (type != 'q');

    return 0;
}

void read()
{
    ifstream fin;
    string str;
    fin.open("textFile.txt");
    char cont = '0';

    if (fin.is_open())
    {
        system("CLS");
        cout << "------------------------- Start of Text File -------------------------" << endl;
    }

    do
    {
        if(fin.is_open())
        {
            for(int i = 0; i < 10 && !fin.eof(); i++)
            {
                getline(fin, str);
                cout << str << endl;
            }
        }

        else

        {
            cout << "File not found\n" << endl;
            break;
        }
        if (fin.eof()) {
            break;
        }
            do
            {
                if (fin.is_open())
                {
                    cout << endl;
                    cout << "Do you wish to continue?(y/n): ";
                    cin >> cont;
                    cout << endl;
                }
            }
            while(cont != 'y' && cont != 'n');

            if (cont == 'n')
            {
                break;
            }
    }
    while(!fin.eof());

    if (fin.is_open())
    {
        cout << "-------------------------- End of Text File --------------------------" << endl;
        fin.close();
    }
}

void write()
{
    ofstream fout;
    fout.open("textFile.txt", ios::app);

    if (fout.is_open())
    {
        string input;
        bool cont = true;
        do
        {
            getline(cin, input);
            if (input[0] == '\\')
            {
                cont = false;
            }
            else
            {
                fout << input << endl;
            }
        }
        while (cont);

        fout.close();
    }
    else
    {
        cout << "File could not be opened!" << endl;
    }
}
