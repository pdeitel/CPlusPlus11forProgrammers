// Fig. 6.3: GradeBook.cpp
// Member-function definitions for class GradeBook that
// determines the maximum of three grades.
#include <iostream>
using namespace std;

#include "GradeBook.h" // include definition of class GradeBook

// constructor initializes courseName with string supplied as argument;
// initializes maximumGrade to 0
GradeBook::GradeBook( string name )
   : maximumGrade( 0 ) // this value will be replaced by the maximum grade
{
   setCourseName( name ); // validate and store courseName
} // end GradeBook constructor

// function to set the course name; limits name to 25 or fewer characters
void GradeBook::setCourseName( string name )
{
   if ( name.size() <= 25 ) // if name has 25 or fewer characters
      courseName = name; // store the course name in the object
   else // if name is longer than 25 characters
   { // set courseName to first 25 characters of parameter name
      courseName = name.substr( 0, 25 ); // select first 25 characters
      cerr << "Name \"" << name << "\" exceeds maximum length (25).\n"
         << "Limiting courseName to first 25 characters.\n" << endl;
   } // end if...else
} // end function setCourseName

// function to retrieve the course name
string GradeBook::getCourseName() const
{
   return courseName;
} // end function getCourseName

// display a welcome message to the GradeBook user
void GradeBook::displayMessage() const
{
   // this statement calls getCourseName to get the 
   // name of the course this GradeBook represents
   cout << "Welcome to the grade book for\n" << getCourseName() << "!\n" 
      << endl;
} // end function displayMessage

// input three grades from user; determine maximum
void GradeBook::inputGrades()
{
   int grade1; // first grade entered by user
   int grade2; // second grade entered by user
   int grade3; // third grade entered by user

   cout << "Enter three integer grades: ";
   cin >> grade1 >> grade2 >> grade3;

   // store maximum in member maximumGrade
   maximumGrade = maximum( grade1, grade2, grade3 );
} // end function inputGrades

// returns the maximum of its three integer parameters
int GradeBook::maximum( int x, int y, int z ) const
{
   int maximumValue = x; // assume x is the largest to start

   // determine whether y is greater than maximumValue
   if ( y > maximumValue )
      maximumValue = y; // make y the new maximumValue

   // determine whether z is greater than maximumValue
   if ( z > maximumValue )
      maximumValue = z; // make z the new maximumValue

   return maximumValue;
} // end function maximum

// display a report based on the grades entered by user
void GradeBook::displayGradeReport() const
{
   // output maximum of grades entered
   cout << "Maximum of grades entered: " << maximumGrade << endl;
} // end function displayGradeReport



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
