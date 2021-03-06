#include <iostream>
#include <fstream>
#include <string>
#include "hash.h"

using namespace std;

int intFromChar(const char c)
{
   return c - 'a';
}

class TestHash : public Hash <string>
{
public:
   TestHash(int num)  throw (const char *) : Hash <string> (num) {};
   TestHash(const TestHash & rhs) throw (const char *) : Hash <string> (rhs){};

protected:
   virtual int hash(const string & value) const
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

int main()
{
   TestHash h(140);
   
   string input = "dictionary.txt";

   /*
   cout << "Filename: ";
   cin  >> input;
   */

   ifstream fin(input.c_str());

   while (fin >> input)
      h.insert(input);

   h.display();

   
   return 0;
}
