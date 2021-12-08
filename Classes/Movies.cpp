// Author: Shudhant Gautam
// Date: 05 December 2021

#include <iostream>
#include <cstring>
#include "Media.h"
#include "Movies.h"

using namespace std;

Movie::Movie() {
  // Nothing goes here
}

int Movie::getType() {
  return 0;
}

char* Movie::getDirector() {
  return director;
}

float* Movie::getRating() {
  return &rating;
}

int* Movie::getDuration() {
  return &duration;
}
