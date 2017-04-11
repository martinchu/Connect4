#include <string>
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include "player.h"
#include "grid.h"
#include "node.h"

using namespace std;

int ptest = 1;
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
      if(g->getColumnChecker(i)!=g->getrowSize()){
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
      else if(ptest>=1000){
        cout <<"col "<<i<<" already full, unnecessary to generate corresponding states"<<endl;
      }
    }
    n->setChildren(tempc);
    if(ptest>=1000)cout<<*n;
    return n;
  }
  return 0;
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
    if(ptest>=10)cout<<"Lookahead done."<<*futureStates<<endl;

    futureStates->alphabeta(INT_MIN,INT_MAX,true,3);
    int choice = futureStates->getRoute();
    if(ptest>=1)cout<<"Minimax & AlphaBeta done. choice: "<<choice<<endl;
    if(choice ==-1){
      choice = randDrop();
    }
    Player::g->dropChecker(choice,false);
    // Player::g->dropChecker(alphabeta(futureStates,INT_MIN,INT_MAX,true,3),false);
    delete futureStates;
    // deleting the futureStates;
    // Note: it might add time complexity, will figure out a way to keep some states
    return 1;
  }
}

AI::~AI(){
  // delete
}
Human::~Human(){

}
Player::~Player(){

}
