#ifndef STUDENT_H
#define STUDENT_H

using namespace std;

class Student {
 public:
  Student();
  ~Student();
  char* getFirst();
  char* getLast();
  int* getID();
  float* getGPA();

 private:
  char firstName[30];
  char lastName[30];
  int ID;
  float GPA;
};

#endif
