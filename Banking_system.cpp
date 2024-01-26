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

//function declaration
void write_account();  //function to write record in binary file
void display_sp(int);  //function to display acc details given by user
void modify_account(int); //function to modify record or file
void delete_account(int); //function to delete record or file
void display_all();  //function to display all accounts details
void deposit_withdraw(int, int); //function to deposit/withdraw amount for given account
void intro(); //introductory screen function

//main fonction

int main()
{
    char ch; //hold choice in switch case
    int num; //
    intro();
    do
    {
        system("cls");
		cout<<"\n\n\n\t MAIN MENU";
		cout<<"\n\n\t 01. NEW ACCOUNT";
		cout<<"\n\n\t 02. DEPOSIT AMOUNT";
		cout<<"\n\n\t 03. WITHDRAW AMOUNT";
		cout<<"\n\n\t 04. BALANCE ENQUIRY";
		cout<<"\n\n\t 05. LIST OF ALL ACCOUNT HOLDERS";
		cout<<"\n\n\t 06. CLOSE AN ACCOUNT";
		cout<<"\n\n\t 07. MODIFY AN ACCOUNT";
		cout<<"\n\n\t 08. EXIT";
		cout<<"\n\n\t Enter Your Option (1-8): ";
		cin>>ch;
		system("cls");

        switch (ch)
        {
        case '1':
            write_account();
            break;
        case '2':
			cout<<"\n\n\t Enter The account No. : "; cin>>num;
			deposit_withdraw(num, 1);
			break;
		case '3':
			cout<<"\n\n\t Enter The account No. : "; cin>>num;
			deposit_withdraw(num, 2);
			break;
		case '4': 
			cout<<"\n\n\t Enter The account No. : "; cin>>num;
			display_sp(num);
			break;
		case '5':
			display_all();
			break;
		case '6':
			cout<<"\n\n\t Enter The account No. : "; cin>>num;
			delete_account(num);
			break;
		 case '7':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			modify_account(num);
			break;
		 case '8':
			cout<<"\n\n\t Thanks for using bank managemnt system! ";
			break;
		 default:
            cout << "\nInvalid option! Please enter a valid option between 11 and 8.\n";
		}
		cin.ignore();
		cin.get();
	}while(ch!='8');
	return 0;
}





