// Header file for Videogames daughter class in Classes project
// Author: Shudhant Gautam
// Date: 05 December 2021

#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include <iostream>
#include <cstring>
#include "Media.h"

using namespace std;

class Videogame : public Media {
 public:
  Videogame();
  virtual int getType();
  char* getPublisher();
  float* getRating();
 private:
  char publisher[30];
  float rating;
};
#endif
