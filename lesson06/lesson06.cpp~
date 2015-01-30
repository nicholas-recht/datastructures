/***********************************************************************
* Program:
*    Lesson 06, LIST
*    Brother Helfrich, CS 235
* Author:
*    Br. Helfrich
* Summary: 
*    This is a driver program to exercise the List class.  When you
*    submit your program, this should not be changed in any way.  That being
*    said, you may need to modify this once or twice to get it to work.
************************************************************************/

#include <iostream>     // for CIN and COUT
#include <iomanip>      // for SETW
#include <string>       // for the String class
#include "list.h"       // your List class should be in list.h
#include "fibonacci.h"  // your fibonacci() function
using namespace std;


// prototypes for our four test functions
void testSimple();
void testPush();
void testIterate();
void testInsertRemove();

// To get your program to compile, you might need to comment out a few
// of these. The idea is to help you avoid too many compile errors at once.
// I suggest first commenting out all of these tests, then try to use only
// TEST1.  Then, when TEST1 works, try TEST2 and so on.
#define TEST1   // for testSimple()
#define TEST2   // for testPush()
#define TEST3   // for testIterate()
#define TEST4   // for testInsertRemove()

/**********************************************************************
 * MAIN
 * This is just a simple menu to launch a collection of tests
 ***********************************************************************/
int main()
{
   // menu
   cout << "Select the test you want to run:\n";
   cout << "\t0. Fibonacci\n";
   cout << "\t1. Just create and destroy a List\n";
   cout << "\t2. The above plus push items onto the List\n";
   cout << "\t3. The above plus iterate through the List\n";
   cout << "\t4. The above plus insert and remove items from the list\n";

   // select
   int choice;
   cout << "> ";
   cin  >> choice;
   switch (choice)
   {
      case 0:
         fibonacci();
         break;
      case 1:
         testSimple();
         cout << "Test 1 complete\n";
         break;
      case 2:
         testPush();
         cout << "Test 2 complete\n";
         break;
      case 3:
         testIterate();
         cout << "Test 3 complete\n";
         break;
      case 4:
         testInsertRemove();
         cout << "Test 4 complete\n";
         break;
      default:
         cout << "Unrecognized command, exiting...\n";
   }

   return 0;
}

/*******************************************
 * TEST SIMPLE
 * Very simple test for a List: create and destroy
 ******************************************/
void testSimple()
{
#ifdef TEST1
   cout.setf(ios::fixed | ios::showpoint);
   cout.precision(5);
   
   // Test1: a bool List with default constructor
   cout << "Create a bool List using the default constructor\n";
   List <bool> l1;
   cout << "\tEmpty? " << (l1.empty() ? "Yes" : "No") << endl;

   // Test2: double List and add one element
   cout << "Create a double List and add one element: 3.14159\n";
   List <double> l2;
   l2.push_back(3.14159);
   cout << "\tEmpty? " << (l2.empty() ? "Yes" : "No") << endl;
   cout << "\tFront: " << l2.front()                  << endl;
   cout << "\tBack:  " << l2.back()                   << endl;
   
   {
      // Test3: copy the double List
      cout << "Copy the double List using the copy-constructor\n";
      List <double> l3(l2);
      cout << "\tEmpty? " << (l3.empty() ? "Yes" : "No") << endl;
      cout << "\tFront: " << l3.front()                  << endl;
      cout << "\tBack:  " << l3.back()                   << endl;
   }
   cout << "\tDestroying the third List\n";   
#endif //TEST1
}

/*******************************************
 * TEST PUSH
 * Add a whole bunch of items to the List.  This will
 * test the push_back() and push_front() algorithm
 *****************************************/
void testPush()
{
#ifdef TEST2
   // create
   cout << "Create an integer List with the default constructor\n";
   List <int> l;
   cout << "\tEmpty? " << (l.empty() ? "Yes" : "No") << endl;

   // test push_back
   cout << "Test push_back() by adding items to the back of the list\n";
   cout << "\tEnter integer values, type 0 when done\n";
   int value;
   do
   {
      cout << "\t> ";
      cin  >> value;
      if (value)
      {
         l.push_back(value);

         // display the front and the back
         cout << "\t\tFront: " << l.front()
              << "    Back: "  << l.back()
              << endl;
      }
   }
   while (value);

   // test empty
   cout << "Test clear() to remove all the items\n";
   l.clear();
   cout << "\tEmpty? " << (l.empty() ? "Yes" : "No") << endl;

   // test push_front
   cout << "Test push_front() by adding items to the front of the list\n";
   cout << "\tEnter integer values, type 0 when done\n";
   do
   {
      cout << "\t> ";
      cin  >> value;
      if (value)
      {
         l.push_front(value);

         // display the front and the back
         cout << "\t\tFront: " << l.front()
              << "    Back: "  << l.back()
              << endl;
      }
   }
   while (value);
#endif // TEST2   
}

/*******************************************
 * TEST ITERATE
 * We will test the iterators. We will go through the
 * list forwards and backwards
 ******************************************/
void testIterate()
{
#ifdef TEST3
   // create
   cout << "Create a string List with the default constructor\n";
   List <string> l;

   // instructions
   cout << "Instructions:\n"
        << "\t+ dog   pushes dog onto the front\n"
        << "\t- cat   pushes cat onto the back\n"
        << "\t#       displays the contents of the list\n"
        << "\t*       clear the list\n"
        << "\t!       quit\n";

   char command;
   string text;
   do
   {
      cout << "> ";
      cin  >> command;

      try
      {
         switch (command)
         {
            case '+':
               cin >> text;
               l.push_front(text);
               break;
            case '-':
               cin >> text;
               l.push_back(text);
               break;
            case '#':
            {
               ListIterator <string> it;
               cout << "\tForwards: ";
               for (it = l.begin(); it != l.end(); ++it)
                  cout << ' ' << *it;
               cout << endl;

               cout << "\tBackwards:";
               for (it = l.rbegin(); it != l.rend(); --it)
                  cout << ' ' << *it;
               cout << endl;
               break;
            }
            case '*':
               l.clear();
               break;
            case '!':
               break;
            default:
               cout << "Unknown command\n";
               cin.ignore(256, '\n');
         }      
      }
      catch (const char * e)
      {
         cout << '\t' << e << endl;
      }
   }
   while (command != '!');
#endif // TEST3
}

/*******************************************
 * TEST INSERT REMOVE
 * We will insert items in a list from the location
 * specified by the iterator, and remove items from
 * the list from the given iterator
 *******************************************/
void testInsertRemove()
{
#ifdef TEST4
   // first, fill the list
   List <char> l;
   for (char letter = 'a'; letter <= 'm'; letter++)
      l.push_back(letter);

   // instructions
   cout << "Instructions:\n"
        << "\t+ 3 A  put 'A' after the 3rd item in the list\n"
        << "\t- 4    remove the fourth item from the list\n"
        << "\t!       quit\n";

   char command;
   do
   {
      ListIterator <char> it;
      int index = 0;
      char letter;
      
      // display the list
      for (it = l.begin(); it != l.end(); ++it)
         cout << setw(3) << index++;
      cout << endl;
      for (it = l.begin(); it != l.end(); ++it)
         cout << setw(3) << *it;

      // prompt for the next command
      cout << "\n> ";
      cin  >> command;

      try
      {
         switch (command)
         {
            case '+':
               cin >> index >> letter;
               it = l.begin();
               while (index-- > 0)
                  ++it;
               l.insert(it, letter);
               break;
            case '-':
               cin >> index;
               it = l.begin();
               while (index-- > 0)
                  ++it;
               l.remove(it);
               break;
            case '!':
               break;
            default:
               cout << "Unknown command\n";
               break;
         }

         // error recovery: unexpected input
         if (cin.fail())
         {
            cin.clear();
            cin.ignore(256, '\n');
         }
         
      }
      // error recovery: thrown exception
      catch (const char * e)
      {
         cout << '\t' << e << endl;
      }
   }
   while (command != '!'); 
#endif // TEST4
}
