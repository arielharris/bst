//Ariel Harris
//tree.cpp
//Purpose: Implimentation of functions in tree class

#include "tree.h"
#include <stack>
#include <iostream>

using namespace std;

Tree::Tree()
{
  root = nullptr;
  return;
}

Tree::~Tree()
{
  deleteAll(root);
  return;
}

Tree& Tree::operator=(const Tree& rhs)
{
  if (this != &rhs) {
    deleteAll(root);
    root = makeCopy(rhs.root);
  }
  return *this;
}

Tree::Tree(const Tree& aTree)
{
  if (aTree.root == nullptr)
    root = nullptr;
  else
    root = makeCopy(aTree.root);
}

bool Tree::insert(int k)
{
  return insert(root, k);
}

bool Tree::search(int k)
{
  return search(root, k);
}

bool Tree::findMin(int& min)
{
  return findMin(root, min);
}

bool Tree::findMax(int& max)
{
  return findMax(root, max);
}

int Tree::findHeight()
{
  return findHeight(root);
}

void Tree::preOrder()
{
  preOrder(root);
}

void Tree::inOrder()
{
  stack<tNode*> stack;
  tNode* current = root;
  while (current != nullptr || !stack.empty()) {
    if (current != nullptr) {
      stack.push(current);
      current = current->left;
    } else{
      current = stack.top();
      stack.pop();
      cout << current->key << endl;
      current = current->right;
    }
  }
}

void Tree::remove (int k)
//pre: node has none or one child
//post: node removed from tree
{
  tNode* parent;
  if (root == nullptr){
    cout << "Tree is empty" << endl;
    return;
  }
 if (root->key == k)
    makeDeletion(root);
  else {
    parent = findParent (root, k);
    if (parent != nullptr) {
      if (parent->left->key == k)
        makeDeletion(parent->left);
      else
        makeDeletion(parent->right);
    }
  }
 }

void Tree::removeTwoChild(int k)
//pre: node has two children
//post: node removed from tree
{
  makeDeleteTwo(root, k);
}

void Tree::deleteAll()
{
  deleteAll(root);
}

//private
Tree::tNode* Tree::makeCopy(tNode* r)
{
  if (r == nullptr)
    return nullptr;
  else {
    tNode* temp = new tNode;
    temp->key = r->key;
    temp->left = makeCopy(r->left);
    temp->right = makeCopy(r->right);
    return temp;
  }
}

bool Tree::insert(tNode*& root, int k)
{
  if (root == nullptr){
    root = new tNode;
    root->key = k;
    root->left = nullptr;
    root->right = nullptr;
    return true;
  }
  else if (root->key > k){
    return insert(root->left, k);
  }
  else if (root->key < k){
    return insert(root->right, k);
  }
  else
    return false;
}

bool Tree::search(tNode* root, int k)
{
  if (root == nullptr)
    return false;
  else if (root->key == k)
    return true;
  else if (root->key > k)
    return search(root->left, k);
  else
    return search(root->right, k);
}



bool Tree::findMin (tNode* root, int& min)
{
  tNode* current;
  current = root;
  if (current == nullptr){
    return false;
  }
  while (current->left !=nullptr){
    current = current->left;
  }
  min = current->key;
  return true;
}

bool Tree::findMax (tNode* root, int& max)
{
  tNode* current;
  current = root;
  if (current == nullptr){
    return false;
  }
  while (current->right != nullptr){
    current = current->right;
  }
  max = current->key;
  return true;
}

int Tree::findHeight (tNode* root)
{
  int lHeight, rHeight;
  if (root == nullptr)
    return 0;
  lHeight = findHeight(root->left);
  rHeight = findHeight(root->right);
  if (lHeight > rHeight)
    return 1 + lHeight;
  else
    return 1 + rHeight;
}

void Tree::preOrder (tNode* root)
{
  if (root!= nullptr){
    cout << root->key << endl;
    preOrder(root->left);
    preOrder(root->right);
  }
}

Tree::tNode* Tree::findParent(tNode* r, int k)
{
  if (k < r->key) {
    if (k == r->left->key)
      return r;
    else
      return findParent(r->left, k);
  } else {
    if (k == r->right->key)
      return r;
    else
      return findParent(r->right, k);
  }
}

void Tree::makeDeletion(tNode*& nodePtr)
{
  tNode* tmpNodePtr;
  tNode* tmpNodePtrL;

  if (nodePtr->right == nullptr){
    tmpNodePtr = nodePtr;
    nodePtr = nodePtr->left;
    delete tmpNodePtr;
  } else if (nodePtr->left == nullptr) {
    tmpNodePtr = nodePtr;
    nodePtr = nodePtr->right;
    delete tmpNodePtr;
  } else if (nodePtr->left != nullptr && nodePtr->right != nullptr){
    if ((nodePtr->right)->left!=nullptr){
    tmpNodePtr = nodePtr->right;
    tmpNodePtrL = (nodePtr->right)->left;
    while(tmpNodePtrL->left != nullptr){
      tmpNodePtr = tmpNodePtrL;
      tmpNodePtrL = tmpNodePtrL->left;
    }
    nodePtr->key = tmpNodePtrL->key;
    tmpNodePtr->left = tmpNodePtrL->right;
    delete tmpNodePtrL;
  } else {
    tmpNodePtr = nodePtr->right;
    nodePtr->key = tmpNodePtr->key;
    nodePtr->right = tmpNodePtr->right;
    delete tmpNodePtr;
    }
  }
}

void Tree::makeDeleteTwo(tNode*& root, int k)
{
  //this funtion was made to try and fix the deletion issue
  //when removing a node with two children, if this is called
  //seperatly it works, but not when combined with the makeDeletion
  //func as the final else statment it segmetn faults the first
  //two cases of removal
  tNode* tmpNodePtr;
  tNode* tmpNodePtrL;
  tNode* nodePtr = root;

  while(nodePtr != nullptr && nodePtr->key != k){
    if (nodePtr->key > k)
      nodePtr = nodePtr->left;
    else
      nodePtr = nodePtr->right;
  }
  
  if ((nodePtr->right)->left!=nullptr){
    tmpNodePtr = nodePtr->right;
    tmpNodePtrL = (nodePtr->right)->left;
    while(tmpNodePtrL->left != nullptr){
      tmpNodePtr = tmpNodePtrL;
      tmpNodePtrL = tmpNodePtrL->left;
    }
    nodePtr->key = tmpNodePtrL->key;
    tmpNodePtr->left = tmpNodePtrL->right;
    delete tmpNodePtrL;
  } else {
    tmpNodePtr = nodePtr->right;
    nodePtr->key = tmpNodePtr->key;
    nodePtr->right = tmpNodePtr->right;
    delete tmpNodePtr;
  }
}

    
void Tree::deleteAll(tNode*& root)
{
  if (root != nullptr){
    deleteAll(root->left);
    deleteAll(root->right);
    delete root;
    root = nullptr;
  }
}

