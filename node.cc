#include "node.h"
#include "grid.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <climits>
#include <cmath>

using namespace std;
int ntest = 1000;
int potentialLcheck =10;
int abtest = 100;


int Node::findPotentialWin(){
  Grid* g = state;
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
  for(int i=0;i<4;i++){
    inARow[i]=0;
    inARowOpponent[i]=0;
  }
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
            if(potentialLcheck>=10)cout<<"V1: Found a potential loss(vertical)!!!"<<i<<j<<endl<<*td<<endl;
            num = -100;
            return num;
          }
          else if(td->getCord(i+1,j)=='2') inARow[1]+=i;

        }
        if(i>= 1 && i <= rowSize-3 && td->getCord(i-1,j)==td->getCord(i+1,j)&&td->getCord(i+1,j)==td->getCord(i+2,j)){
          if(td->getCord(i-1,j)=='1'){
            if(potentialLcheck>=10)cout<<"V2: Found a potential loss(vertical)!!!"<<i<<j<<endl<<*td<<endl;
            num = -100;
            return num;
          }
          else if(td->getCord(i-1,j)=='2') inARow[1]+=i;
        }
        if(i>= 2 && i <= rowSize-2 && td->getCord(i-2,j)==td->getCord(i-1,j)&&td->getCord(i-1,j)==td->getCord(i+1,j)){
          if(td->getCord(i-2,j)=='1'){
            if(potentialLcheck>=10)cout<<"V3: Found a potential loss(vertical)!!!"<<i<<j<<endl<<*td<<endl;
            num = -100;
            return num;
          }
          else if(td->getCord(i-2,j)=='2') inARow[1]+=i;
        }
        if(i>= 3 && i <= rowSize-1 && td->getCord(i-3,j)==td->getCord(i-2,j)&&td->getCord(i-2,j)==td->getCord(i-1,j)){
          if(td->getCord(i-3,j)=='1'){
            if(potentialLcheck>=10)cout<<"V4: Found a potential loss(vertical)!!!"<<i<<j<<endl<<*td<<endl;
            num = -100;
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
  if(ntest>1000){
    for(int i=0;i<4;i++){
      cout<< "inARow "<<i<<": "<<inARow[i]<<endl;
    }
  }
  int value =(100* (inARow[0] + inARow[1] + inARow[2] + inARow[3]) )/16 - (100* (inARowOpponent[0] + inARowOpponent[1] + inARowOpponent[2] + inARowOpponent[3]) )/16;
  return value;
}
int Node::potential4(){
  return -1;
}
int Node::evalBoard(){
  int win =100;
  int draw = 0;
  int unsure = 50;

  Grid * g = state;
  if(g->isFilled() && g->getWinner()=='F') {
    id = "draw";
    num = draw;
    return draw;//The board is full
  }
  else if(g->getWinner()=='1'){
    // Player 1 (Human) Wins => Worse Sitution
    id = "loss";
    num = win*-1;
    return win*-1;
  }
  else if(g->getWinner()=='2'){
    // Player 2 (AI) Wins => Best Situation
    id = "loss";
    num = win;
    return win;
  }
  // Unsure Situation => Go back to parent function and call other function
  id = "unsure";
  num = unsure;
  return unsure;
}
int Node::heuristic(){
  if(evalBoard()!=50) return evalBoard();
  int potWL = findPotentialWin();
  // if(potWL==100||potWL==-100||potWL==0)
  return potWL;
  // else if(findPotent{
  //   int p4 = potential4(n);
  //   return p4;
  // }
  // return -1;
}

int Node::alphabeta(int alpha, int beta, bool MAXPLAYER, int depth){
  // mechanism to keep track of the best children/route
  if(children.size()==0||depth==0){
    if(state)return heuristic();
    return num;
    // return heuristic(n);
  }
  else{
    // int v;
    // if it is a parent node
    if(MAXPLAYER==true){
      // Max Player's Turn
      num = INT_MIN;
      for(unsigned int i = 0; i< children.size();i++){
        int ab = children[i]->alphabeta(alpha,beta,false,depth-1);
        if(ab>num){
          route = i;
          cout<<"Route Updated. Route: "<<route<<endl;
          num = ab;
        }
        alpha = max(alpha, ab);
        if(beta<=alpha)break;
      }
    }
    else{
      // Min Player's Turn
      num = INT_MAX;
      for(unsigned int i = 0; i< children.size();i++){
        int ab = children[i]->alphabeta(alpha, beta, true,depth-1);
        if(ab<num){
          route = i;
          cout<<"Route Updated. Route: "<<route<<endl;
          num = ab;
        }
        beta = min(beta, ab);
        if(beta<=alpha)break;
      }
      // cout<<"n->getValue(): "<<n->getValue()<<endl;
    }
    return num;
  }
  return -1;
}

Node::Node():num(0),height(1){}
Node::Node(std::vector<Node *> c):num(0),children(c){
  height = c[0]->height +1;
}
Node::Node(Grid *g):state(g),height(1){
  id = "";
}
Node::Node(int n):num(n),height(1),id("id"){}
void Node::setChildren(vector<Node *>c){
  children = c;
  height = c[0]->height +1;
  //Update Height
}
Grid* Node::getState()const{
  return state;
}
int Node::getValue()const{
  return num;
}
int Node::getRoute()const{
  return route;
}
void Node::updateRoute(int r){
  route = r;
}
void Node::setValue(int v){
  num = v;
}
const int Node::getChildrenSize(){
  return children.size();
}
ostream &operator<<(ostream&out, const Node &n){
  if(n.children.size()==0){
    cout<<"root node -> value: "<<n.getValue()<<" flag: "<<n.getID()<<endl;
    if(n.getState()) cout<<*(n.getState())<<endl;
    // cout<<*n.getState()<<endl;
  }
  else{
    if(ntest>=1000){
      cout<<"parent node with "<<n.children.size()<<" children. "<<endl;
    }
    for(unsigned int i = 0; i<n.children.size();i++){
      cout<<"child "<<i<<": "<<*n.children[i];
    }
    if(ntest>=1000){
      cout<<"done looping node Height: "<<n.height<<endl;
    }
  }
  return out;
}
Node* Node::getChildren(int i){
  return children[i];
}

string Node::getID()const{
  return id;
}
void Node::setID(string s){
  id = s;
}
Node::~Node(){
  for(unsigned int i = 0; i< children.size();i++){
    delete children[i];
  }
}
