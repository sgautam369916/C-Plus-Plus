// CPP file for Student class in Linked Lists Part 1 Project
// Author: Shudhant Gautam
// Date: 16 January 2022

#include <iostream>
#include <cstring>

#include "Student.h"

using namespace std;

// (seemingly useless) constructor
Student::Student() {

}

// Destructor
Student::~Student() {
  delete &firstName;
  delete &lastName;
  delete &ID;
  delete &GPA;
}

// getFirst
char *Student::getFirst() {
  return firstName;
}

// getLast
char* Student::getLast() {
  return lastName;
}

int* Student::getID() {
  return &ID;
}

float* Student::getGPA() {
  return &GPA;
}
