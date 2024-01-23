#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>

using namespace std;

//Class used in project

class account
{
    int acno;
    char name[50];
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