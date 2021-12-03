// The purpose of this assignment is to create a database that include videogames, music, and movies. Oh, and learn how to use classes.
// Author: Shudhant Gautam
// Date: 05 December 2021

#include <iostream>
#include <cstring>
#include <vector>

// Header files
#include "Media.h"
#include "Videogames.h"
#include "Music.h"
#include "Movies.h"

using namespace std;

// Defining functions
void ADD(vector<Media*>* media);
void DELETE(char* title, vector<Media*>* media);
void SEARCH(char* title, vector<Media*>* media);
void SEARCH(int year, vector<Media*>* media);
void DELETE(int year, vector<Media*>* media);

int main() {
  bool running = true;

  char userCommand = [10];
  char titleIn = [50];
  int yearIn;

  vector<Media*> mediaList;

  while (run) {
    cout << "Welcome! Would you like to SEARCH, ADD, DELETE, or QUIT?" << endl;
    cin.get(10);
    cin.clear();
    cin.ignore(10000, '\n');

    if (strcmp(input, "title") == 0) {
      cout << "Input title is: " << endl;
    }
  }
}
