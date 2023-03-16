This is a C++ program for a simple banking system with basic features such as opening an account, checking account details, depositing and withdrawing amounts, and closing an account.

The program consists of three classes: Bank, Admin, and User. The Bank class is the main class, and it inherits from the Admin class, which in turn inherits from the User class. The Bank class contains the LoginMenu function that displays the login options for the user and admin.

The Admin class has two functions: Open_Ac and Close_Ac. The Open_Ac function creates a new account and stores its details in an array of account structures. The Close_Ac function deletes an account by setting all its values to zero.

The User class has four functions: Display_AcDetails, Find_Ac, Deposit_Amt, Withdraw_Amt, and Check_Balance. The Display_AcDetails function displays the details of a given account. The Find_Ac function searches for an account in the array and returns a value indicating whether it was found or not. The Deposit_Amt function deposits an amount in the account. The Withdraw_Amt function withdraws an amount from the account, provided there are sufficient funds. The Check_Balance function displays the balance in the account.

The main function creates an object of the Bank class and calls its LoginMenu function. The LoginMenu function displays the login options and calls the appropriate function based on the user's choice. The program uses the conio.h library to get input from the user without waiting for the user to press the Enter key.
