//list.h
#include <iostream>
#include <cctype>
#include <cstdlib>
using namespace std;

struct node
{
    int data;
    node * next;
};

/* *****************YOUR TURN! ******************************** */
/* PLACE YOUR PROTOTYPE HERE */
void remove_head(node*& head);
void remove_5(node*& head);
void remove_tail(node*& head);

/* These functions are already written and can be called to test out your code */
void build(node * & head);      //supplied
void display_all(node * head);  //supplied
