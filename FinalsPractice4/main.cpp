#include "list.h"
using namespace std;

int main()
{
    node * head = NULL;
    build(head);
    display_all(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned

    // remove head
    // remove_head(head);

    // remove all 5's
    remove_5(head);
    
    // remove tail
    // remove_tail(head);
    
    display_all(head);
    
    return 0;
}
