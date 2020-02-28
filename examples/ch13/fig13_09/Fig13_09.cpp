// Fig. 13.9: fig13_09.cpp 
// Controlling precision of floating-point values.
#include <iostream>
#include <iomanip>
#include <cmath> // for sqrt
using namespace std;

int main()
{
   double root2 = sqrt( 2.0 ); // calculate square root of 2
   int places; // precision, vary from 0-9

   cout << "Square root of 2 with precisions 0-9." << endl
      << "Precision set by ios_base member function "
      << "precision:" << endl;

   cout << fixed; // use fixed point format

   // display square root using ios_base function precision
   for ( places = 0; places <= 9; ++places ) 
   {
      cout.precision( places );
      cout << root2 << endl;
   } // end for

   cout << "\nPrecision set by stream manipulator " 
      << "setprecision:" << endl;

   // set precision for each digit, then display square root
   for ( places = 0; places <= 9; ++places )
      cout << setprecision( places ) << root2 << endl;
} // end main

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
