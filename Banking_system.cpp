#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>

using namespace std;

//Class used in project

class account
{
    int acno;
    int age;
    char name[50];
    char surname[50];
    int deposit;
    char type;

    public:
    void create_account(); //function to get data from user
    void show_account() const; //function to show data on screen
    void modify(); //function to add new data
    void dep(int); //function to accept amount and add to balance amount
    void draw(int); //function to accept amount and subs from balance amount
    void report() const; //function to show data in a tubular format
    void retacno() const; //function to return account number
    void retdeposit() const; //function to return balance amount
    void rettype() const; //function to return type of amount 
};

//function to get data from user
void account::create_account()
{
    cout<<"Please enter your account number: ";
    cin>>acno;
    cout<<"Enter your name: ";
    cin.ignore();
    cin.getline(name,50);
    cout<<"Enter your surname: ";
    cin.ignore();
    cin.getline(surname,50);
    cout<<"Enter your age: ";
    cin>>age;
    cout<<"Enter type of the account (C/S)";
    cin>>type;
    type=toupper(type);
    cout<<"Enter the initail amount(>=500 for Saving and >=200 for current) : ";
    cin>>deposit;
    cout<<"Your account is successfully created..";
}

//function to show data on screen
