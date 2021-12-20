// CPP file for Items class for Zuul project
// Author: Shudhant Gautam
// Date: 19 December 2021

#include <iostream>
#include <cstring>
#include "Item.h"

using namespace std;

// Blank on purpose
Item::item() {
}

// getName function
char* Item::getName() {
  return name;
}

// getId function
int Item::getId() {
  return id;
}

// setName function
void Item::setName(char* newName) {
  name = newName;
}

//setId function
void Item::setId(int newId) {
  id = newId;
}
