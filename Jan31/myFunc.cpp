// myFunc.cpp

#include "list.h"

#include <iostream>

using namespace std;

void remove_head(node*& head) {
  node* temp = new node();
  node* newHead = new node;
  node* last = head;
  node* newTail = new node();
  
  // Copy head into newHead
  newHead = new node();
  newHead->data = head->data;

  // Iterate to end
  while (last->next != NULL) {
    last = last->next;
  }

  // Set temp2 to newTail
  newTail->data = last->data;

  // End of list
  newTail->next = NULL;

  // newTail comes next after newHead
  newHead->next = newTail;

  // Print
  cout << "New LL head: " << newHead->data << endl;
  cout << "New LL tail: " << newTail->data << endl;
  
  // If head is not null, delete it
  if (head != NULL) {
    temp = head;
    head = head->next;
    delete temp;
  }
}

void remove_tail(node*& head) {
  node* prev = NULL;
  node* temp = head;
  
  // Delete tail
  while (temp->next != NULL) {
    prev = temp;
    temp = temp->next;
  }
  delete temp;
  prev->next = NULL;
}
