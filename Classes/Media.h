// Header file for Media parent class in Classes project
// Author: Shudhant Gautam
// Date: 05 December 2021

#include <iostream>
#include <cstring>

using namespace std:

class Media {
 public:
  Media();
  char* getTitle();
  int* getYear();
  char* getType();
  
 private:
  char title[];
  int type;
};
