// gameboard.h
// Game Board Class for a simple two-player tic-tac-toe game
// by Richard Zhao
// For use by CMPUT 201 for educational purposes only
// November 2014

#pragma once

#define XVALUE 1
#define OVALUE -1
#define XWIN 3
#define OWIN -3


class gameboard
{

private:

  int board[9];  // board of 9 spaces
  bool Xturn;    // Xturn == true means player X plays next
                 // Xturn == false means player O plays next
  bool inProgress;  // inProgress == true means a game has started
  
public:
  
  // Constructor
  gameboard();

  // Destructor
  ~gameboard();

  // member functions:

  // initializes each space of the board to 0 (empty)
  void initialize_board();

  // starts the game
  void start_game();

  // ends the game
  void end_game();
  
  // returns whether game has started
  bool game_started();
  
  // Makes a move on the board
  // returns 0 if the move is legal
  // returns a non-zero value if the move is illegal
  int make_move(const int x, const int y, const int value);

  // changes turn to the other player
  void change_turn();

  // gets whose turn it is
  // returns true if player X plays next, false if player O plays next
  bool get_turn();

  // checks the current state of the board
  // return value: 1 == player X has won,  2 == player O has won
  // 3 == draw, 4 == game has not finished
  int check_state();
  
  // prints the game board
  void print_board();
  
  // load the saved game from a file
  // returns 0 on success
  // returns a non-zero value on error
  int load_game(const char *filename);

  // saves the game to a file
  // returns 0 on success
  // returns a non-zero value on error
  int save_game(const char *filename);

};
