#include <algorithm>
#include "node.h"
#include "grid.h"
#include "textdisplay.h"
#include "cell.h"
#include <climits>
#include <vector>
#include <string>

using namespace std;

int main(){
  // Grid *g;
  // g= new Grid();
  // g->init();
  // Node* n = new Node(g);
  // n = lookAhead(n,2,false);
  // // cout<< *n13;
  Node *n1 = new Node(-19);
  Node *n2 = new Node(4);
  Node *n3 = new Node(17);

  vector <Node *> subtree1;
  subtree1.push_back(n1);
  subtree1.push_back(n2);
  subtree1.push_back(n3);
  Node *n4 = new Node(subtree1);

  Node *n5 = new Node(-9);
  Node *n6 = new Node(-18);
  Node *n7 = new Node(1);

  vector <Node *> subtree2;
  subtree2.push_back(n5);
  subtree2.push_back(n6);
  subtree2.push_back(n7);
  Node *n8 = new Node(subtree2);

  Node *n9 = new Node(-1);
  Node *n10 = new Node(0);
  Node *n11 = new Node(-11);

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

  n13->alphabeta(INT_MIN,INT_MAX,true,2);
  cout<<"Route Chosen: "<<n13->getRoute()<<endl;
  cout<<"Next Route: "<<n13->getChildren(n13->getRoute())->getRoute()<<endl;
  delete n13;
}
