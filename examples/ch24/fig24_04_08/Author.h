// Fig. 24.4: Author.h
// Definition of class Author.
#ifndef AUTHOR_H
#define AUTHOR_H

#include <string>
#include <memory>

using namespace std;

class Book; // forward declaration of class Book

// Author class definition
class Author
{
public:
   Author( const string &authorName ); // constructor
   ~Author(); // destructor
   void printBookTitle(); // print the title of the Book
   string name; // name of the Author
   weak_ptr< Book > weakBookPtr; // Book the Author wrote
   shared_ptr< Book > sharedBookPtr; // Book the Author wrote
};

#endif // AUTHOR_H

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
