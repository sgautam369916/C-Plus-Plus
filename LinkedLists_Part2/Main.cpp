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

void addNew(Node* previousNode, Student* student);
void print(Node* nextNode);
float average(Node* nextNode);
void remove(Node* nextNode, Node* previousNode, char studentName[]);

Node* firstNode = NULL;

int main() {
  std::cout << std::fixed;
  std::cout << std::setprecision(2);

  while (true) {
    // Thought I'd defer from 30 char-long arrays for once
    char userInput[10];
    int IDInput;
    float GPAInput;

    cout << "Welcome! What would you like to do? ADD, DELETE, PRINT, AVERAGE, or QUIT?" << endl;
    cin.get(userInput, 10);
    cin.clear();
    cin.ignore(1000000, '\n');

    // If user inputs "ADD" (or "add" lol)
    if (strcmp(userInput, "ADD") == 0 || strcmp(userInput, "add") == 0) {
      Student* newStudent = new Student;

      // First name
      cout << "Please enter the first name of the student: " << endl;
      cin.get(newStudent->getFirst(), 10);
      cin.clear();
      cin.ignore(1000000, '\n');

      // Last name
      cout << "Please enter the last name of the student: " << endl;
      cin.get(newStudent->getLast(), 10);
      cin.clear();
      cin.ignore(1000000, '\n');

      // Student ID
      cout << "Please enter the student's ID #: " << endl;
      cin >> IDInput;
      newStudent->setID(IDInput);
      cin.clear();
      cin.ignore(1000000, '\n');

      // GPA
      cout << "Please enter the student's GPA: " << endl;
      cin >> GPAInput;
      newStudent->setGPA(GPAInput);
      cin.clear();
      cin.ignore(1000000, '\n');

      // Kind of like committing changes to Git lol
      addNew(firstNode, newStudent);

      cout << "Student has succesfully been entered." << endl;
    }

    // Delete
    else if (strcmp(userInput, "DELETE") == 0 || strcmp(userInput, "delete") == 0) {
      // If the first node is NULL, that means there's nothing in the linked list
      if (firstNode == NULL) {
	cout << "ERROR: Please enter a student before trying to delete. There are currently no students in the system." << endl;
      }
      else {
	cout << "Please enter the first name of the student you'd like to delete: " << endl;
	cin.get(userInput, 10);
	cin.clear();
	cin.ignore(1000000, '\n');
	
	remove(firstNode, NULL, userInput);
      }
    }

    // Print
    else if (strcmp(userInput, "PRINT") == 0 || strcmp(userInput, "print") == 0) {
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
    else if (strcmp(userInput, "AVERAGE") == 0 || strcmp(userInput, "average") == 0 || strcmp(userInput, "avg") == 0) {
      // If the first node is NULL, that means there's nothing in the linked list
      if (firstNode == NULL) {
	cout << "ERROR: Please enter a student before trying to average. There are currently no students in the system." << endl;
      }
      else {
	cout << "The average GPA of all students entered is: " << average(firstNode) << endl;
      }
    }

    // Quit
    else if (strcmp(userInput, "QUIT") == 0 || strcmp(userInput, "quit") == 0) {
      cout << "Goodbye." << endl;
      // Got bored and wanted to do a cool shutdown sequence thing
      cout << "........" << endl;
      cout << "......." << endl;
      cout << "......" << endl;
      cout << "....." << endl;
      cout << "...." << endl;
      cout << "..." << endl;
      cout << ".." << endl;
      cout << "." << endl;
      cout << " " << endl;
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
    cout << nextNode->getStudent()->getGPA() << endl;;
    // cout separator
    cout << "===============" << endl;

    // RECURSION!! So once the program gets to this line, it'll go back up to line #162 and run this function over and over again, until the if statement in line #164 is no longer true (end of linked list)
    print(nextNode->getNext());
  }
}

// Delete student function
void remove(Node* nextNode, Node* previousNode, char studentName[]) {
  // For user's "yes" or "no" input
  char binaryUserInput;
  // If the next node is equal to the first node and the student's first names match up with the user's input
  if (nextNode == firstNode && strcmp(nextNode->getStudent()->getFirst(), studentName) == 0) {
    cout << nextNode->getStudent()->getLast() << ", ";
    cout << nextNode->getStudent()->getFirst() << endl;
    cout << nextNode->getStudent()->getID() << endl;
    cout << nextNode->getStudent()->getGPA() << endl;
    // cout separator
    cout << "===============" << endl;

    cout << "Are you sure you want to delete this student from the list? (Y/N)" << endl;
    cin >> binaryUserInput;
    cin.clear();
    cin.ignore(1000000, '\n');

    // If user said yes
    if (binaryUserInput == 'Y' || binaryUserInput == 'y') {
      cout << "The selected student has succesfully been deleted." << endl;

      // Destructor to remove node
      // If the next node is NULL, or if we are at the end of the list, then
      if (nextNode->getNext() == NULL) {
	// next node is destroyed
	nextNode->~Node();
	// first node is set to NULL
	firstNode = NULL;
      }
      // Otherwise if we're not at the end of the list
      else {
	// set firstNode to the next node
	firstNode = nextNode->getNext();
	// Now we can safely destroy the nextNode
	nextNode->~Node();
	// calling remove() to remove the student from the list
	remove(firstNode, NULL, studentName);
      }
    }
    // Otherwise if the user said no
    else if (binaryUserInput == 'n' || binaryUserInput == 'N') {
      cout << "Exited deleting student." << endl;
      // If the next node is not NULL (meaning we're not at the end of the list yet)
      if (nextNode->getNext() != NULL) {
	// Then remove the next node and student
	remove(nextNode->getNext(), nextNode, studentName);
      }
    }
    // Invalid input
    else {
      cout << "ERROR: Invalid input. Please try again." << endl;
    }
  }
  //
  else if (strcmp(nextNode->getStudent()->getFirst(), studentName) == 0) {
    cout << nextNode->getStudent()->getLast() << ", ";
    cout << nextNode->getStudent()->getFirst() << endl;
    cout << nextNode->getStudent()->getID() << endl;
    cout << nextNode->getStudent()->getGPA() << endl;
    cout << "===============" << endl;

    cout << "Are you sure you want to delete this student from the list? (Y/N)" << endl;
    cin >> binaryUserInput;
    cin.clear();
    cin.ignore(1000000, '\n');

    // If user said yes
    if (binaryUserInput == 'y' || binaryUserInput == 'Y') {
      cout << "The selected student has succesfully been deleted." << endl;
      // Doubly-linked lists: going backwards in the list
      previousNode->setNext(nextNode->getNext());
      // Now we can safely destroy the next node
      nextNode->~Node();
    }
    // Otherwise if user said no
    if (binaryUserInput == 'n' || binaryUserInput == 'N') {
      cout << "Exited deleting student." << endl;
    }
    // Invalud input
    else {
      cout << "ERROR: Invalid input. Please try again." << endl;
    }
  }
  // If the next node is not NULL (meaning we're not at the end of the list yet)
  if (nextNode->getNext() != NULL) {
    // Then remove the next node and the student
    remove(nextNode->getNext(), nextNode, studentName);
  }
}

// Average
float average(Node* nextNode) {
  float totalVal = 0;
  // Number of GPA's (AKA number of students)
  int count = 0;

  // If the current node is the first node (iterating through the list)
  if (nextNode == firstNode) {
    // Then add current node's student's GPA value to totalVal
    totalVal += nextNode->getStudent()->getGPA();
    // Increase count
    count++;
  }
  // As long as the next node is not NULL (meaning we haven't reached the end of hte list yet)
  while (nextNode->getNext() != NULL) {
    // Add the next student's GPA to totalVal
    totalVal += nextNode->getNext()->getStudent()->getGPA();
    // Increase count
    count++;
    // Move on to the next node (iteration)
    nextNode = nextNode->getNext();
  }
  // Return the average
  return (totalVal/count);
}
