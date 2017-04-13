#include <string>
#include <iostream>
#include <vector>
#include <climits>
// #include "player.h"
// #include "grid.h"
#include "node.h"

using namespace std;

Node* lookAhead(Node* n,int steps){
  // cout<<"lookAhead: "<<n->getID()<<"\tsteps: "<<steps<<endl;
  int col = 7;
  if(steps == 0 )return n;
  else{
    vector<Node *> tempc;
    for(int i=0; i< col;i++){
      // dropChecker on column i
      Node * tempNode = new Node(n->getID(),i);
      tempNode = lookAhead(tempNode, steps-1);
      tempc.push_back(tempNode);
      // cout<<"tempc.size()"<<tempc.size()<<endl;
    }
    n->setChildren(tempc);
    return n;
  }
  return 0;
}

int main(){
  Node *tree = new Node();
  tree = lookAhead(tree, 3);
  cout<< tree->getChildrenSize()<<endl;
  cout<< *tree;
  cout<<"about to delete tree"<<endl;
  delete tree;
}
