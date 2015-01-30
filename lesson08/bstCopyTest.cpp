/*************************************************************
 * Since TestBed doesn't test the assignment operator or the
 * copy constructor, this file tests those. And it works, BTW
 ************************************************************/

#include <iostream>
#include "bst.h"

using namespace std;

int main()
{
   BST <int> tree;

   tree.insert(7);
   tree.insert(2);
   tree.insert(4);
   tree.insert(14);
   tree.insert(34);
   tree.insert(5);

   BST <int> treeCopy (tree);

    // display the contents
      cout << "\tContents: ";
      for (BSTIterator <int> it = treeCopy.begin(); it != treeCopy.end(); ++it)
         cout << *it << " ";
      cout << endl;
   
   return 0;
}
