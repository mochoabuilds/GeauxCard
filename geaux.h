// GeauxCard permits withdrawals only (eventually linked to autonomous checkout)

#ifndef GEAUX_H
#define GEAUX_H

class Account;
class GeauxCard
{
public:
    // Modifiers
    int cash(double amount);
        // amount is positive
        // deducts amount from card
        // returns 1 for yes and 0 for no
    void operator += (double incrementAmount);
        // throttles cash supply
        // $ - small re-up fee for this service
        // incrementAmount is positive
        // increases card's worth if amount is greater than re-up fee
    void operator= (const GeauxCard & rhs); // assignment operator
        // turns object enacting method into copy of rhs/right hand side

    // Accessors
    double retrieveBalance(void);
        // returns remaining balance on GeauxCard
    static double outstandingDebt(void);
        // returns total of all balances on existing cards
    double startUpFee(void);
        // returns small re-up fee for making new GeauxCard
    double incrementFee(void);
        // return fee for adding funds to existing GeauxCard

    // Conversion Members
    operator Account(void);
        // type cast from a GeauxCard object to an Account object

    // Constructors
    GeauxCard(double purchasePrice);
        // purchasePrice > re-up fee
        // creates a GeauxCard with some of purchasePrice used for initialization fees
    GeauxCard(Account anExistingAccount); // conversion constructor
        // type casts from an Account object to a GeauxCard object
    GeauxCard(const GeauxCard & anExistingCard);  // copy constructor
    GeauxCard(void); // default constructor
        // creates a GeauxCard with no money
    ~GeauxCard(void); // destructor
        // destroys card
        // updates outstanding total debt on existing cards

private:
    double balance; // cash value of card
    static double outstandingFunds;  // total debt on all cards
    //
};
#endif
