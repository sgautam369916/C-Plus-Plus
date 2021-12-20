// Header file for Rooms class in Zuul project
// Author: Shudhant Gautam
// Date: 19 December 2021

#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <cstring>
#include <map>

using namespace std;

// Defining Room class and its attributes
class Room {
 public:
  Room();
  // getDescription function
  char* getDescription();
  // getId function
  int getId();
  // getItem function
  int getItem();
  map<int, char*>* getExits();

  // setDescription function
  void setDescription(char*);
  // setExits function (using map made exits so much easier lol)
  void setExits(map<int, char*>);
  // setId function
  void setId(int);
  // setItem function
  void setItem(int);
 private:
  char* description;
  map<int, char*> exits;
  int id;
  int item;
};

#endif
