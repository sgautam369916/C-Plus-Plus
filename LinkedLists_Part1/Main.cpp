// Main program file for Linked Lists Part 1 project
// Author: Shudhant Gautam
// Date: 16 January 2022

#include <iostream>
#include <cstring>
#include <iomanip>
#include <stdio.h>

#include "Node.h"
#include "Student.h"

// main
int main() {

  // userInput variable
  char userInput[30];

  // first student
  Student* sdnt = new Student;

  // first name
  cout << "Please enter the student's first name: " << endl;
  cin.get(sdnt->getFirst(), 30);
  cin.clear();
  cin.ignore(10000, '\n');

  // last name
  cout << "Please enter the student's last name: " << endl;
  cin.get(sdnt->getLast(), 30);
  cin.clear();
  cin.ignore(10000, '\n');

  // student ID#
  cout << "Please enter the student's ID number: " << endl;
  cin >> *sdnt->getID();
  cin.clear();
  cin.ignore(10000, '\n');

  // GPA
  cout << "Please enter the student's GPA: " << endl;
  cin >> *sdnt->getGPA();
  cin.clear();
  cin.ignore(10000, '\n');

  // second student
  cout << " " << endl;
  Student* sdnt2 = new Student;

  // first name
  cout << "Please enter the student's first name: " << endl;
  cin.get(sdnt2->getFirst(), 30);
  cin.clear();
  cin.ignore(10000, '\n');

  // last name
  cout << "Please enter the student's last name: " << endl;
  cin.get(sdnt2->getLast(), 30);
  cin.clear();
  cin.ignore(10000, '\n');

  // student ID#
  cout << "Please enter the student's ID number: " << endl;
  cin >> *sdnt2->getID();
  cin.clear();
  cin.ignore(10000, '\n');

  // GPA
  cout << "Please enter the student's GPA: " << endl;
  cin >> *sdnt2->getGPA();
  cin.clear();
  cin.ignore(10000, '\n');

}
