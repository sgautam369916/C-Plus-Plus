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
      cin.clear();
      cin.ignore(10000, '\n');

      // If user specified delete by title
      if (strcmp(input, "title") == 0) {
	cout << "Input title: " << endl;
	cin.get(title, 30);
	cin.clear();
	cin.ignore(10000, '\n');

	// Now we delete!
	DELETE(title, &mediaList);
      }
      // if user specified dlete by year
      else if (strcmp(input, "year") == 0) {
	cout << "Input year: " << endl;
	cin >> year;
	cin.clear();
	cin.ignore(10000, '\n');

	// Now we delete, but this time, using year
	DELETE(year, &mediaList);
      }
    }

    // If user wants to quit (or "QUIT)
    else if (strcmp(input, "quit") == 0 || strcmp(input, "QUIT") == 0) {
      // Not too hard, right?
      run = false;
    }

    // Just covering all my bases here
    else {
      cout << "ERROR - Invalid input! Please enter either ADD, DELETE, SEARCH, or QUIT" << endl;
    }
  }
  return 0;
}

// Defining ADD function now
void ADD(vector<Media*>* media) {
  char input[30];
  cout << "What type of media are you adding? Is it a videogame, movie, or song?" << endl;

  // Using 12 since largest word is 12 chars
  cin.get(input, 12);
  cin.clear();
  cin.ignore (10000, '\n');

  // If the user wants to add a movie
  if (strcmp(input, "movie") == 0) {
    // Pointers! I totally didn't spend several class periods learning what these are!
    Movie * movie = new Movie();

    // Title of movie
    cout << "What's the movie title?" << endl;
    cin.get(movie->getTitle(), 30);
    cin.clear();
    cin.ignore(10000, '\n');

    // Year of movie
    cout << "What's the year that the movie was released?" << endl;
    cin >> *movie->getYear();
    cin.clear();
    cin.ignore(10000, '\n');

    // Director of movie (Christopher Nolan is my favorite)
    cout << "Who was the movie's director?" << endl;
    cin.get(movie->getDirector(), 30);
    cin.clear();
    cin.ignore(10000,'\n');

    // Duration of movie
    cout << "How long is the movie, in minutes?" << endl;
    cin >> *movie->getDuration();
    cin.clear();
    cin.ignore(10000, '\n');

    // Rating of movie
    cout << "What is the rating of the movie, out of 5 stars?" << endl;
    cin >> *movie->getRating();
    cin.clear();
    cin.ignore(10000, '\n');

    // Pushback
    media->push_back(movie);
  }

  // Now for my favorite, videogames!
  else if (strcmp(input, "videogame") == 0) {
    Videogame* videogame = new Videogame();

    // Title of videogame
    cout << "What's the videogame title?" << endl;
    cin.get(videogame->getTitle(), 30);
    cin.clear();
    cin.ignore(10000, '\n');

    // Year of videogame
    cout << "What year was the videogame released in?" << endl;
    cin >> *videogame->getYear();
    cin.clear();
    cin.ignore(10000, '\n');

    // Publisher of videogame
    cout << "Who is the videogame's publisher?" << endl;
    cin.get(videogame->getPublisher(), 30);
    cin.clear();
    cin.ignore(10000, '\n');

    // Rating of videogame
    cout << "what is the rating of the videogame, out of 5 stars?" << endl;
    cin >> *videogame->getRating();
    cin.clear();
    cin.ignore(10000, '\n');

    //Pushback
    media->push_back(videogame);
  }

  // Music!
  else if (strcmp(input, "music") == 0) {
    Music* music = new Music();

    // Title of song
    cout << "What is the name of the song?" << endl;
    cin.get(music->getTitle(), 30);
    cin.clear();
    cin.ignore(10000, '\n');

    // Artist of song
    cout << "Who is the song's artist?" << endl;
    cin.get(music->getArtist(), 30);
    cin.clear();
    cin.ignore(10000, '\n');

    // Duration of song
    cout << "How long is the song, in seconds?" << endl;
    cin >> *music->getDuration();
    cin.clear();
    cin.ignore(10000, '\n');

    // Publisher of song
    cout << "Who is the song's publisher?" << endl;
    cin.get(music->getPublisher(), 30);
    cin.clear();
    cin.ignore(10000, '\n');

    // Pushback
    media->push_back(music);
  }
}
