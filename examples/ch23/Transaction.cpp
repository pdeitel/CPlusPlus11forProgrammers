// Transaction.cpp
// Member-function definitions for class Transaction.
#include "Transaction.h" // Transaction class definition
#include "Screen.h" // Screen class definition
#include "BankDatabase.h" // BankDatabase class definition

// constructor initializes common features of all Transactions
Transaction::Transaction( int userAccountNumber, Screen &atmScreen, 
   BankDatabase &atmBankDatabase )
   : accountNumber( userAccountNumber ),
     screen( atmScreen ),
     bankDatabase( atmBankDatabase )
{
   // empty body
} // end Transaction constructor

// return account number 
int Transaction::getAccountNumber() const
{
   return accountNumber; 
} // end function getAccountNumber

// return reference to screen
Screen &Transaction::getScreen() const
{
   return screen;
} // end function getScreen

// return reference to bank database
BankDatabase &Transaction::getBankDatabase() const
{
   return bankDatabase;
} // end function getBankDatabase


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
