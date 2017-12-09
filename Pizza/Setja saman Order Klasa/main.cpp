#include "Order.h"
#include <fstream>

int numbOfOrders()
{
    ifstream fin;
    fin.open("Orders.dat", ios::binary|ios::app);

    fin.seekg(0, fin.end);
    int numbOfOrders  = fin.tellg() / sizeof(Order);
    fin.seekg(0, fin.beg);

    return numbOfOrders;
}

void vieworders(Order* orders, int numbOfOrders)
{
    for(int i = 0; i < numbOfOrders; ++i)
    {
        Order temp_order = orders[i];

        cout << temp_order << endl;
    }
}

void deleteorder(Order* orders)
{
    unsigned int input;

    vieworders(orders, numbOfOrders());

    cout << "Which order would you like to delete? ";
    cin >> input;

    ifstream fin;
    fin.open("Orders.dat", ios::binary);

    Order *neworder = new Order[numbOfOrders()];

    fin.read((char*)neworder, sizeof(Order)* numbOfOrders());
    fin.close();

    int k;
    for(int i = 0; i < numbOfOrders(); i++)
    {
        if(input == neworder[i].get_order_id())
        {
            neworder[i].change_status(300);
            k = i;
            break;
        }
    }
    fstream fout;
    fout.open("Orders.dat", ios::binary | ios::out | ios::in);

    fout.seekp(sizeof(Order)*k);
    fout.write((char*)&neworder[k], sizeof(Order));
    fout.close();
    delete[] neworder;
}
void createorder()
{

    int k;

    Order order;

    ifstream kin;

    kin.open("ordernumber.txt");
    kin >> k;
    kin.close();

    k++;

    ofstream kout;
    kout.open("ordernumber.txt");
    kout << k;
    kout.close();

    order.change_order_id(k);


    cin >> order;
    ofstream fout;
    fout.open("Orders.dat", ios::binary|ios::app);

    fout.write((char*)&order, sizeof(Order));
    fout.close();
}
int main()
{

    char input;

    do
    {

        ifstream fin;
        fin.open("Orders.dat", ios::binary|ios::app);

        int numberoforders  = numbOfOrders();

        Order *orders = new Order[numberoforders];

        fin.read((char*)orders, sizeof(Order)* numberoforders);
        fin.close();

        cout << "Order menu:" << endl;
        cout << "View 'v', Create 'c', Delete 'd', Close program 'q' :";
        cin >> input;
        cout << endl << endl;
        if(input == 'd')
        {
            deleteorder(orders);
        }
        else if(input == 'v')
        {
            vieworders(orders, numbOfOrders());
        }
        else if(input == 'c')
        {
            createorder();
        }
        delete[] orders;

    }while(input != 'q');

    return 0;
}
