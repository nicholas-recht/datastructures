/***********************************************************************
* Header:
*    Vector
* Summary:
*    This class contains the vector class, based off the stl vector class.
*
*    This will contain the class definition of:
*        Vector            : A container class that behaves like a
*                            dynamically allocating array
*        VectorIterator    : An Iterator that runs through the vector
* Author
*    Nicholas Recht
************************************************************************/

#ifndef VECTOR_H
#define VECTOR_H

//#include <cassert>

// forward declaration for VectorIterator
template <class T>
class VectorIterator;
template <class T>
//forward declaration for VectorConstIterator
class VectorConstIterator;

/**********************************************************************
 * VECTOR
 * A class that acts like an array but dynamically allocates memory
 **********************************************************************/
template <class T>
class Vector
{
public:
   // default constructor : empty and kinda useless
   Vector() : numItems(0), maxSize(0), data(0x00000000) {}

   // copy constructor : copy it
   Vector(const Vector & rhs) throw (const char *);
   
   // non-default constructor : pre-allocate
   Vector(int maxSize) throw (const char *);
   
   // destructor : free everything
   ~Vector()        { if (maxSize) delete [] data; }
   
   // is the container currently empty
   bool empty() const  { return numItems == 0;         }

   // remove all the items from the vector
   void clear()        { numItems = 0;                 }

   // how many items are currently in the vector?
   int size() const    { return numItems;              }

   // what is the maxSize of the vector?
   int capacity() const { return maxSize; } 
   
   // add an item to the vector
   void push_back(const T & t) throw (const char *);

   // return an iterator to the beginning of the list
   VectorIterator <T> begin() { return VectorIterator<T>(data); }

   //returns an iterator to the end of the list, used for traversing the list
   //in reverse
   VectorIterator <T> rbegin() {
      return VectorIterator<T>(data + (numItems - 1));  }

   // return an iterator to the end of the list
   VectorIterator <T> end() { return VectorIterator<T>(data + numItems);}

   //returns an iterator to the end of the list, used for traversing the list
   //in reverse which is actually the beginning element minus one
   VectorIterator <T> rend() {
      return VectorIterator<T>(data - 1);      }

    // return a const iterator to the beginning of the list
   VectorConstIterator <T> cbegin() const {
      return VectorConstIterator<T>(data); }

   //returns a const iterator to the end of the list,
   //used for traversing the list
   //in reverse
   VectorConstIterator <T> crbegin() const {
      return VectorConstIterator<T>(data + (numItems - 1));  }

   // return a const iterator to the end of the list
   VectorConstIterator <T> cend() const {
      return VectorConstIterator<T>(data + numItems);}

   //returns a const iterator to the end of the list,
   //used for traversing the list
   //in reverse which is actually the beginning element minus one
   VectorConstIterator <T> crend() const {
      return VectorConstIterator<T>(data - 1);      }

   //Square Bracket Operator; Returns item by reference in data array
   //by an integer index; throws an exception if the index is out of range
   T & operator[](int index) throw (const char *)
   {
      if (index > numItems - 1 || index < 0)
         throw "ERROR: Invalid index";
      else
         return *(data + index); 
   };

   //Functor; Functions the same as the square bracked operator but returns
   //a copy of the data for read only; 
   T operator() (int index) throw (const char *)
   {
      if (index > numItems - 1 || index < 0)
         throw "ERROR: Invalid index";
      else
         return *(data + index);
   };
   
   //Assignment Operator. Copy the data from one vector to another
   T & operator = (const T & rhs) throw (const char *); 

   
   
private:
   T * data;          // dynamically allocated array of T
   int numItems;      // how many items are currently in the Container?
   int maxSize;      // how many items can I put on the Container before full?
};

/**************************************************
 * VECTOR ITERATOR
 * An iterator through the Vector Class
 *************************************************/
template <class T>
class VectorIterator
{
  public:
   // default constructor
  VectorIterator() : p(0x00000000) {}

   // initialize to direct p to some item
  VectorIterator(T * p) : p(p) {}

   // copy constructor
   VectorIterator(const VectorIterator & rhs) { *this = rhs; }

   // assignment operator
   VectorIterator & operator = (const VectorIterator & rhs)
   {
      this->p = rhs.p;
      return *this;
   }

   // not equals operator
   bool operator != (const VectorIterator & rhs) const
   {
      return rhs.p != this->p;
   }

   // Equal to Operator
   bool operator == (const VectorIterator & rhs) const
   {
      return rhs.p == this->p;
   }

   // dereference operator
   T operator * ()
   {
      return *p;
   }

   // prefix increment
   VectorIterator <T> & operator ++ ()
   {
      p++;
      return *this;
   }

   //prefix decrement
   VectorIterator <T> & operator -- ()
   {
      p--;
      return *this;
   }

   // postfix increment
   VectorIterator <T> operator++(int postfix)
   {
      VectorIterator tmp(*this);
      p++;
      return tmp;
   }

   //postfix decrement
   VectorIterator <T> operator--(int postfix)
   {
      VectorIterator tmp(*this);
      p--;
      return tmp;
   }
   
  private:
   T * p;
};

/**************************************************
 * VECTOR CONST ITERATOR
 * An iterator through the Vector Class
 *************************************************/
template <class T>
class VectorConstIterator
{
  public:
   // default constructor
  VectorConstIterator() : p(0x00000000) {}

   // initialize to direct p to some item
  VectorConstIterator(T * p) : p(p) {}

   // copy constructor
   VectorConstIterator(const VectorConstIterator & rhs) { *this = rhs; }

   // assignment operator
   VectorConstIterator & operator = (const VectorConstIterator & rhs)
   {
      this->p = rhs.p;
      return *this;
   }

   // not equals operator
   bool operator != (const VectorConstIterator & rhs) const
   {
      return rhs.p != this->p;
   }

   // Equal to Operator
   bool operator == (const VectorConstIterator & rhs) const
   {
      return rhs.p == this->p;
   }

   // dereference operator
   T & operator * ()
   {
      return *p;
   }

   // prefix increment
   VectorConstIterator <T> & operator ++ ()
   {
      p++;
      return *this;
   }

   //prefix decrement
   VectorConstIterator <T> & operator -- ()
   {
      p--;
      return *this;
   }

   // postfix increment
   VectorConstIterator <T> operator++(int postfix)
   {
      VectorConstIterator tmp(*this);
      p++;
      return tmp;
   }

   //postfix decrement
   VectorConstIterator <T> operator--(int postfix)
   {
      VectorConstIterator tmp(*this);
      p--;
      return tmp;
   }

  private:
   T * p;
};


/*******************************************
 * Vector :: COPY CONSTRUCTOR
 *******************************************/
template <class T>
Vector <T> :: Vector(const Vector <T> & rhs) throw (const char *)
{
   //assert(rhs.maxSize >= 0);
      
   // do nothing if there is nothing to do
   if (rhs.maxSize == 0)
   {
      maxSize = numItems = 0;
      data = 0x00000000;
      return;
   }

   // attempt to allocate
   try
   {
      data = new T[rhs.maxSize];
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate a new buffer for Vector";
   }
   
   // copy over the stuff
   //assert(rhs.numItems >= 0 && rhs.numItems <= rhs.maxSize);
   maxSize = rhs.maxSize;
   numItems = rhs.numItems;
   for (int i = 0; i < numItems; i++)
      data[i] = rhs.data[i];

   return;
}

/**********************************************
 * Vector : NON-DEFAULT CONSTRUCTOR
 * Preallocate the container to "maxSize"
 **********************************************/
template <class T>
Vector <T> :: Vector(int maxSize) throw (const char *)
{
   //assert(maxSize >= 0);
   
   // do nothing if there is nothing to do
   if (maxSize == 0)
   {
      this->maxSize = this->numItems = 0;
      this->data = 0x00000000;
      return;
   }

   // attempt to allocate
   try
   {
      data = new T[maxSize];
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate a new buffer for Vector";
   }

      
   // copy over the stuff
   this->maxSize = maxSize;
   this->numItems = 0;
}

/***************************************************
 * Vector :: push_back
 * Insert an item on the end of the Vector. If no
 * space is available, the maxSize of the vector is doubled
 **************************************************/
template <class T>
void Vector <T> :: push_back(const T & t) throw (const char *)
{
   // do we have space?
   if (maxSize == 0 || maxSize <= numItems)
   {
      if (maxSize == 0)
         maxSize = 1;
      else
         maxSize *= 2;

      T * temp;
      try
      {
         temp = new T[maxSize];
      }
      catch (std::bad_alloc)
      {
         throw "ERROR: Unable to allocate a new buffer for Vector";
      }
      for (int i = 0; i < numItems; i++)
         temp[i] = data[i];

      delete [] data;
      data = temp; 
   }
  
   // addan item to the end
   data[numItems++] = t;
}

/***************************************************
 * Vector :: = Operator
 * Copy the data from the rhs to this Vector
 **************************************************/
template <class T>
T & Vector<T>::operator = (const T & rhs) throw (const char *)
{
   //assert(rhs.maxSize >= 0);

   // do nothing if there is nothing to do
   if (rhs.maxSize == 0)
   {
      numItems = 0;
      maxSize = 0;
      data = 0x00000000;
      return *this; 
   }
       
   if (maxSize <= rhs.numItems)
   {
      /* for (VectorIterator <T> it = rhs.begin(); it != rhs.end(); ++it)
         push_back(*it);*/
      for (int i = 0; i < rhs.numItems; i++)
         data[i] = rhs[i]; 
         
   }
   else
   {
      //Reallocate Memory
      delete [] data;
      maxSize = rhs.maxSize;
      numItems = rhs.numItems;

      // attempt to allocate
         try
      {
         data = new T[maxSize];
      }
      catch (std::bad_alloc)
      {
         throw "ERROR: Unable to allocate a new buffer for Vector";
      }
      
   }
   
   return *this; //because we want to dereference "this" so we can
                 //pass it by reference
}

#endif //VECTOR_H
