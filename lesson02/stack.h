/***********************************************************************
 * Header File
 *    This is the header file for a Set Class
 * Summary:
 *    This is a stack class. It store and allows retieval of data on a 
 *    last-in first out basis.
 * Author:
 *    Adam Cameron
 *
 *    Estimated:  4.0 hrs
 *    Actual:     3.0 hrs
 *      The most difficult part getting the exception handling to work
 *      right. They didn't work till I thew (const char*) as opposed to
 *      just (char*).
 ************************************************************************/

#ifndef STACK_H
#define STACK_H

#include <iostream>
#define ERROR_ALLOCATION "ERROR: Unable to allocate a new buffer for Stack"

/*************************************************************
* STACK CLASS
*************************************************************/
template <class T>
class Stack
{
   public:
      
      //default constructor
      Stack() : data(NULL), maxSize(0), numItems(0){}

      //copy constructor
      Stack(const Stack<T> & rhs);
  
      //constructor: sets initial size
      Stack(int size) throw(const char *);
      
      //destructor
      ~Stack() {if (numItems) delete [] data;}

      // returns a boolean value of whether the set is currently empty
      bool empty() const {return !(numItems);}

      // returns an int value of the number of items in the set
      int size() const {return numItems;}

      // clears all the items from the stack
      void clear() {numItems = 0;}

      // adds a element to the "top" of the stack
      void push(const T & input) throw(const char*);

      // removes the last item added from the stack
      void pop() throw(const char*);

      // references the last item added
      T & top() throw(const char*);

   private:
      T * data;
      int maxSize;
      int numItems;

      //member function used for resizing. Throws exception if allocation fails
      void resize() throw (const char *);
         
};

/***************************************************
* STACK: COPY CONSTRUCTOR
***************************************************/
template<class T>
Stack<T> :: Stack(const Stack<T> & rhs)
{
   //copy information
   numItems = 0;
   maxSize = rhs.maxSize;
   data = new T[rhs.maxSize];

   //do nothing else if size is 0
   if (!maxSize)
      return;

   //copy the data
   while (numItems < rhs.numItems)
   {
      data[numItems] = rhs.data[numItems];
      numItems++;
   }
   return;
}

/***************************************************
* STACK: CONSTRUCTOR
*    Accepts an integer to be used as the starting 
*    size of the stack.
***************************************************/
template<class T>
Stack<T> :: Stack(int size) throw (const char *)
{
   //standard start for numItems
   numItems = 0;
   //maxSize set to input
   maxSize = size;

   //attempt to create an array of the specified size
   try
   {
      data = new T[size];
   }
   //throw an exeption if the allocation fails
   catch (...)
   {
      throw ERROR_ALLOCATION;
   }
}

/***************************************************
* STACK: RESIZE
*    Re-allocates the stack to be twice as large.
***************************************************/
template<class T>
void Stack<T>::resize() throw (const char *)
{
   //attempt to create an array twice as large as data
   T * temp;
   try
   {
      temp = new T[2*maxSize];
   }
   //throw an exeption if the allocation fails
   catch (...)
   {
      throw ERROR_ALLOCATION;
   }

   //copy data elements to new array
   for (int i = 0; i < numItems; i++)
      temp[i] = data[i];

   //delete odd array
   delete [] data;

   //adjust member variables
   data = temp;
   maxSize *= 2;
}

/***************************************************
* STACK: PUSH
*    Adds the inputted element to the top of the
*    stack. Will increase the size of the stack if 
*    neccesary.
***************************************************/
template<class T>
void Stack<T> :: push(const T & input) throw(const char*)
{
   //for a size 0 stack
   if (data == NULL)
   {
      data = new T[1];
      maxSize = 1;
   }

   // for a full stack
   if (maxSize == numItems)
      resize();
   
   //pushing the data
   numItems++;
   top() = input;
}

/***************************************************
* STACK: POP
*    Removes the top element of the stack. Throws an
*    exception if the stack is empty.
***************************************************/
template<class T>
void Stack<T> :: pop() throw(const char*)
{
   // for an empty stack
   if (!numItems)
      throw "ERROR: Unable to pop from an empty Stack";
   
   // remove the most recently adding element
   numItems--;
   return;
}

/***************************************************
* STACK: TOP
*    References the top element of the stack. Throws
*    an exception if the stack is empty.
***************************************************/
template<class T>
T & Stack<T> :: top() throw(const char*)
{
   // for an empty stack
   if (!numItems)
      throw "ERROR: Unable to reference the element from an empty Stack";

   //refence the most recently adding element
   return data[numItems - 1];
}

#endif //STACK_H
