// Date: 05 December 2021
// Author: Shudhant Gautam

#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <cstring>
#include "Media.h"

using namespace std;

class Movie : public Media {
 public:
  Movie();
  virtual int getType();
  int*getDuration();
  char* getDirector();
  float* getRating();
 private:
  char director[30];
  int duration;
  float rating;
};
#endif
