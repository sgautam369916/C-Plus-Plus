// Student.h header file for Linked Lists Part 2 project
// Author: Shudhant Gautam
// Date: 30 January 2022

#ifndef student_h
#define student_h

#include <iostream>
#include <cstring>

using namespace std;

class Student {
 public:
  // Student constructor
  Student();
  // Student destructor
  ~Student();
  // getFirst
  char* getFirst();
  // getLast
  char* getLast();
  // getID
  int getID();
  // setID
  void setID(int);
  // getGPA
  float getGPA();
  // setGPA
  void setGPA(float);
 private:
  char firstName[10];
  char lastName[10];
  int ID;
  float GPA;
};

#endif
