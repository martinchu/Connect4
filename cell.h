#ifndef __CELL_H__
#define __CELL_H__
#include <iostream>
#include "textdisplay.h"

const int maxNeighbours = 4;

class Cell {
  int state;        //current state of the cell
  int numNeighbours;   //number of neighbors
  Cell *neighbours[maxNeighbours];   //pointers to neighbors
  int r, c;                   //co-ordinates of the cell
  TextDisplay * td;        //pointer to the text display
  void notifyDisplay();					    //notify the TextDisplay of the change

  //int x, y, width, height;
  //Xwindow * window;
public:
  Cell();                                   // Default constructor
  int getState();                          //getter for private state
  void setState(const int& change);         //setter for private state
  void setCoords(const int r, const int c);				//setter for private co-ordinates of cell
  void setDisplay(TextDisplay * t);         //setter for TextDisplay
  void addNeighbour(Cell *neighbour);       //add a neighbouring cell
  void notify(const int & change);
  void notify(const int & current, const int & previous);
  //possible setter for partb when we have XWindow
  //void setCoords(int r, int c, int x, int y, int width, int height, Xwindow *w);
};
#endif
