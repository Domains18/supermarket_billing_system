#include <iostream>
#include <stdlib.h>
#include <fstream>
/*------------Headers-------------*/

using namespace std;

class supermarket
{
public:
    int xz;

    supermarket()
    {
        xz = 0;
    }
    int itemNo;
    string name;
    float price, qty, tax, dis;
    void AddProduct();
    void ShowProduct();
    void InputFile();
    void Display();
    void DisplaySpecific(int n);
    void Update();
    void Delete();
    void Menu();
    void AdminMenu();
    void PlaceOrder();
    void intro();
};
fstream f;
supermarket s;

void supermarket::AddProduct()
{
    cout << "\n Enter the Item number of the product";
    cin >> itemNo;
    cout << "\n Enter Name of The Product";
    cin >> name;
    cout << "\n Enter the price of the Product";
    cin >> price;
    cout << "Discount? (%)";
    cin >> dis;
    xz = xz + 1;
}

