// Project 4 Skew Heaps 
// Dr. Wilson
// November 11, 2019
// File: SkewHeap.cpp

using namespace std;

#include "SkewHeap.h"

// *************************************************************************************************************************************************************************
// The function SkewHeap::SkewHeap(pri_fn pri) is the Default Constructor that creates an empty SkewHeap object with the given priority function. Moreover, in the         *
// function SkewHeap::SkewHeap(pri_fn pri), the skew heap must be ready for heap operations. In addition, in the function SkewHeap::SkewHeap(pri_fn pri), even an empty    *
// tree should behave properly when its methods are called.                                                                                                                *
// ************************************************************************************************************************************************************************* 
SkewHeap::SkewHeap(pri_fn pri)
{
    m_heap = nullptr;
    priority = pri;
}

// *****************************************************************************************************************************************************************
// The function SkewHeap::SkewHeap(const SkewHeap& rhs) is the Copy Constructor that makes a deep copy and creates a new object that has its own allocated memory. *
// ***************************************************************************************************************************************************************** 
SkewHeap::SkewHeap(const SkewHeap& rhs)
{
    m_heap = nullptr;
    priority = rhs.priority;
    recursiveCopy(rhs.m_heap);
}

void SkewHeap::recursiveCopy(Node* rhs)
{
    if(rhs)
    {
	if(rhs->tagged_union == ISINT)
	{
	    insert(rhs->data_int);
	}
	if(rhs->tagged_union == ISSTRING)
	{
	    insert(rhs->data_string);
	}
    }
    // Recursively copy the left child node and the right child node.
    recursiveCopy(rhs->left);
    recursiveCopy(rhs->right);
}

// ******************************************************************************************************************
// The function SkewHeap::~SkewHeap() is the Destructor that compeletely frees all memory allocated for the object. *
// ******************************************************************************************************************
SkewHeap::~SkewHeap()
{
}

// ****************************************************************************************************************************************************
// The function const SkewHeap& SkewHeap::operator=(const SkewHeap& rhs) is the Overloaded Assignment Operator. In addition, the function             *
// const SkewHeap& SkewHeap::operator=(const SkewHeap& rhs) is the Assignment Operator that deallocates the memory object used by the host object and *
// then makes a deep copy of rhs.                                                                                                                     *
// ****************************************************************************************************************************************************
const SkewHeap& SkewHeap::operator=(const SkewHeap& rhs)
{
  return *this;
}

// ****************************************************************************************************************************************
// The function pri_fn SkewHeap::getPriFn() const is an accessor function that returns the a pointer to to the current priority function. *
// ****************************************************************************************************************************************
pri_fn SkewHeap::getPriFn() const
{
    return priority;
}

// ***********************************************************************************************************************************************
// The function int SkewHeap::setPriFn(pri_fn pri) is a mutator function that sets the priority function. In addition, in the function           *
// int SkewHeap::setPriFn(pri_fn pri), changing the priority function will typically invalidate the current skew heap. Furthermore, the function *
// int SkewHeap::setPriFn(pri_fn pri) rebuilds the heap using the new priority function to ensure that the heap is still valid.                  *
// ***********************************************************************************************************************************************
void SkewHeap::setPriFn(pri_fn pri)
{
    priority = pri;
    // Write a helper function that rebuilds the current tree, then call it.
    //rebuildTree();
}

// *******************************************************************************************************************************
// The function bool SkewHeap::empty() const is a function that returns true if the skew heap is empty. Otherwise,  the function * 
// book SkewHeap::empty() const returns false if the skew heap is not empty.                                                     *
// *******************************************************************************************************************************
bool SkewHeap::empty() const
{
    // If m_heap is nullptr, then the tree is empty.
    return m_heap == nullptr;
}

// **************************************************************************************************************
// The function void SkewHeap::insert(string data) is a function that inserts a sting value into the skew heap. *
// **************************************************************************************************************
void SkewHeap::insert(string data)
{
    // This is the node that will be inserted into the heap.
    Node *temp = new Node(data);
    m_heap = merge(m_heap, temp);
}

// *************************************************************************************************************
// The function void SkewHeap::insert(int data)is a function that inserts an integer value into the skew heap. *
// *************************************************************************************************************
void SkewHeap::insert(int data)
{
    // This is the node that will be inserted into the heap.
    Node *temp = new Node(data);
    m_heap = merge(m_heap, temp);
}

Node* SkewHeap::merge(Node* p1, Node* p2)
{
    // If either heap is empty, return the other.
    if(p1 == nullptr)
    {
	return p2;
    }
    if(p2 == nullptr)
    {
	return p1;
    }

    Node* temp;

    // Make sure that p1 has a higher priority root.
    if(priority(p1) < priority(p2))
    {
	// Swap(p1, p2).
	temp = p2;
	p2 = p1;
	p1 = temp;
    }
    // Swap the left and right children of p1.
    temp = p1->left;
    p1->left = p1->right;
    p1->right = temp;

    // Recursively merge the left child of p1 with p2. In addition, make the merged heap the new left child of p1.
    p1->left = merge(p1->left, p2);

    return p1;

}

// *******************************************************************************************************************************
// The function void SkewHeap::skewHeapMerge(SkewHeap &sh) is a function that is used to merge two skew heaps. When the function * 
// void SkewHeapMerge(SkewHeap &sh) completes, *this should contain the merged heap and sh should be empty.                      *
// *******************************************************************************************************************************
void SkewHeap::skewHeapMerge(SkewHeap &sh)
{
    m_heap = merge(m_heap, sh.m_heap);
    sh.m_heap = nullptr;
}

// ******************************************************************************************************************************************************
// The function void SkewHeap::inorder() const is a member function, that an inorder() function, that performs an Inorder Traversal and prints the data *
// at each node. In addition, in the function void SkewHeap::inorder() const, the inorder() methods visits each node using an Inorder Traversal and     *
// prints out the data. Moreover, the inorder() function void SkewHeap::inorder() const prints an open parenthesis before visiting the left subtree     *
// and a clos parenthesis after visiting the right subtree. Nothing is printed when the inorder() function void SkewHeap::inorder() const is called on  *
// an empty tree, not even parenthteses. Furthermore, the insert() function void SkewHeap::inorder const can be used for grading and is useful for      *
// debugging.                                                                                                                                           *
// ******************************************************************************************************************************************************
void SkewHeap::inorder() const
{
  // Have a helper function and make a recursive copy for p1 and p2 for the inorder() function. Create a helper function in the header file that
  // recursively calls the left child node and right child node.
    if( empty() )
    return;
    
    cout << "(";
    //m_heap->left->inorder();

    //m_heap->right->inorder();
    cout << ")";

    return;
}

void SkewHeap::dump() const
{

}
