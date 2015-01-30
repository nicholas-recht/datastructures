/***********************************************************************
 * Module:
 *    Lesson 11, Spell Check
 *    Brother Helfrich, CS 235
 * Author:
 *    Nicholas Recht
 * Summary:
 *    This program implements the spell check function. It first reads
 *    in a dictionary file, then asks for a file to check. It returns
 *    all words that are not found in the dictionary, presumed to be
 *    misspelled
 ************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "spellCheck.h"
#include "dictionaryHash.h"
#include "list.h"
using namespace std;

/*****************************************
 * SPELL CHECK
 * Prompt the user for a file to spell-check
 ****************************************/
void spellCheck()
{

   string input; 
   //Read in our Dictionary
   DictionaryHash h(140);
   ifstream fin("/home/cs235/lesson11/dictionary.txt");
   while (fin >> input)
   {
      input[0] = tolower(input[0]); 
      h.insert(input);
   }
   fin.close();
   
   //Get our other file
   cout << "What file do you want to check? ";
   cin  >> input;
   
   fin.open(input.c_str());

   //Check each word in the file
   List<string> errors; 
   while (fin >> input)
   {
      //because we are changing the original input
      string inputCopy = input;
      
      input[0] = tolower(input[0]); 
      if (!h.find(input))
         errors.push_back(inputCopy);
   }
         
   if (errors.size() == 0)
      cout << "File contains no spelling errors\n";
   else
   {
      cout << "Misspelled: ";
      
      ListIterator<string> it = errors.begin();
      for (; it != errors.rbegin(); ++it)
      {
         cout << *it << ", "; 
      }

      cout << *it << endl; 
     
   }
}
