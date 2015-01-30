/***********************************************************************
 * Header:
 *    WHOLENUMBER
 * Summary:
 *    Contains the header file for the WholeNumber class. This class is
 *    used to store arbitrarily long integers. The addition, multiplication,
 *    and subtraction operators are supported as well as the insertion
 *    and extraction operators. 
 * Author
 *    Nicholas Recht
 *    3 hrs (base)
 *    3 hrs (extra)
 *    The most difficult part was adding negative numbers and the subtraction
 *    operator
 ************************************************************************/

#ifndef WHOLENUMBER_H
#define WHOLENUMBER_H

#include "list.h"
#include <string>
#include <iostream>

/************************************************************************
 * The WholeNumber Class
 *  See description above
 ***********************************************************************/
class WholeNumber
{
  public:
   //Constructors
   WholeNumber() : isNegative(false) { } //default constructor does nothing
   WholeNumber(std::string input) : isNegative(false) { parseStr(input); }
   WholeNumber(int input); //constructor with an integer
   WholeNumber(const WholeNumber & rhs) : isNegative(false)
   { *this = rhs; } //copy constructor

   //Assignment Operators
   WholeNumber & operator = (const WholeNumber & rhs);
   WholeNumber & operator = (const int rhs);

   //Outputs the given whole Number
   friend std::ostream & operator <<
      (std::ostream & out, const WholeNumber & rhs);

   friend std::istream & operator >>
      (std::istream & in,        WholeNumber & rhs);

   //Operators

   //math
   friend WholeNumber operator + (const WholeNumber & lhs,
                                  const WholeNumber & rhs);
   friend WholeNumber operator - (const WholeNumber & lhs,
                                  const WholeNumber & rhs);
   friend WholeNumber operator * (const WholeNumber & lhs,
                                  const WholeNumber & rhs);

   friend WholeNumber pow(const WholeNumber & lhs,
                          const WholeNumber & rhs);
      
   //Comparison
   friend bool operator > (const WholeNumber & lhs,
                           const WholeNumber & rhs);
   friend bool operator < (const WholeNumber & lhs,
                           const WholeNumber & rhs);
   friend bool operator ==(const WholeNumber & lhs,
                           const WholeNumber & rhs);

   friend bool operator !=(const WholeNumber & lhs,
                           const WholeNumber & rhs)
   { return !(lhs == rhs); }

   friend bool operator >=(const WholeNumber & lhs,
                           const WholeNumber & rhs)
   { return (lhs > rhs || lhs == rhs); }

   friend bool operator <=(const WholeNumber & lhs,
                           const WholeNumber & rhs)
   { return (lhs < rhs || lhs == rhs); }

   //Other

   void operator += (const WholeNumber & rhs) { *this = *this + rhs; }
   void operator *= (const WholeNumber & rhs) { *this = *this * rhs; }

   //Addition function, makes asssumptions about lhs and rhs
   friend WholeNumber addition(const WholeNumber & lhs,
                               const WholeNumber & rhs,
                               bool isNegativeResult = false);

   //Subtraction function, makes assumptions about lhs and rhs
   friend WholeNumber subtraction(const WholeNumber & lhs,
                                  const WholeNumber & rhs,
                                  bool isNegativeResult = false);
   
  private:
   List<int> segments;

   bool isNegative; 

   //private function for converting a string into a whole number
   void parseStr(std::string input);

};


#endif //WHOLENUMBER_H
