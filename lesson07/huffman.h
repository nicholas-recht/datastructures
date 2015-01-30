/***********************************************************************
 * Module:
 *    Lesson 07, Huffman
 *    Brother Helfrich, CS 235
 * Author:
 *    Br. Helfrich
 * Summary:
 *    This program will implement the huffman() function
 ************************************************************************/

#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <iostream> // for NULL
#include <string>   // strings are so useful!
#include "pair.h"
#include "bnode.h"
#include "vector.h"

// function prototype
void huffman();

// A class to contain a huffman tree
class Huffman
{
  public:
   // constructors
   Huffman(float weight, std::string s);

   Huffman() : pRoot(NULL) {};

   // destructor -- delete the tree
   ~Huffman() { deleteBinaryTree(pRoot); }
   
   // most of the work will happen here
   void operator += (const Huffman & rhs);

   // getters
   std::string getValue() const;
   float  getWeight() const;

   // display yourself - vector to contain the original words
   void display(Vector <string> & words);

   // generate the huffman codes
   void generateCodes(BinaryNode <Pair <float, string> > * pNode,
                            string code, Vector <string> & words);

  private:
   // pointer to the root of the tree
   BinaryNode <Pair <float, std::string> > * pRoot;
};

#endif // HUFFMAN_h
