#pragma once
// cx11-1.h
// Code Example 11-1: Interface File: Binary Tree

#ifndef BINARYTREE
#define BINARYTREE

#include <iostream>
#include <assert.h>
using namespace std;

template < class btElementType >
class BinaryTree {
public:
	BinaryTree();
	bool isEmpty() const;
	// Precondition: None.
	// Postcondition: None.
	// Returns: true if and only if T is an empty tree
	btElementType getData() const; // getData is an accessor
	  // Precondition: !this->isEmpty()
	  // Postcondition: None
	  // Returns: The data associated with the root of the tree
	virtual void insert(const btElementType & d);
	// Precondition: none
	// Postconditions: this->getData() == d; !this->isEmpty()
	BinaryTree * left();
	// Precondition: !this->isEmpty()
	// Postcondition: None
	// Returns: (a pointer to) the left child of T
	BinaryTree * right();
	// Precondition: !this->isEmpty()
	// Postcondition: None
	// Returns: (a pointer to) the right child of T
	void makeLeft(BinaryTree * T1);
	// Precondition: !this->isEmpty(); this->left()->isEmpty()
	// Postcondition: this->left() == T1
	void makeRight(BinaryTree * T1);
	// Precondition: !this->isEmpty(); this->right()->isEmpty()
	// Postcondition: this->right() == T1
protected: // 멤버 변수들을 상속해서 사용하고자 하면, protected로 변경해야 함
	bool nullTree;
	btElementType treeData;
	BinaryTree * leftTree;
	BinaryTree * rightTree;
};

// cx11-2.cpp
// Code Example 11-2: Implementation File: Binary Tree

template < class btElementType >
BinaryTree < btElementType > ::BinaryTree()
{
	nullTree = true;
	leftTree = 0;
	rightTree = 0;
}

template < class btElementType >
bool
BinaryTree < btElementType > ::isEmpty() const
{
	return nullTree;
}

template < class btElementType >
btElementType
BinaryTree < btElementType > ::getData() const
{
	assert(!isEmpty());
	return treeData;
}


template < class btElementType >
void
BinaryTree < btElementType >
::insert(const btElementType & d)
{
	treeData = d;
	if (nullTree) {
		nullTree = false;
		leftTree = new BinaryTree;
		rightTree = new BinaryTree;
	}
}

template < class btElementType >
BinaryTree < btElementType > *
BinaryTree < btElementType > ::left()
{
	assert(!isEmpty());
	return leftTree;
}

template < class btElementType >
BinaryTree < btElementType > *
BinaryTree < btElementType > ::right()
{
	assert(!isEmpty());
	return rightTree;
}



template < class btElementType >
void
BinaryTree < btElementType >
::makeLeft(BinaryTree * T1)
{
	assert(!isEmpty());
	assert(left()->isEmpty());
	delete left();
	leftTree = T1;
}

template < class btElementType >
void
BinaryTree < btElementType >
::makeRight(BinaryTree * T1)
{
	assert(!isEmpty());
	assert(right()->isEmpty());
	delete right();
	rightTree = T1;
}

#endif