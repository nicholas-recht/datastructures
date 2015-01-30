/***********************************************************************
 * INFIXCONVERSION.CPP
 * Summary:
 *    This is the infix conversion class .cpp file. It contains the
 *    function definitions for the functions in the header file. 
 * Author:
 *    Nicholas Recht
 ************************************************************************/

#include "infixconversion.h"

using namespace std; 

/************************************************************************
 * isOperator. Takes a char and returns a boolean value of whether the
 * char is a valid operator.
 **********************************************************************/
bool InfixConversion::isOperator(char s) const
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
 * getOrder. Takes a char (assumed to be a valid operator) and returns
 * it's order of operation value. Lower numbers go first (except for
 * parenthesis which are special cases. 
 **********************************************************************/
int InfixConversion::getOrder(char s) const
{
   if (s == '(' || s == ')')
      return 100; //Absolute First
   else if (s == '^')
      return 0; 
   else if (s == '*' || s == '/')
      return 1;
   else if (s == '+' || s == '-')
      return 2;
   else
      return -1;  //this shouldn't happen
      
}

/************************************************************************
 * putSpace. Takes a char and returns a boolean value of whether a space
 * should be output after the given character. 
 **********************************************************************/
bool InfixConversion::putSpace(char s) const
{
   if (isOperator(s) && s != '(' && s != ')')
      return true;
   else
      return false;
}

/************************************************************************
 * convertString. The primary function for the InfixConversion class.
 * Converts the orginal String to a postfix equation string character by
 * character. 
 **********************************************************************/
void InfixConversion::convertString()
{
   //Loop through our string, char by char, either displaying or putting
   //on the stack to display later
   int i = 0;
   for (i = 0; i < originalString.length(); i++)
   {
      //check if its an operator
      if (isOperator(originalString[i]))
         {
            //we need to check for the parenthesis
            if (originalString[i] == '(')
               dStack.push(originalString[i]);
            else if (originalString[i] == ')')
            {
               while (dStack.top() != '(')
               {
                  newString += " ";
                  newString += dStack.top(); 
                  dStack.pop(); 
               }
               dStack.pop(); //get rid of the end parenthesis
               //now check if we need to put a space (if it's the end of a
               //varible name for example)
               if (i + 1 < originalString.length())
                  if (putSpace(originalString[i + 1]))
                     newString += " ";
            }
            else
            {
               //first check if it's an empty stack
               if (!dStack.empty())
               {
                  //We need to pop everything off the stack until we get to a
                  //lower order
                  while (!dStack.empty() &&
                         getOrder(originalString[i]) >=
                         getOrder(dStack.top()))
                  {
                     newString += dStack.top();
                     newString += " "; 
                     dStack.pop(); 
                  }
               }
               //put operator on the stack
               dStack.push(originalString[i]); 
            }
         }
      else
      {
         //if it's a space, we dont want to output it
         if (originalString[i] != ' ')
            newString += originalString[i]; 
         //now check if we need to put a space (if it's the end of a
         //varible name for example)
         if (i + 1 < originalString.length())
            if (putSpace(originalString[i + 1]))
               newString += " ";
      }
            
   }

   //Now pop off everything left on the stack
   while (!dStack.empty())
   {
      newString += " ";
      newString += dStack.top(); 
      dStack.pop(); 
   }
}

/************************************************************************
 * Operator <<. Takes an ostream and an InfixConversion and outputs the
 * Infix equation. 
 **********************************************************************/
ostream & operator << (ostream & out, const InfixConversion & rhs)
{
   out << rhs.newString; 
   
   return out; 
}
