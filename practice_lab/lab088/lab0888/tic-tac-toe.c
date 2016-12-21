// tic-tac-toe.c
// A simple two-player tic-tac-toe game
// by Richard Zhao
// For use by CMPUT 201 for educational purposes only
// November 2014

#include <stdio.h>
#include <stdlib.h>
#include "gameboard.h"


void print_menu(gameboard & board);


int main()
{

  char choice;
  int ret;
  bool error = false;
  bool saveSuccess = false;

  gameboard board;  // this is the game board

  printf("\nWelcome to the Tic-Tac-Toe Game\n\n");


  do
  {
    error = false; saveSuccess = false;
    
    // prints the game menu
    print_menu(board);

    // asks the player to play on a valid space or enter a menu choice
    ret = scanf("%c", &choice);

    // if the first character is a valid row number
    // then treat this as a play move, not a menu choice
    if ((choice == '1' || choice == '2' || choice == '3')
        && board.game_started())
    {

      // converts the char into an int row number
      int row = atoi(&choice);
      // get the column number
      int column;
      ret = scanf("%d", &column);
      if (ret != 1) {
        error = true;
      }
      
      if (error == false) {
        if (board.get_turn()) {
          // player X plays a move
          error = board.make_move(row, column, XVALUE);
        }
        else {
          // player O plays a move
          error = board.make_move(row, column, OVALUE);
        }
      }

      if (error == false) {
        // change turn, so the other player can play next turn
        board.change_turn();
      }
    }

    // menu choice n: start a new game
    else if (choice == 'n') {
      board.initialize_board();
      board.start_game();
    }
    
    // menu choice l: load a game
    else if (choice == 'l') {
      if (board.load_game("savedgame") != 0) {
        exit(10);
      }
	  
      board.start_game();
    }

    // menu choice s: save the current game
    else if (choice == 's' && board.game_started()) {
      if (board.save_game("savedgame") != 0) {
        exit(10);
      }
      else {
        saveSuccess = true;
      }
    }

    // menu choice q, exit
    else if (choice == 'q') {
      break;
    }
    
    else {
      error = true;
    }

    
    int c;
    // Remove all remaining characters in the standard input stream until newline
    // so if the user types in garbage, they are ignored
    while ((c = getchar()) != '\n'); 

    
    // this "weird" line is a command that clears the terminal screen
    printf("\e[1;1H\e[2J"); 

    // print the game board
    board.print_board();

    // print additional messages to screen
    if (error) {
      printf("\nThe previous input was illegal. Please try again.\n");
    }
    if (saveSuccess) {
      printf("\nGame successfully saved.\n");
    }
    
    // print game status by checking to see if the game has finished
    int state = board.check_state();
    if (state == 1) {
      board.end_game();
      printf("\nPlayer X has won!  Game is finished.\n");
    }
    else if (state == 2) {
      board.end_game();
      printf("\nPlayer O has won!  Game is finished.\n");
    }
    else if (state == 3) {
      board.end_game();
      printf("\nThe game has ended in a draw.\n");
    }

    
  } while (choice != 'q');

  
  if (choice == 'q') {
    printf("\nHave a nice day.\n\n");
  }
  
  return 0;
}


// this support function prints the game menu
void print_menu(gameboard & board)
{


  printf("\n");
    
  if (board.game_started()) {
    if (board.get_turn())
    {
      printf("Player X, please make your move by typing x y ");
      printf("(row and column number).\n");
    }
    else
    {
      printf("Player O, please make your move by typing x y ");
      printf("(row and column number).\n");
    }
  }
  
  if (board.game_started()) {
    printf("\nYou may also use the following menu items.\n");
  }

  if (board.game_started()) {
    printf("n - Restart the current game\n");
  }
  else {
    printf("n - Start a new game\n");
  }

  printf("l - Load a saved game\n");

  if (board.game_started()) {
    printf("s - Save the current game\n");
  }
  
  printf("q - Quit the program\n\n");
  printf("Please enter your choice: ");
  
}
