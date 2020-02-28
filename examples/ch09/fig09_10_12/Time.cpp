// Fig. 9.11: Time.cpp
// Time class member-function definitions.
#include <stdexcept>
#include "Time.h" // include definition of class Time
using namespace std;

// constructor function to initialize private data; calls member function
// setTime to set variables; default values are 0 (see class definition)
Time::Time( int hr, int min, int sec ) 
{
   setTime( hr, min, sec ); 
} // end Time constructor

// set values of hour, minute and second
void Time::setTime( int h, int m, int s )
{
   // validate hour, minute and second
   if ( ( h >= 0 && h < 24 ) && ( m >= 0 && m < 60 ) && 
      ( s >= 0 && s < 60 ) ) 
   {
      hour = h;
      minute = m;
      second = s;
   } // end if
   else
      throw invalid_argument(                            
         "hour, minute and/or second was out of range" );
} // end function setTime

// return hour value
unsigned int Time::getHour() const
{ 
   return hour; 
} // end function getHour

// poor practice: returning a reference to a private data member.
unsigned int &Time::badSetHour( int hh )
{
   if ( hh >= 0 && hh < 24 )
      hour = hh;
   else
      throw invalid_argument( "hour must be 0-23" );

   return hour; // dangerous reference return
} // end function badSetHour

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
