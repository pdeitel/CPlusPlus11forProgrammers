// Deposit.h
// Deposit class definition. Represents a deposit transaction.
#ifndef DEPOSIT_H
#define DEPOSIT_H

#include "Transaction.h" // Transaction class definition
class Keypad; // forward declaration of class Keypad
class DepositSlot; // forward declaration of class DepositSlot

class Deposit : public Transaction
{
public:
   Deposit( int, Screen &, BankDatabase &, Keypad &, DepositSlot & );
   virtual void execute(); // perform the transaction
private:
   double amount; // amount to deposit
   Keypad &keypad; // reference to ATM's keypad
   DepositSlot &depositSlot; // reference to ATM's deposit slot
   double promptForDepositAmount() const; // get deposit amount from user
}; // end class Deposit

#endif // DEPOSIT_H


/**************************************************************************
 * (C) Copyright 1992-2014 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/
