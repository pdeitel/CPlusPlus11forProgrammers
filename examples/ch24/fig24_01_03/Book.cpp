// Fig. 24.2: Book.cpp
// Member function definitions for class Book.
#include <iostream>
#include <string>
#include "Book.h"
using namespace std;

Book::Book( const string &bookTitle ) : title( bookTitle )
{
}

Book::~Book() // destructor
{
   cout << "Destroying Book: " << title << endl;
} // end of destructor

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
