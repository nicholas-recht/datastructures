/***********************************************************************
 * Implementation:
 *    FIBONACCI
 * Summary:
 *    Contains the implementation for fibonacci()
 * Author
 *    Nicholas Recht
 **********************************************************************/

#include <iostream>
#include "fibonacci.h"   // for fibonacci() prototype
#include "list.h"        // for LIST
#include "wholeNumber.h"
using namespace std;


/*******************************************************************
 * FIBONACCI
 * The interactive function allowing the user to display a list of
 * Fibonacci numbers as well as the nth finbonacci number
 ******************************************************************/
void fibonacci()
{
   // show the first serveral Fibonacci numbers
   int number;
   cout << "How many Fibonacci numbers would you like to see? ";
   cin  >> number;

   // your code to display the first <number> Fibonacci numbers

   WholeNumber first = 1;
   WholeNumber second = 1; 
   WholeNumber fibNum = 0; 

   if (number > 0)
      cout << "\t" << first << endl; 
   if (number > 1)
      cout << "\t" << second << endl; 

   //Loop through and display all except the last
   for (int i = 3; i < number; i++)
      {
         fibNum = first + second;
         first = second;
         second = fibNum;

         cout << "\t" << fibNum << endl; 
      }

   //display the last one
   if (number > 2)
   {
      fibNum = first + second;
      cout << "\t" << fibNum << endl;
   }
   
   // prompt for a single large Fibonacci
   cout << "Which Fibonacci number would you like to display? ";
   cin  >> number;

   // your code to display the <number>th Fibonacci number
   first = 1;
   second = 1;
   fibNum = 0;
   
   if (number == 1)
      cout << "\t" << first << endl;
   else if (number == 2)
      cout << "\t" << second << endl;
   else
   {
      for (int i = 3; i <= number; i++)
      {
         fibNum = first + second;
         first = second;
         second = fibNum; 
      }

      cout << "\t" << fibNum << endl; 
   }
}


