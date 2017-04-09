#include "cell.h"
#include "textdisplay.h"
#include <iostream>
using namespace std;
/*
int state;        //current state of the cell
int prevState;    //previous state of the cell
int numNeighbours;   //number of neighbors
Cell *neighbours[maxNeighbours];   //pointers to neighbors
int r, c;                   //co-ordinates of the cell
TextDisplay * td;        //pointer to the text display*/
int ctest=100;
Cell::Cell(){
  state=0;
  prevState=0;
  numNeighbours=0;
  r=0;
  c=0;
  td=0;
}
void Cell::notifyDisplay(){
  if(ctest>=10){
    cout<<"In notifyDisplay..."<<endl;
  }
  td->TextDisplay::notify(r,c,state+48);
}
int Cell::getState(){
  return state;
}
void Cell::setState(const int& change){
  if(ctest>=10){
    cout<<"inSetState"<<endl;
    cout<<"change: "<<change<<" prevState: "<<prevState<<" State: "<<getState()<<endl;
  }
  prevState=getState();
  state=change;
  // setState(change);
  if(ctest>=10){
    // cout<<"inSetState"<<endl;
    cout<<"done state change"<<endl<<"change: "<<change<<" prevState: "<<prevState<<" State: "<<getState()<<endl;
  }
  notifyDisplay();
}
void Cell::setCoords(const int r, const int c){
  this->r=r;
  this->c=c;
}

//possible setter for partb when we have XWindow
//void setCoords(int r, int c, int x, int y, int width, int height, Xwindow *w);

void Cell::setDisplay(TextDisplay* t){
  td=t;
}         //setter for TextDisplay

void Cell::addNeighbour(Cell *neighbour){
  neighbours[numNeighbours]=neighbour;
  numNeighbours++;
}
/*
* The following methods are provided as a hint towards implementing the notification
* You should try to use the methods with the given signatures.
*
* If you feel the need to change the *signature* of the method (not the name) you may
* do so but MUST provide a comprehensive explanation in your code why you felt the change
* was necessary*/
/*
* Intended to be called only by the grid class for changing the state of the 0 0 cell*/
void Cell::notify(const int & change){
  if(ctest>=100)cout<<"in Cell notify"<<endl;
  setState(change);
  // for(int i=0;i<numNeighbours;i++){
  //   neighbours[i]->notify(getState(),prevState);
  // }
  notifyDisplay();
}
/*
* Intended to be called by Cells to notify their neighbors
* current: this cells current(new) state
* previous: this cells past state
*/
void Cell::notify(const int & current, const int & previous){
  if(previous==getState()){
    setState(current);
    notifyDisplay();
    for(int i=0;i<numNeighbours;i++){
      neighbours[i]->notify(current ,previous);
    }
  }
}
