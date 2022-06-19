// note: withdrawals only

#ifndef GEAUX_H
#define GEAUX_H

class Account;
class GeauxCard
{
public:
    // Modifiers
    int cash(double amount);
        // amount is positive
        // deducts amount from tickets
        // returns 1 for yes and 0 for no
    void operator += (double incrementAmount);
        // throttles ticket supply
        // incrementAmount is positive
        // increases tickets worth if amount is greater than 
    void operator= (const GeauxCard & rhs); // assignment operator
        // turns object enacting method into copy of rhs 

    // Accessors
    double retrieveBalance(void);
        // returns remaining balance of tickets
    static double outstandingDebt(void);
        // returns total of all balances on existing tickets
    double startUpFee(void);
        // returns small re-up fee for making bag for tickets
    double incrementFee(void);
        // nominal return fee for adding funds to existing GeauxCard

    // Conversion Members
    operator Account(void);
        // type cast from a ticket object to an Account object

    // Constructors
    GeauxCard(double purchasePrice);
        // purchasePrice > re-up fee
        // creates tickets with some of purchasePrice used for initialization fees
    GeauxCard(Account anExistingAccount); // conversion constructor
        // type casts from an Account object to a GeauxCard object
    GeauxCard(const GeauxCard & anExistingCard);  // copy constructor
    GeauxCard(void); // default constructor
        // creates bag with no tickets
    ~GeauxCard(void); // destructor
        // destroys card
        // updates outstanding total debt on existing cards

private:
    double balance; // ticket value of bag
    static double outstandingFunds;  // total debt on all bags
    //
};
#endif
