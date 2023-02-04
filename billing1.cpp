#include <iostream>
#include <fstream>

using namespace std;

class shopping
{
private:
    int pcode;
    float price;
    float dis;
    string pname;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
};

void shopping ::menu()
{
    int choice;
    string email;
    string password;

    cout << "\t\t\t\t------------------------------------------------------\n";
    cout << "\t\t\t\t--------------SuperMarket System Menu------------------\n";
    cout << "\t\t\t\t------------------------------------------------------\n";

    cout << "\t\t\t\t 1) Administrator|\n";
    cout << "\t\t\t\t                 |\n";
    cout << "\t\t\t\t 2) Client|\n";
    cout << "\t\t\t\t                 |\n";
    cout << "\t\t\t\t 3) Exit         | \n";
    cout << "\t\t\t\t                 |\n";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "\t\t\t\t Please Login \n";
        cout << "\t\t\t\t Enter Email \n";
        cin >> email;
        cout << " Enter Your Password .....";
        cin >> password;

        if (email = "admin@gmail" &&password = "admin")
        {
            administrator();
        }
        else
        {
            cout << "Invalid username or password";
        }
        break;

    case 2:
    {
        buyer();
    }
    case 3:
    {
        exit(0);
    }
    default:{
        cout << "enter a valid choice";
    }
    }
}
