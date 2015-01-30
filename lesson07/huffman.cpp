/***********************************************************************
 * Module:
 *    Lesson 07, Huffman
 *    Brother Helfrich, CS 235
 * Author:
 *    Justin Ricks
 * Summary:
 *    This program will implement the huffman() function and the Huffman
 *    class member functions
 ************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "huffman.h"       // for HUFFMAN() prototype
#include "vector.h"

/*******************************************
 * HUFFMAN
 * Driver program to exercise the huffman generation code
 *******************************************/
void huffman()
{
   // filename from the user
   string filename;

   cout << "Enter the filename containing the value frequencies: ";
   cin  >> filename;

   // file data
   string temp;
   Vector <string> words;

   // storage of all the trees
   Vector <Huffman * > trees;

   // read everything into a vector of Huffman trees
   ifstream fin(filename.c_str());
   assert(!fin.fail());
   while (fin >> temp)
   {
      words.push_back(temp);
      
      float weight;

      fin >> weight;

      Huffman * tree = new Huffman(weight, temp);

      trees.push_back(tree);

   }
   fin.close();

   while (trees.size() > 2)
   {
      // indices of the lightest weighted trees
      int iLight = 0; // lightest
      int iHeavy = 0; // second-lightest
      
      // loop through and pick out the smallest weight
      for (int i = 1; i < trees.size(); i++)
      {
         // is this item lighter than the lightest so far?
         if (trees[i]->getWeight() < trees[iLight]->getWeight())
            iLight = i;
      }

      // make sure iHeavy isn't the same as iLight
      if (iLight == 0)
         iHeavy = 1;

      for (int i = 0; i < trees.size(); i++)
      {
         // is it lighter than the second lightest?
         if (trees[i]->getWeight() < trees[iHeavy]->getWeight()
             && i != iLight)
            iHeavy = i;
      }

      // add the two weights into a new tree
      *(trees[iLight]) += *(trees[iHeavy]);

      // necessary to get the same tree as Br. Helfrich
      if (iLight < iHeavy)
      {      
         // shift the last item into the new empty space
         trees[iHeavy] = trees[trees.size() - 1];
      }

      // keep the new tree to the left of the old
      else
      {
         trees[iHeavy] = trees[iLight];

         // shift the last item into the new empty space
         trees[iLight] = trees[trees.size() - 1];
      }
      trees.pop_back();
   }

   assert(trees.size() >= 2);

   // Last two trees, decide the order to merge them
   if (trees[0]->getWeight() <= trees[1]->getWeight())
   {
      *(trees[0]) += *(trees[1]);
      trees.pop_back();
   }
   
   else
   {
      /*
      cout << "Adding " << trees[1]->pRoot->data << " to "
           << trees[0]->pRoot->data << endl;
      */
      *(trees[1]) += *(trees[0]);
      trees[0] = trees[1];
      trees.pop_back();
   }

   trees[0]->display(words);

   delete trees[0];
   
   return;
}


/***********************************************************************
 * Necessary member functions for the Huffman class
 **********************************************************************/

// Returns the value of the string member of the root node
string Huffman :: getValue() const
{
   assert(pRoot != NULL);

   return pRoot->data.second;
}

// Returns the weight of the root node
float Huffman :: getWeight() const
{
   assert(pRoot!= NULL);

   return pRoot->data.first;
}

/***********************************************************************
 * Most of the work will happen here. It combines two trees into one.
 * ORDER MATTERS! (This)'s pRoot will point to a new node with a weight of
 * the combined weights of (this) and rhs. (This) is the new left child,
 * rhs is the new right child.
 **********************************************************************/
void Huffman :: operator += (const Huffman & rhs)
{
   // set up the data
   Pair <float, string> newValue(this->getWeight() + rhs.getWeight(), "");

   // create a new node. This will be the parent of (this) and rhs
   BinaryNode < Pair<float, string> > * pNew
      = new BinaryNode < Pair<float, string> >(newValue);

   pNew->addLeft(this->pRoot);
   pNew->addRight(rhs.pRoot);

   // be the parent
   this->pRoot = pNew;
}

/***********************************************************************
 * Non-default constructor
 * just set the data in the node
 **********************************************************************/
Huffman :: Huffman(float weight, string s)
{
   pRoot = new BinaryNode < Pair<float, string> >;
   
   pRoot->data.first = weight;
   pRoot->data.second = s;
}

/***********************************************************************
 * Display
 * Outputs the codes for a huffman tree. Takes a vector by reference as
 * a parameter; this vector is a list of all the words that need codes
 **********************************************************************/
void Huffman :: display(Vector <string> & words)
{
   // traverse the tree and generate codes
   generateCodes(this->pRoot, "", words);

   // output it
   for (int i = 0; i < words.size(); ++i)
      cout << words[i] << endl;
}

/***********************************************************************
 * Generate Codes
 * Generates the codes for a huffman tree. This is done recursively.
 * Takes three parameters: a pointer to a node (the root of the subtree),
 * a string containing the code insofar, and a vector passed by reference
 * containing all the words that need codes.
 * When a leaf node is found, the corresponding string is found in the
 * list, and the code is appended to it.
 **********************************************************************/
void Huffman :: generateCodes(BinaryNode <Pair <float, string> > * pNode,
                        string code, Vector <string> & words)
{
   // anchor case
   if (pNode->pLeft == NULL && pNode->pRight == NULL)
   {
      // search for the corresponding string in the vector
      for (int i = 0; i < words.size(); ++i)
      {
         if (words[i] == pNode->data.second)
            words[i] += (" = " + code);
      }

      return;
   }
   
   // recursive case
   if (pNode->pLeft  != NULL)
      generateCodes(pNode->pLeft, code  + "0", words);
   if (pNode->pRight != NULL)
      generateCodes(pNode->pRight, code + "1", words);

}
