// Fig. 6.17: fig06_17.cpp
// Functions that take no arguments.
#include <iostream>
using namespace std;

void function1(); // function that takes no arguments
void function2( void ); // function that takes no arguments

int main()
{
   function1(); // call function1 with no arguments
   function2(); // call function2 with no arguments
} // end main

// function1 uses an empty parameter list to specify that 
// the function receives no arguments 
void function1()
{
   cout << "function1 takes no arguments" << endl;
} // end function1

// function2 uses a void parameter list to specify that 
// the function receives no arguments 
void function2( void )
{
   cout << "function2 also takes no arguments" << endl;
} // end function2


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
