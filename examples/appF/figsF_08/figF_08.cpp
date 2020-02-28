// Fig. F.8: figF_08.cpp
// An example of a union.
#include <iostream>
using namespace std;

// define union Number 
union Number           
{                      
   int integer1;       
   double double1;     
};  // end union Number

int main()
{
   Number value; // union variable

   value.integer1 = 100; // assign 100 to member integer1

   cout << "Put a value in the integer member\n"
        << "and print both members.\nint:   " 
        << value.integer1 << "\ndouble: " << value.double1
        << endl;

   value.double1 = 100.0;  // assign 100.0 to member double1

   cout << "Put a value in the floating member\n" 
        << "and print both members.\nint:   " 
        << value.integer1 << "\ndouble: " << value.double1
        << endl;
}  // end main

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
