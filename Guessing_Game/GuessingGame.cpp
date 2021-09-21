// Shudhant Gautam, C++ Programming, Period 1
// 09.21.2021

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

  // Initialize the variables and boolean
  int num = 0;
  int guess = 0;
  int attempts = 0;

  bool isPlaying = true;

  // Random number generator setup
  srand(time(NULL));

  // Run as long as player wants to play
  while (isPlaying == true) {
  
    // The below line of code is derived from http://www.cppforschool.com/assignment/library-functions-sol/guess-my-number.html
    num = rand() % 100;
    
    // Print statements to help the user start the game
    cout << "Welcome to the Guessing Game!";
    
    cout << "Let's get started. Enter a number between 0 and 100";
    
    cin >> guess;
    
    // Used to keep track of number of attempts
    attempts++;
    
    // Do this loop as long as the guess is incorrect, then exit as soon as it's correct
    while (guess != num) {
      
      if (guess > num) {
	cout << "Try again! You're too high.";
	
	cin >> guess;
	
	// Incorrect guesses still count as attempts
	attempts++;
      }
      
      else if (guess < num) {
	cout << "Try again! You're too low.";
	
	cin >> guess;
	attempts++;
      }
    }
    
    // Winning message!
    cout << "Ding ding ding! You got it in " << attempts << " attempts!";
    
    // Ask player if they want to play again, take in "y" or "n" inputs only
    cout << "Want to play again? (y/n)";
    
    char y_or_n;
    
    cin >> y_or_n;
    
    // If yes, then keep isPlaying to true so that the while loop can keep going
    if (y_or_n == 'y') {
      isPlaying = true;
      cout << "Alright! Here we go again!";
    }
    
    // Otherwise, the player doesn't want to play, so set isPlaying to false so the while loop can exit.
    else if (y_or_n == 'n') {
      cout << "Okay, goodbye!";
      isPlaying = false;
    }
  }
}
