#ifndef __NODE_H_
#define __NODE_H_
#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Grid;

class Node {
  Grid* state;
  int num;
  vector<Node *> children;
  // string id;
public:
  Node(Grid *g);
  Node();
  Node(vector<Node *>c);
  Grid* getState()const;
  // void setID(string s);
  // string getID();
  int height;
  int getValue();
  void setValue(int v);
  void setChildren(vector<Node *>c);
  const int getChildrenSize();
  Node* getChildren(int i);
  friend std::ostream &operator<<(std::ostream &out, const Node &n);
  ~Node();
};

#endif
