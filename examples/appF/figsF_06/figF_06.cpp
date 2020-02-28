// Fig. F.6: figF_06.cpp
// Using signal handling 
#include <iostream>
#include <iomanip>
#include <csignal>
#include <cstdlib>
#include <ctime>
using namespace std;

void signalHandler( int );

int main()
{
   signal( SIGINT, signalHandler );
   srand( time( 0 ) );
   
   // create and output random numbers
   for ( int i = 1; i <= 100; ++i )
   {
      int x = 1 + rand() % 50;
      
      if ( x == 25 )
         raise( SIGINT ); // raise SIGINT when x is 25
         
      cout << setw( 4 ) << i;

      if ( i % 10 == 0 )
         cout << endl; // output endl when i is a multiple of 10
   } // end for
} // end main

// handles signal
void signalHandler( int signalValue )
{
   cout << "\nInterrupt signal (" << signalValue
        << ") received.\n"
        << "Do you wish to continue (1 = yes or 2 = no)? ";

   int response;  

   cin >> response;

   // check for invalid responses
   while ( response != 1 && response != 2 )
   {
      cout << "(1 = yes or 2 = no)? ";
      cin >> response;
   }  // end while
   
   // determine if it is time to exit
   if ( response != 1 )
      exit( EXIT_SUCCESS );

   // call signal and pass it SIGINT and address of signalHandler
   signal( SIGINT, signalHandler );                              
}  // end function signalHandler

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
