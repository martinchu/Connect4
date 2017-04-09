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
