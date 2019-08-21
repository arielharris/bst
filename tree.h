// Ariel Harris
// tree.h
// Purpose: initiate functions for tree class

#ifndef TREE_H
#define TREE_H

class Tree
{
  
 public:
  Tree(); //constructor
  ~ Tree(); //destructor
  Tree& operator=(const Tree& s); //overload assignment
  Tree(const Tree& s); //copy contructor
  bool insert(int k); //insert value - helper for recursive
  bool search(int k);//find key - returns bool if value is present
  bool findMin(int& min);//find max - helper for recursive
  bool findMax(int& max);//find min - helper for recursive
  int findHeight();//find height - helper for recursive
  void preOrder();//pre-order recursibe traversal - helper
  void inOrder();//in-order iterative traversal
  void remove(int k);//remove key - helper for recursive
  void removeTwoChild(int k);//remove key with two children - helper
  void deleteAll();//clear tree

 private:
  struct tNode
  {
    int key;
    tNode* left;
    tNode* right;
  };
  tNode* root;
  tNode* makeCopy(tNode* ra);//for the constructor and overload
  bool insert(tNode*& root, int k);
  bool search(tNode* root, int k);
  bool findMin (tNode* root, int& min);
  bool findMax (tNode* root, int& max);
  int findHeight (tNode* root);
  void preOrder (tNode* root);
  void remove(tNode*& root, int k);
  tNode* findParent(tNode* r, int k);//for removing node
  void makeDeletion(tNode*&nodePtr);//for removing node
  void makeDeleteTwo(tNode*& root, int k); //for removing node w two children
  void deleteAll(tNode*& root);

};
#endif
