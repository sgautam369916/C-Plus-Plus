// Author: Shudhant Gautam
// Date: 05 December 2021

#ifndef MUSIC_H
#define MUSIC_H

#include <iostream>
#include <cstring>
#include "Media.h"

using namespace std;

class Music : public Media {
 public:
  Music();
  virtual int getType();
  char* getPublisher();
  char* getArtist();
  int* getDuration();
 private:
  char artist[30];
  char publisher[30];
  int duration;
};
#endif
