/***********************************************************************
* Program:
*    Lesson 11, Hash
*    Brother Helfrich, CS 235
* Author:
*    Br. Helfrich
* Summary: 
*    This is a driver program to exercise the Hash class.  When you
*    submit your program, this should not be changed in any way.  That being
*    said, you may need to modify this once or twice to get it to work.
************************************************************************/

#include <iostream>      // for CIN and COUT
#include <string>        // for STRING
#include "hash.h"        // for Hash class which should be in hash.h
#include "spellCheck.h"  // for the spellCheck prototype
using namespace std;


// prototypes for our four test functions
void testSimple();
void testAdd();
void testCopy();
void testQuery();

// To get your program to compile, you might need to comment out a few
// of these. The idea is to help you avoid too many compile errors at once.
// I suggest first commenting out all of these tests, then try to use only
// TEST1.  Then, when TEST1 works, try TEST2 and so on.
#define TEST1   // for testSimple()
#define TEST2   // for testAdd()
#define TEST3   // for testCopy()
#define TEST4   // for testQuery()

/**********************************************************************
 * MAIN
 * This is just a simple menu to launch a collection of tests
 ***********************************************************************/
int main()
{
   // menu
   cout << "Select the test you want to run:\n";
   cout << "\t1. Just create and destroy a hash\n";
   cout << "\t2. The above plus add a few entries\n";
   cout << "\t3. The above plus copy a hash table\n";
   cout << "\t4. The above plus look for the entries\n";
   cout << "\ta. Spell check\n";

   // select
   char choice;
   cout << "> ";
   cin  >> choice;
   switch (choice)
   {
      case 'a':
         spellCheck();
         break;
      case '1':
         testSimple();
         cout << "Test 1 complete\n";
         break;
      case '2':
         testAdd();
         cout << "Test 2 complete\n";
         break;
      case '3':
         testCopy();
         cout << "Test 3 complete\n";
         break;
      case '4':
         testQuery();
         cout << "Test 4 complete\n";
         break;
      default:
         cout << "Unrecognized command, exiting...\n";
   }

   return 0;
}

/****************************************
 * I HASH
 * A simple hash of integers
 ****************************************/
class IHash : public Hash <int>
{
public:
   IHash(int numBuckets)    throw (const char *) : Hash <int> (numBuckets) {}
   IHash(const IHash & rhs) throw (const char *) : Hash <int> (rhs)        {}

   // hash function for integers is simply to take the modulous
   int hash(const int & value) const
   {
      return value % capacity();
   }
};

/****************************************
 * S HASH
 * A simple hash of strings
 ****************************************/
class SHash : public Hash <string>
{
public:
   SHash(int numBuckets)    throw (const char *) : Hash <string> (numBuckets){}
   SHash(const SHash & rhs) throw (const char *) : Hash <string> (rhs)       {}

   // hash function for strings will add up all the ASCII values
   int hash(const string & s) const
   {
      int value = 0;
      for (const char * p = s.c_str(); *p; p++)
         value += *p;
      return value % capacity();
   }
};

/*******************************************
 * TEST SIMPLE
 * Very simple test for a Hash: create and destroy
 ******************************************/
void testSimple()
{
#ifdef TEST1
   // Test1: an integer hash
   cout << "Create an integer Hash\n";
   IHash h(5);
   cout << "\tEmpty?    " << (h.empty() ? "yes" : "no") << endl;
   cout << "\tSize:     " << h.size()                   << endl;
   cout << "\tCapacity: " << h.capacity()               << endl;

   // Test1: a string hash
   cout << "Create a string Hash\n";
   SHash * ph = new SHash(7);
   cout << "\tEmpty?    " << (ph->empty() ? "yes" : "no") << endl;
   cout << "\tSize:     " << ph->size()                   << endl;
   cout << "\tCapacity: " << ph->capacity()               << endl;
   delete ph;
   
#endif //TEST1
}

/*******************************************
 * TEST ADD
 * Add a few elements to our Hash
 *****************************************/
void testAdd()
{
#ifdef TEST2
   // create
   cout << "Create a small integer hash\n";
   IHash h(10);
   cout << "\tEmpty?    " << (h.empty() ? "yes" : "no") << endl;
   cout << "\tSize:     " << h.size()                   << endl;
   cout << "\tCapacity: " << h.capacity()               << endl;

   // fill
   cout << "Fill with 12 values\n";
   h.insert(213);  // h[0] -->
   h.insert(431);  // h[1] --> 431 --> 991 --> 101 --> 111
   h.insert(534);  // h[2] --> 452 --> 982
   h.insert(452);  // h[3] --> 213 --> 123
   h.insert(123);  // h[4] --> 534
   h.insert(991);  // h[5] --> 005
   h.insert(982);  // h[6] --> 626
   h.insert(626);  // h[7] -->
   h.insert(408);  // h[8] --> 408
   h.insert(101);  // h[9] -->
   h.insert(111);
   h.insert(005);
   cout << "\tEmpty?    " << (h.empty() ? "yes" : "no") << endl;
   cout << "\tSize:     " << h.size()                   << endl;
   cout << "\tCapacity: " << h.capacity()               << endl;

#endif // TEST2   
}

/*******************************************
 * TEST COPY
 * Create a few Hashes and copy them into each other
 ******************************************/
void testCopy()
{
#ifdef TEST3
   // create a hash of capacity 25 but 100 items in it
   cout << "A hash of 25 buckets\n";
   IHash h1(25);
   for (int i = 0; i < 100; i++)
      h1.insert(i);
   cout << "\tEmpty?    " << (h1.empty() ? "yes" : "no") << endl;
   cout << "\tSize:     " << h1.size()                   << endl;
   cout << "\tCapacity: " << h1.capacity()               << endl;
   
   // use the copy constructor
   cout << "Copy the hash into another\n";
   IHash h2(h1);
   cout << "\tEmpty?    " << (h2.empty() ? "yes" : "no") << endl;
   cout << "\tSize:     " << h2.size()                   << endl;
   cout << "\tCapacity: " << h2.capacity()               << endl;

   // create a hash of 10 items and assign h1 into it
   cout << "Create a hash of 5 buckets\n";
   IHash h3(5);
   cout << "\tEmpty?    " << (h3.empty() ? "yes" : "no") << endl;
   cout << "\tSize:     " << h3.size()                   << endl;
   cout << "\tCapacity: " << h3.capacity()               << endl;

   // copy the large hash into this smaller one
   cout << "Copy the large hash of 25 buckets into the small one of 5\n";
   h3 = h1;
   cout << "\tEmpty?    " << (h3.empty() ? "yes" : "no") << endl;
   cout << "\tSize:     " << h3.size()                   << endl;
   cout << "\tCapacity: " << h3.capacity()               << endl;
#endif // TEST3
}

/*******************************************
 * TEST QUERY
 * Prompt the user for items to put in the hash
 * and then allow the user to query for items
 *******************************************/
void testQuery()
{
#ifdef TEST4
   cout << "Test adding and querying items from the hash:\n";
   cout << "  +dog   Put \"dog\" into the hash\n";
   cout << "  ?dog   Determine if \"dog\" is in the hash\n";
   cout << "  !      Display the size and capacity of the hash\n";
   cout << "  #      Quit\n";

   // create the hash
   SHash h(5);
   
   // interact
   char instruction;
   string word;
   do
   {
      cout << "> ";
      cin  >> instruction;
      switch (instruction)
      {
         case '+':
            cin >> word;
            h.insert(word);
            break;
         case '?':
            cin >> word;
            cout << '\t' << (h.find(word) ? "Found!" : "not found") << endl;
            break;
         case '!':
            cout << "\tEmpty?    " << (h.empty() ? "yes" : "no") << endl;
            cout << "\tSize:     " << h.size()                   << endl;
            cout << "\tCapacity: " << h.capacity()               << endl;
            break;
         case '#':
            break;
         default:
            cout << "Invalid command\n";
      }
   }
   while (instruction != '#');
#endif // TEST4
}

