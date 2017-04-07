#include "grid.h"
#include "textdisplay.h"
#include "cell.h"
#include <iostream>
using namespace std;
//Xwindow * theWindow;
int gtest=0;
void Grid::clearGrid(){
  if(gtest>=10){
    cout<<"in clearGrid"<<endl;
  }
  for(int i=0;i<gridSize;i++){
    for(int j=0;j<gridSize;j++){
      delete &theGrid[i][j];
    }
    delete []theGrid[i];
  }
  delete []theGrid;
  delete td;
  td=0;
  gridSize=0;
  theGrid=0;
}
Grid::Grid():theGrid(0),gridSize(0),td(0){}
Grid::~Grid(){
  this->clearGrid();
}
bool Grid::isWon(){
  return td->TextDisplay::isFilled();
}
void Grid::init(){
  int grow = 6;
  int gcol = 7;
  if(!theGrid){
    clearGrid();
  }
  theGrid=new Cell*[grow];
  for(int q=0;q<grow;q++){
    theGrid[q]=new Cell[gcol];
  }
/*
  td= new TextDisplay(n);

  gridSize=n;
  for(int row=0;row<gridSize;row++){
    for(int col=0;col<gridSize;col++){
      if(row>0){
        theGrid[row][col].addNeighbour(&theGrid[row-1][col]);
      }
      if(col>0){
        theGrid[row][col].addNeighbour(&theGrid[row][col-1]);
      }
      if(row<(gridSize-1)){
        theGrid[row][col].addNeighbour(&theGrid[row+1][col]);
      }
      if(col<(gridSize-1)){
        theGrid[row][col].addNeighbour(&theGrid[row][col+1]);
      }
      theGrid[row][col].setDisplay(td);
      theGrid[row][col].setCoords(row,col);
    }
  }
*/
}
  // Sets up an n x n grid.  Clears old grid, if necessary.
void Grid::change(const int & state){
  	// theGrid[0][0].setState(state);
  theGrid[0][0].notify(state);
}  // Notify Cell (0,0) of the change to new state: state
void Grid::init(int r, int c, int state){
  if(gtest>=10){
    cout<<"in Grid::init"<<endl;
  }
  if(gtest>=10){
    cout<<"r: "<<r<<" c: "<<c<<" state: "<<state<<endl;
    cout<<"theGrid["<<r<<"]["<<c<<"]: "<<&theGrid[r][c]<<endl;
  }
  theGrid[r][c].setState(state);
} //set the state for r,c to state
ostream &operator<<(ostream &out, const Grid &g){
  if(gtest>=10){
    cout<<"in Grid::<<"<<endl;
  }
  out<<*(g.td);
  return out;
}
