// ATM.h
// ATM class definition. Represents an automated teller machine.
#ifndef ATM_H
#define ATM_H

#include "Screen.h" // Screen class definition
#include "Keypad.h" // Keypad class definition
#include "CashDispenser.h" // CashDispenser class definition
#include "DepositSlot.h" // DepositSlot class definition
#include "BankDatabase.h" // BankDatabase class definition
class Transaction; // forward declaration of class Transaction

class ATM
{
public:
   ATM(); // constructor initializes data members
   void run(); // start the ATM
private:
   bool userAuthenticated; // whether user is authenticated
   int currentAccountNumber; // current user's account number
   Screen screen; // ATM's screen
   Keypad keypad; // ATM's keypad
   CashDispenser cashDispenser; // ATM's cash dispenser
   DepositSlot depositSlot; // ATM's deposit slot
   BankDatabase bankDatabase; // account information database

   // private utility functions
   void authenticateUser(); // attempts to authenticate user
   void performTransactions(); // performs transactions
   int displayMainMenu() const; // displays main menu

   // return object of specified Transaction derived class
   Transaction *createTransaction( int ); 
}; // end class ATM

#endif // ATM_H


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
