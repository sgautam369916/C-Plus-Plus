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

    else if (strcmp(input, "go") == 0) {
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

    else if (strcmp(input, "inv") == 0) {

      // As long as the inventory is not empty
      if (inventory.size() != 0) {

      }
    }
  }
}
