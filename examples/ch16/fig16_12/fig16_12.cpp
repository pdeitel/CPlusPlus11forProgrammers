// Fig. 16.12: fig16_12.cpp
// Algorithms push_heap, pop_heap, make_heap and sort_heap.
#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <iterator> 
using namespace std;

int main()
{
   const size_t SIZE = 10;
   array< int, SIZE > init = { 3, 100, 52, 77, 22, 31, 1, 98, 13, 40 };
   array< int, SIZE > a( init ); // copy of init  
   ostream_iterator< int > output( cout, " " );

   cout << "Array a before make_heap:\n";
   copy( a.cbegin(), a.cend(), output );

   make_heap( a.begin(), a.end() ); // create heap from array a
   cout << "\nArray a after make_heap:\n";
   copy( a.cbegin(), a.cend(), output );
   
   sort_heap( a.begin(), a.end() ); // sort elements with sort_heap
   cout << "\nArray a after sort_heap:\n";
   copy( a.cbegin(), a.cend(), output );

   // perform the heapsort with push_heap and pop_heap
   cout << "\n\nArray init contains: ";
   copy( init.cbegin(), init.cend(), output ); // display array init
   cout << endl;

   vector< int > v; 

   // place elements of array init into v and 
   // maintain elements of v in heap
   for ( size_t i = 0; i < init.size(); ++i ) 
   {
      v.push_back( init[ i ] );
      push_heap( v.begin(), v.end() );      
      cout << "\nv after push_heap(init[" << i << "]): ";
      copy( v.cbegin(), v.cend(), output );
   } // end for
   
   cout << endl;

   // remove elements from heap in sorted order
   for ( size_t j = 0; j < v.size(); ++j ) 
   {
      cout << "\nv after " << v[ 0 ] << " popped from heap\n";
      pop_heap( v.begin(), v.end() - j );
      copy( v.cbegin(), v.cend(), output );
   } // end for

   cout << endl;
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
