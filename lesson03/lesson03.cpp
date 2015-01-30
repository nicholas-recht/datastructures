/***********************************************************************
* Program:
*    Lesson 03, Queue
*    Brother Helfrich, CS 235
* Author:
*    Br. Helfrich
* Summary: 
*    This is a driver program to exercise the Queue class.  When you
*    submit your program, this should not be changed in any way.  That being
*    said, you may need to modify this once or twice to get it to work.
************************************************************************/

#include <iostream>    // for CIN and COUT
#include <string>      //
#include "queue.h"     // your Queue class should be in queue.h
#include "stock.h"     // your stocksBuySell() function
#include "dollars.h"   // for the Dollars class
using namespace std;


// prototypes for our four test functions
void testSimple();
void testPush();
void testPop();
void testErrors();

// To get your program to compile, you might need to comment out a few
// of these. The idea is to help you avoid too many compile errors at once.
// I suggest first commenting out all of these tests, then try to use only
// TEST1.  Then, when TEST1 works, try TEST2 and so on.
#define TEST1   // for testSimple()
#define TEST2   // for testPush()
#define TEST3   // for testPop()
#define TEST4   // for testErrors()

/**********************************************************************
 * MAIN
 * This is just a simple menu to launch a collection of tests
 ***********************************************************************/
int main()
{
   // menu
   cout << "Select the test you want to run:\n";
   cout << "\t1. Just create and destroy a Queue\n";
   cout << "\t2. The above plus push items onto the Queue\n";
   cout << "\t3. The above plus pop items off the Queue\n";
   cout << "\t4. The above plus exercise the error handling\n";
   cout << "\ta. Selling Stock\n";

   // select
   char choice;
   cout << "> ";
   cin  >> choice;
   switch (choice)
   {
      case 'a':
         stocksBuySell();
         break;
      case '1':
         testSimple();
         cout << "Test 1 complete\n";
         break;
      case '2':
         testPush();
         cout << "Test 2 complete\n";
         break;
      case '3':
         testPop();
         cout << "Test 3 complete\n";
         break;
      case '4':
         testErrors();
         cout << "Test 4 complete\n";
         break;
      default:
         cout << "Unrecognized command, exiting...\n";
   }

   return 0;
}

/*******************************************
 * TEST SIMPLE
 * Very simple test for a Queue: create and destroy
 ******************************************/
void testSimple()
{
#ifdef TEST1
   // Test1: a bool Queue with default constructor
   cout << "Create a bool Queue using the default constructor\n";
   Queue <bool> q1;
   cout << "\tSize:  " << q1.size() << endl;
   cout << "\tEmpty? " << (q1.empty() ? "Yes" : "No") << endl;

   // Test2: double Queue with non-default constructor
   cout << "Create a double Queue using the non-default constructor\n";
   Queue <double> q2(10 /*capacity*/);
   cout << "\tSize:  " << q2.size() << endl;
   cout << "\tEmpty? " << (q2.empty() ? "Yes" : "No") << endl;

   {
      // Test3: copy the bool Queue
      cout << "Copy the double Queue using the copy-constructor\n";
      Queue <double> q3(q2);
      cout << "\tSize:  " << q3.size() << endl;
      cout << "\tEmpty? " << (q3.empty() ? "Yes" : "No") << endl;
   }
   cout << "\tDestroying the third Queue\n";   
#endif //TEST1
}

/*******************************************
 * TEST PUSH
 * Add a whole bunch of items to the Queue.  This will
 * test the Queue growing algorithm
 *****************************************/
void testPush()
{
#ifdef TEST2
   // create
   cout << "Create a Dollars Queue with the default constructor\n";
   Queue <Dollars> q;
   Dollars noMoney;

   cout << "\tEnter money amounts, type $0 when done\n";
   Dollars money;
   do
   {
      cout << "\t> ";
      cin  >> money;
      if (money != noMoney)
      {
         q.push(money);
         cout << "\tPushed " << q.back() << endl;
      }
   }
   while (money != noMoney);

   // display how big it is
   cout << "\tSize:     " << q.size()                   << endl;
   cout << "\tEmpty?    " << (q.empty() ? "Yes" : "No") << endl;
   cout << "\tCapacity: " << q.capacity()               << endl;
#endif // TEST2   
}

/*******************************************
 * TEST POP
 * We will test both Queue::pop() and Queue::top()
 * to make sure the Queue looks the way we expect
 * it to look.
 ******************************************/
void testPop()
{
#ifdef TEST3
   // create
   cout << "Create a string Queue with the default constructor\n";
   Queue <string> q;

   // instructions
   cout << "\tTo add the word \"dog\", type +dog\n";
   cout << "\tTo pop the word off the queue, type -\n";
   cout << "\tTo see the front word and back word, type *\n";
   cout << "\tTo see the size and capacity, type ?\n";
   cout << "\tTo quit, type !\n";

   // interact
   char instruction;
   string word;
   try
   {
      do
      {
         cout << "\t> ";
         cin  >> instruction;
         switch (instruction)
         {
            case '+':
               cin >> word;
               q.push(word);
               break;
            case '-':
               q.pop();
               break;
            case '*':
               cout << q.front() << " ... " << q.back() << endl;
               break;
            case '?':
               cout << "Size:     " << q.size()                   << endl;
               cout << "Empty?    " << (q.empty() ? "Yes" : "No") << endl;
               cout << "Capacity: " << q.capacity()               << endl;
               break;
            case '!':
               break;
            default:
               cout << "Invalid command\n";
         }            
      }
      while (instruction != '!');
   }
   catch (const char * error)
   {
      cout << error << endl;
   }

   // verify that copy works as we expect
   Queue <string> qCopy(q);
   assert(q.size()     == qCopy.size()    );
   assert(q.capacity() == qCopy.capacity());
   assert(q.empty()    == qCopy.empty()   );
   while (!q.empty())
   {
      assert(q.front() == qCopy.front());
      assert(q.back()  == qCopy.back() );
      assert(q.size()  == qCopy.size() );
      q.pop();
      qCopy.pop();
   }
#endif // TEST3
}

/*******************************************
 * TEST ERRORS
 * Numerous error conditions will be tested
 * here, including bogus popping and the such
 *******************************************/
void testErrors()
{
#ifdef TEST4
   // create
   cout << "Create a char queue with the default constructor\n";
   Queue <char> q;

   // test using front() with an empty queue
   try
   {
      q.front();
      cout << "BUG! We should not be able to front() with an empty queue!\n";
   }
   catch (const char * error)
   {
      cout << "\tQueue::front() error message correctly caught.\n"
           << "\t\"" << error << "\"\n";
   }

   // test using back() with an empty queue
   try
   {
      q.back();
      cout << "BUG! We should not be able to back() with an empty queue!\n";
   }
   catch (const char * error)
   {
      cout << "\tQueue::back() error message correctly caught.\n"
           << "\t\"" << error << "\"\n";
   }

   // test using pop() with an empty queue
   try
   {
      q.pop();
      cout << "BUG! We should not be able to pop() with an empty queue!\n";
   }
   catch (const char * error)
   {
      cout << "\tQueue::pop() error message correctly caught.\n"
           << "\t\"" << error << "\"\n";
   }      
#endif // TEST4
}
