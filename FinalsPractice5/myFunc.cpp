#include "list.h"

#include <iostream>

using namespace std;

void move_to_beginning(node*& head) {
  node* temp = head;
  node* prev = NULL;
  node* last = head;
  node* temp2 = NULL;
  
  if (temp == NULL) {
    return;
  }

  if (temp->next == NULL) {
    temp = temp->next;
    delete temp;
    return;
  }

  while (last->next != NULL) {
    temp2 = last;
    last = last->next;
  }
  // End of list
  temp2->next = NULL;

  last->next = head;
  head = last;
}
