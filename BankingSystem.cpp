#include <bits/stdc++.h>
#include <string>
#include <conio.h>
#define N 100

using namespace std;

int ID = 1;

// Account Structure

struct Account
{
    int No, Age, Contact;
    string Name, Gender, Type;
    float Balance;
};

struct Account Ac[N];

// Class declrations

class User
{
    public:
    void Display_AcDetails(int no);
    int Find_Ac(int no);
    void Deposit_Amt(int no);
    void Withdraw_Amt(int no);
    void Check_Balance(int no);
};

class Admin: public User
{
    public:
    void Open_Ac();
    void Close_Ac(int no);
};

class Bank: public Admin
{
    void UserMenu();
    void AdminMenu();

    public:
    void LoginMenu();
};


// User class Function declarations

void User::Display_AcDetails(int no)
{
    int found = Find_Ac(no);
    if(found == 1)
    {
        cout << "\nAccount Details" << endl;
        cout << "---------------\n" << endl;
        cout << "Account no: " << Ac[no].No << endl;
        cout << "Name: " << Ac[no].Name << endl;
        cout << "Age: " << Ac[no].Age << endl;
        cout << "Contact no: " << Ac[no].Contact << endl;
        cout << "Gender: " << Ac[no].Gender << endl;
        cout << "Account type: " << Ac[no].Type << endl;
        cout << "Balance: " << Ac[no].Balance << endl;
    }
    else if(found == 2)
        cout << "\nSorry Account " << Ac[no].No << " was deleted" << endl;
    
    else
        cout << "\nSorry Account " << Ac[no].No << " was not found" << endl;

    cout << "\n\t\tPress ENTER to continue...";
    getch();
}

int User::Find_Ac(int no)
{
    int found = 0;
    if(no <= ID) // Account exists in created accounts
    {
        if(Ac[no].No = no) // Account exist presently
            found = 1;
        else                   // Account got deleted
            found = 2; 
    }
    return found;
}

void User::Deposit_Amt(int no)
{
    float amount;
    cout << "\nEnter amount to deposit: ";
    cin >> amount;

    Ac[no].Balance += amount;
    cout << "\n\nDeposit Successful" << endl;
    cout << "\nCurrent Balance: " << Ac[no].Balance << endl;

    cout << "\n\t\tPress ENTER to continue...";
    getch();
}

void User::Withdraw_Amt(int no)
{
    float amount;

    cout << "\nEnter amount: ";
    cin >> amount;

    if(amount <= Ac[no].Balance)
    { 
        Ac[no].Balance -= amount;
        cout << "\nWithdrawal Successful" << endl;
    }
    else  // When Insufficient Balance in account
    {
        cout << "\nWithdrawal Unsuccessful" << endl;
    }
    cout << "\nCurrent Balance: " << Ac[no].Balance << endl;

    cout << "\n\t\tPress ENTER to continue...";
    getch();
}

void User::Check_Balance(int no)
{
    cout << "\n\nBalance: " << Ac[no].Balance << endl;
    
    cout << "\n\t\tPress ENTER to continue...";
    getch();
}

// Admin class Function declarations

void Admin::Open_Ac()
{
    Ac[ID].No = ID;
    cout << "\nEnter Name: ";
    cin >> Ac[ID].Name;
    cout << "Enter Age: ";
    cin >> Ac[ID].Age;
    cout << "Enter Gender: ";
    cin >> Ac[ID].Gender;
    cout << "Enter Contact no: ";
    cin >> Ac[ID].Contact;
    cout << "Enter Account type: ";
    cin >> Ac[ID].Type;
    cout << "Enter Initial deposit: ";
    cin >> Ac[ID].Balance;
    ID++;

    cout << "\n\n\t\tACCOUNT CREATED" << endl;
    cout << "\n\t\tPress ENTER to continue...";
    getch();
}

void Admin::Close_Ac(int no)
{
    Ac[no].No = 0;
    Ac[no].Name = "";
    Ac[no].Age = 0;
    Ac[no].Gender = "";
    Ac[no].Contact = 0;
    Ac[no].Type = "";
    Ac[no].Balance = 0;

    cout << "\n\t\tACCOUNT CLOSED" << endl;
    cout << "\n\t\tPress ENTER to continue...";
    getch();
}


// Bank class Function declarations

void Bank::LoginMenu()
{
    system("cls");
    cout << endl;
    cout << "\t\t+------------------+" << endl;
    cout << "\t\t|    LOGIN MENU    |" << endl;
    cout << "\t\t|------------------|" << endl;
    cout << "\t\t| 1. User          |" << endl;
    cout << "\t\t| 2. Admin         |" << endl;
    cout << "\t\t| 9. Exit          |" << endl;
    cout << "\t\t+------------------+" << endl;

    char chs;
    cout << "\n\t\tEnter your choice: ";
    cin >> chs;

    switch(chs)
    {
    case '1': UserMenu(); break;

    case '2': AdminMenu(); break;

    case '9': exit(0);

    default: 
        cout << "\n\t\tInvalid entry! Try again" << endl;
        cout << "\n\t\tPress ENTER to continue...";
        getch();
        break;
    }
    LoginMenu();
}

void Bank::UserMenu()
{
    system("cls");
    cout << endl;
    cout << "\t\t+--------------------------+" << endl;
    cout << "\t\t|        USER MENU         |" << endl;
    cout << "\t\t|--------------------------|" << endl;
    cout << "\t\t| 1. Deposit amount        |" << endl;
    cout << "\t\t| 2. Withdraw amount       |" << endl;
    cout << "\t\t| 3. Check balance         |" << endl;
    cout << "\t\t| 4. Account Details       |" << endl;
    cout << "\t\t| 9. Go back to Login Menu |" << endl;
    cout << "\t\t+--------------------------+" << endl;

    char chs;
    cout << "\n\t\tEnter your choice: ";
    cin >> chs;

    if(chs != '9')
    {
        int no;
        cout << "\n\t\tEnter your Account no: ";
        cin >> no;

        User user;
        int found = user.Find_Ac(no);
        if(found == 1)
        {
            switch(chs)
            {
            case '1': user.Deposit_Amt(no); break;

            case '2': user.Withdraw_Amt(no); break;

            case '3': user.Check_Balance(no); break;

            case '4': user.Display_AcDetails(no); break;

            case '9': LoginMenu(); break;
                
            default:
                cout << "\n\t\tInvalid entry! Try again" << endl;
                cout << "\n\t\tPress ENTER to continue...";
                getch();
                break;
            }
        }

        else user.Display_AcDetails(no);
    }
    else LoginMenu();

    UserMenu();
}

void Bank::AdminMenu()
{
    system("cls");
    cout << endl;
    cout << "\t\t+--------------------------+" << endl;
    cout << "\t\t|        ADMIN MENU        |" << endl;
    cout << "\t\t|--------------------------|" << endl;
    cout << "\t\t| 1. Open Account          |" << endl;
    cout << "\t\t| 2. Find Account          |" << endl;
    cout << "\t\t| 3. Close Account         |" << endl;
    cout << "\t\t| 9. Go back to Login Menu |" << endl;
    cout << "\t\t+--------------------------+" << endl;

    char chs;
    int no;
    cout << "\n\t\tEnter your choice: ";
    cin >> chs;

    Admin admin;
    switch(chs)
    {
    case '1': admin.Open_Ac(); break;

    case '2': 
        cout << "\nEnter Account no: ";
        cin >> no;
        admin.Display_AcDetails(no);
        break;

    case '3':
        cout << "\nEnter Account no: ";
        cin >> no;
        admin.Close_Ac(no);
        break;

    case '9': LoginMenu(); break;
        
    default:
        cout << "\n\t\tInvalid entry! Try again" << endl;
        cout << "\n\t\tPress ENTER to continue...";
        getch();
        break;
    }
    AdminMenu();
}

// Driver Code

int main()
{
    Bank SBI;
    SBI.LoginMenu();
    return 0;
}

