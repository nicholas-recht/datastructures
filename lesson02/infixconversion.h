/***********************************************************************
 * Header File
 *    This is the header file for the InfixConversion Class
 * Summary:
 *    This is the infix conversion class header file. The InfixConversion
 *    class is used to convert an infix equation to a postfix equation.
 *    It is created with a single parameter, a string containing an infix
 *    equation. The result can be obtained with the insertion operator. 
 * Author:
 *    Nicholas Recht
 *    Estimated:  4.0 hrs
 *    Actual:     4.0 hrs
 *      The most difficult part was getting the formatting right for
 *      spaces so that the result was readable. 
 ************************************************************************/

#ifndef INFIXCONVERSION_H
#define INFIXCONVERSION_H

#include "stack.h"
#include <string>
#include <iostream>

/************************************************************************
 * The InfixConversion class header. See above for a description of what
 * the class does
 ***********************************************************************/
class InfixConversion
{
  public:
   //Constructor. Simply stores the passed string until display
   InfixConversion(std::string s) {originalString = s;  convertString(); }

   //Outputs the given infix operation as a postfix equation
   friend std::ostream & operator <<
      (std::ostream & out, const InfixConversion & rhs);

   //Returns the post fix equation as a string
   std::string getEquation() const { return newString; }
   
  private:

   //Runs through the original string and converts in into an infix notation
   //string which is stored in newString; 
   void convertString(); 
   //Takes a char and tells whether a space should be inserted after it
   bool putSpace(char s) const;
   
   //Takes a char (assumed to be a valid operator); Returns an int
   //relating to the order of operations of the operator
   int getOrder(char s) const;

   //Checks whether a given character is a valid operator and returns true
   //if it is
   bool isOperator(char s) const; 

   //the stack used for storing the various operators
   Stack<char> dStack;

   //The original string that we were passed. Stored until time of display
   std::string originalString;
   std::string newString;
   
};


#endif //INFIXCONVERSION_H
