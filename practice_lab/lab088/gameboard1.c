// gameboard.c
// Game Board Class for a simple two-player tic-tac-toe game
// by Richard Zhao
// For use by CMPUT 201 for educational purposes only
// November 2014

#include <stdio.h>
#include <stdlib.h>
#include "gameboard.h"


// Constructor
gameboard::gameboard() {
  initialize_board();
}

// Destructor
gameboard::~gameboard() {
  // nothing to do here
}


// initializes each space of the board to 0 (empty), and resets other variables
void gameboard::initialize_board() {

  for (int i = 0; i< 9; i++)
  {
    board[i] = 0;
  }

  Xturn = true;
  inProgress = false;
}


// starts the game
void gameboard::start_game() {
  inProgress = true;
}

// ends the game
void gameboard::end_game() {
  inProgress = false;
}

// returns whether game has started
bool gameboard::game_started() {
  return inProgress;
}


// Makes a move on the board
// returns 0 if the move is legal
// returns a non-zero value if the move is illegal
int gameboard::make_move(const int x, const int y, const int value) {

  int position = (x-1)*3 + (y-1);

  if (x < 1 || x > 3 || y < 1 || y > 3)
  {
    // illegal move, the position given is outside the boundaries
    return 1;
  }

  // legal move
  if (board[position] == 0) {
    board[position] = value;
  }
  else {
    // illegal move, the position is already occupied
    return 2;
  }

  return 0;
}


// changes turn to the other player
void gameboard::change_turn() {
  Xturn = !Xturn;
}

// gets whose turn it is
// returns true if player X plays next, false if player O plays next
bool gameboard::get_turn() {
  return Xturn;
}

// checks the current state of the board
// return value: 1 == player X has won, 2 == player O has won
// 3 == draw, 4 == game has not finished
int gameboard::check_state() {

  // sum is used to store the sum of the values of three spaces
  int sum = 0;

  // check the three rows to see if a player has won
  for (int i = 0; i <= 6; i+=3)
  {
    sum = board[i] + board[1+i] + board[2+i];
    if (sum == XWIN)
    {
      return 1;
    }
    else if (sum == OWIN)
    {
      return 2;
    }
  }

  // check the three columns to see if a player has won
  for (int i = 0; i <= 2; i++)
  {
    sum = board[i] + board[3+i] + board[6+i];
    if (sum == XWIN)
    {
      return 1;
    }
    else if (sum == OWIN)
    {
      return 2;
    }
  }

  // check one diagonal to see if a player has won
  sum = board[0] + board[4] + board[8];
  if (sum == XWIN)
  {
    return 1;
  }
  else if (sum == OWIN)
  {
    return 2;
  }

  // check the other diagonal to see if a player has won
  sum = board[2] + board[4] + board[6];
  if (sum == XWIN)
  {
    return 1;
  }
  else if (sum == OWIN)
  {
    return 2;
  }

  // check to see if the entire board has been filled
  // if not, the game has not finished, otherwise this is a draw
  for (int i = 0; i < 9; i++)
  {
    if (board[i] == 0) {
      return 4;
    }
  }
  return 3;
}


// Helper function: converts an int value into a char
// representing a board space, for use in print_board()
char convert(const int value)
{
  switch (value)
  {
  case 0:
    return ' ';
    break;
  case XVALUE:
    return 'X';
    break;
  case OVALUE:
    return 'O';
    break;
  default:
    return ' ';
  };
}

// prints the game board
void gameboard::print_board() {

  printf("\n       Game Board\n");
  printf("_________________________\n");
  printf("|%4c   |%4c   |%4c   |\n", convert(board[0]),
         convert(board[1]), convert(board[2]));
  printf("|_______|_______|_______|\n");
  printf("|%4c   |%4c   |%4c   |\n", convert(board[3]),
         convert(board[4]), convert(board[5]));
  printf("|_______|_______|_______|\n");
  printf("|%4c   |%4c   |%4c   |\n", convert(board[6]),
         convert(board[7]), convert(board[8]));
  printf("|_______|_______|_______|\n");

}


// Helper function: converts an int value into a char
// representing a board space, for use in writing to a file
char convertToFileFormat(const int value)
{
  switch (value)
  {
  case 0:
    return '*';
    break;
  case XVALUE:
    return 'X';
    break;
  case OVALUE:
    return 'O';
    break;
  default:
    return '*';
  };
}

// Helper function: converts a char into an int value
// representing a board piece, for use in reading a file
int convertToIntFormat(const char c)
{
  switch (c)
  {
  case '*':
    return 0;
    break;
  case 'X':
    return XVALUE;
    break;
  case 'O':
    return OVALUE;
    break;
  default:
    return 0;
  };
}


// loads the saved game from a file
// returns 0 on success
// returns a non-zero value on error
int gameboard::load_game(const char *filename) {

  // open file for read
  FILE *fp = fopen(filename, "r+");
  if (!fp) {
    fprintf(stderr, "Can't open file %s\n", filename);
    return 10;
  }

  // read the board
  for (int i = 0; i < 9; i++) {
    char boardspace[2];

    // think about why we are reading a string of length 1 char, instead of reading a char
    if (fscanf(fp, "%1s", boardspace) != 1)
    {
      fprintf(stderr, "Can't read file %s\n", filename);
      return 10;
    }

    board[i] = convertToIntFormat(boardspace[0]);
  }

  // Close file
  if (fclose(fp)) {
    fprintf(stderr, "Can't close file %s\n", filename);
    return 10;
  }

  // once a game board is loaded, need to determine whose turn it is next.
  // We add up the sum of 9 spaces (for each space, X = 1, O = -1)
  // if the sum is 0, the numbers of X's and O's on the board are the same,
  // then it is Player X's turn next. Otherwise it is Player O's turn next.
  int sum = 0;
  for (int i = 0; i < 9; i++) {
    sum = sum + board[i];
  }
  if (sum == 0) {
    Xturn = true;
  }
  else {
    Xturn = false;
  }

  return 0;

}

// saves the game to a file
// returns 0 on success
// returns a non-zero value on error
int gameboard::save_game(const char *filename) {

  // open file for write
  FILE *fp = fopen(filename, "w+");
  if (!fp) {
    fprintf(stderr, "Can't open file %s\n", filename);
    return 10;
  }

  // write the board pieces
  for (int i = 0; i < 9; i++) {
    if (fprintf(fp, "%c ", convertToFileFormat(board[i])) < 0) {
      fprintf(stderr, "Can't write to file %s\n", filename);
      return 10;
    }

    // write a new line after 3 board pieces
    if (i == 2 || i == 5) {
      if (fprintf(fp, "\n") < 0) {
        fprintf(stderr, "Can't write to file %s\n", filename);
        return 10;
      }
    }

  }

  // Close file
  if (fclose(fp)) {
    fprintf(stderr, "Can't close file %s\n", filename);
    return 10;
  }

  return 0;

}
