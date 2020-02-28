// CashDispenser.cpp
// Member-function definitions for class CashDispenser.
#include "CashDispenser.h" // CashDispenser class definition

// CashDispenser default constructor initializes count to default
CashDispenser::CashDispenser()
{
   count = INITIAL_COUNT; // set count attribute to default
} // end CashDispenser default constructor

// simulates dispensing of specified amount of cash; assumes enough cash 
// is available (previous call to isSufficientCashAvailable returned true)
void CashDispenser::dispenseCash( int amount )
{
   int billsRequired = amount / 20; // number of $20 bills required
   count -= billsRequired; // update the count of bills
} // end function dispenseCash

// indicates whether cash dispenser can dispense desired amount
bool CashDispenser::isSufficientCashAvailable( int amount ) const
{
   int billsRequired = amount / 20; // number of $20 bills required

   if ( count >= billsRequired )
      return true; // enough bills are available
   else 
      return false; // not enough bills are available
} // end function isSufficientCashAvailable


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
