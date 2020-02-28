// CashDispenser.h
// CashDispenser class definition. Represents the ATM's cash dispenser.
#ifndef CASH_DISPENSER_H
#define CASH_DISPENSER_H

class CashDispenser
{
public:
   CashDispenser(); // constructor initializes bill count to 500

   // simulates dispensing of specified amount of cash
   void dispenseCash( int ); 

   // indicates whether cash dispenser can dispense desired amount
   bool isSufficientCashAvailable( int ) const;
private:
   static const int INITIAL_COUNT = 500;
   int count; // number of $20 bills remaining 
}; // end class CashDispenser

#endif // CASH_DISPENSER_H


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
