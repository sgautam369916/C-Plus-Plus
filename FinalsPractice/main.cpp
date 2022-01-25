#include "list.h"

#include <iostream>

using namespace std;

void addNode(node* head) {
  node* current = new node();

  while (head->next != NULL) {
    head->next = current;
  }
  current->data = (69);
  head = current;
}

int main() {

  // pointer to node head is set to NULL
  node* head = NULL;

  // calling build function to build the linked list
  build(head);

  // caling display_all function to print out the list
  display_all(head);

  cout << "Removing first node now." << endl;
  //PLEASE PUT YOUR CODE HERE to call the function assigned
  remove_head(head);
  
  // printing the list out again
  display_all(head);

  cout << "Adding 69 to end of list now." << endl;

  addNode(head);
  
  display_all(head);
  
  return 0;
}
