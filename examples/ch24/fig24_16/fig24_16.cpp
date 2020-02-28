// Fig. 24.16: fig24_16.cpp
// Summing the elements of an initializer list
#include <iostream>
#include <initializer_list>
using namespace std;

// sum the elements of an initializer_list
template <typename T>
T sum( initializer_list<T> list )
{
   T total{}; // value initialize total based on type T
   
   // sum all the elements in list; requires += operator for type T 
   for ( auto item : list )
      total += item;
 
   return total;
} // end function template sum

int main()
{
   // display the sum of four ints contained in a list initializer
   cout << "The sum of the items in { 1, 2, 3, 4 } is: "
      << sum( { 1, 2, 3, 4 } ) << endl;

   // display the sum of three doubles contained in a list initializer
   cout << "The sum of the items in { 1.1, 2.2, 3.3 } is: "
      << sum( { 1.1, 2.2, 3.3 } ) << endl;

   // display the sum of two strings contained in a list initializer
   string s1{ "Happy " };
   string s2{ "birthday!" };
   cout << "The sum of the items in { s1, s2 } is: "
      << sum( { s1, s2 } ) << endl;
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
