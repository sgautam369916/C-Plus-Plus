// Node.cpp C++ file from my partner, Stefan Smith, for the Linked Lists Part 2 project
// Author: Shudhant Gautam
// Date: 30 January 2022

#include "Node.h"

using namespace std;

Node::Node(Student* newStudent) {
  student = newStudent;
  nextNode = NULL;
}

Node::~Node() {
  cout << "Node deleted" << endl;
}

Student* Node::getStudent() {
  return student;
}

Node* Node::getNext() {
  return nextNode;
}

void Node::setNext(Node* newNext) {
  nextNode = newNext;
}
