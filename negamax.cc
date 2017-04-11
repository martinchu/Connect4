#include <algorithm>
#include "node.h"
#include "grid.h"
#include "textdisplay.h"
#include "cell.h"
#include <climits>
#include <vector>
#include <string>

int ptest = 0;
int minimaxtest = 0;
int potentialLcheck = 0;

using namespace std;

int evalBoard(Node *n){
  int win =100;
  int draw = 0;
  int unsure = 50;

  Grid * g = n->getState();
  if(g->isFilled() && g->getWinner()=='F') {
    n->setID("draw");
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
  n->setID("unsure");
  return unsure;
}
int findPotentialWin(Node* n){
  Grid* g = n->getState();
  TextDisplay *td = g->getTextDisplay();
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
            n->setValue(-100);
            return -100;
          }
          else if(td->getCord(i+1,j)=='2') inARow[1]+=i;

        }
        if(i>= 1 && i <= rowSize-3 && td->getCord(i-1,j)==td->getCord(i+1,j)&&td->getCord(i+1,j)==td->getCord(i+2,j)){
          if(td->getCord(i-1,j)=='1'){
            if(potentialLcheck>=10)cout<<"V2: Found a potential loss(vertical)!!!"<<i<<j<<endl<<*td<<endl;
            n->setValue(-100);
            return -100;
          }
          else if(td->getCord(i-1,j)=='2') inARow[1]+=i;
        }
        if(i>= 2 && i <= rowSize-2 && td->getCord(i-2,j)==td->getCord(i-1,j)&&td->getCord(i-1,j)==td->getCord(i+1,j)){
          if(td->getCord(i-2,j)=='1'){
            if(potentialLcheck>=10)cout<<"V3: Found a potential loss(vertical)!!!"<<i<<j<<endl<<*td<<endl;
            n->setValue(-100);
            return -100;
          }
          else if(td->getCord(i-2,j)=='2') inARow[1]+=i;
        }
        if(i>= 3 && i <= rowSize-1 && td->getCord(i-3,j)==td->getCord(i-2,j)&&td->getCord(i-2,j)==td->getCord(i-1,j)){
          if(td->getCord(i-3,j)=='1'){
            if(potentialLcheck>=10)cout<<"V4: Found a potential loss(vertical)!!!"<<i<<j<<endl<<*td<<endl;
            n->setValue(-100);
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
  if(ptest>10){
    for(int i=0;i<4;i++){
      cout<< "inARow "<<i<<": "<<inARow[i]<<endl;
    }
  }
  int value = (100* (inARow[0] + inARow[1] + inARow[2] + inARow[3]) )/16 - (100* (inARowOpponent[0] + inARowOpponent[1] + inARowOpponent[2] + inARowOpponent[3]) )/16;
  n->setValue(value);
  return value;
}
int potential4(Node *n){
  return -1;
}
int heuristic(Node* n){
  if(evalBoard(n)!=50) return evalBoard(n);
  int potWL = findPotentialWin(n);
  return potWL;
}
//
// int negamax(Node *node,int depth,int color){
//   if ( depth == 0 || node->getState()->isWon()){
//     return color * heuristic(node);
//   }
//   int bestValue = INT_MIN;
//   for(int i=0; i<node->children.size();i++){
//     // v := −negamax(child, depth − 1, −color)
//     // bestValue := max( bestValue, v )
//
//   }
//   return bestValue;
// }

Node* alphabeta(Node *n, int alpha, int beta, bool MAXPLAYER, int depth){
  // mechanism to keep track of the best children/route
  if(n->getChildrenSize()==0||depth==0){
    return n;
    // return heuristic(n);
  }
  else{
    // int v;
    // if it is a parent node
    if(MAXPLAYER==true){
      // Max Player's Turn
      n->setValue(INT_MIN);
      for(int i = 0; i< n->getChildrenSize();i++){
        int ab = alphabeta(n->getChildren(i),alpha,beta,false,depth-1);
        if(ab>n->getValue()){
          n->updateRoute(i);
          cout<<"Route Updated. Route: "<<n->getRoute()<<endl;
          n->setValue(ab);
        }
        alpha = max(alpha, ab);
        if(beta<=alpha)break;
      }
    }
    else{
      // Min Player's Turn
      n->setValue(INT_MAX);
      for(int i = 0; i< n->getChildrenSize();i++){
        int ab = alphabeta(n->getChildren(i), alpha, beta, true,depth-1);
        if(ab<n->getValue()){
          n->updateRoute(i);
          cout<<"Route Updated. Route: "<<n->getRoute()<<endl;
          n->setValue(ab);
        }
        beta = min(beta, ab);
        if(beta<=alpha)break;
      }
      // cout<<"n->getValue(): "<<n->getValue()<<endl;
    }
    return n->getValue();
  }
  return -1;
}
Node* lookAhead(Node* n,int steps, bool humanMove){
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
      // Make a new children node with new/temporary grid
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

int main(){
  // Grid *g;
  // g= new Grid();
  // g->init();
  // Node* n = new Node(g);
  // n = lookAhead(n,2,false);
  // // cout<< *n13;
  Node *n1 = new Node(0);
  Node *n2 = new Node(18);
  Node *n3 = new Node(15);

  vector <Node *> subtree1;
  subtree1.push_back(n1);
  subtree1.push_back(n2);
  subtree1.push_back(n3);
  Node *n4 = new Node(subtree1);

  Node *n5 = new Node(-6);
  Node *n6 = new Node(2);
  Node *n7 = new Node(-4);

  vector <Node *> subtree2;
  subtree2.push_back(n5);
  subtree2.push_back(n6);
  subtree2.push_back(n7);
  Node *n8 = new Node(subtree2);

  Node *n9 = new Node(-15);
  Node *n10 = new Node(10);
  Node *n11 = new Node(1);

  vector <Node *> subtree3;
  subtree3.push_back(n9);
  subtree3.push_back(n10);
  subtree3.push_back(n11);
  Node *n12 = new Node(subtree3);

  vector <Node *> tree;
  tree.push_back(n4);
  tree.push_back(n8);
  tree.push_back(n12);

  Node *n13 = new Node(tree);
  cout<<"tree built"<<endl;
  cout<<"n13 children:"<<n13->getChildrenSize()<<endl;
  cout<<*n13<<endl;

  alphabeta(n13,INT_MIN,INT_MAX,true,2);


  delete n13;
}
