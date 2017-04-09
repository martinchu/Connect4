#ifndef __GRID_H__
#define __GRID_H__
#include <iostream>
#include "cell.h"
#include "textdisplay.h"
#include "window.h"
#include "player.h"

class Grid {
  Cell **theGrid;                   // The actual n x n grid.
  int rowSize;
  int colSize;                   // Size of the grid (n)
  int checkers;
  TextDisplay *td;                  // The text display.
  Player* p1;
  Player* p2;
  //Xwindow * theWindow;

  void clearGrid();                 // Frees the theGrid field.

  // Add private members, if necessary.


 public:
  Grid();
  ~Grid();

  /*
   * The following method is used to determine if the game has been won
   * An, inefficient implementation would be to use nested for loops to determine
   * that all Cells in theGrid are of the same color.
   * A more efficient approach is to compute this information during the game as
   * Cells change colors
   * Look through the textdisplay.h file for hints on how to do this
   */
  bool isFilled();
  char getWinner();
  void dropChecker(int targetcol,bool player1);
  void init();                 // Sets up an n x n grid.  Clears old grid, if necessary.
  void change(const int & state);  // Notify Cell (0,0) of the change to new state: state
  // void init(int r, int c, int state); //set the state for r,c to state
  friend std::ostream &operator<<(std::ostream &out, const Grid &g);
  void printAddress();
};

#endif
