// newFunction.cpp file for function that removes the head of the linked list, then print's it out again
// Author: Shudhant Gautam
// Date: 27 January 2022

#include "list.h"

#include <iostream>

void remove_head(node* head) {
  node *tempNode = head;
  head = head->next;
  delete tempNode;
}
