/***********************************************************************
 * Header File
 *    This is the header file for the AssemblyConversion Class
 * Summary:
 *    This is the assembly conversion class header file. The AssemblyConversion
 *    class is used to convert a postfix equation to assembly instructions.
 *    It is created with a single parameter, a string containing a postfix
 *    equation. The result can be obtained with the insertion operator. 
 * Author:
 *    Nicholas Recht
 *    Estimated:  1.0 hrs
 *    Actual:     1.0 hrs
 *      The most difficult part was converting an integer to a string.
 *      Thanks Br Helfrich!
 ************************************************************************/

#ifndef ASSEMBLYCONVERSION_H
#define ASSEMBLYCONVERSION_H

#include "stack.h"
#include <string>
#include <iostream>

/************************************************************************
 * The AssemblyConversion class header. See above for a description of what
 * the class does
 ***********************************************************************/
class AssemblyConversion
{
  public:
   //Constructor. Simply stores the passed string until display
   AssemblyConversion(std::string s) {originalString = s;  convertString(); }

   //Outputs the given postfix equation in Assembly Instructions
   friend std::ostream & operator <<
      (std::ostream & out, const AssemblyConversion & rhs);
   
  private:

   //Runs through the original string and converts in into assembly instruction
   //string which is stored in newString; 
   void convertString(); 

   //Returns the name of an assembly operator from a mathmatical operator
   std::string getOperator(char s) const;
   
   //Checks whether a given character is a valid operator and returns true
   //if it is
   bool isOperator(char s) const; 

   //the stack used for storing the various variables and operators
   Stack<std::string> dStack;

   //The original string that we were passed. Stored until time of display
   std::string originalString;

   //the new string in assembly level instructions 
   std::string newString;
   
};


#endif //ASSEMBLYCONVERSION_H
