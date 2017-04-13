#include <string>
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include "player.h"
#include "grid.h"
#include "node.h"

using namespace std;

int ptest = 0;
int lookAtest = 0;

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
        if(linenum > Player::g->getcolSize() || linenum < 1)cout<<"Invalid Column. Please Choose Again";
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

int AI::nthAvailabe(int n){
  int temp = n;
  int i = 0;
  while(i<=temp){
    if(g->getColumnChecker(i)==g->getrowSize()){
      temp++;
    }
      i++;
  }
  return temp;
}
Human::Human(Grid *grid){
  Player::g = grid;
}

AI::AI(Grid* grid,int iq, bool mf):IQ(iq),moveFirst(mf){
  Player::g = grid;
}
void AI::checkHuman(){
  cout<<"I am not HUMAN!!"<<endl;

}

Node* AI::lookAhead(Node* n,int steps, bool humanMove){
  // cout<<"lookAhead: "<<n->getID()<<"\tsteps: "<<steps<<endl;
  Grid *g = n->getState();
  int col = g->getcolSize();
  if(steps == 0) {
    return n;
  }
  else if(g->getWinner()=='F'){
    vector<Node *> tempc;
    for(int i=0; i< col;i++){
      Grid * tempGrid = new Grid(*g);
      //call a copy constructor to make a duplicate grid
      tempGrid->dropChecker(i,humanMove);
      // drop a checker on column i of the temporary grid
      Node * tempNode = new Node(tempGrid);
      //make a new node
      if(tempGrid->getColumnChecker(i)<tempGrid->getrowSize()){
        // Make a new children node with new/temporary grid
        tempNode = lookAhead(tempNode, steps-1,!humanMove);
        // Recurse
      }
      else if(ptest>=1000){
        cout <<"col "<<i<<" already full, unnecessary to generate corresponding states"<<endl;
      }
      tempc.push_back(tempNode);
      // push it to the vector
    }
    n->setChildren(tempc);
    // if(ptest>=1000)cout<<*n;
    return n;
  }
  return n;
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
    Player::g->dropChecker(center,moveFirst);
    return 1;
    // AI is always player 2 in this game, so p1 is always false
    // always take the center for the first move
    // (research indicates it is always the best move)
  }
  else{
    cout<<"Calculating... Please Wait..."<<endl;
    if(ptest>=100)cout<<"looking "<<IQ<<" steps ahead"<<endl;
    Grid* temp = new Grid(*g);
    decisionTree = new Node(temp);
    if(decisionTree->findPotentialWin()!= -1){
      // A win or a lose is imminent;
      g->dropChecker(decisionTree->findPotentialWin(), false);
      cout<<"AI drop a checker on column "<<decisionTree->findPotentialWin()+1<<endl;
    }
    else{
      decisionTree = lookAhead(decisionTree,IQ,moveFirst);
      //look certains steps ahead, depending on IQ of the AI
      // next Step is an AI move
      if(ptest>=10)cout<<"Lookahead done."<<*decisionTree<<endl;
      decisionTree->alphabeta(INT_MIN,INT_MAX,true,IQ);
      int choice = nthAvailabe(decisionTree->getRoute());
      cout<<"AI drop a checker on column "<<choice+1<<endl;
      if(choice < 0 || choice > g->getcolSize() )choice = randDrop();
      Player::g->dropChecker(choice,false);
    }


    // Player::g->dropChecker(alphabeta(futureStates,INT_MIN,INT_MAX,true,3),false);
    if(ptest>=100)cout<<"deleting future states now... "<<decisionTree<<endl;
    delete decisionTree;
    // deleting the futureStates;
    // Note: it might add time complexity, will figure out a way to keep some states
    return 1;
  }
}

AI::~AI(){
  // delete
  // if(decisionTree != NULL) delete decisionTree;
}
Human::~Human(){

}
Player::~Player(){

}
