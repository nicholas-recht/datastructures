/*********************************************************
 * Quick Sort!
 * There are two functions in here. The sortQuick is the
 * outward facing interface that will get called by the
 * driver program. It is really just a wrapper function for
 * the recursive function that takes different parameters to
 * work.
 * The quickSort function is where the quickSort actually
 * takes place. It is recursive in nature, but works on the
 * same array; it doesn't copy it every time, which makes it
 * pretty useful.
 *
 * NOTE: this algorithm works for any data type (T) that has
 * overloaded the > operator
 *
 * Author: Justin Ricks, adapted from the algorithm given
 * at http://www.algolist.net/Algorithms/Sorting/Quicksort
 ********************************************************/

#ifndef SORT_QUICK_H
#define SORT_QUICK_H

/********************************************************
 * The quickSort function. Where the magic happens :)
 *******************************************************/
template <class T>
void quickSort(T arr[], int iFirst, int iLast)
{
   int iLeft = iFirst;
   int iRight = iLast;

   // pick the pivot. don't make a copy, just use the index
   int iPivot = (iFirst + iLast) / 2;

   // put everything less than the pivot to the left, and
   // everything else to the right
   while (iLeft <= iRight)
   {
      while (arr[iPivot] > arr[iLeft])
         iLeft++;

      while (arr[iRight] > arr[iPivot])
         iRight--;

      if (iLeft <= iRight)
      {
         T tmp = arr[iLeft];
         arr[iLeft] = arr[iRight];
         arr[iRight] = tmp;

         // check if the pivot moved
         if (iPivot == iLeft)
            iPivot = iRight;
         else if (iPivot == iRight)
            iPivot = iLeft;
         
         iLeft++;
         iRight--;
      }
   }

   // recursion
   if (iFirst < iRight)
      quickSort(arr, iFirst, iRight);

   if (iLeft < iLast)
      quickSort(arr, iLeft, iLast);
}

/*********************************************************
 * sortQuick
 * This function derives the correct parameters for the
 * recursive quick sort function and calls it. Not very
 * interesting.
 ********************************************************/
template <class T>
void sortQuick(T arr[], int numItems)
{
   quickSort(arr, 0, numItems - 1);
}

#endif // SORT_QUICK_H
