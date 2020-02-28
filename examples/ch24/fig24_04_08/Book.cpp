// Fig. 24.7: Book.cpp
// Member function definitions for class Book.
#include <iostream>
#include <string>
#include <memory>
#include "Author.h"
#include "Book.h"

using namespace std;

Book::Book( const string &bookTitle ) : title( bookTitle )
{
}

Book::~Book()
{
   cout << "Destroying Book: " << title << endl;
} // end of destructor

// print the name of this Book's Author
void Book::printAuthorName()
{
   // if weakAuthorPtr.lock() returns a non-empty shared_ptr
   if ( shared_ptr< Author > authorPtr = weakAuthorPtr.lock() )
   {
      // show the reference count increase and print the Author's name
      cout << "Reference count for Author " << authorPtr->name
         << " is " << authorPtr.use_count() << "." << endl;
      cout << "The book " << title << " was written by " 
         << authorPtr->name << "\n" << endl;
   } // end if
   else // weakAuthorPtr points to NULL
      cout << "This Book has no Author." << endl;
} // end of printAuthorName

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
