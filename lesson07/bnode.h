/***********************************************************************
 * Header:
 *    BNODE
 * Summary:
 *    Contains the header file for the BinaryNode class. This class
 *    implements the individual nodes of a binary tree container. Each
 *    nodes contains a template data item with a left, right, and parent
 *    pointer to other BinaryNodes. 
 * Author
 *    Nicholas Recht
 *    1 hr
 *    2 hrs doing the debugging of the huffman codes
 *    I spent the most time adding error checking to the bnode class
 ************************************************************************/
#ifndef BNODE_H
#define BNODE_H

#include <iostream>
#include <cassert>

#define ERROR_ALLOCATION "ERROR: Unable to allocate a node"

/************************************************************************
 * The BinaryNode Class
 * See description above
 ***********************************************************************/
template<class T>
class BinaryNode
{
  public:
   //default constructor
  BinaryNode() : pLeft(NULL), pRight(NULL), pParent(NULL) { }
   //nondefault constructor
  BinaryNode(T data) : pLeft(NULL), pRight(NULL), pParent(NULL) { this->data = data; }

   //Add a new node to the left of this
   // Throws is the given node already points to another node
   // or a new node can't be allocated
   BinaryNode * addLeft(T newData) throw (const char*);
   BinaryNode * addLeft(BinaryNode * newNode) throw (const char*);
   //Add a new node to the right of this
   // Throws is the given node already points to another node
   // or a new node can't be allocated
   BinaryNode * addRight(T newData) throw (const char*);
   BinaryNode * addRight(BinaryNode * newNode) throw (const char*);

   //data items -- All public
   T data;
   BinaryNode * pLeft;
   BinaryNode * pRight;
   BinaryNode * pParent;
};

/************************************************************************
 * addLeft
 * Takes a pointer to a node and sets the pLeft of this to the passed node
 ***********************************************************************/
template<class T>
BinaryNode<T> * BinaryNode<T>::addLeft(BinaryNode * newNode) throw (const char*)
{
   assert(!pLeft);
   
   this->pLeft = newNode;
   newNode->pParent = this;

   return this;
}

/************************************************************************
 * addLeft
 * Takes a data item and creates a new node, then assigns the pLeft
 * of this to the new node
 ***********************************************************************/
template<class T>
BinaryNode<T> * BinaryNode<T>::addLeft(T newData) throw (const char*)
{

   BinaryNode * pNew = new(std::nothrow) BinaryNode(newData);
   if (pNew != NULL)
      return addLeft(pNew);
   else
   {      
      delete pNew; 
      throw ERROR_ALLOCATION;
   }
   
}

/************************************************************************
 * addRight
 * Takes a pointer to a node and sets the pRight of this to the passed node
 ***********************************************************************/
template<class T>
BinaryNode<T> * BinaryNode<T>::addRight(BinaryNode * newNode) throw (const char*)
{
   assert(!pRight);
   
   this->pRight = newNode;
   newNode->pParent = this;

   return this;
}

/************************************************************************
 * addRight
 * Takes a data item and creates a new node, then sets the pRight of this
 * to the new node
 ***********************************************************************/
template<class T>
BinaryNode<T> * BinaryNode<T>::addRight(T newData) throw (const char*)
{
   
   BinaryNode * pNew = new(std::nothrow) BinaryNode(newData);
   if (pNew != NULL)
      return addRight(pNew);
   else
   {
      delete pNew; 
      throw ERROR_ALLOCATION;
   }


}

/************************************************************************
 * deleteBinaryTree
 * Recursively deletes a binarysubtree. Takes a pointer to the root node
 ***********************************************************************/
template<class T>
void deleteBinaryTree(BinaryNode<T> * node)
{
   if (node->pLeft)
      deleteBinaryTree(node->pLeft);
   if (node->pRight)
      deleteBinaryTree(node->pRight);

   delete node;
}

/************************************************************************
 * Insertion Operator
 * Recursively displays a binarysubtree. Takes a pointer to the root node
 ***********************************************************************/
template<class T>
std::ostream & operator << (std::ostream & out, const BinaryNode<T> * rhs)
{
   //Recursive Case
   if (!rhs) 
      return out; 
   //L
   return out << rhs->pLeft
   //V
       << rhs->data << " "
   //R  
       << rhs->pRight;
   
}

#endif //BNODE_H
