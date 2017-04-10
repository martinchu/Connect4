#include <iostream>
using namespace std;

int main(){
  int mode = 0;
while(true){
  if(cin>>mode){
    if(mode > 2 || mode < 1){
      cout<<"Invalid Number. Please Choose Again";
    }
    else break;
  }
  else {
    if(cin.eof())break;
    cin.clear(); //This corrects the stream.
    cin.ignore(); //This skips the left over stream data.
    cout << "Please enter an Integer only." << endl;
  }
}
}
