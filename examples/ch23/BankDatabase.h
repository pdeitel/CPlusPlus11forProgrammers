// BankDatabase.h
// BankDatabase class definition. Represents the bank's database.
#ifndef BANK_DATABASE_H
#define BANK_DATABASE_H

#include <vector> // class uses vector to store Account objects
#include "Account.h" // Account class definition
using namespace std;

class BankDatabase
{
public:
   BankDatabase(); // constructor initializes accounts

   // determine whether account number and PIN match those of an Account
   bool authenticateUser( int, int ); // returns true if Account authentic

   double getAvailableBalance( int ); // get an available balance
   double getTotalBalance( int ); // get an Account's total balance
   void credit( int, double ); // add amount to Account balance
   void debit( int, double ); // subtract amount from Account balance
private:
   vector< Account > accounts; // vector of the bank's Accounts

   // private utility function
   Account * getAccount( int ); // get pointer to Account object
}; // end class BankDatabase

#endif // BANK_DATABASE_H


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
