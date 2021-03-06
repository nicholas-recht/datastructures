/***********************************************************************
* Program:
*    SortInsertion
* Author:
*    Nicholas Recht
* Summary: 
*    This is a header file which contains the Insertion Sort. Never use this
*    sort...
************************************************************************/
#ifndef SORTINSERTION_H
#define SORTINSERTION_H

#include <iostream>

/***********************************************************************
 * SortInsertion
 * Function for sorting an array using the insertion algorithm. Takes an
 * integer number of items in the array
 *********************************************************************/
template<class T>
void sortInsertion(T data[], int numItems)
{
   for (int wall = 1; wall < numItems; ++wall)
   {
      //binary sort
      int start = 0;
      int end = wall - 1;
      T temp = data[wall];
      int mid = 0;
      while (start <= end && end >= start)
      {
         mid = (start + end) / 2;
         if (temp > data[mid])
            start = mid + 1;
         else
            end = mid - 1;
      }
      //If the start is greater than the end than he should go to the next spot over
      if (temp > data[mid])
         ++mid; 
      //otherwise it's already in the right spot
      //Shift everything else
      for (int i = wall; i >= mid + 1; --i)
         data[i] = data[i - 1]; 
      
      //copy over the data
      data[mid] = temp;
      
   }
}


#endif
