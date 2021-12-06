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

    // Clearing/ignoring buffers was a contribution of a prior C++ student, Mahmoud Abdelmoneum
    cin.clear();
    cin.ignore(10000, '\n');

    // If user command is "add" (or "ADD", we gotta keep track of capitalizations lol), we add!
    if (strcmp(input, "add") == 0 || strcmp(input, "ADD") == 0) {
      ADD(&mediaList);
    }

    // If user command is "search", we search!
    else if (strcmp(input, "search") == 0 || strcmp(input, "SEARCH") == 0) {
      // Ask user to specify search method
      cout << "Do you want to search by title, or search by year?" << endl;

      // Shoutout to Momo once again
      cin.get(input, 6);
      cin.clear();
      cin.ignore(10000, '\n');

      // If user specified "search by title"
      if (strcmp(input, "title") == 0) {
	cout << "Enter title: " << endl;

	cin.get(title, 40);
	cin.clear();
	cin.ignore(10000, '\n');

	// Now we search!
	SEARCH(title, &mediaList);
      }

      // If user specified "search by year"
      else if (strcmp(input, "year") == 0) {
	cout << "Input year: " << endl;
	cin >> year;

	cin.clear();
	cin.ignore(10000, '\n');

	// Now we search, but this time, using the year
	SEARCH(year, &mediaList);
      }
    }

    // If user command is "delete", we delete!
    else if (strcmp(input, "delete") == 0 || strcmp(input, "DELETE") == 0) {
      cout << "Do you want to delete by title, or delete by year?" << endl;
      // Don't need to get any more than 6 chars since "title" = 6 chars long (don't forget that last one lol this took me the longest time to debug)
      cin.get(input, 6);
    }
  }
}
