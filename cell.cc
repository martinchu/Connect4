#include "cell.h"
#include "textdisplay.h"
#include <iostream>

using namespace std;

int ctest=100;
Cell::Cell(){
  state=0;
  numNeighbours=0;
  r=0;
  c=0;
  td=0;
}
void Cell::notifyDisplay(){
  if(ctest>=1000){
    cout<<"In notifyDisplay..."<<endl;
  }
  td->TextDisplay::notify(r,c,state+48);
}
int Cell::getState(){
  return state;
}
void Cell::setState(const int& change){
  if(ctest>=1000)cout<<"inSetState"<<endl;
  state=change;
  if(ctest>=1000)cout<<"done state change"<<"change: "<<change<<" State: "<<getState()<<endl;
  notifyDisplay();
}
void Cell::setCoords(const int r, const int c){
  this->r=r;
  this->c=c;
}


void Cell::setDisplay(TextDisplay* t){
  td=t;//setter for TextDisplay
}

void Cell::addNeighbour(Cell *neighbour){
  neighbours[numNeighbours]=neighbour;
  numNeighbours++;
}
void Cell::notify(const int & change){
  if(ctest>=1000)cout<<"in Cell notify"<<endl;
  setState(change);
  notifyDisplay();
}

//possible setter for partb when we have XWindow
//void setCoords(int r, int c, int x, int y, int width, int height, Xwindow *w);
