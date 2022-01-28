#include "list.h"

#include <iostream>

using namespace std;

void move_to_beginning(node*& head) {
  node* temp = head;
  node* last = head;
  node* temp2 = NULL;

  // If list is empty or only one node long, return
  if (temp == NULL || temp->next = NULL) {
    return;
  }

  // As long as we're not at null
  while (last->next != NULL) {
    // temp is updated with values of list
    temp2 = last;
    // iterate forward
    last = last->next;
  }
  // End of list once we've reached right before it (temp2->next, not temp2)
  temp2->next = NULL;

  // now the original head (last), has it's next set to the new head
  last->next = head;

  // and new head becomes the last number we removed
  head = last;
}
