/***********************************************************************
 * Header:
 *    DEQUE_H
 * Summary:
 *    This is the header file for the deque class. The deque is a template
 *    container class that behaves as first-in, first-out and can be added to
 *    from both ends; 
 * Author
 *    Nicholas Recht
 * Time:
 *    EST: 2hrs
 *    ACT: 2.5hrs
 *         The most difficult part was working with negative indexes
 ************************************************************************/

#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include <cassert>

#define ERROR_ALLOCATION "ERROR: Unable to allocate a new buffer for deque"
#define ERROR_EMPTY "ERROR: unable to access data from an empty deque"
#define ERROR_POP_FRONT "ERROR: unable to pop from the front of empty deque"
#define ERROR_POP_BACK "ERROR: unable to pop from the back of empty deque"


/**************************************************************************
 * Deque Class
 * A template container that behaves as first-in, first-out. Items can be
 * added to either end of the deque using the push_back, push_front functions
 * and then be removed from either end with the pop functions. Only the
 * front and end items of the deque can be accessed. 
 **************************************************************************/
template<class T>
class Deque
{
  public: 
   //default constructor. Does almost nothing
   Deque() : numFront(0), numBack(0), maxSize(0), data(NULL) {       }
   //non-default construct. Assigns capacity to passed integer value. Throws
   //if the allocation fails
   Deque(int newSize) throw(const char *) :
         numFront(0), numBack(0), maxSize(0), data(NULL)
   {
      resize(newSize);
   }
   
   //copy constructor. Assigns the contents of the referenced queue to this
   Deque(const Deque & q) throw(const char *) :
   numFront(0), numBack(0), maxSize(0), data(NULL)
   {
       *this = q;
   }
   
   //Destructor. Frees the allocated memory
   ~Deque() { if (maxSize != 0) delete [] data; }

   //Assignment Operator. Copies the contents of another queue to this
   Deque<T> & operator = (const Deque & rhs) throw (const char *);

   //empty. Returns a boolean value of whether the set is empty or not
   bool empty() const { return (size() == 0); }

   //size. Returns the number of items in the dequeue. 
   int size() const  { return numBack - numFront; }
   
   //capacity; returns an integer value of the capacity of the dequeue
   int capacity() const { return maxSize; }

   //clear; Empties the dequeue of all items
   void clear()
   {
      numFront = 0;
      numBack = 0; 
   }

   //push_front; adds an item to the front of the deque. Throws an error
   //            if allocation fails
   void push_front(const T & item) throw(const char *); 

   //pop_front: pops an item off of the front of the deque. Throws an error
   //           if the deque is empty
   void pop_front() throw(const char *);

   //push_back; adds an item to the back of the deque. Throws an error
   //           if allocation fails
   void push_back(const T & item) throw(const char *); 

   //pop_back: removes an item off of the back of the deque. Throws an error
   //          if the deque is empty
   void pop_back() throw(const char *);

   //front; returns the item currently at the front of the queue. Throws an
   //       error if the queue is empty
   T & front() throw(const char *);

   //back; returns the item currently at the back of the queue. Throws an
   //      error if the queue is empty
   T & back() throw (const char *);
   
  private:

   //Reallocates memory to grow the queue. Throws an error if allocation fails
   void resize(int newSize) throw(const char *);

   //head; gives the integer index of the head of my queue
   int head() const; 

   //end; gives the integer index of the end of the queue
   int end() const;
   
   T * data;
   int numFront; //The number of pushes and pops to the front of my deque
   int numBack; //The number of pushes and pops to the back of my deque
   int maxSize; 
};


/**************************************************************************
 * Deque::head
 * returns an integer index to where an item should be pushed in the front.
 * Or the next index of where an item should be added to the front
 **************************************************************************/
template<class T>
int Deque<T>::head() const
{
   if (maxSize > 0)
      if (numFront > 0)
         return (numFront - 1) % maxSize;
      else
         return (maxSize - 1) + (numFront % maxSize); 
   else
      return 0; 
}

/**************************************************************************
 * Deque::end
 * Returns an integer index to where the last item in the deque should
 * be placed. Or where the next item will be pushed to the back
 **************************************************************************/
template<class T>
int Deque<T>::end() const
{
   if (maxSize > 0)
      if (numBack >= 0)
         return numBack % maxSize;
      else
         return maxSize + (numBack % maxSize);
   else
      return 0; 
}

/**************************************************************************
 * Deque:: = operator
 * copies the data of rhs deque to this deque. Throws if allocation fails
 **************************************************************************/
template<class T>
Deque<T> & Deque<T>::operator = (const Deque<T> & rhs) throw(const char *)
{
   if (rhs.capacity() != 0)
   {
      if (maxSize < rhs.maxSize)
         resize(rhs.maxSize);

      
      int iRhs = 0;
      if (rhs.head() != rhs.maxSize - 1)
         iRhs = rhs.head() + 1; //counter for rhs queue
      int iLhs = 0; //counter for this queue
      
      //stop once all our elements  have been copied
      while(iLhs < rhs.size())
      {
         //wrap around if we've reached the end
         if (iRhs > rhs.maxSize - 1)
            iRhs = 0;
      
         data[iLhs] = rhs.data[iRhs];
         iRhs++;
         iLhs++;
      }

      //Reset our push and pops to the beginning and end
      numBack = rhs.size();
      numFront = 0;
     
   }
   else //if it's empty just clear this Queue
      clear(); 
}


/**************************************************
 * Deque::resize
 * Internal function for reallocating memory. Throws
 * an exception if the allocation fails. 
 *************************************************/
template<class T>
void Deque<T>::resize(int newSize) throw (const char *)
{
   T * temp;
   try
   {
      temp = new T[newSize];
   }
   catch (...)
   {
      throw ERROR_ALLOCATION;
   }
   if (maxSize != 0)
   {
      //Loop; start with the front and loop through until we've reached the head        
      int iTemp = 0;
      int iData = 0;
      if (head() != maxSize - 1)
         iData = head() + 1; //counter for rhs queue
      
      //stop once all our elements  have been copied
      while(iTemp < size())
      {
         //wrap around if we've reached the end
         if (iData > maxSize - 1)
            iData = 0;
         
         temp[iTemp] = data[iData];
         iTemp++;
         iData++; 
      }
   
      assert(NULL != data);
      delete [] data;
   }
   data = temp;

   numBack = size();
   numFront = 0; 
   maxSize = newSize;
   
}

/**************************************************************************
 * Deque::push_back
 * Adds an item to the back of the deque. Throws if allocation fails
 **************************************************************************/
template<class T>
void Deque<T>::push_back(const T & item) throw(const char *)
{
   //resize if needed
   if (size() == maxSize)
   {
      if (maxSize == 0)
         resize(1);
      else
         resize(maxSize * 2);
   }

   //assign our item; 
   data[end()] = item;
   numBack++; 
}

/**************************************************************************
 * Deque::pop
 * Removes the first item from the back of the deque. Throws if the
 * deque is empty. 
 **************************************************************************/
template<class T>
void Deque<T>::pop_back() throw(const char *)
{
   //Throw if it is empty
   if (size() == 0)
      throw ERROR_POP_BACK;
   else
   {
      numBack--; 
   }
}

/**************************************************************************
 * Deque::push_front
 * Adds an item to the beginning on the deque. Throws if allocation fails
 **************************************************************************/
template<class T>
void Deque<T>::push_front(const T & item) throw(const char *)
{
   //resize if needed
   if (size() == maxSize)
   {
      if (maxSize == 0)
         resize(1);
      else
         resize(maxSize * 2);
   }

   //assign our item; 
   data[head()] = item;
   numFront--; 
}

/**************************************************************************
 * Deque::pop
 * Removes the first item from the front of the deque. Throws if the
 * deque is empty. 
 **************************************************************************/
template<class T>
void Deque<T>::pop_front() throw(const char *)
{
   //Throw if it is empty
   if (size() == 0)
      throw ERROR_POP_FRONT;
   else
   {
      numFront++; 
   }
}

/****************************************************************************
 * Deque::front; returns the item currently at the front of the deque. Throws an
 *       error if the deque is empty
 ****************************************************************************/
template<class T>
T & Deque<T>::front() throw(const char *)
{
   if (size() != 0)
   {
      if (maxSize > 1)//Special Case
      {
         //wrap around to the beginning
         if (head() == maxSize - 1)
            return data[0];
         else
            return data[head() + 1];
      }
      else
         return data[0]; 
   }
   else
      throw ERROR_EMPTY;
}

/**************************************************************************
 * Deque::back; returns the item currently at the back of the deque. Throws an
 *     error if the deque is empty
 *************************************************************************/
template<class T>
T & Deque<T>::back() throw (const char *)
{
   if (size() != 0)
   {
      //wrap around to the end
      if (end() == 0)
         return data[maxSize - 1]; 
      else
         return data[end() - 1];
   }
   else
      throw ERROR_EMPTY; 
}

#endif //QUEUE_H
