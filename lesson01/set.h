/***********************************************************************
 * Header File
 *    This is the header file for a Set Class
 * Summary:
 *     A self expanding container class that only stores unique data. 
 * Author:
 *    Nicholas Recht
 *
 *    Estimated:  3.0 hrs
 *    Actual:     5.0 hrs
 *      The most difficult part was creating a good locate function and
 *      and distiguishing between where and item should go or if it was found
 ************************************************************************/

#ifndef SET_H
#define SET_H

#include <iostream>
#define ERROR_ALLOCATION "Error: Unable to Allocate Memory"

//Forward Declaration of SetIterator
template <class T>
class SetIterator;


template <class T>
class Set
{
  public:
   
   //Default Constructor; Simply sets the size and capacity to 0
  Set() : data(NULL), maxSize(0), numItems(0) {   }

   //Constructor that takes an initial capacity as a parameter
   //Throws an exception if the space can't be allocated
   Set(int capacity) throw (char *);

   //Copy Constructor. Also throws exception if space can't be allocated
   Set(const T & rhs) throw (char *)
   {
      try {
         *this = rhs; }
      catch (char * p) {
         throw p; }
   }

   //Destructor; frees the memory
   ~Set() { if (numItems > 0) delete [] data; }

   //Insert; Adds an item to the set; Throws an exception if space can't
   //be allocated
   void insert(const T & item) throw (char *);

   //Empty. Returns a boolean value of whether the set is currently empty
   bool empty() const {  return !numItems; }

   //Size; returns an int value of the number of items in the set
   int size() const { return numItems; }

   //Clear; clears all the items from the Set
   void clear() { numItems = 0; }

   //Erase. Removes an item from the set based on an iterator pointing
   //to the item. 
   void erase(SetIterator<T> it);

   //Find. Takes a templated item as a parameter and returns an
   //iterator to the corresponing item in the set
   SetIterator <T> find(const T & item) const; 

   //= Operator. Copies all data from one set to this set. Throws
   // exception if the allocation fails
   Set<T> & operator = (const Set & rhs) throw (char *);

   //&& operator. Performs the intersection operation. Takes a Set
   //as a parameter and returns a new set containing the elements that
   //both this set and that set contain
   Set<T> operator && (const Set & rhs) const throw(char *);

   //|| operator. Performs the union function. Returns a new set with
   //all the elemnts from the other two sets.
   Set<T> operator || (const Set & rhs) const throw(char *); 

   //begin; returns an iterator to the first item in the set 
   SetIterator <T> begin() const  {return SetIterator<T>(data); }

   //end; returns an iterator to the last item in the set
   SetIterator <T> end() const    {return SetIterator<T>(data + numItems); }   
   
  private:
   T * data;
   int maxSize;
   int numItems;

   //Member function used for resizing. Throws exception if allocation fails
   void resize(int newSize) throw (char *);

   //Private Locate function. Returns an integer index where an item should
   //be or where a copy of that item already is
   int locate(const T & item) const;
   
};

/**************************************************
 * SET ITERATOR
 * An iterator through the Set Class
 *************************************************/
template <class T>
class SetIterator
{
  public:
   // default constructor
  SetIterator() : p(NULL) {}

   // initialize to direct p to some item
  SetIterator(T * p) : p(p) {}

   // copy constructor
   SetIterator(const SetIterator & rhs) { *this = rhs; }

   // assignment operator
   SetIterator & operator = (const SetIterator & rhs)
   {
      this->p = rhs.p;
      return *this;
   }

   // not equals operator
   bool operator != (const SetIterator & rhs) const
   {
      return rhs.p != this->p;
   }

   // Equal to Operator
   bool operator == (const SetIterator & rhs) const
   {
      return rhs.p == this->p;
   }

   // dereference operator
   T & operator * ()
   {
      return *p;
   }

   // prefix increment
   SetIterator <T> & operator ++ ()
   {
      p++;
      return *this;
   }

   //prefix decrement
   SetIterator <T> & operator -- ()
   {
      p--;
      return *this;
   }

   // postfix increment
   SetIterator <T> operator++(int postfix)
   {
      SetIterator tmp(*this);
      p++;
      return tmp;
   }

   //postfix decrement
   SetIterator <T> operator--(int postfix)
   {
      SetIterator tmp(*this);
      p--;
      return tmp;
   }

  private:
   T * p;
};

/**************************************************
 * SET::Find
 * Takes an item; returns an iterator pointing to that item
 * or the end iterator if the item isn't found
 *************************************************/
template<class T>
SetIterator<T> Set<T>::find(const T & item) const
{
   int iMiddle = locate(item);
   if (data[iMiddle] == item)
      return SetIterator<T> (data + iMiddle);
   else
      return end(); 

   return end();

}

/**************************************************
 * SET::resize
 * Internal function for reallocating memory. Throws
 * an exception if the allocation fails. 
 *************************************************/
template<class T>
void Set<T>::resize(int newSize) throw (char *)
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

   for (int i = 0; i < numItems; i++)
      temp[i] = data[i];

   delete [] data;

   data = temp; 
}

/**************************************************
 * SET::insert
 * Inserts an item into the set. If the item already
 * is in the set then nothing happens. Throws exception
 * if memory allocation fails. 
 *************************************************/
template<class T>
void Set<T>::insert(const T & item) throw (char *)
{
   //Reallocations
   if (numItems >= maxSize)
   {
      if (maxSize == 0)
      {
      
         resize(1);
         maxSize = 1;
      }
      else
      {

         resize(maxSize * 2);
         maxSize *= 2;
      }
   }
    
   if (numItems > 1)
   {
      int iMiddle = locate(item);
      bool doPut = false;
      if (data[iMiddle] == item)
         doPut = false;
      else
      {
         if (iMiddle == numItems - 1)
         {
            if (item > data[iMiddle])
               iMiddle++;
         }
         else if (iMiddle == 0)
         {
            if (item > data[0])
               iMiddle++;
         }
         else if (item > data[iMiddle])
            iMiddle++; 

         doPut = true; 
      }
      //If we didn't find it in the list, then we insert it
      if (doPut)
      {
         numItems++;
         //Move each item "up" one spot in the array
         for (int i = (numItems - 1); i > iMiddle; i--)
            data[i] = data[i - 1]; 
         data[iMiddle] = item; 
      }
   }
   else if (numItems == 1)
   {
      if  (item != data[0])
      {
         if (item > data[0])
            data[1] = item;
         else 
         {
            data[1] = data[0];
            data[0] = item; 
         }
         numItems++;
      }
   }
   else //special case where it is an empty set; we just add it; 
   {
      numItems++; 
      data[0] = item;
   }

}

/**************************************************
 * SET::Set
 * Non-default constructor. Sets the capacity to an iteger value
 *************************************************/
template<class T>
Set<T>::Set(int capacity) throw (char *)
{
   numItems = 0;
   maxSize = 0;
   data = NULL;

   resize(capacity);
   maxSize = capacity;
   
}

/**************************************************
 * SET::operator =
 * Assignment operator; copies the contents of one set
 * to this set
 *************************************************/
template<class T>
Set<T> & Set<T>::operator = (const Set & rhs) throw (char *)
{

   if (this->maxSize < rhs.maxSize)
   {
 
      resize(rhs.maxSize);
 
   }
   
   numItems = rhs.numItems;
   maxSize = rhs.maxSize;
   
   for (int i = 0; i < maxSize; i++)
      data[i] = rhs.data[i]; 
   
   return *this; 

}

/**************************************************
 * SET::erase
 * Takes an iterator pointing to an item in the set
 * which is then removed.
 *************************************************/
template<class T>
void Set<T>::erase(SetIterator<T> it)
{
   //Push each item back starting with our initial iterator
   SetIterator<T> temp = it;
   
   for (++it; it != end(); ++it)
   {
      *temp = *it;
      ++temp; 
   }
   
   numItems--;
   
}

/**************************************************
 * SET::locate
 * An internal function that takes an item. Searches for the
 * given item and returns an index to it or to where it should
 * go in the order. 
 *************************************************/
template<class T>
int Set<T>::locate(const T & item) const
{
   if (numItems > 0)
   {
      int iBegin = 0; 
      int iEnd = numItems - 1;
      int iMiddle = -1; 
      
      //Check ends first
      if (data[numItems - 1] <= item)
         return (numItems - 1); 
      else if (data[0] >= item)
         return 0;
      else
      {
         while (iBegin <= iEnd)
         {
            iMiddle = (iBegin + iEnd) / 2;
            if (item == data[iMiddle])
               return iMiddle;  
            else if (item > data[iMiddle])
               iBegin = iMiddle + 1;
            else
               iEnd = iMiddle - 1;
         }
      }
      
      return iMiddle; 
   }
   else
      return 0; 
}

/**************************************************
 * SET::operator ||
 * Union operator. Returns a new set containing the elements
 * of both this set and another
 *************************************************/
template<class T>
Set<T> Set<T>::operator||(const Set & rhs) const throw(char *)
{
   int iMax;
   if (numItems > rhs.numItems)
      iMax = numItems;
   else
      iMax = rhs.numItems;

   Set<T> tempSet(iMax); 
   
   int i = 0;
   int j = 0;
   
   while (i < numItems && j < rhs.numItems)
   {
      if (data[i] == rhs.data[j])
      {
         tempSet.insert(data[i]);
         i++;
         j++; 
      }
      else if (data[i] > rhs.data[j])
      {
         tempSet.insert(rhs.data[j]);
         j++;
      }
      else
      {
         tempSet.insert(data[i]);
         i++;
      }
   }
   //IF  THERES any left on one of the sets
   if (i < numItems)
   {
      for (; i < numItems; i++)
         tempSet.insert(data[i]);
   }
   else if (j < numItems)
   {
      for (; j < rhs.numItems; j++)
         tempSet.insert(rhs.data[j]);
   }
   
   return tempSet;

}

/**************************************************
 * SET::operator &&
 * Intersection operator. Returns a new set containing the
 * elements that both this and that set share.  
 *************************************************/
template<class T>
Set<T> Set<T>::operator&&(const Set & rhs) const throw(char *)
{
   int iMax;
   if (numItems > rhs.numItems)
      iMax = numItems;
   else
      iMax = rhs.numItems;
      
   Set<T> tempSet(iMax);
   
   int i = 0;
   int j = 0;
   
   while (i < numItems && j < rhs.numItems)
   {
      if (data[i] == rhs.data[j])
      {
         tempSet.insert(data[i]);
         i++;
         j++;
      }
      else if (data[i] > rhs.data[j])
      {
         j++;
      }
      
      else //rhs.data[j] > data[i]
      {
         i++;
      }
   }
   
   return tempSet; 
      
   
}


#endif //SET_H

