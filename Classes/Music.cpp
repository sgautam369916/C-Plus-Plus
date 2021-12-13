// Author: Shudhant Gautam
// Date: 05 December 2021

#include <iostream>
#include <cstring>
#include "Media.h"
#include "Music.h"

using namespace std;

Music::Music() {
  // Nothing goes here
}

char* Music::getArtist() {
  return artist;
}

int*Music::getDuration() {
  // Gotta use the & to pass by reference!
  return &duration;
}

char* Music::getPublisher() {
  return publisher;
}

int Music::getType() {
  return 1;
}
