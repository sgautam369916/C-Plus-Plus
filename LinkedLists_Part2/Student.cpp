// Student.cpp class file for Linked Lists Part 2 project
// Author: Shudhant Gautam
// Date: 30 January 2022

#include <iostream>
#include <cstring>
#include "Student.h"

using namespace std;

// Empty Student constructor
Student::Student() {

}

// Empty Student destructor
Student::~Student() {
  // Got help for this part from Mahmoud A and Faizan K
  delete &firstName;
  delete &lastName;
  delete &ID;
  delete &GPA;
}

// getFirst function
char* Student::getFirst() {
  return firstName;
}

// getLast function
char* Student::getLast() {
  return lastName;
}

// getID function
int Student::getID() {
  return ID;
}

// setID function
void Student::setID(int IDin) {
  ID = IDin;
}

// getGPA function
float Student::getGPA() {
  return GPA;
}

// setGPA function
void Student::setGPA(float GPAin) {
  GPA = GPAin;
}
