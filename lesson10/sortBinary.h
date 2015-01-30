/***********************************************************************
 * Module:
 *    Lesson 08, Sort Binary
 *    Brother Helfrich, CS 235
 * Author:
 *    Nicholas Recht
 * Summary:
 *    This program implements the Binary Tree Sort
 *    It takes an array and a number of items and
 *    then sorts the passed array
 ************************************************************************/

#ifndef SORT_BINARY_H
#define SORT_BINARY_H

#include "bst.h"

/*****************************************************
 * SORT BINARY
 * Perform the binary tree sort
 ****************************************************/
template <class T>
void sortBinary(T array[], int num)
{
   BST<T> tree;
   
   for (int i = 0; i < num; ++i)
      tree.insert(array[i]);

   int i = 0;
   for (BSTIterator<T> it = tree.begin(); it != tree.end(); ++it, ++i)
      array[i] = *it;

   return; 
}


#endif // SORT_BINARY_H
