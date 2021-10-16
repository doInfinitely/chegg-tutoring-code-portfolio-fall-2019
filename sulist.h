#include<iostream>
#include <stdio.h>
#ifndef SULIST_H
#define SULIST_H
using namespace std;

template <class DataType>
class SUList{
private:
struct Node{     // The nodes of the list
DataType data;      // The data stored in the node
Node* next;     // The next node in the list
Node* prev;
};
Node* head;      // The front of the list
Node* tail;      // The last node of the list
public:
SUList();
SUList(const SUList&);         // Copy ctor
~SUList();// Destructor
DataType getFront();           // Remove & return the front
DataType getBack();            // Remove & return the back
void putFront(const DataType&);// Add to the front
void putBack(const DataType&); // Add to the back
int size() const;              // Returns the number of elements
bool contains(const DataType&);// Tests for membership
SUList<DataType>& operator=(const SUList<DataType>&); // Overloaded assignment
void display();
};
template <class DataType>
SUList<DataType>::SUList(){                      // Default ctor
  head = NULL;
  tail = NULL;
}
template <class DataType>
SUList<DataType>::~SUList(){                     // Destructor
    Node* cursor = head;
    while (cursor) {
    cursor = cursor->next;
    delete head;
    head = cursor;
    }
}
template <class DataType>
SUList<DataType>::SUList(const SUList& other){         // Copy ctor
  head = NULL;
  Node* newNode; // pointer to new head
  Node* copier; // pointer to original head
  Node* temp;
  
  if (!other.head){
  return;
  }
  
  copier = other.head;
  head = new Node;
  head->data = copier->data;
  head->next = NULL;
  copier = copier->next;
  temp = head;
  
  while(copier != NULL)//while loop to copy nodes 
    { 
	newNode = new Node;
        newNode->data = copier->data; //copies payroll object into new node
        newNode->next = NULL;
	temp->next = newNode;
	temp = newNode;
	copier = copier->next; // assigns next node to copier
    }

}  
template <class DataType>
DataType SUList<DataType>::getFront(){           // Remove & return the front
     Node* temp = head;
     head = head->next;
     Node* cursor = temp;
     delete temp;
     return cursor->data;
}
template <class DataType>
DataType SUList<DataType>::getBack(){            // Remove & return the back
 for (Node* temp = head; temp; temp = temp->next){
   
  if (temp->next->next == NULL){
    Node* bottom = temp->next;
    tail = temp;
    Node* cursor = bottom;
    delete bottom;
    return cursor->data;    
  }
 }
}
template <class DataType>
void SUList<DataType>::putFront(const DataType& other){// Add to the front
  if (head == NULL){
    Node* temp = new Node;
   temp->data = other; 
   temp->next = head; 
   head = temp;
   tail = head;
  }
   Node* temp = new Node;
   temp->data = other; 
   temp->next = head; 
   head = temp;  
}
template <class DataType>
void SUList<DataType>::putBack(const DataType& other){ // Add to the back
  if (head == NULL){
  Node* temp = new Node;
  temp->data = other;
  tail->next = temp;
  tail = temp;
  head = tail;
  }
  Node* temp = new Node;
  temp->data = other;
  tail->next = temp;
  tail = temp;
}
template <class DataType>
int SUList<DataType>::size() const{              // Returns the number of elements
  int count = 0;
  Node* temp = new Node; // pointer to original object
  temp = head;
  while (temp->next != nullptr)
  {
    count++;
    temp = temp->next;
  }
  return count;
}  
template <class DataType>
bool SUList<DataType>::contains(const DataType& other){// Tests for membership
  for (Node* temp = head; temp; temp = temp->next){
   if (temp->data == other){
     return true;
   }
  }
  return false;
}
template <class DataType>
SUList<DataType>& SUList<DataType>::operator=(const SUList<DataType>& other){ // Overloaded assignment
if ( this != &other ){
  head = NULL;
  Node* newNode = head; // pointer to new head
  Node* copier; // pointer to original head
  Node* temp;

  while (newNode) { //empties linked list
    newNode = newNode->next;
    delete head;
    head = newNode;
  }
  
  copier = other.head;
  head = new Node;
  head->data = copier->data;
  head->next = NULL;
  copier = copier->next;
  temp = head;
  
  while(copier != NULL)//while loop to copy nodes 
    { 
	newNode = new Node;
        newNode->data = copier->data; //copies payroll object into new node
        newNode->next = NULL;
	temp->next = newNode;
	temp = newNode;
	copier = copier->next; // assigns next node to copier
    }
    return *this;
}  
}
template <class DataType>
void SUList<DataType>::display(){
 for (Node* temp = head; temp; temp = temp->next){
  cout << temp->data << endl; 
 }
}
#endif
