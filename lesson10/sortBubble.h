/***********************************************************************
* Program:
*    SortBubble
* Author:
*    Nicholas Recht
* Summary: 
*    This is a header file which contains the Bubble Sort. Never use this
*    sort...
************************************************************************/
#ifndef SORTBUBBLE_H
#define SORTBUBBLE_H

#include <iostream>

/************************************************************************
 * sortBubble
 * Sorts a passed array of any type, given a number of items in the array
 ***********************************************************************/
template<class T>
void sortBubble(T data [], int numItems)
{
   int counter = 0; 
   int i, numSwaps; 
   
   while (counter < numItems - 1)
   {
      i = 0; 
      numSwaps = 0; 
      while (i < numItems - 1 - counter)
      {
         if (data[i] > data[i + 1])
         {
            T temp = data[i];
            data[i] = data[i + 1];
            data[i + 1] = temp;
            ++numSwaps; 
         }
         
         ++i;
      }
      if (numSwaps == 0)
         return; //the list must be already sorted
      ++counter; 
   }
}

#endif
