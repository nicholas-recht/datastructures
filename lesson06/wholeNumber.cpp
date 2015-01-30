/***********************************************************************
 * Source:
 *    WHOLENUMBER
 * Summary:
 *    Contains the source file for the WholeNumber class
 * Author
 *    Nicholas Recht
 *    3 hrs (base)
 *    3 hrs (extra)
 ************************************************************************/

#include "wholeNumber.h"
#include <stdlib.h>
#include <iomanip>
#include <sstream>
using namespace std;

/************************************************************************
 * parseStr
 * Breaks a passed string into 3 digit segments which are then stored
 * in the list
 ***********************************************************************/
void WholeNumber::parseStr(string input)
{
   segments.clear();

   if (input[0] == '-')
   {
      isNegative = true;
      input.erase(0, 1);
   }
   else
      isNegative = false; 
   
   int remainder = input.length() % 3;
   if (remainder == 1)
      input = "00" + input;
   else if (remainder == 2)
      input = "0" + input;

   int numSegments = input.length() / 3;
   
   for (int i = 0; i < numSegments; i++)
   {
      string tempStr = input.substr(i * 3, 3);
      int tempInt = atoi(tempStr.c_str());
      segments.push_back(tempInt); 
   }
}

/************************************************************************
 * Non-Default Constructor
 * Takes an integer as a parameter and creates a new WholeNumber
 ***********************************************************************/
WholeNumber::WholeNumber(int input)
{
   isNegative = false;
   
   stringstream sout;

   sout << input;

   parseStr(sout.str()); 

   
}

/************************************************************************
 * Assignment Operator
 * Assigns the value of an integer to this WholeNumber
 ***********************************************************************/
WholeNumber & WholeNumber::operator = (const int rhs)
{
   *this = WholeNumber(rhs);
   return *this; 
}

/************************************************************************
 * Insertion Operator
 * Outputs the WholeNumber with commas between every 3 digits
 ***********************************************************************/
ostream & operator << (ostream & out, const WholeNumber & rhs)
{
   //First display the negative sign if needed
   if (rhs.isNegative)
      out << "-";
   
   for (ConstListIterator<int> it = rhs.segments.cbegin();
        it != rhs.segments.cend(); ++it)
   {

      if (++it != rhs.segments.cend())
      {
         --it;
         //we don't want leading 0's on first digit
         if (it == rhs.segments.cbegin())
            out << *it << ",";
         else
            //we want to force it to show 3 digits with leading 0's
            out << setfill('0') << std::setw(3) << *it << ",";
      }
      else
      {
         //set it equal to the last item in the list
         it = rhs.segments.crbegin();
         if (it == rhs.segments.cbegin())
            out << *it;
         else
            //no commas on the last one
            out << setfill('0') << std::setw(3) << *it;
      }
    
   }

   return out; 
}

/************************************************************************
 * Extraction Operator
 * Takes an input stream and converts it to a WholeNumber
 ***********************************************************************/
istream & operator >> (istream & in,  WholeNumber & rhs)
{
   if (in.fail())
      return in;

   //Skip leading spaces
   while (isspace(in.peek()))
      in.get();
   
   string tempstr;
   while (!isspace(in.peek()))
   {
      tempstr += in.peek();
      in.get(); 
   }

   //add our string into our wholeNumber
   rhs.parseStr(tempstr);
   
   return in; 
}

/************************************************************************
 * Assignment Operator
 * Assigns the value of one WholeNumber to this WholeNumber
 ***********************************************************************/
WholeNumber & WholeNumber::operator = (const WholeNumber & rhs)
{
   this->segments.clear();
   
   for (ConstListIterator<int> it = rhs.segments.cbegin();
        it != rhs.segments.cend(); ++it)
      this->segments.push_back(*it);

   this->isNegative = rhs.isNegative; 
   
   return *this; 
}

/************************************************************************
 * Addition Operator
 * Adds two WholeNumbers and returns the result
 ***********************************************************************/
WholeNumber operator + (const WholeNumber & lhs, const WholeNumber & rhs)
{
   if (!lhs.isNegative && !rhs.isNegative)
      return addition(lhs, rhs); 
   else if (lhs.isNegative && rhs.isNegative)
      return addition(lhs, rhs, true);
   else if (lhs.isNegative && !rhs.isNegative)
   {
      WholeNumber temp = lhs;
      temp.isNegative = false; 
      return rhs - temp; 
   }
   else //!lhs.isNegative && rhs.isNegative
   {
      WholeNumber temp = rhs;
      temp.isNegative = false;
      return lhs - temp;
   }
 
}

/************************************************************************
 * Subtraction Operator
 * Subtracts two WholeNumbers and returns the result
 ***********************************************************************/
WholeNumber operator - (const WholeNumber & lhs, const WholeNumber & rhs)
{
   //We need some serious logic to handle our negative cases
   if (!lhs.isNegative && !rhs.isNegative)
   {
      if (lhs > rhs)
         return subtraction(lhs, rhs, false);
      else if (lhs < rhs)
         return subtraction(rhs, lhs, true);  
      else //they're equal
         return WholeNumber(0); 
   }
   else if (lhs.isNegative && rhs.isNegative)
   {
      if (lhs > rhs)
         return subtraction(rhs, lhs, false);
      else if (lhs < rhs)
         return subtraction(lhs, rhs, true);
      else //they're equal
         return WholeNumber(0); 
   }
   else if (lhs.isNegative && !rhs.isNegative)
      return addition(lhs, rhs, true);
   else //!lhs.isNegative && rhs.isNegative
      return addition(lhs, rhs, false); 
   
}

/************************************************************************
 * Multiplication Operator
 * Multiplies two WholeNumbers and returns the result
 ***********************************************************************/
WholeNumber operator * (const WholeNumber & lhs, const WholeNumber & rhs)
{
   WholeNumber result;

   ConstListIterator<int> iLhs = lhs.segments.crbegin();
   ConstListIterator<int> iRhs = rhs.segments.crbegin();

   int first,
       second,
       inResult,
       carry = 0;

   //keeps track of how many times I've executed the loop
   int counter = 0; 
   while (iRhs != rhs.segments.crend())
   {
      WholeNumber temp;
      iLhs = lhs.segments.crbegin(); 
      carry = 0;
      inResult = 0; 
      first = 0;
      second = 0;
      
      while (iLhs != lhs.segments.crend())
      {
         first = *iLhs;
         second = *iRhs;
         inResult = (first * second + carry) % 1000;
         carry = (first * second + carry) / 1000;

         temp.segments.push_front(inResult);

         --iLhs; 
      }

      if (carry > 0)
          temp.segments.push_front(carry);

      //Add on our 1000's 
      for (int i = counter; i > 0; --i)
         temp.segments.push_back(0);

      result += temp;
      
      --iRhs;
      ++counter; 
   }

   if (lhs.isNegative && rhs.isNegative)
      result.isNegative = false;
   else if (!lhs.isNegative && !rhs.isNegative)
      result.isNegative = false;
   else
      result.isNegative = true;
   
   return result; 
}

/************************************************************************
 * Exponent Operator
 * Raises first WholeNumber to WholeNumber power and returns the result
 ***********************************************************************/
WholeNumber pow(const WholeNumber & lhs, const WholeNumber & rhs)
{
   if (rhs > WholeNumber(0))
   {
      WholeNumber result(lhs);

      for (WholeNumber i = 1; i < rhs; i += WholeNumber(1))
         result *= lhs;

      return result;
   }
   else
      return WholeNumber(1); 
}

/************************************************************************
 * Greater Than Operator
 * compares two Whole Numbers
 ***********************************************************************/
bool operator > (const WholeNumber & lhs, const WholeNumber & rhs)
{
   //check signs
   if (lhs.isNegative && !rhs.isNegative)
      return false;
   else if (!lhs.isNegative && rhs.isNegative)
      return true;
   else if (!lhs.isNegative && !rhs.isNegative)//they're both positive
   {
      //the easy cases
      if (lhs.segments.size() > rhs.segments.size())
         return true;
      else if (lhs.segments.size() < rhs.segments.size())
         return false;
      //Now we mus t compare every segment individually
      else
      {
         ConstListIterator<int> iLhs = lhs.segments.cbegin();
         ConstListIterator<int> iRhs = rhs.segments.cbegin(); 
         for ( ; iLhs != lhs.segments.cend() && iRhs != rhs.segments.cend();
               ++iLhs, ++iRhs)
            if (*iLhs > *iRhs)
               return true; 
         
         //if we make it here then they it must be greater than or equal to
         return false;
      }
   }
   else //they're both negative
   {
      //the easy cases
      if (lhs.segments.size() > rhs.segments.size())
         return false;
      else if (lhs.segments.size() < rhs.segments.size())
         return true;
      //Now we mus t compare every segment individually
      else
      {
         ConstListIterator<int> iLhs = lhs.segments.cbegin();
         ConstListIterator<int> iRhs = rhs.segments.cbegin(); 
         for ( ; iLhs != lhs.segments.cend() && iRhs != rhs.segments.cend();
               ++iLhs, ++iRhs)
            if (*iLhs > *iRhs)
               return false; 
         
         //if we make it here then they it must be greater than or equal to
         return true;
      }
   }
}

/************************************************************************
 * Less Than Operator
 * compares two Whole Numbers
 ***********************************************************************/
bool operator < (const WholeNumber & lhs, const WholeNumber & rhs)
{
   //check signs
   if (lhs.isNegative && !rhs.isNegative)
      return true;
   else if (!lhs.isNegative && rhs.isNegative)
      return false;
   else if (!lhs.isNegative && !rhs.isNegative)//they're both positive
   {
      //the easy cases
      if (lhs.segments.size() > rhs.segments.size())
         return false;
      else if (lhs.segments.size() < lhs.segments.size())
         return true;
      //Now we mus t compare every segment individually
      else
      {
         ConstListIterator<int> iLhs = lhs.segments.cbegin();
         ConstListIterator<int> iRhs = rhs.segments.cbegin(); 
         for ( ; iLhs != lhs.segments.cend() && iRhs != rhs.segments.cend();
               ++iLhs, ++iRhs)
            if (*iLhs < *iRhs)
               return true; 
         
         //if we make it here then they it must be greater than or equal to
         return false;
      }
   }
   else //they're both negative
   {
      //the easy cases
      if (lhs.segments.size() > rhs.segments.size())
         return true;
      else if (lhs.segments.size() < rhs.segments.size())
         return false;
      //Now we mus t compare every segment individually
      else
      {
         ConstListIterator<int> iLhs = lhs.segments.cbegin();
         ConstListIterator<int> iRhs = rhs.segments.cbegin(); 
         for ( ; iLhs != lhs.segments.cend() && iRhs != rhs.segments.cend();
               ++iLhs, ++iRhs)
            if (*iLhs < *iRhs)
               return false; 
         
         //if we make it here then they it must be greater than or equal to
         return true;
      }
   }
}

/************************************************************************
 * Equal To Operator
 * compares two Whole Numbers
 ***********************************************************************/
bool operator == (const WholeNumber & lhs, const WholeNumber & rhs)
{
   //the two easy cases
   if (lhs.segments.size() != rhs.segments.size())
      return false;
   else if (rhs.isNegative && !lhs.isNegative)
      return false;
   else if (!rhs.isNegative && lhs.isNegative)
      return false; 
   //Now we must compare every segment individually
   else
   {
      ConstListIterator<int> iLhs = lhs.segments.cbegin();
      ConstListIterator<int> iRhs = rhs.segments.cbegin(); 
      for ( ; iLhs != lhs.segments.cend() && iRhs != rhs.segments.cend();
            ++iLhs, ++iRhs)
         if (*iLhs != *iRhs)
            return false;

      //if we make it here then they it must be equal to each other
      return true;
   }
}

/************************************************************************
 * Addition
 * A private function that adds two whole numbers. Takes an optional
 * 3rd parameter that tells whether the result should be positive or negative
 ***********************************************************************/
WholeNumber addition(const WholeNumber & lhs,
                     const WholeNumber & rhs,
                     bool isNegativeResult)
{
   WholeNumber sum;

   ConstListIterator<int> iLhs = lhs.segments.crbegin();
   ConstListIterator<int> iRhs = rhs.segments.crbegin();

   int first,
       second,
       result,
       carry = 0;

   while (iLhs != lhs.segments.crend() || iRhs != rhs.segments.crend())
   {
      if (iLhs != lhs.segments.crend())
      {
         first = *iLhs;
         --iLhs;
      }
      else
         first = 0;

      if (iRhs != rhs.segments.crend())
      {
         second = *iRhs;
         --iRhs;
      }
      else
         second = 0;

      int temp = first + second + carry;
      result = temp % 1000;
      carry = temp / 1000;
      sum.segments.push_front(result);
   }

   if (carry > 0)
      sum.segments.push_front(carry);

   sum.isNegative = isNegativeResult; 
   return sum;
}

/************************************************************************
 * Subtraction
 * A private function that subtracts two whole numbers. Takes an optional
 * 3rd parameter that tells whether the result should be positive or negative
 ***********************************************************************/
WholeNumber subtraction(const WholeNumber & lhs,
                        const WholeNumber & rhs,
                        bool isNegativeResult)
{
   WholeNumber sum;

   ConstListIterator<int> iLhs = lhs.segments.crbegin();
   ConstListIterator<int> iRhs = rhs.segments.crbegin();

   int first,
       second,
       result,
       borrow = 0;

   //We assume the absolute value of lhs is greater than rhs
   while (iLhs != lhs.segments.crend() || iRhs != rhs.segments.crend())
   {
      if (iLhs != lhs.segments.crend())
      {
         first = *iLhs;
         --iLhs;
      }
      else
         first = 0;

      if (iRhs != rhs.segments.crend())
      {
         second = *iRhs;
         --iRhs;
      }
      else
         second = 0;

      //If we borrowed from the last subtraction then we need to add it here
      if (borrow)
         first -= 1;
      
      //Do we need to borrow this time?
      if (first < second)
         borrow = 1;
      else
         borrow = 0; 
      int temp = (first + borrow * 1000) - second;
      result = temp % 1000;

      if (iLhs != lhs.segments.crend() || temp)
         sum.segments.push_front(result); 

   } 

   sum.isNegative = isNegativeResult;
   
   return sum;
}
