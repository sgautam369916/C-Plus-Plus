// Title: Command Line-based Tic Tac Toe Game
// Author: Shudhant Gautam
// Date: 24 October 2021

#include <iostream>
using namespace std;

// Function to initialize character array and check for win conditions
int check_win(char square[3][3]) {
  // Compare the values of the two squares with one another to keep it simple
    // Check for win conditions in row 1
    if (square[0][0] == square[1][0] && square[1][0] == square[2][0])

        return 1;
    // Check for win conditions in row 2
    else if (square[0][1] == square[1][1] && square[1][1] == square[2][1])

        return 1;
    // Check for win conditions in row 3
    else if (square[2][0] == square[2][1] && square[2][1] == square[2][2])

        return 1;
    // Check for win conditions column 1
    else if (square[0][0] == square[0][1] && square[0][1] == square[0][2])

        return 1; 
    // Check for win conditions in column 2
    else if (square[1][0] == square[1][1] && square[1][1] == square[1][2])

        return 1;
    // Check for win conditions in column 3
    else if (square[2][0] == square[2][1] && square[2][1] == square[2][2])

        return 1;
    // Now we have fun! The diagonals...
    else if (square[0][0] == square[1][1] && square[1][1] == square[2][2])

        return 1;
    else if (square[2][0] == square[1][1] && square[1][1] == square[0][2])

        return 1;
    // The outcome of most of my games, the draw:
    else if (square[0][0] != '1' && square[1][0] != '2' && square[2][0] != '3' 
                    && square[0][1] != '4' && square[1][1] != '5' && square[2][1] != '6' 
                  && square[0][2] != '7' && square[1][2] != '8' && square[2][2] != '9')

        return 0;
    else
        return -1;
    // Win = 1 | 0 = Draw | -1 = No win
}

// Function that actually creates the physical board for the CLI
void create_board(char square[3][3]) {
    cout << "\nPlayer 1 (X)  -  Player 2 (O)" << endl << endl;
    cout << endl;

    cout << "     |     |     " << endl;
    cout << "  " << square[0][0] << "  |  " << square[1][0] << "  |  " << square[2][0] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[0][1] << "  |  " << square[1][1] << "  |  " << square[2][1] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[0][2] << "  |  " << square[1][2] << "  |  " << square[2][2] << endl;

    cout << "     |     |     " << endl << endl;
}

// Main part of code that runs everything
int main() {
  // Each square
  char square[3][3] = {'1','4','7','2','5','8','3','6','9'};

  // Setting up the integers
  int player = 1, i, choice, xWins = 0, oWins = 0, ties = 0;
  int lol = 1;

  // Temp char
  char mark;

  // Reassign the values to each square after each round is complete
  while (lol == 1) {
    char square[3][3] = {'1','4','7','2','5','8','3','6','9'};
    i = -1;

    // As long as there is no win or draw, do the following:
    do {

      // Call function to create board
      create_board(square);

      // Change player from 1 to 2 to go from X --> O
      player = (player % 2) ? 1 : 2;

      // Ask user for choice
      cout << "Player " << player << ", enter a number:  ";
      cin >> choice;

      // Treat mark as second player, and then change to whatever the user didn't choose
      mark = (player == 1) ? 'X' : 'O';

      // As long as the square is empty, mark plays a move
      if (choice == 1 && square[0][0] == '1')

        square[0][0] = mark;
      else if (choice == 2 && square[1][0] == '2')

        square[1][0] = mark;
      else if (choice == 3 && square[2][0] == '3')

         square[2][0] = mark;
      else if (choice == 4 && square[0][1] == '4')

        square[0][1] = mark;
      else if (choice == 5 && square[1][1] == '5')

         square[1][1] = mark;
      else if (choice == 6 && square[2][1] == '6')

        square[2][1] = mark;
      else if (choice == 7 && square[0][2] == '7')

         square[0][2] = mark;
      else if (choice == 8 && square[1][2] == '8')

        square[1][2] = mark;
      else if (choice == 9 && square[2][2] == '9')

         square[2][2] = mark;
      // Otherwise, when it's not an empty square, throw an error message
      else {
        cout<<"Invalid move ";

        // Since the move was invalid, we go back to the previous turn
        player--;
        cin.ignore();
        cin.get();
      }

      // Call to check for win conditions after each move
      i = check_win(square);

      // Next player
      player++;

      // nPlayer wins! Yay!
      if(i == 1) {
        cout << "\nPlayer " << --player << " wins!\n";

	// If player is X
	if (player == 1) {
	  xWins++;
          cout << "X Wins: " << xWins << endl;
          cout << "O Wins: " << oWins << endl;
          cout << "Ties: " << ties << endl;
        }

	// Otherwise, if player is O
        else {
          oWins++;
          cout << "X Wins: " << xWins << endl;
          cout << "O Wins: " << oWins << endl;
          cout << "Ties: " << ties << endl;
        }

      }
      // What about if it was not a win, nor a loss? A draw...?
      else if (i == 0) {
        ties++;
        cout << "Game resulted in a draw!\n";

        cout << "X Wins: " << xWins << endl;
        cout << "O Wins: " << oWins << endl;
        cout << "Ties: " << ties << endl;

      }

    } while (i==-1);
  }
  // Create the board once again to prep for next round
    create_board(square);

    cin.ignore();
    cin.get();
    return 0;
}
