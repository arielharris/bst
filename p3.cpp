// Ariel Harris
// p3.cpp
// Purpose: Create a binary search tree and impliment differnt BST operations.
// Input: Can take user input for insertion, search, and removal. This program
// only takes user input for searching the tree.
// Process: Insert 20 random values into the BST, print these values in a
// pre order traversal and an in order traversal. Ask the user for a value and
// search the tree for value, returing if it was found or not. Print the min,
// max, and height of the tree. Delete four values for each deletion case: the
// root, a leaf, a single child node, and a two child node. These values are
// predetermined based on how the values are inserted into the tree. Print
// another in order traversal to show values were deleted. Create new trees to
// test copy constructor and overload operator.
// Output: A pre order and in order list of the original tree. The min, max, and
// height of tree. Another in order list of the tree after removal. The other
// three trees used to test copy and overload.

#include <iostream>
#include <ctime>
#include "tree.h"

using namespace std;

void searchTree (int searchVal);
int main ()
{
  Tree t1;
  Tree test1, test2;
  int searchVal;
  int min, max;

  //test insert function
  cout << endl << endl;
  cout << "Creating tree." << endl;
  t1.insert(83);
  t1.insert(86);
  t1.insert(77);
  t1.insert(15);
  t1.insert(93);
  t1.insert(35);
  t1.insert(92);
  t1.insert(49);
  t1.insert(21);
  t1.insert(62);
  t1.insert(27);
  t1.insert(90);
  t1.insert(59);
  t1.insert(63);
  t1.insert(26);
  t1.insert(40);
  t1.insert(72);
  t1.insert(36);
  t1.insert(11);
  t1.insert(68);
  
  //test pre order
  cout << "Pre order tree values: " << endl;
  t1.preOrder();

  //test in order
  cout << "In order tree values: " << endl;
  t1.inOrder();
  
  //test search function
  cout << "Enter value to search for in tree: " << endl;
  cin >> searchVal;
  if (t1.search(searchVal))
    cout << "Value in tree." << endl;
  else
    cout << "Value not in tree." << endl;

  //test findMin
  t1.findMin(min);
  cout << "The minimum value is: " << min << endl;

  //test findMax
  t1.findMax(max);
  cout << "The maximum value is: " << max << endl;

  //test findHeight
  cout <<"The height of the tree is: " <<  t1.findHeight() << endl;

  //test remove
  cout << "Removing root node(83)." << endl;
  t1.remove(83);
  
  cout << "Removing node(21) with no children. " << endl;
  t1.remove(21);
  
  cout << "Removing node(77) with one child. " << endl;
  t1.remove(77);

  cout<< "Removing node(62) with two children. " << endl;
  t1.removeTwoChild(62);

  t1.inOrder();

  //test copy constructor & overload

  cout << "Creating new test tree, in order values: " << endl;
  test1.insert(12);
  test1.insert(3);
  test1.insert(21);
  test1.insert(4);
  test1.insert(2);

  Tree test3(test1);
  
  test3.inOrder();

  cout << "Over writting test tree with new values: " << endl;
  test2.insert(7);
  test2.insert(6);
  test2.insert(13);
  test2.insert(32);
  test2.insert(1);

  test3 = test2;

  test3.inOrder();

  cout << "Clearing all trees." << endl;
  t1.deleteAll();
  test1.deleteAll();
  test2.deleteAll();
  test3.deleteAll();

  return 0;
}


