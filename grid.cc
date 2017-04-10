#include "grid.h"
#include "textdisplay.h"
#include "cell.h"
#include <iostream>
using namespace std;
//Xwindow * theWindow;
int gtest=100;
int memgtest=100;
int testTotalCheckers = 0;
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
int Grid::getCheckers(){
  return checkers;
}
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
int Grid::getrowSize(){
  return rowSize;
}
int Grid::getcolSize(){
  return colSize;
}
TextDisplay* Grid::getTextDisplay(){
  return td;
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
  if(gtest>=1000) cout<<"theGrid: "<<theGrid<<endl;
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
int Grid::dropChecker(int targetcol,bool player1){
  if(gtest>=1000)cout<<"in dropChecker. grid address: "<<this<<endl;
  for(int i = rowSize-1; i>=0;i--){
    if(gtest>=1000)cout<<"theGrid["<<i<<"]["<<targetcol<<"].getState(): "<<theGrid[i][targetcol].getState()<<endl;
    if(theGrid[i][targetcol].getState()==0){
      if(player1) theGrid[i][targetcol].notify(1);
      else theGrid[i][targetcol].notify(2);
      checkers++;
      if(testTotalCheckers>=100)cout<<"totalCheckers: "<<checkers<<endl;
      // moved = true;
      return 1;
    }
  }
  // cout<<"ERROR: the entire column is full."<<endl;
  return -1;

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
  if(gtest>=1000){
    cout<<"in Grid::<<, grid address: "<<&g<<endl;
  }
  out<<*(g.td);
  return out;
}

Grid::Grid(const Grid &g){

  // td = new TextDisplay(*g.td);
  theGrid=new Cell*[g.rowSize];
  for(int q=0;q<g.rowSize;q++){
    theGrid[q]=new Cell[g.colSize];
  }
  td= new TextDisplay(g.rowSize,g.colSize);
  for(int row=0;row<g.rowSize;row++){
    for(int col=0;col<g.colSize;col++){
      theGrid[row][col].setDisplay(td);
      theGrid[row][col].setCoords(row,col);
      theGrid[row][col].notify(g.theGrid[row][col].getState());
    }
  }
  rowSize = g.rowSize;
  colSize = g.colSize;
  checkers = g.checkers;
  p1 = g.p1;
  p2 = g.p2;
  if(gtest>=1000){
    cout<<"IN GRID COPY CONSTRUCTOR"<<endl;
    cout<<"NEW Grid: "<<&theGrid<<"\tOLD Grid: "<<&g.theGrid<<endl;
    cout<<"NEW rowSize: "<<rowSize<<"\tNEW colSize: "<<colSize<<endl;
    cout<<"NEW TD: "<<td<<"\tOLD TD: "<<&g.td<<endl;
  }
  // if(gtest>=100)cout<<"CC->td:"<<*td<<endl;
}
