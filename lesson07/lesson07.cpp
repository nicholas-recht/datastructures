/***********************************************************************
* Program:
*    Lesson 07, Binary Trees 
*    Brother Helfrich, CS 235
* Author:
*    Br. Helfrich
* Summary: 
*    This is a driver program to exercise the BinaryNode class.  When you
*    submit your program, this should not be changed in any way.  That being
*    said, you may need to modify this once or twice to get it to work.
************************************************************************/

#include <iostream>    // for CIN and COUT
#include <string>      //
#include "bnode.h"     // your BinaryNode class should be in bnode.h
#include "huffman.h"     // for huffman()
using namespace std;


// prototypes for our four test functions
void testSimple();
void testAdd();
void testDisplay();
void testMerge();

// To get your program to compile, you might need to comment out a few
// of these. The idea is to help you avoid too many compile errors at once.
// I suggest first commenting out all of these tests, then try to use only
// TEST1.  Then, when TEST1 works, try TEST2 and so on.
#define TEST1   // for testSimple()
#define TEST2   // for testAdd()
#define TEST3   // for testDisplay()
#define TEST4   // for testMerge()

/**********************************************************************
 * MAIN
 * This is just a simple menu to launch a collection of tests
 ***********************************************************************/
int main()
{
   // menu
   cout << "Select the test you want to run:\n";
   cout << "\t0. To generate Huffman codes\n";
   cout << "\t1. Just create and destroy a BinaryNode\n";
   cout << "\t2. The above plus add a few nodes to create a Binary Tree\n";
   cout << "\t3. The above plus display the contents of a Binary Tree\n";
   cout << "\t4. The above plus merge Binary Trees\n";

   // select
   int choice;
   cout << "> ";
   cin  >> choice;
   switch (choice)
   {
      case 0:
         huffman();
         break;
      case 1:
         testSimple();
         cout << "Test 1 complete\n";
         break;
      case 2:
         testAdd();
         cout << "Test 2 complete\n";
         break;
      case 3:
         testDisplay();
         cout << "Test 3 complete\n";
         break;
      case 4:
         testMerge();
         cout << "Test 4 complete\n";
         break;
      default:
         cout << "Unrecognized command, exiting...\n";
   }

   return 0;
}

/*******************************************
 * TEST SIMPLE
 * Very simple test for a BinaryNode: create and destroy
 ******************************************/
void testSimple()
{
#ifdef TEST1
   // Test1: a bool Stack with defeault constructor
   cout << "Create a bool BinaryNode using the default constructor\n";
   BinaryNode <bool> tree;

   // Test2: double Stack with non-default constructor
   cout << "Create a double BinaryNode using the non-default constructor\n";
   BinaryNode <double> *pTree = new BinaryNode <double>(3.14159);
   delete [] pTree;
#endif //TEST1
}

/*******************************************
 * TEST ADD
 * Add a few nodes together to create a tree, then
 * destroy it when done
 *****************************************/
void testAdd()
{
#ifdef TEST2
   // create
   cout << "Create an integer Binary Tree with the default constructor\n";
   BinaryNode <int> * pTree = new BinaryNode <int> (1);

   // add 2 to the left and 6 to the right
   pTree->addLeft(2);
   pTree->addRight(3);

   // add 1 and 3 off the left node
   pTree->pLeft->addLeft(4);
   pTree->pLeft->addRight(5);

   // add 5 and 7 to the right node
   pTree->pRight->addLeft(6);
   pTree->pRight->addRight(7);

   // now display the results:
   cout << "\tRoot......... " << pTree->data                 << endl;
   cout << "\tLeft......... " << pTree->pLeft->data          << endl;
   cout << "\tRight........ " << pTree->pRight->data         << endl;
   cout << "\tLeft-Left.... " << pTree->pLeft->pLeft->data   << endl;
   cout << "\tLeft-Right... " << pTree->pLeft->pRight->data  << endl;
   cout << "\tRight-Left... " << pTree->pRight->pLeft->data  << endl;
   cout << "\tRight-Right.. " << pTree->pRight->pRight->data << endl;

   // finally, delete everything
   deleteBinaryTree(pTree);
   cout << "\tTree deleted\n";   
#endif // TEST2   
}

/*******************************************
 * TEST Display
 * We will build a binary tree and display the
 * results on the screen
 ******************************************/
void testDisplay()
{
#ifdef TEST3
   // create
   cout << "Create a string Binary Node with the default constructor\n";
   BinaryNode <string> *pTree = NULL;

   // prompt for seven words
   cout << "\tEnter seven words\n";
   string words[7];
   for (int i = 0; i < 7; i++)
   {
      cout << "\t> ";
      cin  >> words[i];
   }

   // put the seven words in the tree
   pTree =                 new BinaryNode <string> (words[3]);
   pTree->addLeft(         new BinaryNode <string> (words[1]));
   pTree->addRight(        new BinaryNode <string> (words[5]));
   pTree->pLeft->addLeft(  new BinaryNode <string> (words[0]));
   pTree->pLeft->addRight( new BinaryNode <string> (words[2]));
   pTree->pRight->addLeft( new BinaryNode <string> (words[4]));
   pTree->pRight->addRight(new BinaryNode <string> (words[6]));
   
   // display the results
   cout << pTree << endl;

   // delete the tree
   deleteBinaryTree(pTree);
   cout << "\tTree deleted\n";
#endif // TEST3
}

/*******************************************
 * TEST MERGE
 * Create three binary trees and merge them
 *******************************************/
void testMerge()
{
#ifdef TEST4
   // create three trees
   cout << "Create three 3-node binary trees\n";
   BinaryNode <char> * pLower  = new BinaryNode <char> ('b');
   BinaryNode <char> * pMiddle = new BinaryNode <char> ('m');
   BinaryNode <char> * pUpper  = new BinaryNode <char> ('y');
   pLower->addLeft  ('a');
   pLower->addRight ('c');
   pMiddle->addLeft ('l');
   pMiddle->addRight('n');
   pUpper->addLeft  ('x');
   pUpper->addRight ('z');
   
   // add Lower to the left of Middle, and Upper to the right of Middle
   pMiddle->pLeft->addLeft(pLower);
   pMiddle->pRight->addRight(pUpper);
   
   // display the results
   cout << pMiddle << endl;

   // delete the tree
   deleteBinaryTree(pMiddle);
   cout << "\tTree deleted\n";
#endif // TEST4
}
