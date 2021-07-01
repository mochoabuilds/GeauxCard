// GeauxCards methods, with details to follow

#include "account.h"
#include "geaux.h"

const double START_UP_FEE = 1.00; // Fee for building GeauxCard

const double INCREMENT_FEE = 0.25; // Fee for adding funds to existing GeauxCard

double GeauxCard::outstandingFunds = 0.0; // construction of static data member

int GeauxCard::cash(double amount)
{
    if (amount > balance)
        return 0;
    else {
        outstandingFunds -= amount;
        balance -= amount;
        return 1;
    } // endif
} // end Cash

// overloading operator +=
void GeauxCard::operator += (double amount)
{
    double fee;
    if (balance <= 0.0) // charge re-up fee
        fee = START_UP_FEE;
    else
        fee = INCREMENT_FEE;
    double temp = balance + amount-fee;

    // see if parameter is enough to cover fee
    if (temp >= 0)
    {
        // decrement outstandingFunds by card's old balance
        outstandingFunds -= balance;
        balance = temp;
        // increment outstandingFunds by card's new balance
        outstandingFunds += balance;
    }
    else { // amount added to card cannot cover fee
    } // endif
    return;
}

// update receiving object's balance and update outstanding funds
void GeauxCard::operator= (const GeauxCard& rhs)
{
    // decrement outstandingFunds by card's old balance
    outstandingFunds -= balance;
    balance = rhs.balance;
    // increment outstandingFund's by card's new balance
    outstandingFunds += balance;
    return;
}

double GeauxCard::retrieveBalance(void)
{
    return balance;
}

double GeauxCard::outstandingDebt(void)
{
    return outstandingFunds;
}

double GeauxCard::startUpFee(void)
{
    return START_UP_FEE;
}

double GeauxCard::incrementFee(void)
{
    return INCREMENT_FEE;
}

// conversion operator to convert from a GeauxCard to an Account
GeauxCard::operator Account(void) {
    // construct an account with opening balance equal to card's cash value
    return Account(balance);
}

// constructor to convert from account to GeauxCard
GeauxCard::GeauxCard(Account anExistingAccount):
    balance(anExistingAccount.retrieveBalance() - START_UP_FEE)
{
    outstandingFunds += balance;
    return;
}

// constructor with purchaseAmount parameter
GeauxCard::GeauxCard(double purchaseAmount):
    balance(purchaseAmount - START_UP_FEE)
{
    // increment outstandingFunds by card's balance
    outstandingFunds += balance;
    return;
}

// copy constructor
GeauxCard::GeauxCard(const GeauxCard& anExistingCard):
    balance(anExistingCard.balance)
{
    outstandingFunds += balance;
    return;
}

// default - parameterless constructor
GeauxCard::GeauxCard(void):balance(0.0)
{
    return;
}

// destructor
GeauxCard::~GeauxCard(void) {
    // destroying card means funds no longer exist
    outstandingFunds -= balance;
    return;
}







