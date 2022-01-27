#include "list.h"

using namespace std;

void remove_head(node*& head) {

  // As long as the head isn't NULL (empty list)
  if (head != NULL) {
    // create a temp node
    node *temp = head;
    // traverse to next node
    head = head->next;
    // delete the temp node
    delete temp;
  }
}
