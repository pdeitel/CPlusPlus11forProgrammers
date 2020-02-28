// Fig. 24.21: fig24_21.cpp
// Using regex_replace algorithm.
#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main()
{
   // create the test strings
   string testString1 = "This sentence ends in 5 stars *****";
   string testString2 = "1, 2, 3, 4, 5, 6, 7, 8";
   string output;
   
   cout << "Original string: " << testString1 << endl;

   // replace every * with a ^
   testString1 = 
      regex_replace( testString1, regex( "\\*" ),  string( "^" ) );
   cout << "^ substituted for *: " << testString1 << endl;

   // replace "stars" with "carets"
   testString1 = 
      regex_replace( testString1, regex( "stars" ), string( "carets" ) );
   cout << "\"carets\" substituted for \"stars\": " 
      << testString1 << endl;

   // replace every word with "word"
   testString1 =
       regex_replace( testString1, regex( "\\w+" ), string( "word" ) );
   cout << "Every word replaced by \"word\": " << testString1 << endl;

   // replace the first three digits with "digit"
   cout << "\nOriginal string: " << testString2 << endl;
   string testString2Copy = testString2;

   for ( int i = 0; i < 3; ++i ) // loop three times
   {
      testString2Copy = regex_replace( testString2Copy, regex( "\\d" ),
         string( "digit" ), regex_constants::format_first_only );
   } // end for

   cout << "Replace first 3 digits by \"digit\": " 
      << testString2Copy << endl;

   // split the string at the commas
   cout << "string split at commas [";

   regex splitter( ",\\s" ); // regex to split a string at commas
   sregex_token_iterator tokenIterator( testString2.begin(),
      testString2.end(), splitter, -1 ); // token iterator
   sregex_token_iterator end; // empty iterator

   while (  tokenIterator != end ) // tokenIterator isn't empty
   {
      output += "\"" + (*tokenIterator).str() + "\", "; 
      ++tokenIterator; // advance the iterator
   } // end while

   // delete the ", " at the end of output string
   cout << output.substr( 0, output.size() - 2 ) << "]" << endl;
} // end of function main

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
