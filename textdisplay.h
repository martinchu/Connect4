#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__
#include <iostream>
#include <sstream>

class TextDisplay {
  char **theDisplay;          //the n x n display
  const int rowSize;          //number of rows
  const int colSize;          //number of columns
  unsigned int colourCount[2];
 public:
  TextDisplay(int row, int col); //one arg constructor where the parameter is the gridSize
  void notify(int r, int c, char ch);
  bool isFilled();
  char getWinner();
  ~TextDisplay(); //decontructor
  friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif
