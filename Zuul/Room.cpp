// CPP file for Rooms class in Zuul project
// Author: Shudhant Gautam
// Date: 19 December 2021

#include <iostream>
#include <cstring>
#include <map>
#include "Room.h"

using namespace std;

// Blank on purpose
Room::Room() {

}

// getDescription function
char* Room::getDescription() {
  return description;
}

// getExits function (I love maps)
map<int,char*>* Room::getExits() {
  return &exits;
}

// getId function
int Room::getId() {
  return id;
}

// getItem function
int Room::getItem() {
  return item;
}

// setDescription function
void Room::setDescription(char* newDescription) {
  description = newDescription;
}

// setExits function
void Room::setExits(map<int, char*> newExits) {
  exits = newExits;
}

// setId function
void Room::setId(int newId) {
  id = newId;
}

// setItem function
void Room::setItem(int newItem) {
  item = newItem;
}
