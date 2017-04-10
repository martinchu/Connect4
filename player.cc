#include <string>
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include "player.h"
#include "grid.h"
#include "node.h"

using namespace std;

int ptest = 100;
int potentialLcheck =10;
void Human::checkHuman(){
  cout<<"I am HUMAN!!"<<endl;
}
int Human::makeMove(bool p1){
  int linenum;
  int dropStatus = -1;
  while(dropStatus<0){
    cout<<"Player, Please make move now."<<endl;
    cout<<"Please select the line you want to drop your token: ";
    // bool checkInput = true;
    while(true){
      if(cin>>linenum){
        if(linenum > 7 || linenum < 1)cout<<"Invalid Column. Please Choose Again";
        else break;
      }
      else{
        if(cin.eof()) return -1;
        cin.clear();
        cin.ignore();
        cout<<"Please enter a number."<<endl;
      }
    }
    dropStatus=Player::g->dropChecker(linenum-1,p1);
    if(dropStatus<0)cout<<"ERROR: the entire column is full."<<endl;
  }
  return 1;
}
Human::Human(Grid *grid){
  Player::g = grid;
}

AI::AI(Grid* grid,int iq):IQ(iq){
  Player::g = grid;
}
void AI::checkHuman(){
  cout<<"I am not HUMAN!!"<<endl;

}
int AI::evalBoard(Node *n){
  int win =100;
  int draw = 0;
  int unsure = 50;

  Grid * g = n->getState();
  if(g->isFilled() && g->getWinner()=='F') {
    n->setValue(draw);
    return draw;//The board is full
  }
  else if(g->getWinner()=='1'){
    // Player 1 (Human) Wins => Worse Sitution
    n->setValue(win*-1);
    return win*-1;
  }
  else if(g->getWinner()=='2'){
    // Player 2 (AI) Wins => Best Situation
    n->setValue(win);
    return win;
  }
  // Unsure Situation => Go back to parent function and call other function
  n->setValue(unsure);
  return unsure;
}
Node* AI::lookAhead(Node* n,int steps, bool humanMove){
  // cout<<"lookAhead: "<<n->getID()<<"\tsteps: "<<steps<<endl;
  Grid *g = n->getState();
  int col = g->getcolSize();
  if(steps == 0) {
    return n;
  }

  else{
    vector<Node *> tempc;
    for(int i=0; i< col;i++){
      Grid * tempGrid = new Grid(*g);//call a copy constructor to make a duplicate grid
      // drop a checker on column i of the temporary grid
      tempGrid->dropChecker(i,humanMove);
      if(ptest>=1000){
        cout<<"g: "<<g<<endl<<"tempGrid: "<<tempGrid<<endl;
        cout<<"g: "<<endl<<(*g)<<endl<<"tempGrid: "<<endl<<(*tempGrid)<<endl;
      }
      Node * tempNode = new Node(tempGrid);
      // Make a new children node with new/temporary grid
      tempNode = lookAhead(tempNode, steps-1,!humanMove);
      // Recurse
      tempc.push_back(tempNode);
      // push it to the vector
    }
    n->setChildren(tempc);
    if(ptest>=1000)cout<<*n;
    return n;
  }
  return 0;
}
int AI::findPotentialWin(Node* n){
  Grid* g = n->getState();
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
  //     => inARow[0]+=4             =>inARow[0]+=6;

  int inARow[4];
  int inARowOpponent[4];
  int rowSize = g->getrowSize();
  int colSize = g->getcolSize();
  for(int i = 0; i< rowSize;i++){
    for(int j = 0; j< colSize;j++){
      if(td->getCord(i,j)=='0'){//if there is empty spot for a checker
        // Check Horizontal
        // 0 x x x
        if(j>=0 && j <= colSize-4 && td->getCord(i,j+1)==td->getCord(i,j+2)&&td->getCord(i,j+2)==td->getCord(i,j+3)){
          if(td->getCord(i,j+1)=='1') inARowOpponent[0]+=i;
          else if(td->getCord(i,j+1)=='2') inARow[0]+=i;
        }
        // x 0 x x
        if(j>=1 && j <= colSize-3 && td->getCord(i,j-1)==td->getCord(i,j+1)&&td->getCord(i,j+1)==td->getCord(i,j+2)){
          if(td->getCord(i,j-1)=='1') inARowOpponent[0]+=i;
          else if(td->getCord(i,j-1)=='2') inARow[0]+=i;
        }
        // x x 0 x
        if(j>=2 && j <= colSize-2 && td->getCord(i,j-2)==td->getCord(i,j-1)&&td->getCord(i,j-1)==td->getCord(i,j+1)){
          if(td->getCord(i,j-2)=='1') inARowOpponent[0]+=i;
          else if(td->getCord(i,j-2)=='2') inARow[0]+=i;
        }
        // x x x 0
        if(j>=3 && j <= colSize-1 && td->getCord(i,j-3)==td->getCord(i,j-2)&&td->getCord(i,j-2)==td->getCord(i,j-1)){
          if(td->getCord(i,j-3)=='1') inARowOpponent[0]+=i;
          else if(td->getCord(i,j-3)=='2') inARow[0]+=i;
        }

        // Check Vertical
        if(i>= 0 && i <= rowSize-4 && td->getCord(i+1,j)==td->getCord(i+2,j)&&td->getCord(i+2,j)==td->getCord(i+3,j)){
          if(td->getCord(i+1,j)=='1'){
            if(potentialLcheck>=10)cout<<"Found a potential loss(vertical)!!!"<<endl;
            return -100;
          }
          else if(td->getCord(i+1,j)=='2') inARow[1]+=i;

        }
        if(i>= 1 && i <= rowSize-3 && td->getCord(i-1,j)==td->getCord(i+1,j)&&td->getCord(i+1,j)==td->getCord(i+2,j)){
          if(td->getCord(i+1,j)=='1'){
            if(potentialLcheck>=10)cout<<"Found a potential loss(vertical)!!!"<<endl;
            return -100;
          }
          else if(td->getCord(i-1,j)=='2') inARow[1]+=i;
        }
        if(i>= 2 && i <= rowSize-2 && td->getCord(i-2,j)==td->getCord(i-1,j)&&td->getCord(i-1,j)==td->getCord(i+1,j)){
          if(td->getCord(i+1,j)=='1'){
            if(potentialLcheck>=10)cout<<"Found a potential loss(vertical)!!!"<<endl;
            return -100;
          }
          else if(td->getCord(i-2,j)=='2') inARow[1]+=i;
        }
        if(i>= 3 && i <= rowSize-1 && td->getCord(i-3,j)==td->getCord(i-2,j)&&td->getCord(i-2,j)==td->getCord(i-1,j)){
          if(td->getCord(i+1,j)=='1'){
            if(potentialLcheck>=10)cout<<"Found a potential loss(vertical)!!!"<<endl;
            return -100;
          }
          else if(td->getCord(i-3,j)=='2') inARow[1]+=i;
        }
        // Check for (Descending) Diagonal
        if(j>= 0 && j <= colSize-4 && i >= 0 && i <= rowSize-4 && td->getCord(i+1,j+1)==td->getCord(i+2,j+2)&&td->getCord(i+2,j+2)==td->getCord(i+3,j+3)){
          if(td->getCord(i+1,j+1)=='1') inARowOpponent[2]+=i;
          else if(td->getCord(i+1,j+1)=='2') inARow[2]+=i;
          /*
          0 0 0 0
          0 x 0 0
          0 0 x 0
          0 0 0 x
          */
        }
        if(j>= 1 && j <= colSize-3 && i >= 1 && i <= rowSize-3 && td->getCord(i-1,j-1)==td->getCord(i+1,j+1)&&td->getCord(i+1,j+1)==td->getCord(i+2,j+2)){
          if(td->getCord(i-1,j-1)=='1') inARowOpponent[2]+=i;
          else if(td->getCord(i-1,j-1)=='2') inARow[2]+=i;
          /*
          x 0 0 0
          0 0 0 0
          0 0 x 0
          0 0 0 x
          */
        }
        if(j>= 2 && j <= colSize-2 && i >= 2 && i <= rowSize-2 && td->getCord(i-2,j-2)==td->getCord(i-1,j-1)&&td->getCord(i-1,j-1)==td->getCord(i+1,j+1)){
          if(td->getCord(i-2,j-2)=='1') inARowOpponent[2]+=i;
          else if(td->getCord(i-2,j-2)=='2') inARow[2]+=i;
          /*
          x 0 0 0
          0 x 0 0
          0 0 0 0
          0 0 0 x
          */
        }
        if(j>= 3 && j <= colSize-1 && i >= 3 && i <= rowSize-1 && td->getCord(i-3,j-3)==td->getCord(i-2,j-2)&&td->getCord(i-2,j-2)==td->getCord(i-1,j-1)){
          if(td->getCord(i-3,j-3)=='1') inARowOpponent[2]+=i;
          else if(td->getCord(i-3,j-3)=='2') inARow[2]+=i;
          /*
          x 0 0 0
          0 x 0 0
          0 0 x 0
          0 0 0 0
          */
        }
        if(j>= 0 && j <= colSize-4 && i >= 3 && i <= rowSize-1 && td->getCord(i-1,j+1)==td->getCord(i-2,j+2)&&td->getCord(i-2,j+2)==td->getCord(i-3,j+3)){
          /*
          0 0 0 x
          0 0 x 0
          0 x 0 0
          0 0 0 0
          */
          if(td->getCord(i-1,j+1)=='1') inARowOpponent[2]+=i;
          else if(td->getCord(i-1,j+1)=='2') inARow[2]+=i;

        }
        if(j>= 1 && j <= colSize-3 && i >= 2 && i <= rowSize-2 && td->getCord(i+1,j-1)==td->getCord(i-1,j+1)&&td->getCord(i-1,j+1)==td->getCord(i-2,j+2)){
          /*
          j 4 5 6 7
          i
          3 0 0 0 x
          4 0 0 x 0
          5 0 0 0 0
          6 x 0 0 0
          */
          if(td->getCord(i+1,j-1)=='1') inARowOpponent[3]+=i;
          else if(td->getCord(i+1,j-1)=='2') inARow[3]+=i;
        }
        if(j>= 2 && j <= colSize-2 && i >= 1 && i <= rowSize-3 && td->getCord(i+2,j-2)==td->getCord(i+1,j-1)&&td->getCord(i+1,j-1)==td->getCord(i-1,j+1)){
          /*
          j 4 5 6 7
          i
          3 0 0 0 x
          4 0 0 0 0
          5 0 x 0 0
          6 x 0 0 0
          */
          if(td->getCord(i+2,j-2)=='1') inARowOpponent[3]+=i;
          else if(td->getCord(i+2,j-2)=='2') inARow[3]+=i;

        }
        if(j >= 3 && j <= colSize-1 && i >=0 && i <= rowSize-4 && td->getCord(i+1,j-1)==td->getCord(i+2,j-2)&&td->getCord(i+2,j-2)==td->getCord(i+3,j-3)){
          /*
          j 4 5 6 7
          i
          3 0 0 0 0
          4 0 0 x 0
          5 0 x 0 0
          6 x 0 0 0
          */
          if(td->getCord(i+1,j-1)=='1') inARowOpponent[3]+=i;
          else if(td->getCord(i+1,j-1)=='2') inARow[3]+=i;

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
  else if(findPotentialWin(n)!=-100){
    int p4 = potential4(n);
    return p4;
  }
  return -1;
}
int AI::alphabeta(Node *n, int alpha, int beta, bool MAXPLAYER, int depth){
  // mechanism to keep track of the best children/route
  if(n->getChildrenSize()==0||depth==0){
    return heuristic(n);
  }
  else{
    // int v;
    // if it is a parent node
    if(MAXPLAYER==true){
      // Max Player's Turn
      n->setValue(INT_MIN);
      for(int i = 0; i< n->getChildrenSize();i++){
        n->setValue(max(n->getValue(), alphabeta(n->getChildren(i), alpha, beta, false,depth-1)));
        alpha = max(alpha, n->getValue());
        if(beta<=alpha)break;
      }
    }
    else{
      // Min Player's Turn
      n->setValue(INT_MAX);
      for(int i = 0; i< n->getChildrenSize();i++){
        int temp = alphabeta(n->getChildren(i), alpha, beta, true,depth-1);
        n->setValue(min(n->getValue(), temp));
        beta = min(beta, n->getValue());
        if(beta<=alpha)break;
      }
      // cout<<"n->getValue(): "<<n->getValue()<<endl;
    }
    return n->getValue();
  }
  return -1;
}
int AI::randDrop(){
  int center = 3; //Center Column
  int minColValue = INT_MAX;
  int minCol = -1;
  for(int i = 0;i<g->getcolSize();i++){
    int colCheckers = g->getColumnChecker(i);
    if(minColValue > colCheckers){
      minColValue = colCheckers;
      minCol = i;
    }
    else if(minColValue == colCheckers && abs(i-center) < abs(minCol-center)){
      minCol = i;
    }
  }
  return minCol;
}
int AI::makeMove(bool p1){
  if(g->getCheckers()<2){
    int center = 3;
    Player::g->dropChecker(center,false);
    return 1;
    // AI is always player 2 in this game, so p1 is always false
    // always take the center for the first move
    // (research indicates it is always the best move)
  }
  else{
    cout<<"Calculating... Please Wait..."<<endl;
    if(ptest>=100)cout<<"looking "<<IQ<<" steps ahead"<<endl;
    Node *futureStates = new Node(g);
    futureStates = lookAhead(futureStates,IQ,false);
    //look certains steps ahead, depending on IQ of the AI
    // next Step is an AI move
    if(ptest>=10)cout<<"Lookahead done."<<endl;
    int choice = alphabeta(futureStates,INT_MIN,INT_MAX,true,3);
    if(ptest>=10)cout<<"Minimax & AlphaBeta done."<<endl;
    if(choice ==-1) Player::g->dropChecker(randDrop(),false);
    // Player::g->dropChecker(alphabeta(futureStates,INT_MIN,INT_MAX,true,3),false);
    delete futureStates;
    // deleting the futureStates;
    // Note: it might add time complexity, will figure out a way to keep some states
    return 1;
  }
}

AI::~AI(){

}
Human::~Human(){

}
Player::~Player(){

}
