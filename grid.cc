#include "grid.h"
#include "textdisplay.h"
#include "cell.h"
#include <iostream>
using namespace std;
//Xwindow * theWindow;

int Grid::getColumnChecker(int targetColumn)const{
  return CheckersCounter[targetColumn];
}
void Grid::init(int r, int c, int state){
  theGrid[r][c].setState(state);
} //set the state for r,c to state
int Grid::getCheckers(){
  return checkers;
}
void Grid::clearGrid(){
  for(int i=0;i<numberOfRows;i++){
    delete []theGrid[i];
  }
  delete []theGrid;
  delete td;
}
int Grid::getNumberOfRows(){
  return numberOfRows;
}
int Grid::getNumberOfColumns(){
  return numberOfColumns;
}
TextDisplay* Grid::getTextDisplay(){
  return td;
}
Grid::Grid(int row, int col):theGrid(0),numberOfRows(row),numberOfColumns(col),checkers(0){}
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
  theGrid=new Cell*[numberOfRows];
  for(int q=0;q<numberOfRows;q++){
    theGrid[q]=new Cell[numberOfColumns];
  }
  td= new TextDisplay(numberOfRows,numberOfColumns);
  for(int col=0;col<numberOfColumns;col++){
    for(int row=0;row<numberOfRows;row++){
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
int Grid::dropChecker(int targetColumn,bool player1){
  for(int i = numberOfRows-1; i>=0;i--){
    if(theGrid[i][targetColumn].getState()==0){
      if(player1) theGrid[i][targetColumn].notify(1);
      else theGrid[i][targetColumn].notify(2);
      checkers++;
      // moved = true;
      CheckersCounter[targetColumn]++;
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
  theGrid=new Cell*[g.numberOfRows];
  for(int q=0;q<g.numberOfRows;q++){
    theGrid[q]=new Cell[g.numberOfColumns];
  }
  td = new TextDisplay(g.numberOfRows,g.numberOfColumns);
  for(int col=0;col<g.numberOfColumns;col++){
    for(int row=0;row<g.numberOfRows;row++){
      theGrid[row][col].setDisplay(td);
      theGrid[row][col].setCoords(row,col);
      theGrid[row][col].notify(g.theGrid[row][col].getState());
    }
    CheckersCounter[col] = g.getColumnChecker(col);
  }
  numberOfRows = g.numberOfRows;
  numberOfColumns = g.numberOfColumns;
  checkers = g.checkers;
  p1 = g.p1;
  p2 = g.p2;
}
