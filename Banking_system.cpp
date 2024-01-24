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
    cin.getline(surname,50);
    cout<<"Enter your age: ";
    cin>>age;
    cout<<"Enter type of the account (C/S)";
    cin>>type;
    type=toupper(type);

     while (type != 'C' && type != 'S')
    {
        cout << "Invalid account type! Please enter 'C' or 'S': ";
        cin >> type;
        type = toupper(type);
    }

    cout<<"Enter the initail amount(>=500 for Saving and >=200 for current) : ";
    cin>>deposit;

     while (deposit < 0)
    {
        cout << "Invalid deposit amount! Please enter a non-negative value: ";
        cin >> deposit;
    }

    cout<<"Your account is successfully created..";
}

//function to show data on screen
void account::show_account() const
{
    cout<<"Account Number: "<<acno<<endl;
    cout<<"Account holder name: "<<name<<endl;
    cout<<"Account holder surname: "<<surname<<endl;
    cout<<"Your age: "<<age<<endl;
    cout<<"Type of account: "<<type<<endl;
    cout<<"Balance: "<<deposit<<endl;
}

//function to add new data
void account::modify()
{
    cout<<"Account Number: "<<acno<<endl;
	cout<<"Modify Account Holder Name : "<<endl;
	cin.ignore();
	cin.getline(name,50);
    cout<<"Modify Account Holder Surname : "<<endl;
	cin.getline(surname,50);
    cout<<"Modify Age of Account holder: "<<endl;
	cin>>age;
	cout<<"Modify Type of Account : "<<endl;
	cin>>type;
	type=toupper(type);
    while (type != 'C' && type != 'S')
    {
        cout << "Invalid account type! Please enter 'C' or 'S': ";
        cin >> type;
        type = toupper(type);
    }

    cout << "Do you want to modify the balance? (Y/N): ";
    char choice;
    cin >> choice;
    if (toupper(choice) == 'Y')
    {
        cout << "Enter the new balance: ";
        cin >> deposit;

        while (deposit < 0)
        {
            cout << "Invalid deposit amount! Please enter a non-negative value: ";
            cin >> deposit;
        }
    }
}

void account::dep(int x)
{
	deposit+=x;
}
	
void account::draw(int x)
{
	deposit-=x;
}
	
void account::report() const
{
  cout << setw(10) << left << acno << setw(20) << left << name
         << setw(10) << left << surname << setw(5) << left << age
         << setw(5) << left << type << setw(10) << left << deposit << endl;
}

	
int account::retacno() const
{
	return acno;
}

int account::retdeposit() const
{
	return deposit;
}

char account::rettype() const
{
	return type;
}




