// Author: Shudhant Gautam
// Date: 05 December 2021

#include <iostream>
#include <cstring>
#include "Media.h"
#include "Videogames.h"

using namespace std;

Videogame::Videogame() {
  // Nothing goes here
}

char* Videogame::getPublisher() {
  return publisher;
}

float* Videogame::getRating() {
  return &rating;
}

int Videogame::getType() {
  return 2;
}
