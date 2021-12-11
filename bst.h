// Hari Kumar
// 002352411
// hkumar@chapman.edu
// CPSC350-02
// Assignment 6

// Template class implementation of Binary Search Tree composed of TreeNodes objects

#ifndef BST_H
#define BST_H

#include <iostream>
#include <fstream>

using namespace std;

template <class T>
class TreeNode
{
  public:
    TreeNode();
    TreeNode(T key);
    virtual ~TreeNode(); //virtual destructor can be overriden for other uses

    T key;
    TreeNode<T> *left;
    TreeNode<T> *right;
};

//constructor
template<class T>
TreeNode<T>::TreeNode()
{
  left = NULL;
  right = NULL;
  key = NULL;
}

// overloaded constructor
template<class T>
TreeNode<T>::TreeNode(T k)
{
  left = NULL;
  right = NULL;
  key = k;
}

// destructor
template<class T>
TreeNode<T>::~TreeNode()
{
  left = NULL;
  right = NULL;
}

template<class T>
class BST
{
  public:
      BST();
      virtual ~BST();
      void insert(T value);
      bool contains (T value);
      T search(T data);
      bool deleteNode(T k);
      bool isEmpty();
      T* getMin();
      T* getMax();
      TreeNode<T> *getSuccessor(TreeNode<T> *d); //find successor for node to be deleted
      void printNodes();
      void recPrint(TreeNode<T> *node);
      void treeToFile(ofstream& fileName);
      void treeToFile(TreeNode<T>* root, ofstream& fileName);
    private:
      TreeNode<T> *root;
};

// constructor
template<class T>
BST<T>::BST()
{
  root = NULL;
}

//destructor
template<class T>
BST<T>::~BST()
{
  //research
}

// treeToFile takes a output file stream parameter and calls the overloaded treeToFile function
template<class T>
void BST<T>::treeToFile(ofstream& fileName)
{
  return treeToFile(root, fileName);
}

// treeToFile function takes a pointer to the BST root and an output file stream
// saves BST to file
template<class T>
void BST<T>::treeToFile(TreeNode<T>* root, ofstream& fileName)
{
  if (root == NULL)
  {
    return;
  }
  fileName << root->key << endl;
  treeToFile(root->left, fileName);
  treeToFile(root->right, fileName);
}

// recPrint takes pointer of a treeNode and prints the tree from smallest to largest value
template<class T>
void BST<T>::recPrint(TreeNode<T> *node)
{
  if (node == NULL)
    return;

  recPrint(node->left);
  cout << node->key << endl;
  recPrint(node->right);
}

// printNodes calls the recPrint function
template<class T>
void BST<T>::printNodes()
{
  recPrint(root);
}

// isEmpty returns true if the BST does not contain any TreeNodes
template<class T>
bool BST<T>::isEmpty()
{
  return (root == NULL);
}

// getMin finds the minimum value in the BST, returns the BST datatype
template<class T>
T* BST<T>::getMin()
{
  TreeNode<T> *current = root;
  if (isEmpty())
  {
    return NULL;
  }

  while (current->left != NULL)
  {
    current = current->left;
  }
  return &(current->key); //returning address of the current node key
}

// getMax retruns the max value from the BST
template<class T>
T* BST<T>::getMax()
{
  TreeNode<T> *current = root;
  if (isEmpty())
  {
    return NULL;
  }

  while (current->right != NULL)
  {
    current = current->right;
  }
  return &(current->key); //returning address of the current node key
}

// insert takes the specified BST datatype and inserts the value/object to the BST
template<class T>
void BST<T>::insert(T value)
{
  TreeNode<T> *node = new TreeNode<T>(value);

  if (isEmpty())
  {
    root = node;
  }
  else // tree not empty, find insertion point
  {
    TreeNode<T> *current = root;
    TreeNode<T> *parent = NULL;

    while (true)
    {
      parent = current;

      if (value < current->key)
      {
        current = current->left;

        if (current == NULL) //found insertion point
        {
          parent->left = node;
          break;
        }
      }

      else
      {
        current = current->right;

        if (current == NULL) //found insertion point
        {
          parent->right = node;
          break;
        }
      }
    }
  }
}

// contains takes the specified BST datatype as a parameter and returns true or false if the value/object
// is in the BST
template<class T>
bool BST<T>::contains(T value)
{
  if (isEmpty())
  {
    return false;
  }
  else
  {
    TreeNode<T> *current = root;

    while (current->key != value)
    {
      if (value < current->key)
      {
        current = current->left;
      }
      else
      {
        current = current->right;
      }

      if (current == NULL)
        return false;
    }
  }
  return true;
}

// search takes the specified BST datatype and returns the BST datatype if the value/object is found
template<class T>
T BST<T>::search(T data)
{
  TreeNode<T> *current = root;
  if (isEmpty())
  {
    throw runtime_error("Tree is empty.");
  }
  else
  {
    while (current->key != data)
    {
      if (data < current->key)
      {
        current = current->left;
      }
      else
      {
        current = current->right;
      }
    }
  }
  return current->key;
}

// deleteNode takes the specified BST datatype as parameter and returns true or false if the node is deleted 
template<class T>
bool BST<T>::deleteNode(T k)
{
  if (isEmpty())
  {
    return false;
  }

  //if we get here, find it and set pointers
  TreeNode<T> *current = root;
  TreeNode<T> *parent = root;

  bool isLeft = true;

  while (current->key != k)
  {
    parent = current;

    if (k < current->key)
    {
      isLeft = true;
      current = current->left;
    }
    else
    {
      isLeft = false;
      current = current->right;
    }
    if (current == NULL)
    {
      return false;
    }
  }

  //if we get here, node is found, now delete

  //no children, node to be deleted is a leaf

  if (current->left == NULL && current->right == NULL)
  {
    if (current == root)
    {
      root == NULL;
    }
    else if (isLeft)
    {
      parent->left = NULL;
    }
    else
    {
      parent->right = NULL;
    }
  }

  else if (current->right == NULL)
  {
    //only one child and its a right child
    if (current == root)
    {
      root = current->left;
    }
    else if (isLeft)
    {
      parent->left = current->left;
    }
    else
    {
      parent->right = current->left;
    }
  }

  else if (current->left == NULL)
  {
    //only one child and its left child
    if (current == root)
    {
      root = current->right;
    }
    else if (isLeft)
    {
      parent->left = current->right;
    }
    else
    {
      parent->right = current->right;
    }
  }

  else
  {
    TreeNode<T> *successor = getSuccessor(current);

    if (current == root)
    {
      root = successor;
    }
    else if (isLeft)
    {
      parent->left = successor;
    }
    else
    {
      parent->right = successor;
    }

    successor->left = current->left;
    current->left = NULL;
    current->right = NULL;
  }
  return true;
}

// getSuccessor takes a pointer to a TreeNode as parameter and returns the successor of the parameter value/object
// as a TreeNode
template<class T>
// *d is node to be deleted
TreeNode<T> *BST<T>::getSuccessor(TreeNode<T> *d)
{
  TreeNode<T> *sp = d; //successor parent = d
  TreeNode<T> *successor = d;
  TreeNode<T> *current = d->right;

  while (current != NULL)
  {
    sp = successor;
    successor = current;
    current = current->left;
  }

  //all pointers should be in correct locations

  // check if successor is a descendant of a right child (d->right)
  if (successor != d->right)
  {
    sp->left = successor->right;
    successor->right = d->right;
  }
  return successor;
}

#endif
