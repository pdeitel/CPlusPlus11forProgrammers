// Fig. 24.8: fig24_08.cpp
// Demonstrate use of boost::weak_ptr.
#include <iostream>
#include <memory>
#include "Author.h"
#include "Book.h"
using namespace std;

int main()
{
   // create a Book and an Author
   shared_ptr< Book > bookPtr( new Book( "C++ How to Program" ) );
   shared_ptr< Author > authorPtr( new Author( "Deitel & Deitel" ) );

   // reference the Book and Author to each other
   bookPtr->weakAuthorPtr = authorPtr;
   authorPtr->weakBookPtr = bookPtr;

   // set the shared_ptr data members to create the memory leak
   bookPtr->sharedAuthorPtr = authorPtr;
   authorPtr->sharedBookPtr = bookPtr;

   // reference count for bookPtr and authorPtr is one
   cout << "Reference count for Book " << bookPtr->title << " is "
      << bookPtr.use_count() << endl;
   cout << "Reference count for Author " << authorPtr->name << " is " 
      << authorPtr.use_count() << "\n" << endl;

   // access the cross references to print the data they point to
   cout << "Access the Author's name and the Book's title through "
      << "weak_ptrs." << endl;
   bookPtr->printAuthorName();
   authorPtr->printBookTitle();
   
   // reference count for each shared_ptr is back to one
   cout << "Reference count for Book " << bookPtr->title << " is "
      << bookPtr.use_count() << endl;
   cout << "Reference count for Author " << authorPtr->name << " is " 
      << authorPtr.use_count() << "\n" << endl;

   // the shared_ptrs go out of scope, the Book and Author are destroyed
   cout << "The shared_ptrs are going out of scope." << endl;
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
