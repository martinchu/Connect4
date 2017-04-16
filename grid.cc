#include "grid.h"
#include "textdisplay.h"
#include "cell.h"
#include <iostream>
using namespace std;
//Xwindow * theWindow;

int Grid::getColumnChecker(int targetcol)const{
  return CheckersCounter[targetcol];
}
void Grid::init(int r, int c, int state){
  theGrid[r][c].setState(state);
} //set the state for r,c to state
int Grid::getCheckers(){
  return checkers;
}
void Grid::clearGrid(){
  for(int i=0;i<rowSize;i++){
    delete []theGrid[i];
  }
  delete []theGrid;
  delete td;
}
int Grid::getrowSize(){
  return rowSize;
}
int Grid::getcolSize(){
  return colSize;
}
TextDisplay* Grid::getTextDisplay(){
  return td;
}
Grid::Grid(int row, int col):theGrid(0),rowSize(row),colSize(col),checkers(0){}
Grid::~Grid(){
  this->clearGrid();
}
bool Grid::isFilled(){
  return td->TextDisplay::isFilled();
}
char Grid::getWinner(){
  return td->TextDisplay::getWinner();
}
void Grid::init(){
  int grow = rowSize;
  int gcol = colSize;
  theGrid=new Cell*[grow];
  for(int q=0;q<grow;q++){
    theGrid[q]=new Cell[gcol];
  }
  td= new TextDisplay(grow,gcol);
  for(int col=0;col<gcol;col++){
    for(int row=0;row<grow;row++){
      theGrid[row][col].setDisplay(td);
      theGrid[row][col].setCoords(row,col);
    }
    CheckersCounter[col] = 0;
  }

}
// Sets up an n x n grid.  Clears old grid, if necessary.
void Grid::change(const int & state){
  // theGrid[0][0].setState(state);
  theGrid[0][0].notify(state);
}  // Notify Cell (0,0) of the change to new state: state
int Grid::dropChecker(int targetcol,bool player1){
  for(int i = rowSize-1; i>=0;i--){
    if(theGrid[i][targetcol].getState()==0){
      if(player1) theGrid[i][targetcol].notify(1);
      else theGrid[i][targetcol].notify(2);
      checkers++;
      // moved = true;
      CheckersCounter[targetcol]++;
      return 1;
    }
  }
  // cout<<"ERROR: the entire column is full."<<endl;
  return -1;

}


ostream &operator<<(ostream &out, const Grid &g){
  out<<*(g.td);
  return out;
}
// Copy CONSTRUCTOR
Grid::Grid(const Grid &g){

  // td = new TextDisplay(*g.td);
  theGrid=new Cell*[g.rowSize];
  for(int q=0;q<g.rowSize;q++){
    theGrid[q]=new Cell[g.colSize];
  }
  td = new TextDisplay(g.rowSize,g.colSize);
  for(int col=0;col<g.colSize;col++){
    for(int row=0;row<g.rowSize;row++){
      theGrid[row][col].setDisplay(td);
      theGrid[row][col].setCoords(row,col);
      theGrid[row][col].notify(g.theGrid[row][col].getState());
    }
    CheckersCounter[col] = g.getColumnChecker(col);
  }
  rowSize = g.rowSize;
  colSize = g.colSize;
  checkers = g.checkers;
  p1 = g.p1;
  p2 = g.p2;
}
