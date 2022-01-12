// CPP file for Nodes class in Linked Lists Part 1 Project
// Author: Shudhant Gautam
// Date: 01/16/2022

#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;

Node::Node(Student* newStudent) {
  student = new Student;
  next = NULL;
}

Node::~Node() {
  delete &student;
  next = NULL;
}

// setStudent function
void Node::setStudent(Student* newStudent) {
  student = newStudent;
}

// setNext function
void Node::setNext(Node* newNext) {
  next = newNext;
}

// getStudent function
Student* Node::getStudent() {
  return student;
}

// getNext function
Node* Node::getNext() {
  return next;
}
