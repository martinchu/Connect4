#include <algorithm>
#include "node.h"
#include "grid.h"
#include "textdisplay.h"
#include "cell.h"
#include <climits>
#include <vector>
#include <string>

using namespace std;
int minimaxtest = 1000;
int heuristic(Node *node){
  return 1;
}

int negamax(Node *node,int depth,int color){
  if ( depth == 0 || node->state->isWon()){
    return color * heuristic(node);
  }
  int bestValue = INT_MIN;
  for(int i=0; i<node->children.size();i++){
    // v := −negamax(child, depth − 1, −color)
    // bestValue := max( bestValue, v )

  }
  return bestValue;
}

int alphabeta(Node *n, int alpha, int beta, bool MAXPLAYER){
  if(minimaxtest>=100) cout<<"alpha: "<<alpha<<"\tbeta: "<<beta<<endl;
  if(n->children.size()==0){
    // if it is a terminal node
    cout<<"End state. value = "<<n->num<<endl;
    return n->num;
  }
  else{
    if(minimaxtest>=1000) {
      cout<<"in level "<<n->height<<". It is ";
      cout<<(MAXPLAYER?"MAX":"MIN");
      cout<<"'s turn."<<endl;
    }
    int v;
    // if it is a parent node
    if(MAXPLAYER==true){
      // Max Player's Turn
      v = INT_MIN;
      for(int i = 0; i< n->children.size();i++){
        v = max(v, alphabeta(n->children[i], alpha, beta, false));
        alpha = max(alpha, v);
        if(beta<=alpha){
          if(minimaxtest>=100)cout<<"alpha is smaller than beta; no need to go through the following children"<<endl;
          break;
        }
      }
    }
    else{
      // Min Player's Turn
      v = INT_MAX;
      for(int i = 0; i< n->children.size();i++){
        int temp = alphabeta(n->children[i], alpha, beta, true);
        if(minimaxtest>=100)cout<<"temp: "<<temp<<"\tv: "<<v<<"\tbeta: "<<beta<<endl;
        v = min(v, temp);
        beta = min(beta, v);
        // if(minimaxtest>=100) cout<<"v: "<<v<<"\talpha: "<<alpha<<"\tbeta: "<<beta<<endl;
        if(beta<=alpha){
          if(minimaxtest>=100)cout<<"beta is smaller than alpha; no need to go through the following children"<<endl;
          break;
        }
      }
      cout<<"v: "<<v<<endl;

    }

    return v;
  }
  return -1;
}


int main(){
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

  // cout<< *n13;
  alphabeta(n13,INT_MIN,INT_MAX,true);

  delete n13;
}
