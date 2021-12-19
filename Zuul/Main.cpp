// This project is for the Zuul game, but in the horrendously blasphemous language of C++ programming
// Author: Shudhant Gautam
// Date: 19 December 2021

#include <iostream>
#include <cstring>
#include <iomanip>
#include <vector>
#include <map>
#include <algorithm>

#include "Room.h"
#include "Item.h"

using namespace std;

// Internal functions
void createRoom(vector<Room*>* rooms);
void createItem(vector<Item*>* items);

// User-end functions
void printRoom(vector<Room*>* rooms, vector<Item*>* items, int curRoom);
void getInventory(vector<Item*>* items, vector<int> inventory);
void getItem(vector<Room*>* rooms, vector<Item*>* items, vector<int>* inventory, int curRoom, char itemName[]);
void dropItem(vector<Room*>* rooms, vector<Item*>* items, vector<int>* inventory, int curRoom, char itemName[]);
int move(vector<Room*>* rooms, int curRoom, char direction[]);

// Finally! Something I recognize. Just kidding.
int main() {
  // Almost standard practice at this point...
  bool running = true;

  vector<Room*> roomList;
  vector<Item*> itemList;
  vector<int> inventory;

  // To be used in determining user's wish
  char userInput[30];
  int curRoom = 1;

  // Calling internal functions
  createRoom(&roomList);
  createItem(&itemList);

  // Initial game messages
  cout << "Welcome! Huh? Oh what's that! The coronavirus is coming!" << endl;
  cout << "Quick! Get into the hospital and find things for your survival." << endl;
  cout << "Wondering how to play? You have 4 commands: move, get, drop, and inv." << endl;
  cout << "Good luck." << endl;
  
  // Only execute while program is in running state
  while (running) {
    cout << "You are in the " << endl;
    printRoom(&roomList, *itemList, curRoom);
    cin >> userInput;
    cin.clear();
    cin.ignore(10000, '\n');

    // God I love strcmp
    if (strcmp(userInput, "quit") == 0) {
      running = false;
    }

    else if (strcmp(userInput, "go") == 0) {
      cout << "Where would you like to go?" << endl;
      cin >> userInput;
      cin.clear();
      cin.ignore(10000, '\n');

      if (move(&roomList, curRoom, userInput) == 0) {
	cout << "Uh oh. There's nothing there. Try a different direction." << endl;
      }

      else {
	curRoom = move(&roomList, curRoom, userInput);
      }
    }

    else if (strcmp(userInput, "inv") == 0) {

      // As long as the inventory is not empty
      if (inventory.size() != 0) {
	cout << "Here's your inventory: " << endl;
	printInventory(&itemList, inventory);
      }
      
      // Otherwise, if it's empty...
      else {
	cout << "You do not have anything in your inventory. Pick up items in rooms to fill it up!" << endl;
      }
    }

    // Pick up item
    else if (strcmp(userInput, "get") == 0) {
      cout << "Name the item you'd like to pick up (spelling counts!): " << endl;

      cin >> userInput;
      cin.clear();
      cin.ignore(10000, '\n');

      // Calling getItem function
      getItem(&roomList, &itemList, &iunventory, curRoom, userInput);
    }

    // Dropping an item
    else if (strcmp(userInput, "drop") == 0) {
      cout << "Name the item you'd like to drop (spelling counts!): " << endl;

      cin >> userInput;
      cin.clear();
      cin.ignore(10000, '\n');

      // Calling dropItem function
      dropItem(&roomList, *itemList, &inventory, curRoom, input);
    }

    else if (strcmp(input, "help") == 0) {
      cout << "The goal of the game is to go through the rooms and find a certain item that will help you win the game. Start by exploring!" << endl;
      cout << "Wondering how to play? You have 4 commands: move, get, drop, and inv." << endl;
      cout << "Good luck!" << endl;
    }

    // If invalid input
    else {
      cout << "Uh oh. Invalid input. Please try again." << endl;
    }

    // Winning
    for (int i = 0; i < inventory.size(); i++) {
      for (int j = 0; j < inventory.size(); j++) {
	for (int k = 0; k < inventory.size(); k++) {

	  // I got help for this part from Faizan K and Mahmoud A
	  if (curRoom == 1 && inventory[i] == 1 && inventory[j] == 2 && inventory[k] == 3) {
	    // You won!
	    cout << "HOORAY! You've survived the coronavirus and have won the game. Give yourself a pat on the back!" << endl;
	    return 0;
	  }
	}
      }
    }

    // Losing
    for (int i = 0; i < inventory.size(); i++) {

      // I got inspiration from Faizan for this part of my Zuul game
      if (inventory[i] == 4 || inventory[i] == 5) {
	cout << "lol you just lost" << endl;
	return 0;
      }
    }
  }
  return 0;
}

// Defining move function
int move(vector<Room*>* rooms, int curRoom, char direction[]) {
  // Now I can see why Classes comes before this project
  vector<Room*>::iterator it;

  for (it = rooms->begin(); it != rooms->end(); it++) {
    if (curRoom == (*it)->getId()) {
      map<int, char*> exits;
      exits = *(*i) -> getExits();

      // Exits
      map<int, char*>::const_iterator cit;

      for (cit = exits.begin(); cit != exits.end(); cit++) {
	if (strcmp(cit -> second, direction) == 0) {
	  // Return player's desired move
	  return cit -> first;
	}
      }
    }
  }
  return 0;
}

// Room creation function
void createRoom(vector<Room*>* rooms) {
  // Exits
  char* north = (char*)("north");
  char* east = (char*)("east");
  char* south = (char*)("south");
  char* west = (char*)("west");

  // Create exit map for exit mapping
  map<int, char*> exitMap;

  // Rooms
  Room* rotunda = new Room();
  rotunda -> setDescrioption((char*)("at the front entrance of the hospital."));
  rotunda -> setId(1);

  // Possible exits from the rotunda
  exitMap.insert(pair<int, char*> (2, east));
  exitMap.insert(pair<int, char*> (3, north));
  exitMap.insert(pair<int, char*> (4, south));
  rotunda -> setExits(exitMap);
  rotunda ->setItem(0);

  // Vector stuff
  rooms -> push_back(rotunda);

  // Wipe map clean to be reused for next room's exit mapping
  exitMap.clear();

  Room* LND = new Room();
  LND -> setDescription((char*)("in the Labor and Delivery Room. Uh... what are you doing here?"));
  LND -> set Id(4);
  exitMap.insert(pair<int, char*> (1, north));
}
