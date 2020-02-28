// Withdrawal.cpp
// Member-function definitions for class Withdrawal.
#include "Withdrawal.h" // Withdrawal class definition
#include "Screen.h" // Screen class definition
#include "BankDatabase.h" // BankDatabase class definition
#include "Keypad.h" // Keypad class definition
#include "CashDispenser.h" // CashDispenser class definition

// global constant that corresponds to menu option to cancel
static const int CANCELED = 6;

// Withdrawal constructor initialize class's data members
Withdrawal::Withdrawal( int userAccountNumber, Screen &atmScreen, 
   BankDatabase &atmBankDatabase, Keypad &atmKeypad, 
   CashDispenser &atmCashDispenser )
   : Transaction( userAccountNumber, atmScreen, atmBankDatabase ),
     keypad( atmKeypad ), cashDispenser( atmCashDispenser )
{
   // empty body
} // end Withdrawal constructor

// perform transaction; overrides Transaction's pure virtual function
void Withdrawal::execute()
{
   bool cashDispensed = false; // cash was not dispensed yet
   bool transactionCanceled = false; // transaction was not canceled yet

   // get references to bank database and screen
   BankDatabase &bankDatabase = getBankDatabase(); 
   Screen &screen = getScreen();

   // loop until cash is dispensed or the user cancels
   do
   {
      // obtain the chosen withdrawal amount from the user 
      int selection = displayMenuOfAmounts();
      
      // check whether user chose a withdrawal amount or canceled
      if ( selection != CANCELED )
      {
         amount = selection; // set amount to the selected dollar amount

         // get available balance of account involved
         double availableBalance = 
            bankDatabase.getAvailableBalance( getAccountNumber() );
   
         // check whether the user has enough money in the account 
         if ( amount <= availableBalance )
         {   
            // check whether the cash dispenser has enough money
            if ( cashDispenser.isSufficientCashAvailable( amount ) )
            {
               // update the account involved to reflect withdrawal
               bankDatabase.debit( getAccountNumber(), amount );
               
               cashDispenser.dispenseCash( amount ); // dispense cash
               cashDispensed = true; // cash was dispensed

               // instruct user to take cash
               screen.displayMessageLine( 
                  "\nPlease take your cash from the cash dispenser." );
            } // end if
            else // cash dispenser does not have enough cash
               screen.displayMessageLine( 
                  "\nInsufficient cash available in the ATM."
                  "\n\nPlease choose a smaller amount." );
         } // end if
         else // not enough money available in user's account
         {
            screen.displayMessageLine( 
               "\nInsufficient funds in your account."
               "\n\nPlease choose a smaller amount." );
         } // end else
      } // end if
      else // user chose cancel menu option 
      {
         screen.displayMessageLine( "\nCanceling transaction..." );
         transactionCanceled = true; // user canceled the transaction
      } // end else
   } while ( !cashDispensed && !transactionCanceled ); // end do...while
} // end function execute

// display a menu of withdrawal amounts and the option to cancel;
// return the chosen amount or 0 if the user chooses to cancel
int Withdrawal::displayMenuOfAmounts() const
{
   int userChoice = 0; // local variable to store return value

   Screen &screen = getScreen(); // get screen reference
   
   // array of amounts to correspond to menu numbers
   int amounts[] = { 0, 20, 40, 60, 100, 200 };

   // loop while no valid choice has been made
   while ( userChoice == 0 )
   {
      // display the menu
      screen.displayMessageLine( "\nWithdrawal options:" );
      screen.displayMessageLine( "1 - $20" );
      screen.displayMessageLine( "2 - $40" );
      screen.displayMessageLine( "3 - $60" );
      screen.displayMessageLine( "4 - $100" );
      screen.displayMessageLine( "5 - $200" );
      screen.displayMessageLine( "6 - Cancel transaction" );
      screen.displayMessage( "\nChoose a withdrawal option (1-6): " );

      int input = keypad.getInput(); // get user input through keypad

      // determine how to proceed based on the input value
      switch ( input )
      {
         case 1: // if the user chose a withdrawal amount 
         case 2: // (i.e., chose option 1, 2, 3, 4 or 5), return the
         case 3: // corresponding amount from amounts array
         case 4:
         case 5:
            userChoice = amounts[ input ]; // save user's choice
            break;       
         case CANCELED: // the user chose to cancel
            userChoice = CANCELED; // save user's choice
            break;
         default: // the user did not enter a value from 1-6
            screen.displayMessageLine( 
               "\nIvalid selection. Try again." );
      } // end switch
   } // end while

   return userChoice; // return withdrawal amount or CANCELED
} // end function displayMenuOfAmounts


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
