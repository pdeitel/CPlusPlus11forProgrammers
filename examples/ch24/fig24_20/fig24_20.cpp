// Fig. 24.20: fig24_20.cpp
// Validating user input with regular expressions.
#include <iostream>
#include <string>
#include <regex>
using namespace std;

bool validate( const string&, const string& ); // validate prototype
string inputData( const string&, const string& ); // inputData prototype

int main()
{
   // enter the last name
   string lastName = inputData( "last name", "[A-Z][a-zA-Z]*" );

   // enter the first name
   string firstName = inputData( "first name", "[A-Z][a-zA-Z]*" );

   // enter the address
   string address = inputData( "address", 
      "[0-9]+\\s+([a-zA-Z]+|[a-zA-Z]+\\s[a-zA-Z]+)" );

   // enter the city
   string city = 
      inputData( "city", "([a-zA-Z]+|[a-zA-Z]+\\s[a-zA-Z]+)" );

   // enter the state
   string state = inputData( "state",
      "([a-zA-Z]+|[a-zA-Z]+\\s[a-zA-Z]+)" );

   // enter the zip code
   string zipCode = inputData( "zip code", "\\d{5}" );

   // enter the phone number
   string phoneNumber = inputData( "phone number", 
      "[1-9]\\d{2}-[1-9]\\d{2}-\\d{4}" );

   // display the validated data
   cout << "\nValidated Data\n\n"
      << "Last name: " << lastName << endl
      << "First name: " << firstName << endl
      << "Address: " << address << endl
      << "City: " << city << endl
      << "State: " << state << endl
      << "Zip code: " << zipCode << endl
      << "Phone number: " << phoneNumber << endl;
} // end of function main

// validate the data format using a regular expression
bool validate( const string &data, const string &expression )
{
   // create a regex to validate the data
   regex validationExpression = regex( expression );
   return regex_match( data, validationExpression );
} // end of function validate

// collect input from the user
string inputData( const string &fieldName, const string &expression )
{
   string data; // store the data collected

   // request the data from the user
   cout << "Enter " << fieldName << ": ";
   getline( cin, data );

   // validate the data
   while ( !( validate( data, expression ) ) )
   {
      cout << "Invalid " << fieldName << ".\n";
      cout << "Enter " << fieldName << ": ";
      getline( cin, data );
   } // end while

   return data;
} // end of function inputData

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
