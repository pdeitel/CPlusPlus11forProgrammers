// Fig. 6.23: fig06_23.cpp
// Name mangling to enable type-safe linkage.

// function square for int values
int square( int x ) 
{ 
   return x * x; 
} // end function square

// function square for double values
double square( double y ) 
{ 
   return y * y; 
} // end function square

// function that receives arguments of types 
// int, float, char and int &
void nothing1( int a, float b, char c, int &d ) 
{ 
   // empty function body
} // end function nothing1

// function that receives arguments of types 
// char, int, float & and double &
int nothing2( char a, int b, float &c, double &d ) 
{ 
   return 0; 
} // end function nothing2

int main()
{
} // end main


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
