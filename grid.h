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
 public:
  Grid();
  ~Grid();
  bool isFilled();
  char getWinner();
  TextDisplay * getTextDisplay();
  void dropChecker(int targetcol,bool player1);
  int getrowSize();
  int getcolSize();
  int getCheckers();
  void init();                 // Sets up an n x n grid.  Clears old grid, if necessary.
  void change(const int & state);  // Notify Cell (0,0) of the change to new state: state
  void init(int r, int c, int state); //set the state for r,c to state
  friend std::ostream &operator<<(std::ostream &out, const Grid &g);
  void printAddress();
};

#endif
