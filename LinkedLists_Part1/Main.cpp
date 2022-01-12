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

  // printing first student
  cout << " " << endl;
  // print name
  cout << "Student 1 is: " << sdnt->getFirst() << " " << sdnt->getLast() << ", ";
  cout << "ID # is: " << *sdnt->getID() << ", GPA is: ";

  // I got help on this part from Mahmoud A.
  cout << fixed << setprecision(2) << *sdnt->getGPA() << endl;

  // printing second student
  cout << "Student 2 is: " << sdnt2->getFirst() << " " << sdnt2->getLast() << ", ";
  cout << "ID # is: " << *sdnt2->getID() << ", GPA is: ";
  cout << fixed << setprecision(2) << *sdnt2->getGPA() << endl << endl;

  // Node stuff
  Node* nodeA = new Node(sdnt);
  Node* nodeB = new Node(sdnt2);
  nodeA->setStudent(sdnt);
  nodeA->setNext(nodeB);
  nodeB->setStudent(sdnt2);

  // Printing the nodes
  cout << " " << endl;
  cout << "The nodes are: " << endl;
  cout << nodeA->getStudent()->getFirst() << " " << nodeA->getStudent()->getLast() << endl;
  // I probably should put spaces before and after the arrows but I'm too lazy to change it everywhere
  cout << nodeA->getNext()->getStudent()->getFirst() << " " << nodeA->getNext()->getStudent()->getLast() << endl;

  // staple of C++ code
  return 0;
}
