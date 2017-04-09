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
AI::AI(Grid* grid){
  Player::g = grid;
}
void AI::checkHuman(){
  cout<<"I am not HUMAN!!"<<endl;

}
int AI::evalBoard(Node *n){
  Grid * g = n->state;
  if(g->isFilled() && g->getWinner()=='F') {
    n->num = 0;
    return 0;//The board is full
  }
  else if(g->getWinner()=='1'){
    // Player 1 (Human) Wins => Worse Sitution
    n->num = -100;
    return n->num;
  }
  else if(g->getWinner()=='2'){
    // Player 2 (AI) Wins => Best Situation
    n-> num = 100;
    return n->num;
  }
  // Unsure Situation => Go back to parent function and call other function
  n->num = 50;
  return n->num;
}
Node* AI::lookAhead(int steps){
  return 0;
}
int AI::findPotentialWin(Node* n){
  Grid* g = n->state;
  TextDisplay *td = g->getTextDisplay();
  // Exploit potential opportunities to win/lose the Game
  // To simplify and lower computational cost,
  // The algorithm will (for now) ignore whether the potential opportunity is imminent
  // i.e. whether AI will win/lose right away or in the future states
  // for example, the following 2 states are considered the same for AI in this function
  // column:  1 2 3 4 ...                1 2 3 4 ...
  //      ... ...........            ... ...........
  //      4   1 0 1 1 ...            4   0 0 0 0 ...
  //      5   2 0 1 2 ...            5   0 0 0 0 ...
  //      6   1 0 2 1 ...            6   1 0 1 1 ...
  //     => inaRow[0]+=4             =>inaRow[0]+=6;

  int inARow[4];
  int inARowOpponent[4];
  int rowSize = g->getrowSize();
  int colSize = g->getcolSize();
  for(int i = 0; i< rowSize;i++){
    for(int j = 0; j< colSize;j++){
      if(td->getCord(i,j)=='0'){
        // There is empty spot for a checker
        if(j <= colSize-4){//Check the right
          if(td->getCord(i,j+1)==td->getCord(i,j+2)&&td->getCord(i,j+2)==td->getCord(i,j+3)){
            intARow[0]+=i;
          }
          // x 0 x x
          if(j>0&&td->getCord(i,j-1)==td->getCord(i,j+2)&&td->getCord(i,j+2)==td->getCord(i,j+3)){
            intARow[0]+=i;
          }
          // x x 0 x
          if(j>1&&td->getCord(i,j-1)==td->getCord(i,j-2)&&td->getCord(i,j-1)==td->getCord(i,j+1)){
            intARow[0]+=i;
          }
          
        }
        else if(j >= 3){//Check the left
          if(td->getCord(i,j-1)==td->getCord(i,j-2)&&td->getCord(i,j-1)==td->getCord(i,j-3)){
            intARow[0]+=i;
          }

        }
        // Check for Vertical
        if(i <= rowSize-4){//Check the Up
          if(td->getCord(i+1,j)==td->getCord(i+2,j)&&td->getCord(i+1,j)==td->getCord(i+3,j)){
            return td->getCord(i,j);
          }
        }
        else if(i >= 3){//Check the down
          if(td->getCord(i-1,j)==td->getCord(i-2,j)&&td->getCord(i-1,j)==td->getCord(i-3,j)){
            return td->getCord(i,j);
          }
        }
        // Check for Diagonal
        if(j <= colSize-4 && i <= rowSize-4){
          if(td->getCord(i+1,j+1)==td->getCord(i+2,j+2)&&td->getCord(i+1,j+1)==td->getCord(i+3,j+3)){
            return td->getCord(i,j);
          }
          /*
          X 0 0 0
          0 x 0 0
          0 0 x 0
          0 0 0 x
          */
        }
        if(j <= colSize-4 && i >= 3){
          if(td->getCord(i-1,j+1)==td->getCord(i-2,j+2)&&td->getCord(i-1,j+1)==td->getCord(i-3,j+3)){
            return td->getCord(i,j);
          }
        }

        if(j >= 3 && i <= rowSize-4){
          if(td->getCord(i+1,j-1)==td->getCord(i+2,j-2)&&td->getCord(i+1,j-1)==td->getCord(i+3,j-3)){
            return td->getCord(i,j);
          }
        }
        if(j >= 3 && i >= 3){
          if(td->getCord(i-1,j-1)==td->getCord(i-2,j-2)&&td->getCord(i-1,j-1)==td->getCord(i-3,j-3)){
            return td->getCord(i,j);
          }
        }
      }
    }
  }
  return -1;
}
int AI::potential4(Node *n){
  return -1;
}
int AI::heuristic(Node* n){
  if(evalBoard(n)!=50) return evalBoard(n);
  else{
    int pw = findPotentialWin(n);
    int p4 = potential4(n);
  }
  return -1;
}
int AI::alphabeta(Node *n, int alpha, int beta, bool MAXPLAYER, int depth){
  if(n->children.size()==0||depth==0){
    return heuristic(n);
  }
  else{
    // int v;
    // if it is a parent node
    if(MAXPLAYER==true){
      // Max Player's Turn
      n->num = INT_MIN;
      for(unsigned int i = 0; i< n->children.size();i++){
        n->num = max(n->num, alphabeta(n->children[i], alpha, beta, false,depth-1));
        alpha = max(alpha, n->num);
        if(beta<=alpha)break;
      }
    }
    else{
      // Min Player's Turn
      n->num = INT_MAX;
      for(unsigned int i = 0; i< n->children.size();i++){
        int temp = alphabeta(n->children[i], alpha, beta, true,depth-1);
        n->num = min(n->num, temp);
        beta = min(beta, n->num);
        if(beta<=alpha)break;
      }
      cout<<"n->num: "<<n->num<<endl;

    }
    return n->num;
  }
  return -1;
}

void AI::makeMove(bool p1){
  Node *futureStates = lookAhead(3);//look 3 steps ahead
  Player::g->dropChecker(alphabeta(futureStates,INT_MIN,INT_MAX,true,3),false);
}

AI::~AI(){

}
Human::~Human(){

}
Player::~Player(){

}
