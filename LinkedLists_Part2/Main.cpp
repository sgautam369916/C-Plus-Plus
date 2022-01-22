// Main file for Linked Lists Part 2 project
// Author: Shudhant Gautam
// Date: 30 January 2022

#include "Node.h"
#include "Student.h"

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <iomanip>

using namespace std;

// Defining the functions

void addNew(Node* prev, Student* student);
void print(Node* next);
float average(Node* next);
void remove(Node* next, Node* prev, char name[]);

Node* firstNode = NULL;

int main() {
  std::cout << std::fixed;
  std::cout << std:setprecision(2);

  while (true) {
    // Thought I'd defer from 30 char-long arrays for once
    char userInput[10];
    int IDInput;
    float GPAInput;

    cout << "Welcome! What would you like to do? ADD, DELETE, PRINT, AVERAGE, or QUIT?" << endl;
    cin.get(userInput, 10);
    cin.clear();
    cin.ignore(10000, '\n');

    // If user inputs "ADD" (or "add" lol)
    if (strcmp(userInput, "ADD") == 0 || strcmp(userInput, "add") == 0) {
      Student* newStudent = new Student;

      // First name
      cout << "Please enter the first name of the student: " << endl;
      cin.get(newStudent->getFirst(), 10);
      cin.clear();
      cin.ignore(10000, '\n');

      // Last name
      cout << "Please enter the last name of the student: " << endl;
      cin.get(newStudent->getLast(), 10);
      cin.clear();
      cin.ignore(10000, '\n');

      // Student ID
      cout << "Please enter the student's ID #: " << endl;
      cin >> IDInput;
      cin.clear();
      cin.ignore(10000, '\n');

      // GPA
      cout << "Please enter the student's GPA: " << endl;
      newStudent->setGPA(GPAInput);
      cin.clear();
      cin.ignore(10000, '\n');

      // Kind of like committing changes to Git lol
      addNew(firstNode, newStudent);

      cout << "Student has succesfully been entered." << endl;
    }

    // Delete
    else if (strcmp(userInput, "DELETE") == 0 || strcmp(userInput, "delete" == 0)) {
      // If the first node is NULL, that means there's nothing in the linked list
      if (firstNode == NULL) {
	cout << "ERROR: Please enter a student before trying to delete. There are currently no students in the system." << endl;
      }
      else {
	cout << "Please enter the first name of the student you'd like to delete: " << endl;
	cin.get(userInput, 10);
	cin.clear();
	cin.ignore(10000, '\n');

	// Practical Final prep lol
	remove(firstNode, NULL, userInput);
      }
    }

    // Print
    else if (strcmp(userInput, "PRINT") == 0 || strcmp(userInput, "print" == 0)) {
      // If the first node is NULL, that means there's nothing in the linked list
      if (firstNode == NULL) {
	cout << "ERROR: Please enter a student before trying to print. There are currently no students in the system." << endl;
      }
      else {
	cout << endl;
	print(firstNode);
      }
    }

    // Average
    else if (strcmp(userInput, "AVERAGE") == 0 || strcmp(userInput, "average" == 0) || strcmp(userInput, "avg" == 0)) {
      // If the first node is NULL, that means there's nothing in the linked list
      if (firstNode == NULL) {
	cout << "ERROR: Please enter a student before trying to average. There are currently no students in the system." << endl;
      }
      else {
	cout << "The average GPA of all students entered is: " << average(firstNode) << endl;
      }
    }

    // Quit
    else if (strcmp(userInput, "QUIT") == 0 || strcmp(userInput, "quit" == 0)) {
      break;
    }
    else {
      cout << "ERROR: invalid input. Please try again." << endl;
    }
  }
  return 0;
}

// Adding new student function
void addNew (Node* previousNode, Student* student) {
  // If first node is NULL, it's blank, and the node can be used to construct the linked list now
  if (firstNode == NULL) {
    firstNode = new Node(student);
  }

  // Otherwise, if the node is already filled with data, create a new node after it
  else if (student->getID() < firstNode->getStudent()->getID()) {
    Node* tempNode = new Node(firstNode->getStudent());
    tempNode->setNext(firstNode->getNext());
    firstNode->setStudent(student);
    // Now the next node is the tempNode
    firstNode->setNext(tempNode);
  }

  // Otherwise, if the next node is NULL (end of linked list)
  else if (previousNode->getNext() == NULL) {
    Node* newNode = new Node(student);
    // Add a node to the end of the list
    previousNode->setNext(newNode);
  }

  // If the current student's ID number is less than that of the next student's ID number in the linked list...
  else if (student->getID() < previousNode->getNext()->getStudent()->getID()) {
    Node* newNode = new Node(student);
    newNode->setNext(previousNode->getNext());
    // Now the next node is a new node
    previousNode->setNext(newNode);
  }

  // Otherwise, add a new node
  else {
    addNew(previousNode->getNext(), student);
  }
}

// Printing current list function
void print(Node* nextNode) {
  // As long as the next node is not blank/as long as you've not reached the end of the linked list
  if (nextNode != NULL) {
    // Print out the last name of the student
    cout << nextNode->getStudent()->getLast() << ", ";
    cout << nextNode->getStudent()->getFirst() << endl;
    cout << nextNode->getStudent()->getID() << endl;
    cout << nextNode->getStudent()->getGPA();
    // cout separator
    cout << "===============" << endl;

    // RECURSION!! So once the program gets to this line, it'll go back up to line #162 and run this function over and over again, until the if statement in line #164 is no longer true (end of linked list)
    print(nextNode->getNext());
  }
}

// Delete student function
void removeStudent(Node* nextNode, Node* previousNode, char studentName[]) {
  // For user's "yes" or "no" input
  char binaryUserInput;
  // If the next node is equal to the first node and the student's first names match up with the user's input
  if (nextNode == firstNode && strcmp(nextNode->getStudent()->getFirst(), studentName) == 0) {
    
  }
  
}
