// Fig. 14.14: fig14_14.cpp
// This program reads a random-access file sequentially, updates
// data previously written to the file, creates data to be placed
// in the file, and deletes data previously stored in the file.
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib> // exit function prototype
#include "ClientData.h" // ClientData class definition
using namespace std;

int enterChoice();
void createTextFile( fstream& );
void updateRecord( fstream& );
void newRecord( fstream& );
void deleteRecord( fstream& );
void outputLine( ostream&, const ClientData & );
int getAccount( const char * const );

enum Choices { PRINT = 1, UPDATE, NEW, DELETE, END };

int main()
{
   // open file for reading and writing
   fstream inOutCredit( "credit.dat", ios::in | ios::out | ios::binary );

   // exit program if fstream cannot open file
   if ( !inOutCredit ) 
   {
      cerr << "File could not be opened." << endl;
      exit ( EXIT_FAILURE );
   } // end if
   
   int choice; // store user choice

   // enable user to specify action
   while ( ( choice = enterChoice() ) != END ) 
   {
      switch ( choice ) 
      {
         case PRINT: // create text file from record file
            createTextFile( inOutCredit );
            break;
         case UPDATE: // update record
            updateRecord( inOutCredit );
            break;
         case NEW: // create record
            newRecord( inOutCredit );
            break;
         case DELETE: // delete existing record
            deleteRecord( inOutCredit );
            break;
         default: // display error if user does not select valid choice
            cerr << "Incorrect choice" << endl;
            break;
      } // end switch

      inOutCredit.clear(); // reset end-of-file indicator
   } // end while
} // end main

// enable user to input menu choice
int enterChoice()
{
   // display available options
   cout << "\nEnter your choice" << endl
      << "1 - store a formatted text file of accounts" << endl
      << "    called \"print.txt\" for printing" << endl
      << "2 - update an account" << endl
      << "3 - add a new account" << endl
      << "4 - delete an account" << endl
      << "5 - end program\n? ";

   int menuChoice;
   cin >> menuChoice; // input menu selection from user
   return menuChoice;
} // end function enterChoice

// create formatted text file for printing
void createTextFile( fstream &readFromFile )
{
   // create text file
   ofstream outPrintFile( "print.txt", ios::out );

   // exit program if ofstream cannot create file
   if ( !outPrintFile ) 
   {
      cerr << "File could not be created." << endl;
      exit( EXIT_FAILURE );
   } // end if

   // output column heads
   outPrintFile << left << setw( 10 ) << "Account" << setw( 16 )
      << "Last Name" << setw( 11 ) << "First Name" << right
      << setw( 10 ) << "Balance" << endl;

   // set file-position pointer to beginning of readFromFile
   readFromFile.seekg( 0 );

   // read first record from record file
   ClientData client;
   readFromFile.read( reinterpret_cast< char * >( &client ),
      sizeof( ClientData ) );

   // copy all records from record file into text file
   while ( !readFromFile.eof() ) 
   {
      // write single record to text file
      if ( client.getAccountNumber() != 0 ) // skip empty records
         outputLine( outPrintFile, client );

      // read next record from record file
      readFromFile.read( reinterpret_cast< char * >( &client ), 
         sizeof( ClientData ) );
   } // end while
} // end function createTextFile

// update balance in record
void updateRecord( fstream &updateFile )
{
   // obtain number of account to update
   int accountNumber = getAccount( "Enter account to update" );

   // move file-position pointer to correct record in file
   updateFile.seekg( ( accountNumber - 1 ) * sizeof( ClientData ) );

   // read first record from file
   ClientData client;
   updateFile.read( reinterpret_cast< char * >( &client ), 
      sizeof( ClientData ) );

   // update record
   if ( client.getAccountNumber() != 0 ) 
   {
      outputLine( cout, client ); // display the record

      // request user to specify transaction
      cout << "\nEnter charge (+) or payment (-): ";
      double transaction; // charge or payment
      cin >> transaction;

      // update record balance
      double oldBalance = client.getBalance();
      client.setBalance( oldBalance + transaction );
      outputLine( cout, client ); // display the record

      // move file-position pointer to correct record in file
      updateFile.seekp( ( accountNumber - 1 ) * sizeof( ClientData ) );

      // write updated record over old record in file
      updateFile.write( reinterpret_cast< const char * >( &client ), 
         sizeof( ClientData ) );
   } // end if
   else // display error if account does not exist
      cerr << "Account #" << accountNumber 
         << " has no information." << endl;
} // end function updateRecord

// create and insert record
void newRecord( fstream &insertInFile )
{
   // obtain number of account to create
   int accountNumber = getAccount( "Enter new account number" );

   // move file-position pointer to correct record in file
   insertInFile.seekg( ( accountNumber - 1 ) * sizeof( ClientData ) );

   // read record from file
   ClientData client;
   insertInFile.read( reinterpret_cast< char * >( &client ), 
      sizeof( ClientData ) );

   // create record, if record does not previously exist
   if ( client.getAccountNumber() == 0 ) 
   {
      string lastName;
      string firstName;
      double balance;

      // user enters last name, first name and balance
      cout << "Enter lastname, firstname, balance\n? ";
      cin >> lastName;
      cin >> firstName;
      cin >> balance;

      // use values to populate account values
      client.setLastName( lastName );
      client.setFirstName( firstName );
      client.setBalance( balance );
      client.setAccountNumber( accountNumber );

      // move file-position pointer to correct record in file
      insertInFile.seekp( ( accountNumber - 1 ) * sizeof( ClientData ) );

      // insert record in file                       
      insertInFile.write( reinterpret_cast< const char * >( &client ),
         sizeof( ClientData ) );                     
   } // end if
   else // display error if account already exists
      cerr << "Account #" << accountNumber
         << " already contains information." << endl;
} // end function newRecord

// delete an existing record
void deleteRecord( fstream &deleteFromFile )
{
   // obtain number of account to delete
   int accountNumber = getAccount( "Enter account to delete" );

   // move file-position pointer to correct record in file
   deleteFromFile.seekg( ( accountNumber - 1 ) * sizeof( ClientData ) );

   // read record from file
   ClientData client;
   deleteFromFile.read( reinterpret_cast< char * >( &client ), 
      sizeof( ClientData ) );

   // delete record, if record exists in file
   if ( client.getAccountNumber() != 0 ) 
   {
      ClientData blankClient; // create blank record

      // move file-position pointer to correct record in file
      deleteFromFile.seekp( ( accountNumber - 1 ) * 
         sizeof( ClientData ) );

      // replace existing record with blank record
      deleteFromFile.write( 
         reinterpret_cast< const char * >( &blankClient ), 
         sizeof( ClientData ) );

      cout << "Account #" << accountNumber << " deleted.\n";
   } // end if
   else // display error if record does not exist
      cerr << "Account #" << accountNumber << " is empty.\n";
} // end deleteRecord

// display single record
void outputLine( ostream &output, const ClientData &record )
{
   output << left << setw( 10 ) << record.getAccountNumber()
      << setw( 16 ) << record.getLastName()
      << setw( 11 ) << record.getFirstName()
      << setw( 10 ) << setprecision( 2 ) << right << fixed 
      << showpoint << record.getBalance() << endl;
} // end function outputLine

// obtain account-number value from user
int getAccount( const char * const prompt )
{
   int accountNumber;

   // obtain account-number value
   do 
   {
      cout << prompt << " (1 - 100): ";
      cin >> accountNumber;
   } while ( accountNumber < 1 || accountNumber > 100 );

   return accountNumber;
} // end function getAccount

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
