#include "node.h"
#include <vector>
#include <iostream>

using namespace std;

Node::Node(int n):num(n){}
Node::Node(std::vector<Node *> c):num(0),children(c){}
ostream &operator<<(ostream&out, const Node &n){
  if(n.children.size()==0){
    cout<<"root node -> value: ";
    cout<<n.num<<endl;
  }
  else{
    cout<<"parent node"<<endl;
    for(int i = 0; i<n.children.size();i++){
      cout<<"child "<<i<<": ";
      cout<<*n.children[i];
    }
  }
}

Node::~Node(){
  for(int i = 0; i< children.size();i++){
    delete children[i];
  }
}
