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
