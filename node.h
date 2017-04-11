#ifndef __NODE_H_
#define __NODE_H_
#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Grid;

class Node {
  Grid* state;
  int route;
  int num;
  vector<Node *> children;
  string id;
public:
  Node(Grid *g);
  Node();
  Node(int n);
  Node(vector<Node *>c);
  void updateRoute(int r);
  int getRoute() const;
  Grid* getState()const;
  void setID(string s);
  string getID() const;
  int height;
  int getValue() const;
  void setValue(int v);
  void setChildren(vector<Node *>c);
  const int getChildrenSize();
  Node* getChildren(int i);
  friend std::ostream &operator<<(std::ostream &out, const Node &n);
  ~Node();
};

#endif
