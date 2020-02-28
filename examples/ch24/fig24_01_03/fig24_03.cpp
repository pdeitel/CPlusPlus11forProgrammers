// Fig. 24.3: fig24_03.cpp
// Demonstrate used of shared_ptrs.
#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>
#include "Book.h"
using namespace std;

typedef shared_ptr< Book > BookPtr; // shared_ptr to a Book

// a custom delete function for a pointer to a Book
void deleteBook( Book* book )
{
   cout << "Custom deleter for a Book, ";
   delete book; // delete the Book pointer
} // end of deleteBook

// compare the titles of two Books
bool compareTitles( BookPtr bookPtr1, BookPtr bookPtr2 )
{
   return ( bookPtr1->title < bookPtr2->title );
} // end of compareTitles

int main()
{
   // create a shared_ptr to a Book and display the reference count
   BookPtr bookPtr( new Book( "C++ How to Program" ) );
   cout << "Reference count for Book " << bookPtr->title << " is: " 
      << bookPtr.use_count() << endl;

   // create another shared_ptr to the Book and display reference count
   BookPtr bookPtr2( bookPtr );
   cout << "Reference count for Book " << bookPtr->title << " is: " 
      << bookPtr.use_count() << endl;

   // change the Book's title and access it from both pointers
   bookPtr2->title = "Java How to Program";
   cout << "\nThe Book's title changed for both pointers: "
      << "\nbookPtr: " << bookPtr->title
      << "\nbookPtr2: " << bookPtr2->title << endl;

   // create a std::vector of shared_ptrs to Books (BookPtrs)
   vector< BookPtr > books;
   books.push_back( BookPtr( new Book( "C How to Program" ) ) );
   books.push_back( BookPtr( new Book( "VB How to Program" ) ) );
   books.push_back( BookPtr( new Book( "C# How to Program" ) ) );
   books.push_back( BookPtr( new Book( "C++ How to Program" ) ) );

   // print the Books in the vector
   cout << "\nBooks before sorting: " << endl;
   for ( int i = 0; i < books.size(); ++i )
      cout << ( books[ i ] )->title << "\n";

   // sort the vector by Book title and print the sorted vector
   sort( books.begin(), books.end(), compareTitles );
   cout << "\nBooks after sorting: " << endl;
   for ( int i = 0; i < books.size(); ++i )
      cout << ( books[ i ] )->title << "\n";

   // create a shared_ptr with a custom deleter
   cout << "\nshared_ptr with a custom deleter." << endl;
   BookPtr bookPtr3( new Book( "Small C++ How to Program" ), deleteBook );
   bookPtr3.reset(); // release the Book this shared_ptr manages

   // shared_ptrs are going out of scope
   cout << "\nAll shared_ptr objects are going out of scope." << endl;
} // end of main

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
