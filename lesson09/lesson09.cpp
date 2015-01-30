/***********************************************************************
* Program:
*    Lesson 09, Map and balanced BSTs
*    Brother Helfrich, CS 235
* Author:
*    Br. Helfrich
* Summary: 
*    This is a driver program to exercise the Map class.  When you
*    submit your program, this should not be changed in any way.  That being
*    said, you may need to modify this once or twice to get it to work.
************************************************************************/

#include <iostream>      // for CIN and COUT
#include <string>        // for STRING
#include "map.h"         // for BST class which should be in bst.h
#include "wordCount.h"   // for the wordCount() function
using namespace std;


// prototypes for our four test functions
void testSimple();
void testAdd();
void testIterate();
void testQuery();
void testSort();
void testBalance();

// To get your program to compile, you might need to comment out a few
// of these. The idea is to help you avoid too many compile errors at once.
// I suggest first commenting out all of these tests, then try to use only
// TEST1.  Then, when TEST1 works, try TEST2 and so on.
#define TEST1   // for testSimple()
#define TEST2   // for testAdd()
#define TEST3   // for testIterate()
#define TEST4   // for testQuery()
#define TESTB   // for testBalance()

/**********************************************************************
 * MAIN
 * This is just a simple menu to launch a collection of tests
 ***********************************************************************/
int main()
{
   // menu
   cout << "Select the test you want to run:\n";
   cout << "\t1. Just create and destroy a Map\n";
   cout << "\t2. The above plus add a few entries\n";
   cout << "\t3. The above plus display the contents of a Map\n";
   cout << "\t4. The above plus retrieve entries from the Map\n";
   cout << "\ta. Count word frequency\n";
   cout << "\tb. Test tree balancing\n";

   // select
   char choice;
   cout << "> ";
   cin  >> choice;
   switch (choice)
   {
      case 'a':
         wordCount();
         break;
      case 'b':
         testBalance();
         cout << "Test Balance complete\n";
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
         testIterate();
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

/*******************************************
 * TEST SIMPLE
 * Very simple test for a Map: create and destroy
 ******************************************/
void testSimple()
{
#ifdef TEST1
   // Test1: a bool-int Map
   cout << "Create a bool-int Map\n";
   Map <bool, int> m;

   // Test2: double-bool Map
   cout << "Create a double-bool Map\n"; 
   Map <double, bool> * pM = new Map <double, bool>;
   delete pM;
#endif //TEST1
}

/*******************************************
 * TEST ADD
 * Add a few nodes to the Map then
 * destroy it when done
 *****************************************/
void testAdd()
{
#ifdef TEST2
   // create
   cout << "Create an integer-string Map\n";
   Map <int, string> m1;
   Map <int, string> m2;
   cout << "\tEmpty? " << (m1.empty() ? "yes" : "no") << endl;
   cout << "\tCount: " << m1.size() << endl;

   // fill
   cout << "Fill with 10 values\n";
   m1[8]  = string("eight");    //               8
   m1[4]  = string("four");     //          +----+----+
   m1[12] = string("twelve");   //          4         12
   m1[2]  = string("two");      //       +--+--+   +--+--+
   m1[6]  = string("six");      //       2     6   9     13
   m1[9]  = string("nine");     //     +-+   +-+   +-+
   m1[13] = string("thirteen"); //     0     5       11
   m1[0]  = string("zero");
   m1[5]  = string("five");
   m1[11] = string("eleven");
   m2 = m1;
   m1.clear();
   cout << "\tEmpty? " << (m2.empty() ? "yes" : "no") << endl;
   cout << "\tCount: " << m2.size() << endl;

   // clear
   cout << "Empty the contents\n";
   cout << "\tEmpty? " << (m1.empty() ? "yes" : "no") << endl;
   cout << "\tCount: " << m1.size() << endl;

#endif // TEST2   
}

/*******************************************
 * TEST ITERATE
 * We will build a Map and display the
 * contents on the screen
 ******************************************/
void testIterate()
{
#ifdef TEST3
   cout.setf(ios::fixed | ios::showpoint);
   cout.precision(1);   

   //
   // An empty map
   //
   try
   {
      cout << "Create an empty bool-bool Map\n";
      Map <bool, bool> m;
      MapIterator <bool, bool> it;
      cout << "\tEmpty? " << (m.empty() ? "yes" : "no") << endl;
      cout << "\tCount: " << m.size() << endl;

      // display the contents
      cout << "\tContents: ";
      for (it = m.begin(); it != m.end(); ++it)
         cout << (*it) << " ";
      cout << endl;
      
      // map deleted
      cout << "\tMap deleted\n";      
   }
   catch (const char * s)
   {
      cout << "Thrown exception: " << s << endl;
   }

   //
   // a non-trivial map
   //
   try
   {
      cout << "Create a string-integer Map\n";
      Map <string, int> m1;
      Map <string, int> m2;
      MapIterator <string, int> it;
      cout << "\tEmpty? " << (m1.empty() ? "yes" : "no") << endl;
      cout << "\tCount: " << m1.size() << endl;

      // fill the tree
      cout << "\tFill the Map with: f c i b e g j a d h\n";
      m1[string("f")] = 6; 
      m1[string("c")] = 3;   //               f
      m1[string("i")] = 9;   //          +----+----+
      m1[string("b")] = 2;   //          c         i
      m1[string("e")] = 5;   //       +--+--+   +--+--+
      m1[string("g")] = 7;   //       b     e   g     j
      m1[string("j")] = 10;  //     +-+   +-+   +-+
      m1[string("a")] = 1;   //     a     d       h
      m1[string("d")] = 4; 
      m1[string("h")] = 8;
      m2 = m1;
      m1.clear();
      cout << "\tCount: " << m2.size() << endl;

      // display the contents forward
      cout << "\tContents forward:  ";
      for (it = m2.begin(); it != m2.end(); ++it)
         cout << *it << "  ";
      cout << endl;

      // display the contents backwards
      cout << "\tContents backward: ";
      for (it = m2.rbegin(); it != m2.rend(); --it)
         cout << *it << "  ";
      cout << endl;
      
      // tree deleted
      cout << "\tMap deleted\n";
   }
   catch (const char * s)
   {
      cout << "Thrown exception: " << s << endl;
   }
#endif // TEST3
}

/*******************************************
 * TEST QUERY
 * Prompt the user for items to put in the map
 * and then allow the user to query for items
 *******************************************/
void testQuery()
{
#ifdef TEST4
   try
   {
      // create the map
      cout << "Create a char-string Map\n";
      Map <char, string> m;
      char letter;
      string word;

      // fill the map
      cout << "Please enter a letter word pair. "
           << "Enter ! for the letter when finished.\n";
      cout << "> ";
      cin  >> letter >> word;
      while (letter != '!')
      {
         m[letter] = word;
         cout << "> ";
         cin  >> letter >> word;
      }
      cout << "\tThere are " << m.size() << " items in the map\n";

      // prompt for the values in the map
      cout << "Please enter the letter to be found. Enter ! when finished.\n";
      cout << "> ";
      cin  >> letter;
      while (letter != '!')
      {
         cout << '\t' << m[letter] << endl;
         cout << "> ";
         cin  >> letter;
      }
   }
   catch (const char * s)
   {
      cout << "Thrown exception: " << s << endl;
   }
#endif // TEST4
}

/**************************************************
 * TEST BALANCE
 * Test if a given tree is balanced
 *************************************************/
void testBalance()
{
#ifdef TESTB
   cout << "Create a simple Binary Search Tree\n";
   BST <int> tree;
   BinaryNode <int> * root;

   // Case 1: Add a black root
   tree.insert(60);                           //      60b
   root = tree.getRoot();
   assert(root->isRed == false);
   cout << "\tPass Case 1\n";

   // Case 2: Add two children which will be red
   tree.insert(50);                           //       60b
   tree.insert(70);                           //   +----+-----+
   assert(root->pRight->isRed == true);       //   50r       70r
   assert(root->pLeft->isRed == true);
   cout << "\tPass Case 2\n";

   // Case 3: Add a child which should case 50 and 70 to turn black
   tree.insert(20);                            //           60b
   assert(root->isRed == false);               //      +-----+-----+
   assert(root->data  == 60);                  //     50b         70b
   assert(root->pRight->isRed == false);       //   +--+
   assert(root->pRight->data  == 70);          // 20r
   assert(root->pLeft->isRed == false);
   assert(root->pLeft->data  == 50);
   assert(root->pLeft->pLeft->isRed == true);
   assert(root->pLeft->pLeft->data  == 20);
   cout << "\tPass Case 3\n";

   // Case 4a: Add a child to 20 which should cause a right rotation on 50
   tree.insert(10);                            //           60b
   assert(root->isRed == false);               //      +-----+-----+
   assert(root->data  == 60);                  //     20b         70b
   assert(root->pRight->isRed == false);       //   +--+--+
   assert(root->pRight->data  == 70);          // 10r     50r
   assert(root->pLeft->isRed == false);
   assert(root->pLeft->data  == 20);
   assert(root->pLeft->pLeft->isRed == true);
   assert(root->pLeft->pLeft->data  == 10);
   assert(root->pLeft->pRight->isRed == true);
   assert(root->pLeft->pRight->data  == 50);
   cout << "\tPass Case 4a\n";

   // Case 4b: Add 30 (Case 3 then 2) followed by 40 (Case 4b)
   tree.insert(30); // cause 3, followed by 2
   tree.insert(40); // cause 4b
   assert(root->isRed == false);              //              60b
   assert(root->data  == 60);                 //       +-------+-------+
   assert(root->pRight->isRed == false);      //      20r              70b
   assert(root->pRight->data  == 70);         //  +----+-----+
   assert(root->pLeft->isRed == true);        // 10b        40b
   assert(root->pLeft->data  == 20);          //         +---+---+       
   assert(root->pLeft->pLeft->isRed == false);//        30r      50r
   assert(root->pLeft->pLeft->data  == 10);
   assert(root->pLeft->pRight->isRed == false);
   assert(root->pLeft->pRight->data  == 40);
   assert(root->pLeft->pRight->pRight->isRed == true);
   assert(root->pLeft->pRight->pRight->data  == 50);
   assert(root->pLeft->pRight->pLeft->isRed == true);
   assert(root->pLeft->pRight->pLeft->data  == 30);
   cout << "\tPass Case 4b\n";

   // Case 4c: Add 100 (Case 2) followed by 110 (Case 4c) rotate left
   tree.insert(100);   // case 2
   tree.insert(110);   // case 4c
   assert(root->isRed == false);               //         60b
   assert(root->data  == 60);                  //  +-------+-------+
   assert(root->pRight->isRed == false);       // ...             100b
   assert(root->pRight->data  == 100);         //              +----+-----+
   assert(root->pRight->pRight->isRed == true);//             70r       110r
   assert(root->pRight->pRight->data  == 110); //
   assert(root->pRight->pLeft->isRed == true);
   assert(root->pRight->pLeft->data  == 70); 
   cout << "\tPass Case 4c\n";

   // Case 4d: Add 90 (Case 3 then 2) followed by 80 (Case 4d)
   tree.insert(90);    // case 3 followed by 2
   tree.insert(80);    // case 4d
   assert(root->isRed == false);                //         60b
   assert(root->data  == 60);                   //  +-------+-------+
   assert(root->pRight->isRed == true);         // ...             100r
   assert(root->pRight->data  == 100);          //              +----+-----+
   assert(root->pRight->pRight->isRed == false);//             80b       110b
   assert(root->pRight->pRight->data  == 110);  //          +---+---+
   assert(root->pRight->pLeft->isRed == false); //         70r    90r
   assert(root->pRight->pLeft->data  == 80);
   assert(root->pRight->pLeft->pLeft->isRed == true);
   assert(root->pRight->pLeft->pLeft->data  == 70);
   assert(root->pRight->pLeft->pRight->isRed == true);
   assert(root->pRight->pLeft->pRight->data  == 90);   
   cout << "\tPass Case 4d\n";

   // make sure it all works as we expect
   cout << "Final tree:";
   for (BSTIterator <int> it = tree.begin(); it != tree.end(); ++it)
      cout << ' ' << *it;
   cout << endl;
   
#endif // TESTB
}
