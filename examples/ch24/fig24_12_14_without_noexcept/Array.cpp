// Fig. 24.13: Array.cpp
// Array class member- and friend-function definitions.
#include <iostream>
#include <iomanip>
#include <stdexcept> 
#include <utility> // contains std::move

#include "Array.h" // Array class definition
using namespace std;

// default constructor for class Array (default size 10)
Array::Array( size_t arraySize )
   : size( arraySize ),
     ptr( new int[ size ] )
{
   cout << "Array(int) constructor called" << endl;

   for ( size_t i = 0; i < size; ++i )
      ptr[ i ] = 0; // set pointer-based array element
} // end Array default constructor

// copy constructor for class Array;
// must receive a reference to an Array
Array::Array( const Array &arrayToCopy ) 
   : size( arrayToCopy.size ),
     ptr( new int[ size ] )
{
   cout << "Array copy constructor called" << endl;

   for ( size_t i = 0; i < size; ++i )
      ptr[ i ] = arrayToCopy.ptr[ i ]; // copy into object
} // end Array copy constructor

// move constructor for class Array;
// must receive an rvalue reference to an Array
Array::Array( Array &&arrayToMove ) // should be noexcept
   : size( arrayToMove.size ), // move arrayToMove's size to new Array
     ptr( arrayToMove.ptr ) // move arrayToMove's ptr to new Array
{
   cout << "Array move constructor called" << endl;

   // indicate that arrayToMove is now empty
   arrayToMove.size = 0; 
   arrayToMove.ptr = nullptr;  
} // end Array copy constructor

// destructor for class Array
Array::~Array()
{
   cout << "Array destructor called" << endl;
   delete [] ptr; // release pointer-based array space
} // end destructor

// return number of elements of Array
size_t Array::getSize() const
{
   return size; // number of elements in Array
} // end function getSize

// copy assignment operator
Array &Array::operator=( const Array &right )
{
   cout << "Array copy assignment operator called" << endl;

   if ( &right != this ) // avoid self-assignment
   {
      // for Arrays of different sizes, deallocate original
      // left-side Array, then allocate new left-side Array
      if ( size != right.size )
      {
         delete [] ptr; // release space
         size = right.size; // resize this object
         ptr = new int[ size ]; // create space for Array copy
      } // end inner if

      for ( size_t i = 0; i < size; ++i )
         ptr[ i ] = right.ptr[ i ]; // copy array into object
   } // end outer if

   return *this; // enables x = y = z, for example
} // end copy assignment operator=

// move assignment operator;
Array &Array::operator=( Array &&arrayToMove )
{
   cout << "Array move assignment operator called" << endl;

   if ( &arrayToMove != this ) // avoid self-assignment
   {
      delete [] ptr; // release space
      size = arrayToMove.size; // move arrayToMove's size to new Array
      ptr = arrayToMove.ptr; // move arrayToMove's ptr to new Array

      // indicate that arrayToMove is now empty
      arrayToMove.size = 0; 
      arrayToMove.ptr = nullptr;  
   } // end outer if

   return *this; // enables x = y = z, for example
} // end move assignment operator=

// determine if two Arrays are equal and
// return true, otherwise return false
bool Array::operator==( const Array &right ) const
{
   if ( size != right.size )
      return false; // arrays of different number of elements

   for ( size_t i = 0; i < size; ++i )
      if ( ptr[ i ] != right.ptr[ i ] )
         return false; // Array contents are not equal

   return true; // Arrays are equal
} // end function operator==

// overloaded subscript operator for non-const Arrays;
// reference return creates a modifiable lvalue
int &Array::operator[]( size_t subscript )
{
   // check for subscript out-of-range error
   if ( subscript >= size )
      throw out_of_range( "Subscript out of range" );

   return ptr[ subscript ]; // reference return
} // end function operator[]

// overloaded subscript operator for const Arrays
// const reference return creates an rvalue
int Array::operator[]( size_t subscript ) const
{
   // check for subscript out-of-range error
   if ( subscript >= size )
      throw out_of_range( "Subscript out of range" );

   return ptr[ subscript ]; // returns copy of this element
} // end function operator[]

// overloaded input operator for class Array;
// inputs values for entire Array
istream &operator>>( istream &input, Array &a )
{
   for ( size_t i = 0; i < a.size; ++i )
      input >> a.ptr[ i ];

   return input; // enables cin >> x >> y;
} // end function 

// overloaded output operator for class Array 
ostream &operator<<( ostream &output, const Array &a )
{
   // output private ptr-based array 
   for ( size_t i = 0; i < a.size; ++i )
      output << a.ptr[ i ] << " ";

   output << endl;
   return output; // enables cout << x << y;
} // end function operator<<

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
