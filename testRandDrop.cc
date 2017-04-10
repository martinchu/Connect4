#include <string>
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
// #include <array>

using namespace std;

int randDrop(int a[]){
  int center = 3; //Center Column
  int minColValue = INT_MAX;
  int minCol = -1;
  for(int i = 0;i<7;i++){
    int colCheckers = a[i];
    if(minColValue > colCheckers){
      minColValue = colCheckers;
      minCol = i;
    }
    else if(minColValue == colCheckers && abs(i-center) < abs(minCol-center)){
      minCol = i;
    }
    cout<<"i: "<<i<<"\tminColumnValue: "<<minColValue<<"\tminCol: "<<minCol<<endl;
  }
  return minCol;
}
int main(){
  int test [7] = {3,2,3,5,2,6,2};
  int temp = randDrop(test);
  cout <<temp;
}
