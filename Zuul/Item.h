// Header file for Items class in Zuul project
// Author: Shudhant Gautam
// Date: 19 December 2021

#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <cstring>

using namespace std;

class Item {
 public:
  Item();
  void setName(char*);
  char* getName();
  void setId(int);
  int getId();
 private:
  char* name;
  int id;
};

#endif
