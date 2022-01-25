#include "list.h"

using namespace std;

int main() {

  // pointer to node head is set to NULL
  node* head = NULL;

  // calling build function to build the linked list
  build(head);

  // caling display_all function to print out the list
  display_all(head);
  
  //PLEASE PUT YOUR CODE HERE to call the function assigned
  remove_head(head);
  
  // printing the list out again
  display_all(head);  
  return 0;
}
