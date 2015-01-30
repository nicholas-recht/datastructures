/***********************************************************************
* DictionaryHash.h
*    DictionaryHash is an instance of the Hash Class which uses strings
* Author:
*    Nicholas Recht, Justin Ricks
* Contains:
*    A Derived Hash Class for use for spell check. "Massaged" to work
*    with the words in a dictionary
*
*    For our hash function, we used the first and middle letters to
*    decide which bucket a word should go into.
*    We used the relative frequency of the first letters of words for
*    the first bucket giving a value of 0-13, then the relative frequency
*    of other letters in our dictionary to give a value of 0-9. We then
*    wrote a driver function to analyze the distribution of buckets and
*    made small swaps where necessary to try and even out spread.
************************************************************************/
#ifndef DICTIONARYHASH_H
#define DICTIONARYHASH_H

#include "hash.h"
#include <string>

int intFromChar(const char c)
{
   return c - 'a';
}

class DictionaryHash : public Hash <std::string>
{
public:
   DictionaryHash(int num)  throw (const char *) : Hash <std::string> (num) {};
   DictionaryHash(const DictionaryHash & rhs) throw (const char *) : Hash <std::string> (rhs){};

protected:
   virtual int hash(const std::string & value) const
   {

      const int firstLetter[] = // 0 or 1
      // a  b  c  d  e  f  g  h  i  j  k  l  m  n
         {0, 6, 3, 13, 9, 7, 9, 2, 2, 12, 12, 11, 8, 8,
          
        //o  p  q  r  s  t  u  v  w  x  y  z
          5, 5, 12, 12, 10, 1, 11, 12, 4, 12, 12, 12 };
      
      const int middleLetter[]= // 0 - 9
       // a  b  c  d  e  f  g  h  i  j  k  l  m  n
         {0, 0, 2, 2, 1, 2, 7, 8, 3, 4, 7, 6, 5, 5,

       // o  p  q  r  s  t  u  v  w  x  y  z
          4, 6, 4, 8, 9, 7, 9, 4, 8, 4, 2, 4 };

   return (firstLetter[intFromChar(tolower(value[0]))] * 10)
      + (middleLetter[intFromChar(tolower(value[value.size() / 2]))]);
  }  
};

#endif
