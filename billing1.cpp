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

void supermarket::ShowProduct()
{
    cout << "\n The Item number of thr product: " << itemNo;
    cout << "\n The name of the product : ";
    cout << name;
    cout << "\n The price of the product : " << price;
    cout << "\n Discount : " << dis;
}

void supermarket::InputFile()
{
    f.open("/home/supermarket_billing_system/Store.txt", ios::out | ios::app);
    s.AddProduct();
    f.write((char *)&s, sizeof(supermarket));
    f.close();
    cout << "\n\n The Has been created \n";
}

void supermarket::Display()
{
    system("clear");
    cout << "\n\n\n\t\t Displaying all records!!!\n\n";
    f.open("home/supermarket_billing_system/Store.txt", ios::in);
    int flag;
    flag = 0;
    while(flag==0)
    {
        if(!f.eof()){
            flag == 0;
            f.read((char *)&s, sizeof(supermarket));
            s.ShowProduct();
        }
        else
            flag == 1;
    }
    f.close();
}

void supermarket::DisplaySpecific(int n)
{
    int flag = 0;
    f.open("home/supermarket_billing_system/Store.txt", ios::in);
    while(f.read((char*)&s, sizeof(supermarket))){
        if(s.itemNo == n){
            system("clear");
            s.ShowProduct();
            flag = 1;
        }
    }
    f.close();
    if(flag ==0)
        cout << "\n\n\nrecord doesn't exist";
}

void supermarket::Update(){
    int no, found;
    found = 0;
    system("clear");
    cout << "\n\n\tTo modify";
    cout << "\n\n\t Enter The item Number to modify";
    cin >> no;
    f.open("home/supermarket_billing_system/Store.txt", ios::in | ios::out);
    while(f.read((char*)&s, sizeof(supermarket)) && found==0)
    {
        if(s.itemNo==no)
        {
            s.ShowProduct();
            cout << "\nEnter The new Details of Product" << endl;
            s.AddProduct();
            int pos = 1 * sizeof(s);
            f.seekp(pos, ios::cur);
            f.write((char *)&s, sizeof(supermarket));
            cout << "\n\n\t Record Update";
            found = 1;
        }
    }
    f.close();
    if(found==0)
        cout << "\n\n Record Not Found";
}

void supermarket::Delete(){
    int no;
    system("clear");
    cout << "\n\n\n\n\tDelete Record";
    cout << "\n\nEnter the Item number you want to delete";
    cin >> no;
    f.open("home/supermarket_billing_system/Store.txt", ios::in | ios::out);
    fstream f2;
    f2.open("home/supermarket_billing_system/Store.txt", ios::out);
    f.seekg(0, ios::beg);
    while(f.read((char*)&s, sizeof(supermarket)))
    {
        if(s.itemNo!=no){
            f2.write((char *)&s, sizeof(supermarket));
        }
    }
    f2.close();
    f.close();
    remove("home/supermarket_billing_system/Store.txt");
    rename("home/supermarket_billing_system/Store.txt", "home/supermarket_billing_system/Store.txt");
    cout << "\n\n\n\tRecord Deleted";
}

void supermarket::Menu()
{
    system("clear");
    f.open("home/supermarket_billing_system/Store.txt", ios::in);
    if(!f){
        cout << "ERROR!! file could not be opened \n\n\n Go to Admin to create file";
        cout << "\n\n\n Program is closing....";
        exit(0);
    }
    cout << "\n\n\t\tProduct MENU\n\n";
    cout<<"=======================================\n";
cout<<"ITEM.NO.\t\tNAME\t\tPRICE\n";
cout<<"============================================\n";

while(f.read((char*)&s, sizeof(supermarket)))
{
        cout << s.itemNo << "\t\t" << s.name << "\t\t" << s.price << endl;
}
f.close();
}



