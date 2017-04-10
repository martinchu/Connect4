#include "node.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
int ntest = 100;

Node::Node():num(0),height(1),id("0"){}
Node::Node(string s,int i):num(0),height(1){
  stringstream ss;
  ss<<i;
  id = s + ss.str();
}
Node::Node(string s):num(0),height(1),id(s){

}
Node::Node(int n):num(n),height(1){}
Node::Node(std::vector<Node *> c):num(0),children(c){
  height = c[0]->height +1;
}
Node::Node(Grid *g):state(g){}
void Node::setChildren(vector<Node *>c){
  children = c;
}
 Grid* Node::getState(){
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
    if(ntest>=100){
      cout<<"root node -> value: "<<n.num<<"id: "<<n.id<<endl;
      // cout<<*n.getState()<<endl;
    }
  }
  else{
    cout<<"parent node with "<<n.children.size()<<" children. "<<endl;
    for(unsigned int i = 0; i<n.children.size();i++){
      cout<<"child "<<i<<": ";
    }
    cout<<"done looping node ID: "<<n.id<<endl;
  }
  return out;
}
Node* Node::getChildren(int i){
  return children[i];
}

string Node::getID(){
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
