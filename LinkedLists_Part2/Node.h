// Node.h header file from my partner, Stefan Smith, for the Linked Lists Part 2 project
// Author: Stefan Smith
// Date: 30 January 2022

#ifndef node_h
#define node_h
#include "Student.h"
#include <iostream>
#include <cstring>

using namespace std;

class Node {
 public:
  Node(Student*);
  ~Node();
  Student* getStudent();
  Node* getNext();
  void setNext(Node* newNext);
  void setStudent(Student* newStudent);
 private:
  Node* nextNode;
  Student* student;
};

#endif
