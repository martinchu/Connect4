#include <algorithm>
#include "node.h"
#include "grid.h"
#include "textdisplay.h"
#include "cell.h"
#include <climits>
#include <vector>
#include <string>

using namespace std;

int heuristic(Node node){
  return 1;
}

int negamax(Node *node){
  if ( depth == 0 || node.state->isWon()){
    return color * heuristic(node);
  }
  int bestValue = INT_MIN;
  for(int i=0; i<node.children.size();i++){
    // v := −negamax(child, depth − 1, −color)
    // bestValue := max( bestValue, v )

  }
  return bestValue;
}

string switchTurn(string turn){
  if(turn =="MAX") return "MIN";
  return "MAX";
}
int alphabeta(Node *node, int alpha, int beta, bool MAXPLAYER){
  if(node->children.size()==0){
    // if it is a terminal node
    return node->num;
  }
  else{
    int v;
    string nextTurn = switchTurn(turn);
    // if it is a parent node
    if(MAXPLAYER==true){
      v = INT_MIN;
      for(int i = 0; i< n->children.size();i++){
        v = max(v, alphabeta(n->children[i], alpha, beta, FALSE));
        alpha = max(alpha, v);
        if(beta<=alpha)break;
      }
    }
    else{
      v = INT_MAX;
      for(int i = 0; i< n->children.size();i++){
        v = min(v, alphabeta(n->children[i], alpha, beta, TRUE));
        beta = min(beta, v);
      }
      if(beta<=alpha)break;
    }

    return v;
  }
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

  Node *n5 = new Node(0);
  Node *n6 = new Node(18);
  Node *n7 = new Node(15);

  vector <Node *> subtree2;
  subtree2.push_back(n5);
  subtree2.push_back(n6);
  subtree2.push_back(n7);
  Node *n8 = new Node(subtree2);

  Node *n9 = new Node(0);
  Node *n10 = new Node(18);
  Node *n11 = new Node(15);

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

  cout<< *n13;
  negamax(n13);

  delete n13;
}
