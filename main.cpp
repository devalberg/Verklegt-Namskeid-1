#include <iostream>
using namespace std;

int get_number()
{
    int i;
    cin >> i;
    return i;
}

void fizz(int i)
{
    int base = 1;

    while (base <= i)
    {
        if(base % 3 == 0 && base % 5 != 0)
        {
            cout << "Fizz" << endl;
        }
        else if(base % 5 == 0 && base % 3 != 0)
        {
            cout << "Buzz" << endl;
        }
        else if (base % 3 == 0 && base % 5 == 0)
        {
            cout << "FizzBuzz" << endl;
        }
        else
        {
            cout << base << endl;
        }
        base++;
    }
}

int main()
{
    int i = get_number();

    fizz(i);

    return 0;
}
