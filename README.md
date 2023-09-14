# Banking System in C++

This repository contains a simple C++ program for a basic banking system with user and administrator functionalities. It allows users to open accounts, check account details, deposit and withdraw money, and administrators to open, find, and close accounts.

## Table of Contents

- [Features](#features)
- [Classes](#classes)
- [Usage](#usage)
- [License](#license)
- [Author](#author)

## Features

- **User Features:**
  - Open an account.
  - Check account details.
  - Deposit money into an account.
  - Withdraw money from an account.
  - Check account balance.

- **Admin Features:**
  - Open a new account.
  - Find account details.
  - Close an account.

## Classes

### 1. User

- `Display_AcDetails(int no)`: Displays account details for a given account number.
- `Find_Ac(int no)`: Searches for an account and returns whether it was found or not.
- `Deposit_Amt(int no)`: Deposits an amount into the account.
- `Withdraw_Amt(int no)`: Withdraws an amount from the account, provided there are sufficient funds.
- `Check_Balance(int no)`: Displays the account balance.

### 2. Admin (inherits from User)

- `Open_Ac()`: Opens a new account and initializes its details.
- `Close_Ac(int no)`: Closes an account by resetting its values.

### 3. Bank (inherits from Admin)

- `LoginMenu()`: Displays the main login menu for users and administrators.

## Usage

Upon running the program, you will be presented with a login menu that allows you to choose between user and administrator options. Follow the prompts to perform various banking operations.

## License

This project is licensed under the MIT License - see the [LICENSE](https://github.com/ArjunPramod/Banking-System-CPP/blob/main/LICENSE) file for details.

## Author

[Arjun Pramod](https://github.com/ArjunPramod)