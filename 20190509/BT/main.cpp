// cx11-3.cpp
// Code Example 11-3: Simple Client for Binary Tree

#include "BinaryTree.h"

int main()
{
	typedef BinaryTree < char > charTree;
	typedef charTree * charTreePtr;
	
	// bottom-up 방식
	// Create tree from Figure 11-2

	// Create left subtree (rooted at B)
	// Create B's left subtree
	charTreePtr bt1(new charTree);
	bt1->insert('D');

	// Create B's right subtree
	charTreePtr bt2(new charTree);
	bt2->insert('E');

	// Create node containing B, and link
	// up to subtrees
	charTreePtr bt3(new charTree);
	bt3->insert('B');
	bt3->makeLeft(bt1);
	bt3->makeRight(bt2);
	// ** done creating left subtree
	  // Create right subtree

   // Create C's right subtree
	charTreePtr bt4(new charTree);
	bt4->insert('F');

	// Create node containing C, and link
	// up its right subtree
	charTreePtr bt5(new charTree);
	bt5->insert('C');
	bt5->makeRight(bt4);
	// ** done creating right subtree

	// Create the root of the tree, and link together
	charTreePtr bt6(new charTree);
	bt6->insert('A');
	bt6->makeLeft(bt3);
	bt6->makeRight(bt5);

	// print out the root
	cout << "Buttom-Up 방식으로 구현" << endl;

	cout << "Root contains: " << bt6->getData() << endl;

	// print out root of left subtree
	cout << "Left subtree root: " << bt6->left()->getData() << endl;

	// print out root of right subtree
	cout << "Right subtree root: " << bt6->right()->getData() << endl;

	// print out leftmost child in tree
	cout << "Leftmost child is: " <<
		bt6->left()->left()->getData() << endl;

	// print out rightmost child in tree
	cout << "Rightmost child is: " <<
		bt6->right()->right()->getData() << endl;

	cout << endl << endl;

	// Top-down 방식으로 구현하기(1점짜리 시험문제)
	charTreePtr topdown(new charTree);
	topdown->insert('G');
	topdown->left()->insert('E');
	topdown->right()->insert('F');
	topdown->left()->left()->insert('A');
	topdown->left()->right()->insert('B');
	topdown->right()->left()->insert('C');
	topdown->right()->right()->insert('D');

	cout << "Top-Down 방식으로 구현" << endl;

	// print out the root
	cout << "Root contains: " << topdown->getData() << endl;

	// print out root of left subtree
	cout << "Left subtree root: " << topdown->left()->getData() << endl;

	// print out root of right subtree
	cout << "Right subtree root: " << topdown->right()->getData() << endl;

	// print out leftmost child in tree
	cout << "Leftmost child is: " << topdown->left()->left()->getData() << endl;

	// print out rightmost child in tree
	cout << "Rightmost child is: " << topdown->right()->right()->getData() << endl;


	return 0;
}