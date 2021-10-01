// Title: Palindrome Assignment
// Author: Shudhant Gautam, Helped by another C++ student
// Date: 10.1.2021
#include <iostream>
#include <cstring>

using namespace std;

// The idea to make a function that checks for the presence of punctuation was given to me by a fellow C++ student
bool palindrome_checker(char char_array[80], int length) {
  for (int i = 0; i < length; i++) {

    // For every character in the input, compare it with the array backwards
    if (char_array[i] != char_array[length - i - 1]) {
      return false;
    }
    // If the characters don't match, return true and it's not a Palindrome.
    else {
      return true;
    }
  }
}

// Main portion of the program that runs everything
int main() {

  char user_input[80];
  char input_prime[80];

  // Welcome message
  cout << "Welcome! This is a Palindrome Checker. Please enter a word or sentence that you'd like to check for Palindrome-ness :)";

  // The idea for the line below was also given to me by the same C++ student, so credit goes to him for that.
  cin.getline(user_input, 80);

  int length = strlen(user_input);

  // This is a counter variable that helps the code know the next index to iterate on after it has gone through once, but it also knows how many times a character has been written to input_prime. This is so that the function "palindrome_checker" from above knows the length of the character array.
  int x = 0;

  for (int i = 0; i < length; i++) {

    // If the current char we're looking at is a alphanumeric (aka no punctuation)... this is just an easier way to "remove punctuation"
    if (isalpha(user_input[i])) {

      // Converting the current char we're looking at to a lowerchase character, and putting it into the input_prime array which stores the PROPOSED palindrome
      input_prime[x] = tolower(user_input[i]);

      // Here's that counter I was talking about earlier
      x++;
    }
  }

  // Now the counter comes in to save the day and define the new length of user_input after flushing out the punctuation
  length = x;

  // If the palindrome_checker function returns a true value, then that is a Palindrome.
  if (palindrome_checker(input_prime, x)) {
    cout << "That IS a Palindrome! Yay!";
  }

  // Otherwise, it's not a Palindrome.
  else {
    cout << "That is not a Palindrome!";
  } 
}
