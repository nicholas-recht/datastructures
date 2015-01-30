/***********************************************************************
* Program:
*    SortHeap
* Author:
*    Nicholas Recht
* Summary: 
*    This is a header file which contains the Heap Class and the sortHeap
*    function
************************************************************************/
#ifndef SORTHeap_H
#define SORTHeap_H

#include <iostream>

/***************************************************************
 * Heap Class
 * Used almost exclusively for sorting an array
 ***************************************************************/
template<class T>
class Heap
{
public:
	//Constructor; Assigns the pointer and copies the numItems
	Heap(T * data, int numItems);
	//Destructor
	~Heap() { }; //we don't want to delete the array?
	//getMax; returns the value of the max item in the heap
	T & getMax() { return *(data + 1); } 
	//deleteMax; removes maximum item from heap
	void deleteMax();
	//heapify; turns given array into a heap
	void heapify(); 
	//sort; performs a sort on an array using the heap
	void sort(); 
	//percolateDown; recursive function that takes an integer index to start from
	void percolateDown(int index); 

private:
	//For simplicity later; gets the parent/children of a given node
	int lChild(int index) { if (index * 2 <= numItems) return (index * 2); 
							else return -1; }
	int rChild(int index) { if (index * 2 + 1 <= numItems) return (index * 2 + 1);
							else return -1; }
	int parent(int index) { if (index > 1) return (index / 2);
							else return -1; }
	T * data;
	int numItems;
};

/***************************************************************
* heap
* assigns the data pointer and the numItems
***************************************************************/
template<class T>
Heap<T>::Heap(T * data, int numItems)
{
   this->data = data; 
   this->numItems = numItems;
   
   --this->data; //because Heaps are 1 based 
}

/***************************************************************
* deleteMax
* swaps the maximum item with the last item and decrements numItems
***************************************************************/
template<class T>
void Heap<T>::deleteMax()
{
   //swap the first and last item
   if (numItems > 1)
   {
      T tmp = *(data + 1);
      *(data + 1) = *(data + numItems);
      *(data + numItems) = tmp;
   }
   
   //decrement the numItems
   --numItems;
}

/***************************************************************
* percolateDown
* assumes a semi-heap and recursively converts the semi-heap into
* a heap
***************************************************************/
template<class T>
void Heap<T>::percolateDown(int index)
{
   int iLCh = lChild(index);
   int iRCh = rChild(index); 
   //check if we have children?
   if (iLCh > 0 && iRCh > 0)
   {
      //check if the children are bigger
      if (*(data + iLCh) > *(data + index) || *(data + iRCh) > *(data + index))
      {
         //which child is bigger?
         //Left
         if (*(data + iLCh) > *(data + iRCh))
         {
            //swap and recursion
            T tmp = *(data + index);
            *(data + index) = *(data + iLCh);
            *(data + iLCh) = tmp;
            
            percolateDown(iLCh);
         }
         //Right
         else
         {
            //swap and recursion
            T tmp = *(data + index);
            *(data + index) = *(data + iRCh);
            *(data + iRCh) = tmp;
            
            percolateDown(iRCh);
         }
      }
   }
   else if (iLCh > 0)
   {
      if (*(data + iLCh) > *(data + index))
      {
         //swap and recursion
         T tmp = *(data + index);
         *(data + index) = *(data + iLCh);
         *(data + iLCh) = tmp;
         
         percolateDown(iLCh);
      }
   }
   //else do nothing
}

/***************************************************************
* Heapify
* Converts an array into a valid heap
***************************************************************/
template<class T>
void Heap<T>::heapify()
{
   //find the last node that is not a leaf
   int index = numItems / 2;  
   
   //Now percolate down on this subtree and work our way back up
   while (index >= 1)
   {
      percolateDown(index);
      --index;
   }
   
}

/***************************************************************
* sort
* Sorts a heap into accending order
***************************************************************/
template<class T>
void Heap<T>::sort()
{
   while (numItems > 0)
   {
      deleteMax();
      percolateDown(1); 
   }
}

/***************************************************************
* sortHeap
* Takes an array of data and an integer number of Items
* Sorts the passed array into accending order using the heap method
***************************************************************/
template<class T>
void sortHeap(T data[], int numItems)
{
   Heap<T> h(data, numItems); 
   
   h.heapify();
   
   h.sort(); 
}




#endif
