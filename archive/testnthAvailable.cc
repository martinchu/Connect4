// #include <array>
#include <iostream>

using namespace std;


int nthAvailabe(int a[],int n){
  int rowSize = 6;
  int temp = n;
  int i = 0;
  while(i<=temp){
    if(a[i]==6){
      temp++;
    }
      i++;
  }
  return temp;
}
int main(){
  //          0 1 2 3 4
  int a[7] = {3,6,3,6,5,4,6};
  cout<<nthAvailabe(a,2)<<endl;
}
