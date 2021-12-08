// CPP file for Media class
// Author: Shudhant Gautam
// Date: 5 December 2021

#include "Media.h"
#include <cstring>
#include <iostream>

using namespace std;

Media::Media() {
  // Nothing goes here
}

// Retrieval methods
char* Media::getTitle() {
  return title;
}

int* Media::getYear() {
  return year;
}

int Media::getType() {
  return 0;
}
