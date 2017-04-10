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
