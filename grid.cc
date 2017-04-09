#include "grid.h"
#include "textdisplay.h"
#include "cell.h"
#include <iostream>
using namespace std;
//Xwindow * theWindow;
int gtest=100;
int memgtest=100;
void Grid::clearGrid(){
  if(gtest>=10){
    cout<<"in clearGrid"<<endl;
    cout<<"rowSize: "<<rowSize<<endl;
    cout<<"colSize: "<<colSize<<endl;
  }
  for(int i=0;i<rowSize;i++){
    // for(int j=0;j<colSize;j++){
    //   if(memgtest>=100){
    // 		cout<<"deleting cell"<<i<<j<<"\taddress: "<<&theGrid[i][j]<<endl;
    // 	}
    //   delete &theGrid[i][j];
    // }
    delete []theGrid[i];
  }
  delete []theGrid;
  delete td;
}
Grid::Grid():theGrid(0),rowSize(6),colSize(7),checkers(0){}
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
  int grow = 6;
  int gcol = 7;
  if(gtest>=100) cout<<"theGrid: "<<theGrid<<endl;
  // if(!theGrid){
  //   clearGrid();
  // }
  theGrid=new Cell*[grow];
  for(int q=0;q<grow;q++){
    theGrid[q]=new Cell[gcol];
  }
  td= new TextDisplay(grow,gcol);
  for(int row=0;row<grow;row++){
    for(int col=0;col<gcol;col++){
      if(row>0){
        theGrid[row][col].addNeighbour(&theGrid[row-1][col]);
      }
      if(col>0){
        theGrid[row][col].addNeighbour(&theGrid[row][col-1]);
      }
      if(row<(rowSize-1)){
        theGrid[row][col].addNeighbour(&theGrid[row+1][col]);
      }
      if(col<(colSize-1)){
        theGrid[row][col].addNeighbour(&theGrid[row][col+1]);
      }
      theGrid[row][col].setDisplay(td);
      theGrid[row][col].setCoords(row,col);
    }
  }
}
  // Sets up an n x n grid.  Clears old grid, if necessary.
void Grid::change(const int & state){
  	// theGrid[0][0].setState(state);
  theGrid[0][0].notify(state);
}  // Notify Cell (0,0) of the change to new state: state
void Grid::dropChecker(int targetcol,bool player1){
  bool moved = false;
  if(gtest>=100)cout<<"in dropChecker."<<endl;
  for(int i = rowSize-1; i>=0;i--){
    if(gtest>=100)cout<<"theGrid["<<i<<"]["<<targetcol<<"].getState(): "<<theGrid[i][targetcol].getState()<<endl;

    if(theGrid[i][targetcol].getState()==0){
      if(player1) theGrid[i][targetcol].notify(1);
      else theGrid[i][targetcol].notify(2);
      moved = true;
      break;
    }

  }
  if(moved)checkers++;
  else{
    cout<<"ERROR: the entire column is full."<<endl;
  }
}

void Grid::printAddress(){
  cout<<"printing addresses..."<<endl;
  for(int i=0;i<rowSize;i++){
    for(int j=0;j<colSize;j++){
      cout<<"Cell"<<i<<j<<": "<<&theGrid[i][j]<<endl;
    }
  }
}
ostream &operator<<(ostream &out, const Grid &g){
  if(gtest>=10){
    cout<<"in Grid::<<"<<endl;
  }
  out<<*(g.td);
  return out;
}
