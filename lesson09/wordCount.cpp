/***********************************************************************
 * Module:
 *    Lesson 09, WORD COUNT
 *    Brother Helfrich, CS 235
 * Author:
 *    <your name here>
 * Summary:
 *    This program will implement the wordCount() function
 ************************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include "map.h"       // for MAP
#include "wordCount.h" // for wordCount() prototype

using namespace std;

void readFile(Map <string, int> & counts, const string & fileName);

/*****************************************************
 * WORD COUNT
 * Prompt the user for a file to read, then prompt the
 * user for words to get the count from
 *****************************************************/
void wordCount()
{
   Map <string, int> words;
   
   string input;

   cout << "What is the filename to be counted? ";
   cin  >> input;

   readFile(words, input);

   cout << "What word whose frequency is to be found. Type ! when done\n";
   
   do
   {
      cout << "> ";
      cin  >> input;

      if (input == "!")
         break;

      if (words.find(input) != words.end())
         cout << "\t" << input << " : " << words[input] << endl;
      else
         cout << "\t" << input << " : " << "0" << endl;
      
   } while (input != "!");
}

/*****************************************************
 * READ FILE
 * Read the words from a file into a map
 *****************************************************/
void readFile(Map <string, int> & counts, const string & fileName)
{
   ifstream fin;
   string temp;

   fin.open(fileName.c_str());

   while (fin >> temp)
   {
      if (counts.find(temp) == counts.end())
         counts[temp] = 1;
      else
         counts[temp] += 1;
   }
}
