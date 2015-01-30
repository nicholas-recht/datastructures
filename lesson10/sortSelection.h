/*********************************************************************
 * Selection Sort
 * Author: Justin Ricks
 ********************************************************************/

#ifndef SORT_SELECTION_H
#define SORT_SELECTION_H

template <class T>
void sortSelection(T * pArray, int numItems)
{
   for (int i = 0; i < numItems; ++i)
   {
      // i is the wall
      int iSmall = i;

      int j = i;

      // find the smallest value
      while (j < numItems)
      {
         if (pArray[iSmall] > pArray[j])
            iSmall = j;
         ++j;
      }

      // swap
      T temp = pArray[i];
      pArray[i] = pArray[iSmall];
      pArray[iSmall] = temp;
   }
}

#endif // SORT_SELECTION_H
