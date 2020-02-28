// ATM.cpp
// Member-function definitions for class ATM.
#include "ATM.h" // ATM class definition
#include "Transaction.h" // Transaction class definition
#include "BalanceInquiry.h" // BalanceInquiry class definition
#include "Withdrawal.h" // Withdrawal class definition
#include "Deposit.h" // Deposit class definition

// enumeration constants represent main menu options
enum MenuOption { BALANCE_INQUIRY = 1, WITHDRAWAL, DEPOSIT, EXIT };

// ATM default constructor initializes data members
ATM::ATM() 
   : userAuthenticated ( false ), // user is not authenticated to start
     currentAccountNumber( 0 ) // no current account number to start
{
   // empty body
} // end ATM default constructor

// start ATM 
void ATM::run()
{
   // welcome and authenticate user; perform transactions
   while ( true )
   {
      // loop while user is not yet authenticated
      while ( !userAuthenticated ) 
      {
         screen.displayMessageLine( "\nWelcome!" );       
         authenticateUser(); // authenticate user
      } // end while
      
      performTransactions(); // user is now authenticated 
      userAuthenticated = false; // reset before next ATM session
      currentAccountNumber = 0; // reset before next ATM session 
      screen.displayMessageLine( "\nThank you! Goodbye!" );
   } // end while   
} // end function run

// attempt to authenticate user against database
void ATM::authenticateUser() 
{
   screen.displayMessage( "\nPlease enter your account number: " );
   int accountNumber = keypad.getInput(); // input account number
   screen.displayMessage( "\nEnter your PIN: " ); // prompt for PIN
   int pin = keypad.getInput(); // input PIN
   
   // set userAuthenticated to bool value returned by database
   userAuthenticated = 
      bankDatabase.authenticateUser( accountNumber, pin );
   
   // check whether authentication succeeded
   if ( userAuthenticated )
   {
      currentAccountNumber = accountNumber; // save user's account #
   } // end if
   else
      screen.displayMessageLine( 
         "Invalid account number or PIN. Please try again." );
} // end function authenticateUser

// display the main menu and perform transactions
void ATM::performTransactions() 
{
   // local pointer to store transaction currently being processed
   Transaction *currentTransactionPtr;
   
   bool userExited = false; // user has not chosen to exit

   // loop while user has not chosen option to exit system
   while ( !userExited )
   {     
      // show main menu and get user selection
      int mainMenuSelection = displayMainMenu();

      // decide how to proceed based on user's menu selection
      switch ( mainMenuSelection )
      {
         // user chose to perform one of three transaction types
         case BALANCE_INQUIRY: 
         case WITHDRAWAL: 
         case DEPOSIT:
            // initialize as new object of chosen type
            currentTransactionPtr = 
               createTransaction( mainMenuSelection );

            currentTransactionPtr->execute(); // execute transaction

            // free the space for the dynamically allocated Transaction
            delete currentTransactionPtr;
            
            break; 
         case EXIT: // user chose to terminate session
            screen.displayMessageLine( "\nExiting the system..." );
            userExited = true; // this ATM session should end
            break;
         default: // user did not enter an integer from 1-4
            screen.displayMessageLine( 
               "\nYou did not enter a valid selection. Try again." );
            break;
      } // end switch
   } // end while
} // end function performTransactions

// display the main menu and return an input selection
int ATM::displayMainMenu() const
{
   screen.displayMessageLine( "\nMain menu:" );
   screen.displayMessageLine( "1 - View my balance" );
   screen.displayMessageLine( "2 - Withdraw cash" );
   screen.displayMessageLine( "3 - Deposit funds" );
   screen.displayMessageLine( "4 - Exit\n" );
   screen.displayMessage( "Enter a choice: " );
   return keypad.getInput(); // return user's selection
} // end function displayMainMenu
      
// return object of specified Transaction derived class
Transaction *ATM::createTransaction( int type )
{
   Transaction *tempPtr; // temporary Transaction pointer
   
   // determine which type of Transaction to create     
   switch ( type )
   {
      case BALANCE_INQUIRY: // create new BalanceInquiry transaction
         tempPtr = new BalanceInquiry( 
            currentAccountNumber, screen, bankDatabase );
         break;
      case WITHDRAWAL: // create new Withdrawal transaction
         tempPtr = new Withdrawal( currentAccountNumber, screen, 
            bankDatabase, keypad, cashDispenser );
         break; 
      case DEPOSIT: // create new Deposit transaction
         tempPtr = new Deposit( currentAccountNumber, screen, 
            bankDatabase, keypad, depositSlot );
         break;
   } // end switch

   return tempPtr; // return the newly created object
} // end function createTransaction


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
