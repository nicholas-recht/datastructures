/***********************************************************************
 * Header:
 *    INSERTION SORT
 * Summary:
 *    This will contain just the prototype for insertionSortTest(). You may
 *    want to put other class definitions here as well.
 * Author
 *    Nicholas Recht
 * Time
 *    1.5 hrs
 *    The most difficult part was finding an error in our pPrev pointer
 ************************************************************************/

#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "node.h"
#include "assert.h"

//A test function to go backwards through the list
template<class T>
void testReverseDisplay(Node <T> * pHead);

//Returns a point to a node of the preceding Node to be used in an insert
template<class T>
Node <T> * insertionFind(Node <T> * lHead, T value);


/***********************************************
 * INSERTION SORT
 * Sort the items in the array
 **********************************************/
template <class T>
void sortInsertion(T array[], int num)
{
   if (num > 0) //we don't do anything if the num is 0
   {
      //Create a new head for our list
      Node <T> * lHead = NULL;
      insert(array[0], lHead, true);
      
      for (int i = 1; i < num; ++i)
      {
         Node <T> * tNode = insertionFind(lHead, array[i]);
         if (tNode == NULL)
            insert(array[i], lHead, true);
         else
            insert(array[i], tNode); 
      }
      
      //Copy the sorted data back to the array
      int i = 0;
      Node <T> * tNode = lHead;
      while(tNode)
      {
         array[i++] = tNode->data;
         tNode = tNode->pNext;
      }

      //delete the old list
      freeData(lHead); 
   }
}

/****************************************************************
 * INSERTION FIND
 * Takes a pointer to the head of a linked list and a value to compare.
 * Returns a NULL pointer if the item should be placed at the head of the
 * list and otherwise returns a pointer to the node previous to where
 * the value should be inserted
 ****************************************************************/
template<class T>
Node <T> * insertionFind(Node <T> * lHead, T value)
{
   if (value < lHead->data)
   {
      return NULL; 
   }
   else
   {
      for (Node <T> * tNode = lHead; tNode; tNode = tNode->pNext)
      {
         //if we're at the end then insert it at the end
         if (!tNode->pNext)
         {
            return tNode; 
         }
         else if (!(value > tNode->pNext->data))
         {
            //Insert after this one if it's not
            //greater than the next and end the loop
            return tNode; 
         }
         
      }
   }
}
      

/*************************************************************
 * TEST REVERSE DISPLAY
 * Traverses a list in reverse order and displays the contents
 *************************************************************/
template<class T>
void testReverseDisplay(Node <T> * pHead)
{
   while(pHead->pNext)
      pHead = pHead->pNext;

   while(pHead)
   {
      std::cout << pHead->data << ", ";
      pHead = pHead->pPrev;
   }

   std:: cout << std::endl; 
}

#endif // INSERTION_SORT_H

