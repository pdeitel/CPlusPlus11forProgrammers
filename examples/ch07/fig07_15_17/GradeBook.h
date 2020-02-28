// Fig. 7.15: GradeBook.h
// Definition of class GradeBook that uses an array to store test grades.
// Member functions are defined in GradeBook.cpp
#include <string> 
#include <array>

// GradeBook class definition
class GradeBook
{
public:
   // constant -- number of students who took the test
   static const size_t students = 10; // note public data

   // constructor initializes course name and array of grades
   GradeBook( const std::string &, const std::array< int, students > & );

   void setCourseName( const std::string & ); // set the course name
   std::string getCourseName() const; // retrieve the course name
   void displayMessage() const; // display a welcome message
   void processGrades() const; // perform operations on the grade data
   int getMinimum() const; // find the minimum grade for the test
   int getMaximum() const; // find the maximum grade for the test
   double getAverage() const; // determine the average grade for the test
   void outputBarChart() const; // output bar chart of grade distribution
   void outputGrades() const; // output the contents of the grades array
private:
   std::string courseName; // course name for this grade book
   std::array< int, students > grades; // array of student grades
}; // end class GradeBook  

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
