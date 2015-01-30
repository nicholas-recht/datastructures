/*********************************************************
 * Merge Sort
 * Author: Justin Ricks
 ********************************************************/

#ifndef SORT_MERGE_H
#define SORT_MERGE_H

#include <iostream> // for null
#include <cassert>

/********************************************************
 * sortMerge
 * This function implements the merge sort.
 *******************************************************/
template <class T>
void sortMerge(T * array, int numItems) throw (const char *)
{
   // Arrays to copy between
   T * source = array;
   T * dest   = NULL;
   
   // indices used in the sort
   int iFirstBegin  = 0;
   int iFirstMax    = 0;
   int iSecondBegin = 0;
   int iSecondMax   = 0;
   int iDest        = 0;

   // allocate a twin array of the same size to merge into
   try
   {
      dest = new T[numItems];
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Could not allocate a new buffer for the merge sort";
   }

   /*************************************************
    * INFINITE LOOP! -- needs explaination --
    * Sounds crazy, but the only way out is if there
    * is only one subarry in the array. This condition
    * is checked inside the loop within this infinite
    * one.
    ************************************************/
   while (true)
   {
      // loop until we've gone through the entire array
      while (iFirstBegin < numItems)
      {
         /************** FIND SUBARRAYS **************/
         
         // get the proper iFirstMax
         iFirstMax = iFirstBegin;
         while (!(source[iFirstMax] > source[iFirstMax + 1]) && iFirstMax < numItems)
            ++iFirstMax;
         ++iFirstMax; // max is one past the end

         // same with iSecondMax
         iSecondBegin = iSecondMax = iFirstMax;
         while (!(source[iSecondMax] > source[iSecondMax + 1])
                && iSecondMax < numItems)
            ++iSecondMax;
         ++iSecondMax;

         /************** EXIT CONDITION ************/
         if (iFirstBegin == 0 && iFirstMax == numItems)
         {
            if (dest == array)
            {
               // swap dest and source
               T * temp = source;
               source = dest;
               dest = temp;

               // copy all the data over
               for (int i = 0; i < numItems; ++i)
                  source[i] = dest[i];
            }

            // clean up
            delete [] dest;

            // get out of dodge
            return;
         }


         /*************** MERGE ****************/
         iDest = iFirstBegin;

         while (iFirstBegin < iFirstMax && iSecondBegin < iSecondMax
                && iFirstBegin < numItems && iSecondBegin < numItems)
         {
            assert(iFirstMax < numItems && iSecondBegin < numItems);

            // put in the smaller of the two
            if (source[iFirstBegin] > source[iSecondBegin])
            {
               dest[iDest] = source[iSecondBegin];
               ++iSecondBegin;
            }
            else
            {
               dest[iDest] = source[iFirstBegin];
               ++iFirstBegin;
            }
         
            ++iDest;
         }

         // make sure to get all the items from both subarrays
         while (iFirstBegin < iFirstMax && iFirstBegin < numItems)
         {
            assert(iFirstBegin < numItems);
            assert(iDest < numItems);
         
            dest[iDest] = source[iFirstBegin];
            ++iFirstBegin;
            ++iDest;
         }
         while (iSecondBegin < iSecondMax && iSecondBegin < numItems)
         {
            assert(iSecondBegin < numItems);
            assert(iDest < numItems);

            dest[iDest] = source[iSecondBegin];
            ++iSecondBegin;
            ++iDest;
         }

         // set the new iFirstBegin to be where we left off
         iFirstBegin = iSecondMax;

      }


      // swap source and dest
      T * temp = source;
      source = dest;
      dest = temp;

      // re-initialize indices
      iFirstBegin = 0;
   }
}

#endif // SORT_MERGE_H
