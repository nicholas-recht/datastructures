/***********************************************************************
 * ASSEMBLYCONVERSION.CPP
 * Summary:
 *    This is the Assembly Conversion class .cpp file. It contains the
 *    function definitions for the functions in the header file. 
 * Author:
 *    Nicholas Recht  
 ************************************************************************/

#include "assemblyconversion.h"
#include <sstream>

using namespace std; 

/************************************************************************
 * isOperator. Takes a char and returns a boolean value of whether the
 * char is a valid operator.
 **********************************************************************/
bool AssemblyConversion::isOperator(char s) const
{
   if (s == '+' ||
       s == '-' ||
       s == '*' ||
       s == '/' ||
       s == '(' ||
       s == ')' ||
       s == '^')
      return true;
   else
      return false; 
}

/************************************************************************
 * getOperator. Takes a char and returns a string of the given operator's
 * name in assembly language
 **********************************************************************/
string AssemblyConversion::getOperator(char s) const
{
   if (s == '+')
      return "ADD";
   else if (s == '-')
      return "SUBTRACT";
   else if (s == '*')
      return "MULTIPY";
   else if (s == '/')
      return "DIVIDE";
   else if (s == '^')
      return "EXPONENT";
   else
      return "OH CRAP!"; //this shouldn't happen
}

/************************************************************************
 * convertString. The primary function for the AssemblyConversion class.
 * Loops through the postfix equation and converts the equation into a
 * list of assembly instructions. 
 **********************************************************************/
void AssemblyConversion::convertString()
{
   string temp;
   int valueCounter = 1; 
   //Loop through our string, char by char, converting the expression into
   //assembly instructions.
   for (int i = 0; i < originalString.length(); i++)
   {
      if (isOperator(originalString[i]))
      {
         string rhs = dStack.top();
         dStack.pop();
         string lhs = dStack.top();
         dStack.pop();

         newString += "\t";
         newString += "LOAD ";
         newString += lhs;
         newString += "\n";
         newString += "\t";
         newString += getOperator(originalString[i]);
         newString += " ";
         newString += rhs;
         newString += "\n";
         newString += "\t";
         newString += "STORE ";
         newString += "VALUE";
         stringstream sout;
         sout << valueCounter;
   
         newString += sout.str();
         newString += "\n"; 
         dStack.push("VALUE" + sout.str());
         valueCounter++; 
      }
         else if (originalString[i] == ' ')
            ; //we don't want to do anything
      else
      {
         temp.clear(); 
         temp += originalString[i]; 
         int j = i + 1;
         //We need to store the entire variable name in the stack
         while (originalString[j] != ' ' && j < originalString.length())
         {
            temp += originalString[j];
            j++;
         } 
         dStack.push(temp);
         i = j - 1; 
      }
   }

  
}

/************************************************************************
 * Operator <<. Takes an ostream and an InfixConversion and outputs the
 * Infix equation. 
 **********************************************************************/
ostream & operator << (ostream & out, const AssemblyConversion & rhs)
{
   out << rhs.newString; 
   
   return out; 
}
