/***********************************************************************
* hash.h
*    Hash ADT; this contains an abstract hash class, for which it is only
*    necessary to override the 'hash()' method to get working. Everything
*    else is done in this base class.
* Author:
*    Justin Ricks
* Contains:
*    A Hash class
************************************************************************/

#ifndef HASH_H
#define HASH_H

#include <iostream> // for NULL
#include <cassert>
#include "list.h"

/***********************************************************************
* HASH CLASS
* The main event!
************************************************************************/
template <class T>
class Hash
{
public:
   // Constructors
   Hash(unsigned int num) throw (const char *);

   Hash(const Hash <T> & rhs)
      : numItems(0), numBuckets(0), table(NULL) { *this = rhs; };

   // Destructor
   ~Hash() { delete [] table; };

   // Assignment Operator
   Hash & operator = (const Hash & rhs) throw (const char *);

   // Is the hash empty?
   bool empty() const { return (numItems == 0); };

   // How many elements are in the table?
   unsigned int size() const { return numItems; };

   // how many buckets are in the hash?
   unsigned int capacity() const { return numBuckets; };

   // Does this item exist in the table?
   bool find(const T & t);

   // insert an item into the hash table
   void insert(const T & t);

   //display function
   void display() const;
   
protected:

   // the hash function
   virtual int hash(const T & t) const = 0;

   unsigned int numItems;
   unsigned int numBuckets;

   // array of lists to store everything
   List <T> * table;

};

/***********************************************************************
* HASH :: NON-DEFAULT CONSTRUCTOR
* Allocate a given number of buckets in the hash table
************************************************************************/
template <class T>
Hash <T> :: Hash(unsigned int num) throw (const char *)
: numItems(0), numBuckets(num), table(NULL)
{
   // allocate the table
   try
   {
      table = new List <T> [num];
   }

   catch (std::bad_alloc)
   {
      throw "ERROR: Could not allocate an arrray for Hash";
   }
}

/***********************************************************************
* HASH :: ASSIGNMENT OPERATOR
* Deallocate the table
************************************************************************/
template <class T>
Hash <T> & Hash <T> :: operator = (const Hash <T> & rhs) throw (const char *)
{
   if (table != NULL)
      delete [] table;

   numBuckets = numItems = 0;

   try
   {
      table = new List <T> [rhs.numBuckets];
      this->numBuckets = rhs.numBuckets;
      this->numItems = rhs.numItems;
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Cannot allocate an array for Hash";
   }

   for (int i = 0; i < rhs.numBuckets; i++)
      this->table[i] = rhs.table[i];

}

/***********************************************************************
* HASH :: INSERT
* Put the item into the correct bucket based on the hash function
************************************************************************/
template <class T>
void Hash <T> :: insert(const T & t)
{
   // get the correct index from the hash function
   int iBucket = hash(t);

   assert(iBucket >= 0 && iBucket < numBuckets);

   // put the item into the correct tree
   table[iBucket].push_back(t);

   ++numItems;
}

/***********************************************************************
* HASH :: FIND
* Determine whether an item is in the hash table
************************************************************************/
template <class T>
bool Hash <T> :: find(const T & t)
{
   // get the correct index from the hash function
   int iBucket = hash(t);

   assert(iBucket >= 0 && iBucket < numBuckets);

   ListIterator <T> it = table[iBucket].begin();
   for ( ; it != table[iBucket].end(); ++it)
   {
      if (*it == t)
         return true;
   }

   return false;
}

/**********************************************************************
 * HashDisplay
 * A test function for diplaying all the items in a hash
 *********************************************************************/
template <class T>
void Hash <T> :: display() const
{
   for (int i = 0; i < numBuckets; ++i)
   {
      std::cout << i << ": ";

      int j = 0;
      
      for (ListIterator<T> it = table[i].begin(); it != table[i].end(); ++it)
      {
         std::cout << *it << ", ";
         ++j;
      }

      std::cout << "\nTotal: " << j;

      std::cout << "\n------------------------------------------------------\n"; 
   }
}
#endif // HASH_H
