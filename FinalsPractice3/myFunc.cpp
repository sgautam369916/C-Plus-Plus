// myFunc.cpp

#include "list.h"

#include <iostream>

using namespace std;

void remove_5(node*& head) {
  node* current = head;
  node* temp = head;
  node* temp2 = new node();

  // as long as next node is not end of list
  while (current->next != NULL) {

    // If current->next is 5
    if (current->next->data == 5) {
      temp2 = current->next;
      current->next = current->next->next;
      delete temp2;
    }

    // If head is 5
    else if (head->data == 5) {
      temp = head;
      head = head->next;
      delete temp;
    }

    // going on to next
    else {
      current = current->next;
    }
  }
}
