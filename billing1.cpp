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

void supermarket::PlaceOrder(){
int order[50], quan[50], c = 0;
float amt, damt, total = 0;
char ch = 'Y';
Menu();
cout<<"\n============================";
cout<<"\n PLACE YOUR ORDER";
cout<<"\n============================\n";
do{
        cout << "\n\nEnter The Product number : ";
        cin >> order[c];
        cout << "\nQuality in number : ";
        cin >> quan[c];
        c++;
        cout << "\n\nDo you want to order Another Product?: ";
        cin >> ch;
} while (ch == 'y' || ch == 'Y');
cout << "\n\nThank You for placing the order";
system("clear");
cout<<"\n\n*********************INVOICE*********\n";
cout<<"\nItem No.\tItem Name\tQuantity \tPrice \tAmount \tAmount after discount\n";
for (int x = 0; x = c;x++){
        f.open("home/supermarket_billing_system/Store.txt", ios::in);
        f.read((char *)&s, sizeof(supermarket));
        while(!f.eof()){
            if(itemNo==order[x]){
                amt = s.price * quan[x];
                damt = amt - (amt * s.dis / 100);
                cout << "\n"
                     << order[x] << "\t" << s.name << "\t" << quan[x] << "\t\t"
                     << "\t\t" << s.price << "\t" << amt << "\t\t" << damt;
                total += damt;
            }
            f.read((char *)&s, sizeof(supermarket));
        }
        f.close();
    }
    cout << "\n\n\t\t\t\t\tTotal = " << total;
}

void supermarket::intro(){
    system("clear");
    cout << "\t\t\t\t";
    cout << "BILLING";
    cout << "\t\t\t\t";
    cout << "PROJECT";
    cout << "\n Made By: Gibsons Gibson";
}
void supermarket::AdminMenu(){
    system("clear");
    char ch2;
    cout << "\n\n\n\tADMIN MENU";
    cout << "\n\n\t1.CREATE PRODUCT";
    cout << "\n\n\t2.DISPLAY ALL PRODUCTS";
    cout << "\n\n\t3.QUERY ";
    cout << "\n\n\t4.MODIFY PRODUCT";
    cout << "\n\n\t5.DELETE PRODUCT";
    cout << "\n\n\t6.VIEW PRODUCT MENU";
    cout << "\n\n\t7.BACK TO MAIN MENU";
    cout << "\n\n\tPlease Enter Your Choice (1-7) ";
    cin >> ch2;
    switch(ch2){
        case '1':
            system("clear");
            AddProduct();
            break;
        case '2':
            Display();
            break;
        case '3':
            int num;
            system("clear");
            cout << "\n\n\tPlease Enter The Product No. ";
            cin >> num;
            DisplaySpecific(num);
            break;
        case '4':
            Update();
            break;
        case '5':
            Delete();
            break;
        case '6':
            Menu();
            break;
        case '7':
            break;
        default:
            cout << "\a";
            AdminMenu();
    }
}
int main(){
    char ch;
    s.intro();
    do{
            cout << "\n\n\n\tMAIN MENU";
            cout << "\n\n\n\t01. CUSTOMER";
            cout << "\n\n\n\t03. EXIT";
            cout << "\n\n\tPlease Select Your Option (1-3)";
            cin >> ch;
            switch(ch){
                case '1': system("clear");
                    s.PlaceOrder();
                    break;
                
                case '2' :
                    s.AdminMenu();
                    break;
                
                case '3' :
                    exit(0);
                    default :
                    cout << "\a";
                    
            } 
        }while(ch!='3');
            return 0;
    }
