#include "list.h"

#include <iostream>

using namespace std;

int main()
{
    node * head = NULL;
    build(head);

    cout << "Below is original list: " << endl;
    display_all(head);
    
    //PLEASE PUT YOUR CODE HERE to call the function assigned
    remove_head(head);

    // display_all(head);
    cout << "Removing head" << endl;
    
    cout << "Removing tail" << endl;

    remove_tail(head);

    cout << "Final version of list after deleting head and tail is below: " << endl;
    
    display_all(head);
    
    return 0;
}
