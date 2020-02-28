// Fig. 16.15: fig16_15.cpp
// Demonstrating function objects.
#include <iostream>
#include <array> // array class-template definition
#include <algorithm> // copy algorithm
#include <numeric> // accumulate algorithm
#include <functional> // binary_function definition
#include <iterator> // ostream_iterator
using namespace std;

// binary function adds square of its second argument and the
// running total in its first argument, then returns the sum 
int sumSquares( int total, int value ) 
{ 
   return total + value * value; 
} // end function sumSquares

// Class template SumSquaresClass defines overloaded operator()
// that adds the square of its second argument and running     
// total in its first argument, then returns sum               
template< typename T > 
class SumSquaresClass  
{
public:
   // add square of value to total and return result
   T operator()( const T &total, const T &value )
   { 
      return total + value * value; 
   } // end function operator()
}; // end class SumSquaresClass

int main()
{
   const size_t SIZE = 10;
   array< int, SIZE > integers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
   ostream_iterator< int > output( cout, " " );

   cout << "array integers contains:\n";
   copy( integers.cbegin(), integers.cend(), output );

   // calculate sum of squares of elements of array integers
   // using binary function sumSquares
   int result = accumulate( integers.cbegin(), integers.cend(), 
      0, sumSquares );

   cout << "\n\nSum of squares of elements in integers using "
      << "binary\nfunction sumSquares: " << result;

   // calculate sum of squares of elements of array integers
   // using binary function object 
   result = accumulate( integers.cbegin(), integers.cend(), 
      0, SumSquaresClass< int >() );

   cout << "\n\nSum of squares of elements in integers using "
      << "binary\nfunction object of type " 
      << "SumSquaresClass< int >: " << result << endl;
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
