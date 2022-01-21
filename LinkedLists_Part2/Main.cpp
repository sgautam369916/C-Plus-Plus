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
      addNew(first, newStudent);

      cout << "Student has succesfully been entered." << endl;
    }

    // Delete
    if (strcmp(userInput, "DELETE") == 0 || strcmp(userInput, "delete" == 0)) {

    }

    // Print
    if (strcmp(userInput, "PRINT") == 0 || strcmp(userInput, "print" == 0)) {

    }

    // Average
    if (strcmp(userInput, "AVERAGE") == 0 || strcmp(userInput, "average" == 0) || strcmp(userInput, "avg" == 0)) {

    }

    // Quit
    if (strcmp(userInput, "QUIT") == 0 || strcmp(userInput, "quit" == 0)) {

    }
  }
}



// Now deleting function to, obviously, delete students
void del(vector<student*> *list) {
  int ID;
  cout << "Enter the ID of the student you want to delete:";

  cin >> ID;
  int position = 0;

  // Pretty interesting to see how for loops work for vectors, but here we go! (thanks Jack lol)
  for (vector<student*>::iterator j = list->begin(); j != list->end(); ++j) {
    // If the user-specified value matches with one in the vector, then...
    if((*j) -> id == ID) {

      // ... then delete!
      list->erase(list->begin() + position);
      break;
    }

    else {
      // and if not, then keep moving on.
      position++;
    }
  }
}
// Now the function to print the info out...
void print(vector<student*> *list) {

  // Starting to get the hang of iterating through it...
  for (vector<student*>::iterator i = list->begin(); i != list->end(); i++) {
    cout << **i;
  }
}

// Finally, something I recognize: main()!
int main() {
  bool run = true;

  // Setting up the vector
  vector <student*>* list = new vector<student*>();

  // To use strcmp on the user input for later down the road
  char cmd[10];

  // So user can quit at any time
  while (run == true) {
    cout << "\nWould you like to ADD, DELETE, PRINT, or QUIT" << endl;
    cin >> cmd;

    // If the user says "ADD", then...
    if (strcmp(cmd,"ADD") == 0) {
      add(list);
      cout << "The student has been added." << endl;
    }

    // If the user says "DELETE", then...
    else if (strcmp(cmd,"DELETE") == 0) {
      del(list);
      cout << "The student has been deleted.";
    }

    // If the user simply wants a list of all the students, then...
    else if (strcmp(cmd,"PRINT") == 0) {
      print(list);
    }

    // If the user hates your program and wants to quit, then...
    else if (strcmp(cmd,"QUIT") == 0) {
      exit(0);
    }

    else
    {
      cout << "Invalid input. Please try again. Remember, capitalizations matter!";
    }
  }
}
