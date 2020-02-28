// Fig. 24.10: fibonacci.cpp
// Fibonacci calculations performed sequentially
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

unsigned long long int fibonacci( unsigned int n ); // function prototype

// function main begins program execution
int main( void )
{
   cout << fixed << setprecision( 6 );
   cout << "Sequential calls to fibonacci(45) and fibonacci(44)" << endl;

   // calculate fibonacci value for number input by user
   cout << "Calculating fibonacci( 45 )" << endl;
   time_t startTime1 = time( nullptr );
   unsigned long long int result1 = fibonacci( 45 );
   time_t endTime1 = time( nullptr );

   cout << "fibonacci( 45 ) = " << result1 << endl;
   cout << "Calculation time = " 
      << difftime( endTime1, startTime1 ) / 60.0 
      << " minutes\n" << endl; 

   cout << "Calculating fibonacci( 44 )" << endl;
   time_t startTime2 = time( nullptr );
   unsigned long long int result2 = fibonacci( 44 );
   time_t endTime2 = time( nullptr );

   cout << "fibonacci( 44 ) = " << result2 << endl;
   cout << "Calculation time = " 
      << difftime( endTime2, startTime2 ) / 60.0 
      << " minutes\n" << endl; 

   cout << "Total calculation time = " 
      << difftime( endTime2, startTime1 ) / 60.0 << " minutes" << endl;
} // end main

// Recursively calculates fibonacci numbers
unsigned long long int fibonacci( unsigned int n )   
{                                                    
   // base case                                      
   if ( 0 == n || 1 == n ) 
   {                         
      return n;                                      
   } // end if                                       
   else // recursive step
   { 
      return fibonacci( n - 1 ) + fibonacci( n - 2 );
   } // end else                                     
} // end function fibonacci 


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
