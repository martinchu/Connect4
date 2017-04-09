#include <string>
#include <iostream>
#include <vector>
#include <climits>
#include "player.h"
#include "grid.h"
#include "node.h"

using namespace std;

void Human::checkHuman(){
  cout<<"I am HUMAN!!"<<endl;
}
void Human::makeMove(bool p1){
  int linenum;
  cout<<"Player, Please make move now."<<endl;
  cout<<"Please select the line you want to drop your token: ";
  bool checkInput = true;
  while(checkInput){
    cin>>linenum;
    if(linenum > 7 || linenum < 1){
      cout<<"Invalid Line. Please Choose Again";
    }
    else if(cin.fail()){
      cin.clear(); //This corrects the stream.
      cin.ignore(); //This skips the left over stream data.
      cout << "Please enter an Integer only." << endl;
    }
    else checkInput = false;
  }
  Player::g->dropChecker(linenum-1,p1);
}
Human::Human(Grid *grid){
  Player::g = grid;
}
