#include "list.h"

using namespace std;

void remove_head(node*& head) {
  node* temp = new node();

  if (head != NULL) {
    temp = head;
    head = head->next;
    delete temp;
  }
}

void remove_5(node*& head) {
  node* current = head;
  node* temp = head;
  node* temp2 = new node();

  // as long as next node isn't end
  while (current->next != NULL) {
    // If next node is 5
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

    // keep iterating
    else {
      current = current->next;
    }
  }
}

void remove_tail(node*& head) {
  node* temp = head;
  node* prev = NULL;

  // Case #1: if head is null
  if (temp == NULL) {
    return;
  }

  // Case #2: if head->next is null
  if (temp->next == NULL) {
    // delete head
    temp = temp->next;
    delete temp;
    return;
  }

  // Case #3: while head->next is not null
  while (temp->next != NULL) {
    // previous is current node (keeping up with iteration)
    prev = temp;
    // current skips next
    temp = temp->next;
  }
  // delete current
  delete temp;

  // now previous node is NULL, aka end of list
  prev->next = NULL;
}
