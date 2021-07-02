//
// Created by M on 7/1/2021.
//

#include "account.h"

const char KEY = '\x09'; // bit pattern

// bug - unknown type name
const String DEFAULT_PASSWORD = "pizzerias";
const int DUMMY_ID = 0;

class String;

// bug - undeclared identifier
Account::Account(double openingBalance)
{
    identificationNumber = DUMMY_ID;
    balance = openingBalance;
    this->setPassword(DEFAULT_PASSWORD);
    return;
}

// bug - undeclared identifier
Account::Account(int accountNumber, double openingBalance)
{
    identificationNumber = DUMMY_ID;
    balance = openingBalance;
    this -> setPassword(DEFAULT_PASSWORD);
    return;
}

// bug - undeclared identifier
Account::~Account(void)
{
    return;
}

// bug - undeclared identifier
void Account::setPassword(String newPassword)
{
    // set Account's password to newPassword
    codedPassword = codePassword(newPassword);
    return;
}

// bug - undeclared identifier
String Account::codePassword(String password) const
{
    // Set Account's codedPassword attribute to a coded form of password
    String temp = password;
        int n = password.length();
        int i;
        // using exclusive OR with KEY, codes the characters in one at a time
        for (i = 0; i <= n; i++)
        {
            char p;
            p = password[i];
        // use binary exclusive to code in the password
        char t = p^KEY;
        temp[i] = t;
        } // end for
        return temp;
}

// bug - undeclared identifier
int Account::validatePassword(String trialPassword) const
{
    String temp;
    temp = codePassword(trialPassword);
    if (temp == codedPassword) return 1;
    else                       return 0;
}

