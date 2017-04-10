#include "node.h"
#include "grid.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
int ntest = 0;

Node::Node():num(0),height(1){}
Node::Node(std::vector<Node *> c):num(0),children(c){
  height = c[0]->height +1;
}
Node::Node(Grid *g):state(g),height(1){}
void Node::setChildren(vector<Node *>c){
  children = c;
  height = c[0]->height +1;
  //Update Height
}
 Grid* Node::getState()const{
  return state;
}
int Node::getValue(){
  return num;
}
void Node::setValue(int v){
  num = v;
}
const int Node::getChildrenSize(){
  return children.size();
}
ostream &operator<<(ostream&out, const Node &n){
  if(n.children.size()==0){
    cout<<"root node -> height: "<<n.height<<endl;
    cout<<*(n.getState())<<endl;
    // cout<<*n.getState()<<endl;
  }
  else{
    cout<<"parent node with "<<n.children.size()<<" children. "<<endl;
    for(unsigned int i = 0; i<n.children.size();i++){
      cout<<"child "<<i<<": "<<*n.children[i];
    }
    cout<<"done looping node Height: "<<n.height<<endl;
  }
  return out;
}
Node* Node::getChildren(int i){
  return children[i];
}

// string Node::getID(){
//   return id;
// }
// void Node::setID(string s){
//   id = s;
// }
Node::~Node(){
  for(unsigned int i = 0; i< children.size();i++){
    delete children[i];
  }
}
